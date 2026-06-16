#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/spell_check.h"

int main(int argc, char *argv[]) {
    clock_t start_global = clock();

    if (argc == 1) {
        printf("Usage: ./vraja \"string\"");
        return 1;
    }

    char delim[] = ",.? ";
    char *token = strtok(argv[1], delim);
    char line[30];

    while (token != NULL)
    {
        int found = 0;

        // I know this is inefficient, but from what I can currently
        // tell, if I open it outside the loop, I can't iterate
        // through it multiple times
        FILE *full_list = fopen("assets/list.txt", "r");

        if (full_list == NULL) {
            perror("Error opening file");
            return 1;
        }

        while (fgets(line, sizeof(line), full_list)) {
            line[strcspn(line, "\n")] = '\0';
            if (strcmp(line, token) == 0) {
                found = 1;
                break;
            }
        }

        fclose(full_list);
        
        if (found == 0) {
            int discard = spell_check(token);
        }

        token = strtok(NULL, " ");
    }

    clock_t end_global = clock();
    double time_taken_global = (double)(end_global - start_global) / CLOCKS_PER_SEC;
    printf("\n[%fs]\n", time_taken_global);

    return 0;
}
