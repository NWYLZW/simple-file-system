#include "delete.h"

static std::vector<const char *> HELP_MSGS = {
    "delete <file>",
    "Usage delete",
    "",
    "  -h, --help    get help message.",
    "",
    "delete specified path file."
};

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
    std::string path = args[1];
    if (!remove(path.c_str())) {
        std::cout << "ERROR: Delete file failure.";
    }
    return 0;
}
