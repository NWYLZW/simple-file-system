#include "read.h"

static std::vector<const char *> HELP_MSGS = {
    "read <filePath>",
    "Usage read",
    "",
    "  -h, --help    get help message.",
    "",
    "read file content."
};

std::vector<std::string*>* readLines(const std::string& filePath) {
    auto lines = new std::vector<std::string*>;
    std::fstream file;
    file.open(filePath);
    if(!file.is_open()) {
        std::cout << "ERROR: FILE IS NOT OPEN" << std::endl;
        return lines;
    }
    while(!file.eof()) {
        std::string line;
        getline(file, line);
        lines->push_back(new std::string(line));
    }
    return lines;
}

int main(
    int argc, char* *args
) {
    if (argc <= 1) {
        std::cout << "ERROR: Need file path." << std::endl;
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
    for (const auto &line : *readLines(args[1])) {
        std::cout << *line << std::endl;
    }
    return 0;
}
