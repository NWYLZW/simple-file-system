#pragma once
#include <stdlib.h>
#include <string.h>

class Cryptor {
public:
    static char* virginia(char* text, char* key, int isDe = false) {
        int i, j = 0, z = 0;
        int textLen = strlen(text), keyLen = strlen(key);
        char* result = (char *)malloc((textLen + 1) * sizeof(char));
        for (i = 0;i < textLen; i++) {
            if (isDe) {
                result[z] = (text[i] - key[j%keyLen] + 26) % 26 + 'a';
            } else {
                result[z] = (text[i] - 'a' + key[j%keyLen] - 'a') % 26 + 'a';
            }
            j++, z++;
        }
        return result;
    }
};
