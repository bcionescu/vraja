#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/calculate_group_limit.h"
#include "../include/compare_matches.h"
#include "../include/first_and_last_letter.h"
#include "../include/full_group_match.h"
#include "../include/get_max_results.h"
#include "../include/length_difference.h"
#include "../include/manual_rules.h"
#include "../include/neighbour_scan.h"
#include "../include/perfect_letter_match.h"
#include "../include/swapped_letter_match.h"
#include "../include/tokenize.h"

int main() {

    clock_t start_global = clock();

    char *misspelled[500] = {"accomodate", "achieveable", "agressive", "arguement", "beleive", "calender", "cemetary", "concious", "definitly", "disapoint", "embarass", "existance", "extacy", "farenheit", "fluorescent", "foreignor", "goverment", "gratefull", "harrass", "indispensible", "occurance", "paralell", "possession", "privledge", "publically", "recieve", "reccommend", "seperate", "threshhold", "tommorrow", "truely", "untill", "wierd"};

    int total_groups_match = 0;
    char **match_tokens;

    for (int i = 0; misspelled[i] != NULL; i++) {
        clock_t start = clock();

        char path[64];
        sprintf(path, "assets/groups/%c.txt", misspelled[i][0]);

        FILE *file = fopen(path, "r");

        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }

        int entry_count = 0;

        char line_buffer[30];
        line_buffer[0] = '\0';

        Match *results = malloc(sizeof(Match) * get_max_results(misspelled[i][0]));

        int total_groups_misspelled = 0;
        char **misspelled_tokens = tokenize(misspelled[i], &total_groups_misspelled);
        if (misspelled_tokens == NULL) return 1;

        char *manual_match = manual_rules(misspelled[i]);

        if (strcmp(manual_match, " ") != 0) {
            clock_t end = clock();
            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

            // printf("\033[0;32m{\"%s\"}, {\"%s\"} [%fs]\n\033[0m", misspelled[i], manual_match, time_taken);
            printf("{\"%s\", \"%s\"} [%fs] [MANUAL]\n", misspelled[i], manual_match, time_taken);
            continue;
        }

        int miss_len = strlen(misspelled[i]);

        while (fgets(line_buffer, sizeof(line_buffer), file)) {
            line_buffer[strcspn(line_buffer, "\n")] = '\0';

            int line_len = strlen(line_buffer);
            int max_search_length = 2;
            if (line_len < miss_len - max_search_length) continue;
            if (line_len > miss_len + max_search_length) break;

            if (i == 0) {
                total_groups_match = 0;
                match_tokens = tokenize(line_buffer, &total_groups_match);
                if (match_tokens == NULL) return 1;
            }

            int limit = calculate_group_limit(total_groups_misspelled, total_groups_match);

            int score = 0;
            score += full_group_match(limit, misspelled_tokens, match_tokens);
            score += perfect_letter_match(limit, misspelled_tokens, match_tokens);
            score += swapped_letter_match(misspelled[i], line_buffer);
            score += length_difference(misspelled[i], line_buffer);
            score += first_and_last_letter(misspelled[i], line_buffer);
            score += neighbour_scan(misspelled[i], line_buffer);

            strcpy(results[entry_count].word, line_buffer);
            results[entry_count].points = score;
            entry_count++;
        }

        qsort(results, entry_count, sizeof(Match), compare_matches);

        printf("{\"%s\"}", misspelled[i]);
        printf(", { ");

        for (int i = 0; i < 3 && i < entry_count; i++) {
            if (results[i].points < (0.95 * results[0].points)) {
                // printf("\"%s [%d] SKIP\" ", results[i].word, results[i].points);
                continue;
            } else {
                printf("\"%s [%d]\" ", results[i].word, results[i].points);
            }
        }

        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("} \[%fs] ", time_taken);
        printf("-> %d entries\n", entry_count);

        entry_count = 0;
        free(results);
        free(misspelled_tokens);
        fclose(file);
    }

    clock_t end_global = clock();
    double time_taken_global = (double)(end_global - start_global) / CLOCKS_PER_SEC;
    printf("\n[%fs]\n", time_taken_global);

    return 0;
}
