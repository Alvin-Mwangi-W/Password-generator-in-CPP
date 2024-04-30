#include "pw_generator.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_password(const char *alphabet, int length, char *password) {
    int alphabet_length = strlen(alphabet);

    for (int i = 0; i < length; i++) {
        int random_index = rand() % alphabet_length;
        password[i] = alphabet[random_index];
    }

    password[length] = '\0';
}

