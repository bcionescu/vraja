#include "../include/neighbour_scan.h"
#include <string.h>

int neighbour_scan(char *misspelled, char *line_buffer)
{
    int score = 0;

    char shortest[30];
    char largest[30];
    if (strlen(misspelled) < strlen(line_buffer))
    {
        strcpy(shortest, misspelled);
        strcpy(largest, line_buffer);
    } else if (strlen(misspelled) > strlen(line_buffer))
    {
        strcpy(shortest, line_buffer);
        strcpy(largest, misspelled);
    } else {
        strcpy(shortest, misspelled);
        strcpy(largest, line_buffer);
    }

    if (shortest[0] == largest[1]) score += 5;

    for (int i = 1; shortest[i] != '\0'; i++)
    {
        if (shortest[i] == largest[i - 1] || shortest[i] == largest[i + 1]) score += 5;
    }

    return score;
}
