#include <string.h>
#include "../include/swapped_letter_match.h"

int swapped_letter_match(char *misspelled, char *potential_match) {
    int length = 0;
    int score = 0;

    if (strlen(misspelled) < strlen(potential_match)) {
        length = strlen(misspelled);
    } else {
        length = strlen(potential_match);
    }

    for (int i = 1; i < length; i++) {
        if (misspelled[i] == potential_match[i-1] && misspelled[i-1] == potential_match[i]) {
            score += 2;
        }
    }

    return score;
}
