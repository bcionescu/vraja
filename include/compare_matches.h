#ifndef COMPARE_MATCHES_H 
#define COMPARE_MATCHES_H

typedef struct {
    char word[32];
    int points;
} Match;

int compare_matches(const void *a, const void *b);

#endif
