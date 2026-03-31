#include "../include/tokenize.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** tokenize(char *p, int *final_count) {
    char buffer[4];
    int capacity = 2;
    int buffer_counter = 0;
    int group_counter = 0;

    char **list = malloc(capacity * sizeof(char *));
    if (!list) return NULL;

    while (*p) {
        buffer[buffer_counter] = *p;

        if (buffer_counter < 2) {
            buffer_counter++;
        } else {
            buffer[3] = '\0';
            if (group_counter == capacity) {
                capacity *= 2;
                list = realloc(list, capacity * sizeof(char *));
            }

            list[group_counter] = malloc(4 * sizeof(char));
            strcpy(list[group_counter], buffer);
            group_counter++;
            buffer_counter = 0;
        }
        p++;
    }

    if (buffer_counter > 0) {
        buffer[buffer_counter] = '\0';

        if (group_counter == capacity) {
            // Is this even needed? I'll have to think this logic through once more, as I learn more about allocating memory.
            // capacity *= 2;
            // list = realloc(list, capacity * sizeof(char *));
        }

        list[group_counter] = malloc(buffer_counter + 1);
        strcpy(list[group_counter], buffer);
        // group_counter++;
    }

    *final_count = group_counter;

    // printf("%c %d -> ", *p, *final_count);
    return list;
}
