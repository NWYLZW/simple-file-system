#include "users.h"

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
