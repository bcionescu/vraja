#include "../include/length_difference.h"
#include <string.h>
#include <stdlib.h>

int length_difference(char *misspelled, char *line_buffer) {
    int score = 0;
    int word_difference = abs((int)strlen(misspelled) - (int)strlen(line_buffer));

    if (word_difference == 0) { score += 8; }
    else if (word_difference == 1) { score += 5; }
    else if (word_difference == 2) { score += 2;
    }

    return score;
}

