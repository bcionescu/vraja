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
#include "../include/spell_check.h"

int main(int argc, char *argv[]) {
    clock_t start_global = clock();

    if (argc == 1) {
        printf("Usage: ./vraja \"string\"");
        return 1;
    }

    FILE *full_list = fopen("assets/list.txt", "r");

    if (full_list == NULL) {
        perror("Error opening file");
        return 1;
    }
    char delim[] = ",.? ";
    char *token = strtok(argv[1], delim);
    char line[30];

    while (token != NULL)
    {
        int found = 0;
        while (fgets(line, sizeof(line), full_list)) {
            line[strcspn(line, "\n")] = '\0';
            if (strcmp(line, token) == 0) {
                found = 1;
                break;
            }
        }
        
        if (found == 0) {
            spell_check(token);
        }

        token = strtok(NULL, " ");
    }

    clock_t end_global = clock();
    double time_taken_global = (double)(end_global - start_global) / CLOCKS_PER_SEC;
    printf("\n[%fs]\n", time_taken_global);

    return 0;
}
