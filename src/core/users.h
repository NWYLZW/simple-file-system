#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <pwd.h>

#include "core/cryptor.h"

#define USERNAME_SECRET "GFyU5a"
#define PASSWORD_SECRET "12"

struct User {
    std::string* p_username;
    std::string* p_password;
};

std::vector<User*>* listUsers();

void setU(const std::string& username);

std::string* getU();
