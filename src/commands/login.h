#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <pwd.h>

#include "core/cryptor.h"

struct User {
    std::string* p_username;
    std::string* p_password;
};

std::vector<User*>* listUsers();

bool verify(
    const std::string& username, std::string* p_password
);
