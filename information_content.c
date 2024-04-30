#include "information_content.h"
#include <math.h>
#include <string.h>

double calculate_information_content(const char *password) {
    int length = strlen(password);
    double information_content = 0.0;

    // Count occurrences of each character
    int count[256] = {0};
    for (int i = 0; i < length; i++) {
        count[(int)password[i]]++;
    }

    // Calculate information content
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            double probability = (double)count[i] / length;
            information_content -= probability * log2(probability);
        }
    }

    return information_content;
}

