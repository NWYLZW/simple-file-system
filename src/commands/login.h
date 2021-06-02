#pragma once
#include <iostream>
#include <vector>

#include "core/cryptor.h"
#include "core/users.h"

bool verify(
    const std::string& username, std::string* p_password
);
