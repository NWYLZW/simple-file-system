#include "write.h"

static std::vector<const char *> HELP_MSGS = {
    "read <filePath> <content>",
    "Usage read",
    "",
    "  -h, --help    get help message.",
    "",
    "read file content."
};

int main(
    int argc, char* *args
) {
    if (argc <= 2) {
        std::cout << "ERROR: parameter is not enough." << std::endl;
        return 1;
    }
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
    auto filePath = std::string(args[1]);
    auto fileCont = std::string(args[2]);
    for (int i = 1; i + 2 < argc; ++i) {
        fileCont += " " + std::string(args[i + 2]);
    }
    std::fstream file;
    file.open(filePath, std::fstream::out);
    if(!file.is_open()) {
        std::cout << "ERROR: FILE IS NOT OPEN" << std::endl;
        return 1;
    }
    file.clear();
    file.write(fileCont.c_str(), fileCont.length());
    file.close();
    return 0;
}
