// #define INCLUDE_MANUAL 0
#define MAX_ENTRIES 3
#define SCORE_LIMITER 0.95
#define DISPLAY_SCORE 0
#define DISPLAY_TIME 0
#define DISPLAY_ENTRIES 0

#define RED   "\x1b[31m"
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"

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
#include "../include/suffix.h"

void spell_check(char *misspelled_word) {
    clock_t start = clock();

    char path[64];
    sprintf(path, "assets/groups/%c.txt", misspelled_word[0]);

    FILE *file = fopen(path, "r");

    if (file == NULL) {
        perror("Error opening file");
        // return 1;
    }

    int entry_count = 0;

    static char line_buffer[30];
    line_buffer[0] = '\0';

    Match *results = malloc(sizeof(Match) * get_max_results(misspelled_word[0]));

    // if (INCLUDE_MANUAL) {
    //     char *manual_match = manual_rules(misspelled_word);
    //
    //     if (strcmp(manual_match, " ") != 0) {
    //         clock_t end = clock();
    //         double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    //
    //         if (DISPLAY_TIME) {
    //             printf("%s -> %s [%fs] [MANUAL]\n", misspelled_word, manual_match, time_taken);
    //         } else {
    //             printf("%s -> %s [MANUAL]\n", misspelled_word, manual_match);
    //         }
    //     }
    // }

    int miss_len = len(misspelled_word);

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

        int line_len = len(line_buffer);
        int max_search_length = 3;
        if (line_len < miss_len - max_search_length) continue;
        if (line_len > miss_len + max_search_length) break;

        int score = 0;
        score += perfect_letter_match(misspelled_word, line_buffer);
        score += swapped_letter_match(misspelled_word, line_buffer);
        score += length_difference(misspelled_word, line_buffer);
        score += first_and_last_letter(misspelled_word, line_buffer);
        score += neighbour_scan(misspelled_word, line_buffer);
        score += suffix(line_len, line_buffer, miss_end_three, miss_end_four, miss_end_five, misspelled_word);
        score = (float) score / (float) miss_len;

        strcpy(results[entry_count].word, line_buffer);
        results[entry_count].points = score;
        entry_count++;
    }

    qsort(results, entry_count, sizeof(Match), compare_matches);

    printf(RED "%s " RESET "( " GREEN, misspelled_word);

    for (int i = 0; i < MAX_ENTRIES && i < entry_count; i++) {
        if (results[i].points < (SCORE_LIMITER * results[0].points)) {
            // printf("\"%s [%d] SKIP\" ", results[i].word, results[i].points);
            continue;
        } else {
            printf("%s ", results[i].word);
            if (DISPLAY_SCORE) { printf("[%d] ", results[i].points); }
        }
    }

    printf(RESET ") ");

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if (DISPLAY_TIME) { printf("[%0.3fms] ", time_taken * 1000); }
    if (DISPLAY_ENTRIES) { printf("-> %d entries", entry_count); }

    entry_count = 0;
    free(results);
    fclose(file);
}
