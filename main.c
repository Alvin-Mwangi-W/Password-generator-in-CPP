#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pw_generator.h"
#include "information_content.h"

#define DEFAULT_ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

int main(int argc, char *argv[]) {
    // Seed random number generator
    srand((unsigned int)time(NULL));

    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s length quantity\n", argv[0]);
        return 1;
    }

    // Parse command line arguments
    int length = atoi(argv[1]);
    int quantity = atoi(argv[2]);

    // Use default alphabet if none provided
    const char *alphabet = (argc >= 4) ? argv[3] : DEFAULT_ALPHABET;

    // Print used alphabet
    printf("Using alphabet: %s\n\n", alphabet);

    // Generate and print passwords
    for (int i = 0; i < quantity; i++) {
        char* password = (char*)malloc((length + 1) * sizeof(char));
        generate_password(alphabet, length, password);
        double information_content = calculate_information_content(password);

        printf("Password %d:\n", i + 1);
        printf("Password: %s\n", password);
        printf("Information content: %.2f bits\n\n", information_content);
    }

    return 0;
}

