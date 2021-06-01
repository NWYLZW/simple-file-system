#include "login.h"

static std::vector<const char *> HELP_MSGS = {
    "login <username> [password]",
    "Usage login",
    "",
    "  -h, --help    get help message.",
    "",
    "login user."
};

int main (
    int argc, char* *args
) {
    if (argc <= 1) {
        std::cout << "Params is empty." << std::endl;
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
    char * username = args[1];
    std::cout << username << std::endl;
    return 0;
}
