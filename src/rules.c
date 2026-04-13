#include <stdio.h>
#include <string.h>

void last_letters(char *word, int len, int n) {
    char last[n + 1];

    for (int i = 0; i < n; i++) { last[i] = word[len - n + i]; }

    strcpy(word, last);
    word[n + 1] = '\0';    // This is the solution, finally!
}
