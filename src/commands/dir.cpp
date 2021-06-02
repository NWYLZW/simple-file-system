#include "dir.h"

static std::vector<const char *> HELP_MSGS = {
    "dir [dirPath]",
    "Usage dir",
    "",
    "  -h, --help    get help message.",
    "",
    "list path dir."
};

void listDir(const char* path) {
    struct dirent* entry;
    DIR* dir = opendir(path);
    if (dir == nullptr) return;

    std::cout
    << "ino  - "
    << "size - "
    << "mode - "
    << "name"
    << std::endl;
    struct stat fileStat;
    while ((entry = readdir(dir)) != nullptr) {
        auto filePath = std::string(path) + "/" + std::string(entry->d_name);
        stat(filePath.c_str(), &fileStat);
        std::cout
        << fileStat.st_ino  << " - "
        << fileStat.st_size << " - "
        << fileStat.st_mode << " - "
        << entry->d_name
        << std::endl;
    }
    closedir(dir);
}

int main(
    int argc, char* *args
) {
    for (int i = 0;i < argc; i++) {
        std::string arg = args[i];
        if (
            arg == "-h" || arg == "--help"
            ) {
            for (const auto &HELP_MSG : HELP_MSGS) {
                std::cout << HELP_MSG << std::endl;
            }
            return 0;
        }
    }
    std::string path = realpath(".", nullptr);
    if (argc > 1) path = args[1];
    listDir(path.c_str());
}
