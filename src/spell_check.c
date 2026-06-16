#define INCLUDE_MANUAL 0
#define MAX_ENTRIES 3
#define SCORE_LIMITER 0.95
#define DISPLAY_SCORE 1
#define DISPLAY_TIME 1
#define DISPLAY_ENTRIES 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/compare_matches.h"
#include "../include/first_and_last_letter.h"
#include "../include/get_max_results.h"
#include "../include/length_difference.h"
#include "../include/manual_rules.h"
#include "../include/neighbour_scan.h"
#include "../include/perfect_letter_match.h"
#include "../include/rules.h"
#include "../include/swapped_letter_match.h"
#include "../include/utils.h"

void spell_check(char *misspelled_word) {
    clock_t start = clock();

    char path[64];
    sprintf(path, "assets/groups/%c.txt", misspelled_word[0]);

    FILE *file = fopen(path, "r");

    // if (file == NULL) {
    //     perror("Error opening file");
    //     return 1;
    // }

    register int entry_count = 0;

    static char line_buffer[30];
    // line_buffer[0] = '\0';

    Match *results = malloc(sizeof(Match) * get_max_results(misspelled_word[0]));

    if (INCLUDE_MANUAL) {
        char *manual_match = manual_rules(misspelled_word);

        if (strcmp(manual_match, " ") != 0) {
            clock_t end = clock();
            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

            if (DISPLAY_TIME) {
                printf("%s -> %s [%fs] [MANUAL]\n", misspelled_word, manual_match, time_taken);
            } else {
                printf("%s -> %s [MANUAL]\n", misspelled_word, manual_match);
            }
        }
    }

    register int miss_len = len(misspelled_word);

    // This next section is sloppy, lol

    char miss_end_three[miss_len + 1];
    char miss_end_four[miss_len + 1];
    char miss_end_five[miss_len + 1];
    stringcopy(miss_len, miss_end_three, misspelled_word);
    stringcopy(miss_len, miss_end_four, misspelled_word);
    stringcopy(miss_len, miss_end_five, misspelled_word);
    last_letters(miss_end_three, miss_len, 3);
    last_letters(miss_end_four, miss_len, 4);
    last_letters(miss_end_five, miss_len, 5);

    while (fgets(line_buffer, sizeof(line_buffer), file)) {
        line_buffer[strcspn(line_buffer, "\n")] = '\0';

        register int line_len = len(line_buffer);
        int max_search_length = 2;
        if (line_len < miss_len - max_search_length) continue;
        if (line_len > miss_len + max_search_length) break;

        int score = 0;
        score += perfect_letter_match(misspelled_word, line_buffer);
        score += swapped_letter_match(misspelled_word, line_buffer);
        score += length_difference(misspelled_word, line_buffer);
        score += first_and_last_letter(misspelled_word, line_buffer);
        score += neighbour_scan(misspelled_word, line_buffer);

        // The next step is to move all the code below to their own function, and only call them
        // if the misspelled word ends in full, ely, aly, phoby, or if it contains ie. That will
        // spare a lot of computation

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

        score = (float) score / (float) miss_len;

        strcpy(results[entry_count].word, line_buffer);
        results[entry_count].points = score;
        entry_count++;
    }

    qsort(results, entry_count, sizeof(Match), compare_matches);

    printf("%s -> ", misspelled_word);

    for (int i = 0; i < MAX_ENTRIES && i < entry_count; i++) {
        if (results[i].points < (SCORE_LIMITER * results[0].points)) {
            // printf("\"%s [%d] SKIP\" ", results[i].word, results[i].points);
            continue;
        } else {
            printf("%s ", results[i].word);
            if (DISPLAY_SCORE) { printf("[%d] ", results[i].points); }
        }
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if (DISPLAY_TIME) { printf("[%0.3fms] ", time_taken * 1000); }
    if (DISPLAY_ENTRIES) { printf("-> %d entries", entry_count); }
    printf("\n");

    entry_count = 0;
    free(results);
    fclose(file);
}
