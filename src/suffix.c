#include <string.h>

#include "../include/utils.h"
#include "../include/first_and_last_letter.h"
#include "../include/rules.h"

int suffix(int line_len, char *line_buffer, char *miss_end_three, char *miss_end_four, char *miss_end_five, char *misspelled_word) {

    int score = 0;

    char match_end_three[line_len + 1];
    char match_end_four[line_len + 1];
    char match_end_five[line_len + 1];
    char match_end_six[line_len + 1];
    stringcopy(line_len, match_end_three, line_buffer);
    stringcopy(line_len, match_end_four, line_buffer);
    stringcopy(line_len, match_end_five, line_buffer);
    stringcopy(line_len, match_end_six, line_buffer);
    last_letters(match_end_three, line_len, 3);
    last_letters(match_end_four, line_len, 4);
    last_letters(match_end_five, line_len, 5);
    last_letters(match_end_six, line_len, 6);

    if (strcmp(miss_end_three,  "ely") == 0 && strcmp(match_end_three,  "uly") == 0) { score += 50; }
    if (strcmp(miss_end_three,  "aly") == 0 && strcmp(match_end_four,   "ally") == 0) { score += 50; }
    if (strcmp(miss_end_four,   "full") == 0 && strcmp(match_end_three, "ful") == 0) { score += 50; }
    if (strcmp(miss_end_four,   "gnor") == 0 && strcmp(match_end_four,  "gner") == 0) { score += 50; }
    if (strcmp(miss_end_four,   "gnar") == 0 && strcmp(match_end_four,  "gner") == 0) { score += 50; }
    if (strcmp(miss_end_four,   "itly") == 0 && strcmp(match_end_five,  "itely") == 0) { score += 50; }
    if (strcmp(miss_end_four,   "raly") == 0 && strcmp(match_end_five,  "rally") == 0) { score += 50; }
    if (strcmp(miss_end_five,   "tance") == 0 && strcmp(match_end_five, "tence") == 0) { score += 50; }
    if (strcmp(miss_end_five,   "phoby") == 0 && strcmp(match_end_six,  "phobia") == 0) { score += 50; }
    if (strstr(misspelled_word, "ie") != NULL && strstr(line_buffer,    "ei") != NULL ) { score += 30; }

    return score;
}
