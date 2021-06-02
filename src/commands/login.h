#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <pwd.h>

#include "core/cryptor.h"

bool verify(
    const std::string& username, std::string* p_password
);
