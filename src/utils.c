#include <stdio.h>

int len(const char *str) {
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

void stringcopy(int len1, char str1[len1], char str2[]) {
    int i = 0;
    for (; i < len1; i++) {
        str1[i] = str2[i];
    }

    str1[i] = '\0';
}
