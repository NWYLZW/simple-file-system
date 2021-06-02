#include "login.h"

bool verify(
    const std::string& username, std::string* p_password
) {
    for (const auto &user : *listUsers()) {
        if (username == *user->p_username) {
            if (user->p_password->empty()) {
                return true;
            } else {
                std::string password;
                if (p_password == nullptr) {
                    int i = 0;
                    for (; i < 3; ++i) {
                        std::cout << "please input password> ";
                        std::getline(std::cin, password);
                        if (
                            Cryptor::simple(password, PASSWORD_SECRET) == *user->p_password
                        ) {
                            return true;
                        } else {
                            std::cout << "password is wrong." << std::endl;
                        }
                    }
                    if (i == 3) {
                        std::cout << "ERROR: Too many errors." << std::endl;
                        return false;
                    }
                } else {
                    password = *p_password;
                    if (
                        Cryptor::simple(password, PASSWORD_SECRET) == *user->p_password
                    ) {
                        return true;
                    } else {
                        std::cout << "password is wrong." << std::endl;
                    }
                }
            }
        }
    }
    return false;
}

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
        std::cout << "ERROR: params is empty." << std::endl;
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
    std::string username = args[1];
    std::string password;
    if (argc >= 3) {
        password = std::string(args[2]);
    }
    if (!verify(
        username, argc >= 3
        ? &password
        : nullptr
    )) return -1;
    std::cout << "login success." << std::endl;
    setU(username);
    return 0;
}
