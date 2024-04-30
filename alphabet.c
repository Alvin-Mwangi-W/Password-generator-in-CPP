#include "alphabet.h"
#include <string.h>
#include <ctype.h>

void calculate_union_alphabet(const char *flags, const char *additional_chars, char *union_alphabet) {
    // Initialize union alphabet array with zeros
    int alphabet[256] = {0};

    // Process flags
    while (*flags != '\0') {
        if (*flags == '-') {
            flags++;
            while (*flags != '\0' && !isspace(*flags)) {
                alphabet[(int)(*flags)] = 1;
                flags++;
            }
        } else {
            flags++;
        }
    }

    // Process additional characters
    while (*additional_chars != '\0') {
        alphabet[(int)(*additional_chars)] = 1;
        additional_chars++;
    }

    // Construct union alphabet string
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (alphabet[i]) {
            union_alphabet[index++] = (char)i;
        }
    }
    union_alphabet[index] = '\0';
}

