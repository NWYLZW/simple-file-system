#pragma once
#include <iostream>

class Cryptor {
public:
    static std::string simple(
        std::string text, std::string key
    ) {
        std::string result = "";
        for (int i = 0;i < text.length(); i++) {
            result += text[i] ^ key[i % key.length()];
        }
        return result;
    }
};
