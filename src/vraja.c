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
#include "../include/swapped_letter_match.h"
#include "../include/tokenize.h"

int main(void)
{
    clock_t start_global = clock();
    
    const int INCLUDE_MANUAL = 1;

    char *misspelled[500] = {"accomodate", "achieveable", "agressive", "arguement", "beleive", "calender", "cemetary", "concious", "definitly", "disapoint", "embarass", "existance", "extacy", "farenheit", "fluorescent", "foreignor", "goverment", "gratefull", "gracefull", "harrass", "indispensible", "occurance", "paralell", "possession", "privledge", "publically", "recieve", "reccommend", "seperate", "threshhold", "tommorrow", "truely", "untill", "wierd"};

    for (int i = 0; misspelled[i] != NULL; i++)
    {
        clock_t start = clock();

        register char *misspelled_word = misspelled[i];

        char path[64];
        sprintf(path, "assets/groups/%c.txt", misspelled_word[0]);

        FILE *file = fopen(path, "r");

        if (file == NULL)
        {
            perror("Error opening file");
            return 1;
        }

        int entry_count = 0;

        char line_buffer[30];
        line_buffer[0] = '\0';

        Match *results = malloc(sizeof(Match) * get_max_results(misspelled_word[0]));

        if (INCLUDE_MANUAL == 1)
        {
            char *manual_match = manual_rules(misspelled_word);

            if (strcmp(manual_match, " ") != 0)
            {
                clock_t end = clock();
                double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

                // printf("\033[0;32m{\"%s\"}, {\"%s\"} [%fs]\n\033[0m", misspelled_word, manual_match, time_taken);
                printf("{\"%s\", \"%s\"} [%fs] [MANUAL]\n", misspelled_word, manual_match, time_taken);
                continue;
            }
        }

        int miss_len = strlen(misspelled_word);

        char miss_end[5] = "";
        int miss_end_counter = 0;
        for (int j = miss_len - 4; j < miss_len; j++)
        {
            // printf("%c", misspelled_word[j]);
            miss_end[miss_end_counter] = misspelled_word[j];
            miss_end_counter++;
        }

        while (fgets(line_buffer, sizeof(line_buffer), file))
        {
            line_buffer[strcspn(line_buffer, "\n")] = '\0';

            int line_len = strlen(line_buffer);
            int max_search_length = 2;
            if (line_len < miss_len - max_search_length) continue;
            if (line_len > miss_len + max_search_length) break;

            int score = 0;
            score += perfect_letter_match(misspelled_word, line_buffer);
            score += swapped_letter_match(misspelled_word, line_buffer);
            score += length_difference(misspelled_word, line_buffer);
            score += first_and_last_letter(misspelled_word, line_buffer);
            score += neighbour_scan(misspelled_word, line_buffer);

            char match_end[4] = "";
            int match_end_counter = 0;
            for (int j = line_len - 3; j < line_len; j++)
            {
                match_end[match_end_counter] = line_buffer[j];
                match_end_counter++;
            }

            if (strcmp(miss_end, "full") == 0 && strcmp(match_end, "ful") == 0)
            {
                score += 50;
                // printf("\n %s %s %d\n", misspelled_word, line_buffer, score);
            }

            strcpy(results[entry_count].word, line_buffer);
            results[entry_count].points = score;
            entry_count++;
        }

        qsort(results, entry_count, sizeof(Match), compare_matches);

        printf("{\"%s\"}", misspelled_word);
        printf(", { ");

        for (int i = 0; i < 3 && i < entry_count; i++)
        {
            if (results[i].points < (0.95 * results[0].points))
            {
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
        fclose(file);
    }

    clock_t end_global = clock();
    double time_taken_global = (double)(end_global - start_global) / CLOCKS_PER_SEC;
    printf("\n[%fs]\n", time_taken_global);

    return 0;
}
