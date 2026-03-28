#include "../include/full_group_match.h"
#include <string.h>

int full_group_match(int limit, char **misspelled_tokens, char **match_tokens) {
    int score = 0;

    for (int i = 0; i < limit; i++) {
        // printf("%s %s -> ", misspelled_tokens[i], match_tokens[i]);
        if (strcmp(misspelled_tokens[i], match_tokens[i]) == 0) {
            score += 5;
        }
    }

    return score;
}
