#include "login.h"

std::vector<std::string> split(
    std::string s, std::string delim
) {
    char *p = &s[0];
    char *d = &delim[0];
    std::vector<std::string> res = {""};

    do {
        bool is_delim = true;
        char *pp = p;
        char *dd = d;
        while (*dd && is_delim) {
            if (*pp++ != *dd++)
                is_delim = false;
        }

        if (is_delim) {
            p = pp - 1;
            res.push_back("");
        } else {
            *(res.rbegin()) += *p;
        }
    } while (*p++);
    return res;
}

std::vector<User*>* listUsers() {
    auto users = new std::vector<User*>();

    std::string line;
    std::fstream file;
    file.open(
        std::string(getpwuid(getuid())->pw_dir) + "/.sfs.users"
    );
    if(!file.is_open()) {
        std::cout << "ERROR: FILE IS NOT OPEN" << std::endl;
        return users;
    }
    while(!file.eof()) {
        getline(file, line);
        if (!line.empty()) {
            auto lineItems = split(line, ":");
            auto username = lineItems[0];
            auto password = lineItems[1].substr(
                0, lineItems[1].length() - 1
            );
            User* u = new User;
            u->p_username = new std::string(username);
            u->p_password = new std::string(password);
            users->push_back(u);
        }
    }
    file.close();
    return users;
}

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

void setU(
    const std::string& username
) {
    std::fstream file;
    file.open(
        std::string(getpwuid(getuid())->pw_dir) + "/.sfs.cur", std::fstream::out
    );
    if(!file.is_open()) {
        std::cout << "ERROR: FILE IS NOT OPEN" << std::endl;
        return;
    }
    file.clear();
    file.write(Cryptor::simple(
        username, USERNAME_SECRET
    ).c_str(), username.length());
    file.close();
}

std::string* getU() {
    std::string username;
    std::fstream file;
    file.open(
        std::string(getpwuid(getuid())->pw_dir) + "/.sfs.cur", std::fstream::in
    );
    if(!file.is_open()) {
        std::cout << "ERROR: FILE IS NOT OPEN" << std::endl;
        return nullptr;
    }
    getline(file, username);
    file.close();
    return new std::string(Cryptor::simple(
        username, USERNAME_SECRET
    ));
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
    return 0;
}
