#include "../include/compare_matches.h"

int compare_matches(const void *a, const void *b)
{
    Match *m1 = (Match *)a;
    Match *m2 = (Match *)b;

    return (m2->points - m1->points);
}

