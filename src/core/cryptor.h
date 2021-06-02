#pragma once
#include <iostream>

class Cryptor {
public:
    static string simple(
        string text, string key
    ) {
        string result = "";
        for (int i = 0;i < text.length(); i++) {
            result += text[i] ^ key[i % key.length()];
        }
        return result;
    }
};
