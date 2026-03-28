#include "../include/calculate_group_limit.h"

int calculate_group_limit(int total_groups_misspelled, int total_groups_match) {
    int limit = (total_groups_misspelled < total_groups_match)
        ? total_groups_misspelled
        : total_groups_match;
    return limit;
}

