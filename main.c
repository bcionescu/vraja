#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char word[32];
    int points;
} Match;

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
    return list;
}

int calculate_group_limit(int total_groups_misspelled, int total_groups_match) {
    int limit = (total_groups_misspelled < total_groups_match)
        ? total_groups_misspelled
        : total_groups_match;
    return limit;
}

int full_group_match(int limit, char **misspelled_tokens, char **match_tokens) {
    int score = 0;

    for (int i = 0; i < limit; i++) {
        // printf("%s %s -> ", misspelled_tokens[i], match_tokens[i]);
        if (strcmp(misspelled_tokens[i], match_tokens[i]) == 0) {
            score += 5;
        }
    }

    return score;
}

int perfect_letter_match(int limit, char **misspelled_tokens, char **match_tokens) {
    int score = 0;

    for (int i = 0; i < limit; i++) {
        char *p1 = misspelled_tokens[i];
        char *p2 = match_tokens[i];

        while (*p1 && *p2) {
            if (*p1 == *p2) {
                score += 2;
            } else {

                char *n_a = "qwsxz`";
                char *n_b = "vghn";
                char *n_c = "xdfv";
                char *n_d = "werfcxs";
                char *n_e = "34rfdsw";
                char *n_f = "ertgvcd";
                char *n_g = "rtyhbvf";
                char *n_h = "tyujnbg";
                char *n_i = "89olkju";
                char *n_j = "yuikmnh";
                char *n_k = "uiol,mj";
                char *n_l = "iop;.,k";
                char *n_m = "njk,";
                char *n_n = "bhjm";
                char *n_o = "90p;lki";
                char *n_p = "0-[';lo";
                char *n_q = "12wsa";
                char *n_r = "45tgfde";
                char *n_s = "wedxzaq";
                char *n_t = "56yhgfr";
                char *n_u = "78ikjhy";
                char *n_v = "cfgb";
                char *n_w = "23edsaq";
                char *n_x = "zsdc";
                char *n_y = "67ujhgt";
                char *n_z = "asx`";

                while (*n_a) {
                    if (*p1 == 'a' && *p2 == *n_a) {
                        score++;
                        // printf("%c %c -> Ne match -> [1]\n", *p1, *p2);
                    }
                    n_a++;
                }

                while (*n_b) {
                    if (*p1 == 'b' && *p2 == *n_b) {
                        score++;
                    }
                    n_b++;
                }

                while (*n_c) {
                    if (*p1 == 'c' && *p2 == *n_c) {
                        score++;
                    }
                    n_c++;
                }

                while (*n_d) {
                    if (*p1 == 'd' && *p2 == *n_d) {
                        score++;
                    }
                    n_d++;
                }

                while (*n_e) {
                    if (*p1 == 'e' && *p2 == *n_e) {
                        score++;
                    }
                    n_e++;
                }

                while (*n_f) {
                    if (*p1 == 'f' && *p2 == *n_f) {
                        score++;
                    }
                    n_f++;
                }

                while (*n_g) {
                    if (*p1 == 'g' && *p2 == *n_g) {
                        score++;
                    }
                    n_g++;
                }

                while (*n_h) {
                    if (*p1 == 'h' && *p2 == *n_h) {
                        score++;
                    }
                    n_h++;
                }

                while (*n_i) {
                    if (*p1 == 'i' && *p2 == *n_i) {
                        score++;
                    }
                    n_i++;
                }

                while (*n_j) {
                    if (*p1 == 'j' && *p2 == *n_j) {
                        score++;
                    }
                    n_j++;
                }

                while (*n_k) {
                    if (*p1 == 'k' && *p2 == *n_k) {
                        score++;
                    }
                    n_k++;
                }

                while (*n_l) {
                    if (*p1 == 'l' && *p2 == *n_l) {
                        score++;
                    }
                    n_l++;
                }

                while (*n_m) {
                    if (*p1 == 'm' && *p2 == *n_m) {
                        score++;
                    }
                    n_m++;
                }

                while (*n_n) {
                    if (*p1 == 'n' && *p2 == *n_n) {
                        score++;
                    }
                    n_n++;
                }

                while (*n_o) {
                    if (*p1 == 'o' && *p2 == *n_o) {
                        score++;
                    }
                    n_o++;
                }

                while (*n_p) {
                    if (*p1 == 'p' && *p2 == *n_p) {
                        score++;
                    }
                    n_p++;
                }

                while (*n_q) {
                    if (*p1 == 'q' && *p2 == *n_q) {
                        score++;
                    }
                    n_q++;
                }

                while (*n_r) {
                    if (*p1 == 'r' && *p2 == *n_r) {
                        score++;
                    }
                    n_r++;
                }

                while (*n_s) {
                    if (*p1 == 's' && *p2 == *n_s) {
                        score++;
                    }
                    n_s++;
                }

                while (*n_t) {
                    if (*p1 == 't' && *p2 == *n_t) {
                        score++;
                    }
                    n_t++;
                }

                while (*n_u) {
                    if (*p1 == 'u' && *p2 == *n_u) {
                        score++;
                    }
                    n_u++;
                }

                while (*n_v) {
                    if (*p1 == 'v' && *p2 == *n_v) {
                        score++;
                    }
                    n_v++;
                }

                while (*n_w) {
                    if (*p1 == 'w' && *p2 == *n_w) {
                        score++;
                    }
                    n_w++;
                }

                while (*n_x) {
                    if (*p1 == 'x' && *p2 == *n_x) {
                        score++;
                    }
                    n_x++;
                }

                while (*n_y) {
                    if (*p1 == 'y' && *p2 == *n_y) {
                        score++;
                    }
                    n_y++;
                }

                while (*n_z) {
                    if (*p1 == 'z' && *p2 == *n_z) {
                        score++;
                    }
                    n_z++;
                }
            }

            p1++;
            p2++;
        }
    }

    return score;
}

int swapped_letter_match(char *misspelled, char *potential_match) {
    int length = 0;
    int score = 0;

    if (strlen(misspelled) < strlen(potential_match)) {
        length = strlen(misspelled);
    } else {
        length = strlen(potential_match);
    }

    for (int i = 1; i < length; i++) {
        if (misspelled[i] == potential_match[i-1] && misspelled[i-1] == potential_match[i]) {
            score += 2;
        }
    }

    return score;
}

int compare_matches(const void *a, const void *b) {
    Match *m1 = (Match *)a;
    Match *m2 = (Match *)b;

    return (m2->points - m1->points);
}

int length_difference(char *misspelled, char *line_buffer) {
    int score = 0;
    int word_difference = abs((int)strlen(misspelled) - (int)strlen(line_buffer));

    if (word_difference == 0) { score += 8; }
    else if (word_difference == 1) { score += 5; }
    else if (word_difference == 2) { score += 2;
    }

    return score;
}

int first_and_last_letter(char *misspelled, char *line_buffer) {
    int score = 0;
    int first_perfect_match = 0;
    int second_perfect_match = 0;
    int third_perfect_match = 0;

    if (misspelled[0] == line_buffer[0]) {
        score += 15;
        first_perfect_match += 1;
    }

    if (misspelled[strlen(misspelled) - 1] == line_buffer[strlen(line_buffer) - 1]) {
        score += 15;
        first_perfect_match += 1;
    }

    if (first_perfect_match == 2) score += 30;

    if (misspelled[1] == line_buffer[1]) {
        score += 10;
        second_perfect_match += 1;
    }

    if (misspelled[strlen(misspelled) - 2] == line_buffer[strlen(line_buffer) - 2]) {
        score += 10;
        second_perfect_match += 1;
    }

    if (second_perfect_match == 2) score += 15;

    if (misspelled[2] == line_buffer[2]) {
        score += 10;
        third_perfect_match += 1;
    }

    if (misspelled[strlen(misspelled) - 3] == line_buffer[strlen(line_buffer) - 3]) {
        score += 10;
        third_perfect_match += 1;
    }

    if (third_perfect_match == 2) score += 10;

    // If the first letter gets a neighbour match, 7 bonus points.

    char *n_a = "qwsxz`";
    char *n_b = "vghn";
    char *n_c = "xdfv";
    char *n_d = "werfcxs";
    char *n_e = "34rfdsw";
    char *n_f = "ertgvcd";
    char *n_g = "rtyhbvf";
    char *n_h = "tyujnbg";
    char *n_i = "89olkju";
    char *n_j = "yuikmnh";
    char *n_k = "uiol,mj";
    char *n_l = "iop;.,k";
    char *n_m = "njk,";
    char *n_n = "bhjm";
    char *n_o = "90p;lki";
    char *n_p = "0-[';lo";
    char *n_q = "12wsa";
    char *n_r = "45tgfde";
    char *n_s = "wedxzaq";
    char *n_t = "56yhgfr";
    char *n_u = "78ikjhy";
    char *n_v = "cfgb";
    char *n_w = "23edsaq";
    char *n_x = "zsdc";
    char *n_y = "67ujhgt";
    char *n_z = "asx`";

    while (*n_a) {
        if (misspelled[0] == 'a' && line_buffer[0] == *n_a) {
            score += 7;
        }
        n_a++;
    }

    while (*n_b) {
        if (misspelled[0] == 'b' && line_buffer[0] == *n_b) {
            score += 7;
        }
        n_b++;
    }

    while (*n_c) {
        if (misspelled[0] == 'c' && line_buffer[0] == *n_c) {
            score += 7;
        }
        n_c++;
    }

    while (*n_d) {
        if (misspelled[0] == 'd' && line_buffer[0] == *n_d) {
            score += 7;
        }
        n_d++;
    }

    while (*n_e) {
        if (misspelled[0] == 'e' && line_buffer[0] == *n_e) {
            score += 7;
        }
        n_e++;
    }

    while (*n_f) {
        if (misspelled[0] == 'f' && line_buffer[0] == *n_f) {
            score += 7;
        }
        n_f++;
    }

    while (*n_g) {
        if (misspelled[0] == 'g' && line_buffer[0] == *n_g) {
            score += 7;
        }
        n_g++;
    }

    while (*n_h) {
        if (misspelled[0] == 'h' && line_buffer[0] == *n_h) {
            score += 7;
        }
        n_h++;
    }

    while (*n_i) {
        if (misspelled[0] == 'i' && line_buffer[0] == *n_i) {
            score += 7;
        }
        n_i++;
    }

    while (*n_j) {
        if (misspelled[0] == 'j' && line_buffer[0] == *n_j) {
            score += 7;
        }
        n_j++;
    }

    while (*n_k) {
        if (misspelled[0] == 'k' && line_buffer[0] == *n_k) {
            score += 7;
        }
        n_k++;
    }

    while (*n_l) {
        if (misspelled[0] == 'l' && line_buffer[0] == *n_l) {
            score += 7;
        }
        n_l++;
    }

    while (*n_m) {
        if (misspelled[0] == 'm' && line_buffer[0] == *n_m) {
            score += 7;
        }
        n_m++;
    }

    while (*n_n) {
        if (misspelled[0] == 'n' && line_buffer[0] == *n_n) {
            score += 7;
        }
        n_n++;
    }

    while (*n_o) {
        if (misspelled[0] == 'o' && line_buffer[0] == *n_o) {
            score += 7;
        }
        n_o++;
    }

    while (*n_p) {
        if (misspelled[0] == 'p' && line_buffer[0] == *n_p) {
            score += 7;
        }
        n_p++;
    }

    while (*n_q) {
        if (misspelled[0] == 'q' && line_buffer[0] == *n_q) {
            score += 7;
        }
        n_q++;
    }

    while (*n_r) {
        if (misspelled[0] == 'r' && line_buffer[0] == *n_r) {
            score += 7;
        }
        n_r++;
    }

    while (*n_s) {
        if (misspelled[0] == 's' && line_buffer[0] == *n_s) {
            score += 7;
        }
        n_s++;
    }

    while (*n_t) {
        if (misspelled[0] == 't' && line_buffer[0] == *n_t) {
            score += 7;
        }
        n_t++;
    }

    while (*n_u) {
        if (misspelled[0] == 'u' && line_buffer[0] == *n_u) {
            score += 7;
        }
        n_u++;
    }

    while (*n_v) {
        if (misspelled[0] == 'v' && line_buffer[0] == *n_v) {
            score += 7;
        }
        n_v++;
    }

    while (*n_w) {
        if (misspelled[0] == 'w' && line_buffer[0] == *n_w) {
            score += 7;
        }
        n_w++;
    }

    while (*n_x) {
        if (misspelled[0] == 'x' && line_buffer[0] == *n_x) {
            score += 7;
        }
        n_x++;
    }

    while (*n_y) {
        if (misspelled[0] == 'y' && line_buffer[0] == *n_y) {
            score += 7;
        }
        n_y++;
    }

    while (*n_z) {
        if (misspelled[0] == 'z' && line_buffer[0] == *n_z) {
            score += 7;
        }
        n_z++;
    }

    int miss_last = strlen(misspelled) - 1;
    int line_last = strlen(line_buffer) - 1;

    while (*n_a) {
        if (misspelled[miss_last] == 'a' && line_buffer[line_last] == *n_a) {
            score += 7;
        }
        n_a++;
    }

    while (*n_b) {
        if (misspelled[miss_last] == 'b' && line_buffer[line_last] == *n_b) {
            score += 7;
        }
        n_b++;
    }

    while (*n_c) {
        if (misspelled[miss_last] == 'c' && line_buffer[line_last] == *n_c) {
            score += 7;
        }
        n_c++;
    }

    while (*n_d) {
        if (misspelled[miss_last] == 'd' && line_buffer[line_last] == *n_d) {
            score += 7;
        }
        n_d++;
    }

    while (*n_e) {
        if (misspelled[miss_last] == 'e' && line_buffer[line_last] == *n_e) {
            score += 7;
        }
        n_e++;
    }

    while (*n_f) {
        if (misspelled[miss_last] == 'f' && line_buffer[line_last] == *n_f) {
            score += 7;
        }
        n_f++;
    }

    while (*n_g) {
        if (misspelled[miss_last] == 'g' && line_buffer[line_last] == *n_g) {
            score += 7;
        }
        n_g++;
    }

    while (*n_h) {
        if (misspelled[miss_last] == 'h' && line_buffer[line_last] == *n_h) {
            score += 7;
        }
        n_h++;
    }

    while (*n_i) {
        if (misspelled[miss_last] == 'i' && line_buffer[line_last] == *n_i) {
            score += 7;
        }
        n_i++;
    }

    while (*n_j) {
        if (misspelled[miss_last] == 'j' && line_buffer[line_last] == *n_j) {
            score += 7;
        }
        n_j++;
    }

    while (*n_k) {
        if (misspelled[miss_last] == 'k' && line_buffer[line_last] == *n_k) {
            score += 7;
        }
        n_k++;
    }

    while (*n_l) {
        if (misspelled[miss_last] == 'l' && line_buffer[line_last] == *n_l) {
            score += 7;
        }
        n_l++;
    }

    while (*n_m) {
        if (misspelled[miss_last] == 'm' && line_buffer[line_last] == *n_m) {
            score += 7;
        }
        n_m++;
    }

    while (*n_n) {
        if (misspelled[miss_last] == 'n' && line_buffer[line_last] == *n_n) {
            score += 7;
        }
        n_n++;
    }

    while (*n_o) {
        if (misspelled[miss_last] == 'o' && line_buffer[line_last] == *n_o) {
            score += 7;
        }
        n_o++;
    }

    while (*n_p) {
        if (misspelled[miss_last] == 'p' && line_buffer[line_last] == *n_p) {
            score += 7;
        }
        n_p++;
    }

    while (*n_q) {
        if (misspelled[miss_last] == 'q' && line_buffer[line_last] == *n_q) {
            score += 7;
        }
        n_q++;
    }

    while (*n_r) {
        if (misspelled[miss_last] == 'r' && line_buffer[line_last] == *n_r) {
            score += 7;
        }
        n_r++;
    }

    while (*n_s) {
        if (misspelled[miss_last] == 's' && line_buffer[line_last] == *n_s) {
            score += 7;
        }
        n_s++;
    }

    while (*n_t) {
        if (misspelled[miss_last] == 't' && line_buffer[line_last] == *n_t) {
            score += 7;
        }
        n_t++;
    }

    while (*n_u) {
        if (misspelled[miss_last] == 'u' && line_buffer[line_last] == *n_u) {
            score += 7;
        }
        n_u++;
    }

    while (*n_v) {
        if (misspelled[miss_last] == 'v' && line_buffer[line_last] == *n_v) {
            score += 7;
        }
        n_v++;
    }

    while (*n_w) {
        if (misspelled[miss_last] == 'w' && line_buffer[line_last] == *n_w) {
            score += 7;
        }
        n_w++;
    }

    while (*n_x) {
        if (misspelled[miss_last] == 'x' && line_buffer[line_last] == *n_x) {
            score += 7;
        }
        n_x++;
    }

    while (*n_y) {
        if (misspelled[miss_last] == 'y' && line_buffer[line_last] == *n_y) {
            score += 7;
        }
        n_y++;
    }

    while (*n_z) {
        if (misspelled[miss_last] == 'z' && line_buffer[line_last] == *n_z) {
            score += 7;
        }
        n_z++;
    }

    return score;
}

int neighbour_scan(char *misspelled, char *line_buffer) {
    int score = 0;

    char shortest[30];
    char largest[30];
    if (strlen(misspelled) < strlen(line_buffer)) {
        strcpy(shortest, misspelled);
        strcpy(largest, line_buffer);
    } else if (strlen(misspelled) > strlen(line_buffer)) {
        strcpy(shortest, line_buffer);
        strcpy(largest, misspelled);
    } else {
        strcpy(shortest, misspelled);
        strcpy(largest, line_buffer);
    }

    if (shortest[0] == largest[1]) score += 5;

    for (int i = 1; shortest[i] != '\0'; i++){
        if (shortest[i] == largest[i - 1] || shortest[i] == largest[i + 1]) score += 5;
    }

    return score;
}

char* manual_list(char *miss) {
    int score = 0;

    struct Correction {
        char *wrong;
        char *right;
    };

    // if (strcmp(miss, "alot") == 0 && strcmp(line, "a lot") == 0) return 100;
    // if (strcmp(miss, "alright") == 0 && strcmp(line, "all right") == 0) return 100;
    // if (strcmp(miss, "Dravadian") == 0 && strcmp(line, "Dravidian") == 0) return 100;
    // if (strcmp(miss, "Enlish") == 0 && strcmp(line, "English, enlist") == 0) return 100;
    // if (strcmp(miss, "Europian") == 0 && strcmp(line, "European") == 0) return 100;
    // if (strcmp(miss, "Europians") == 0 && strcmp(line, "Europeans") == 0) return 100;
    // if (strcmp(miss, "Eurpean") == 0 && strcmp(line, "European") == 0) return 100;
    // if (strcmp(miss, "Eurpoean") == 0 && strcmp(line, "European") == 0) return 100;
    // if (strcmp(miss, "Farenheit") == 0 && strcmp(line, "Fahrenheit") == 0) return 100;
    // if (strcmp(miss, "Febuary") == 0 && strcmp(line, "February") == 0) return 100;
    // if (strcmp(miss, "Feburary") == 0 && strcmp(line, "February") == 0) return 100;
    // if (strcmp(miss, "Flemmish") == 0 && strcmp(line, "Flemish") == 0) return 100;
    // if (strcmp(miss, "Formalhaut") == 0 && strcmp(line, "Fomalhaut") == 0) return 100;
    // if (strcmp(miss, "Foundland") == 0 && strcmp(line, "Newfoundland") == 0) return 100;
    // if (strcmp(miss, "Fransiscan") == 0 && strcmp(line, "Franciscan") == 0) return 100;
    // if (strcmp(miss, "Fransiscans") == 0 && strcmp(line, "Franciscans") == 0) return 100;
    // if (strcmp(miss, "Galations") == 0 && strcmp(line, "Galatians") == 0) return 100;
    // if (strcmp(miss, "Gameboy") == 0 && strcmp(line, "Game Boy") == 0) return 100;
    // if (strcmp(miss, "Ghandi") == 0 && strcmp(line, "Gandhi") == 0) return 100;
    // if (strcmp(miss, "Godounov") == 0 && strcmp(line, "Godunov") == 0) return 100;
    // if (strcmp(miss, "Gothenberg") == 0 && strcmp(line, "Gothenburg") == 0) return 100;
    // if (strcmp(miss, "Gottleib") == 0 && strcmp(line, "Gottlieb") == 0) return 100;
    // if (strcmp(miss, "Guaduloupe") == 0 && strcmp(line, "Guadalupe, Guadeloupe") == 0) return 100;
    // if (strcmp(miss, "Guadulupe") == 0 && strcmp(line, "Guadalupe, Guadeloupe") == 0) return 100;
    // if (strcmp(miss, "Guatamala") == 0 && strcmp(line, "Guatemala") == 0) return 100;
    // if (strcmp(miss, "Guatamalan") == 0 && strcmp(line, "Guatemalan") == 0) return 100;
    // if (strcmp(miss, "Guilia") == 0 && strcmp(line, "Giulia") == 0) return 100;
    // if (strcmp(miss, "Guilio") == 0 && strcmp(line, "Giulio") == 0) return 100;
    // if (strcmp(miss, "Guiness") == 0 && strcmp(line, "Guinness") == 0) return 100;
    // if (strcmp(miss, "Guiseppe") == 0 && strcmp(line, "Giuseppe") == 0) return 100;
    // if (strcmp(miss, "Habsbourg") == 0 && strcmp(line, "Habsburg") == 0) return 100;
    // if (strcmp(miss, "Hatian") == 0 && strcmp(line, "Haitian") == 0) return 100;
    // if (strcmp(miss, "Heidelburg") == 0 && strcmp(line, "Heidelberg") == 0) return 100;
    // if (strcmp(miss, "Ihaca") == 0 && strcmp(line, "Ithaca") == 0) return 100;
    // if (strcmp(miss, "Israelies") == 0 && strcmp(line, "Israelis") == 0) return 100;
    // if (strcmp(miss, "Janurary") == 0 && strcmp(line, "January") == 0) return 100;
    // if (strcmp(miss, "Januray") == 0 && strcmp(line, "January") == 0) return 100;
    // if (strcmp(miss, "Japanes") == 0 && strcmp(line, "Japanese") == 0) return 100;
    // if (strcmp(miss, "Johanine") == 0 && strcmp(line, "Johannine") == 0) return 100;
    // if (strcmp(miss, "Jospeh") == 0 && strcmp(line, "Joseph") == 0) return 100;
    // if (strcmp(miss, "Juadaism") == 0 && strcmp(line, "Judaism") == 0) return 100;
    // if (strcmp(miss, "Juadism") == 0 && strcmp(line, "Judaism") == 0) return 100;
    // if (strcmp(miss, "Lybia") == 0 && strcmp(line, "Libya") == 0) return 100;
    // if (strcmp(miss, "Malcom") == 0 && strcmp(line, "Malcolm") == 0) return 100;
    // if (strcmp(miss, "Massachussets") == 0 && strcmp(line, "Massachusetts") == 0) return 100;
    // if (strcmp(miss, "Massachussetts") == 0 && strcmp(line, "Massachusetts") == 0) return 100;
    // if (strcmp(miss, "Mediteranean") == 0 && strcmp(line, "Mediterranean") == 0) return 100;
    // if (strcmp(miss, "Michagan") == 0 && strcmp(line, "Michigan") == 0) return 100;
    // if (strcmp(miss, "Misouri") == 0 && strcmp(line, "Missouri") == 0) return 100;
    // if (strcmp(miss, "Missisipi") == 0 && strcmp(line, "Mississippi") == 0) return 100;
    // if (strcmp(miss, "Missisippi") == 0 && strcmp(line, "Mississippi") == 0) return 100;
    // if (strcmp(miss, "Monserrat") == 0 && strcmp(line, "Montserrat") == 0) return 100;
    // if (strcmp(miss, "Montnana") == 0 && strcmp(line, "Montana") == 0) return 100;
    // if (strcmp(miss, "Morisette") == 0 && strcmp(line, "Morissette") == 0) return 100;
    // if (strcmp(miss, "Morrisette") == 0 && strcmp(line, "Morissette") == 0) return 100;
    // if (strcmp(miss, "Mythraic") == 0 && strcmp(line, "Mithraic") == 0) return 100;
    // if (strcmp(miss, "Naploeon") == 0 && strcmp(line, "Napoleon") == 0) return 100;
    // if (strcmp(miss, "Napolean") == 0 && strcmp(line, "Napoleon") == 0) return 100;
    // if (strcmp(miss, "Napoleonian") == 0 && strcmp(line, "Napoleonic") == 0) return 100;
    // if (strcmp(miss, "Nazereth") == 0 && strcmp(line, "Nazareth") == 0) return 100;
    // if (strcmp(miss, "Novermber") == 0 && strcmp(line, "November") == 0) return 100;
    // if (strcmp(miss, "Nullabour") == 0 && strcmp(line, "Nullarbor") == 0) return 100;
    // if (strcmp(miss, "Nuremburg") == 0 && strcmp(line, "Nuremberg") == 0) return 100;
    // if (strcmp(miss, "Palistian") == 0 && strcmp(line, "Palestinian") == 0) return 100;
    // if (strcmp(miss, "Palistinian") == 0 && strcmp(line, "Palestinian") == 0) return 100;
    // if (strcmp(miss, "Palistinians") == 0 && strcmp(line, "Palestinians") == 0) return 100;
    // if (strcmp(miss, "Papanicalou") == 0 && strcmp(line, "Papanicolaou") == 0) return 100;
    // if (strcmp(miss, "Peloponnes") == 0 && strcmp(line, "Peloponnesus") == 0) return 100;
    // if (strcmp(miss, "Pennyslvania") == 0 && strcmp(line, "Pennsylvania") == 0) return 100;
    // if (strcmp(miss, "Pharoah") == 0 && strcmp(line, "Pharaoh") == 0) return 100;
    // if (strcmp(miss, "Philipines") == 0 && strcmp(line, "Philippines") == 0) return 100;
    // if (strcmp(miss, "Phillipine") == 0 && strcmp(line, "Philippine") == 0) return 100;
    // if (strcmp(miss, "Phillipines") == 0 && strcmp(line, "Philippines") == 0) return 100;
    // if (strcmp(miss, "Phillippines") == 0 && strcmp(line, "Philippines") == 0) return 100;
    // if (strcmp(miss, "Phonecian") == 0 && strcmp(line, "Phoenecian") == 0) return 100;
    // if (strcmp(miss, "Portugese") == 0 && strcmp(line, "Portuguese") == 0) return 100;
    // if (strcmp(miss, "Postdam") == 0 && strcmp(line, "Potsdam") == 0) return 100;
    // if (strcmp(miss, "Premonasterians") == 0 && strcmp(line, "Premonstratensians") == 0) return 100;
    // if (strcmp(miss, "Pucini") == 0 && strcmp(line, "Puccini") == 0) return 100;
    // if (strcmp(miss, "Puertorrican") == 0 && strcmp(line, "Puerto Rican") == 0) return 100;
    // if (strcmp(miss, "Puertorricans") == 0 && strcmp(line, "Puerto Ricans") == 0) return 100;
    // if (strcmp(miss, "Queenland") == 0 && strcmp(line, "Queensland") == 0) return 100;
    // if (strcmp(miss, "Rockerfeller") == 0 && strcmp(line, "Rockefeller") == 0) return 100;
    // if (strcmp(miss, "Russion") == 0 && strcmp(line, "Russian") == 0) return 100;
    // if (strcmp(miss, "Sacremento") == 0 && strcmp(line, "Sacramento") == 0) return 100;
    // if (strcmp(miss, "Sanhedrim") == 0 && strcmp(line, "Sanhedrin") == 0) return 100;
    // if (strcmp(miss, "Saterday") == 0 && strcmp(line, "Saturday") == 0) return 100;
    // if (strcmp(miss, "Saterdays") == 0 && strcmp(line, "Saturdays") == 0) return 100;
    // if (strcmp(miss, "Sionist") == 0 && strcmp(line, "Zionist") == 0) return 100;
    // if (strcmp(miss, "Sionists") == 0 && strcmp(line, "Zionists") == 0) return 100;
    // if (strcmp(miss, "Sixtin") == 0 && strcmp(line, "Sistine") == 0) return 100;
    // if (strcmp(miss, "Skagerak") == 0 && strcmp(line, "Skagerrak") == 0) return 100;
    // if (strcmp(miss, "Tolkein") == 0 && strcmp(line, "Tolkien") == 0) return 100;
    // if (strcmp(miss, "Tuscon") == 0 && strcmp(line, "Tucson") == 0) return 100;
    // if (strcmp(miss, "Ukranian") == 0 && strcmp(line, "Ukrainian") == 0) return 100;
    // if (strcmp(miss, "Unites States") == 0 && strcmp(line, "United States") == 0) return 100;
    // if (strcmp(miss, "Yementite") == 0 && strcmp(line, "Yemenite, Yemeni") == 0) return 100;

    struct Correction *dict = NULL;

    if (miss[0] == 'a') {
        struct Correction dict[] = {
            {"abondon", "abandon"},
            {"abondoning", "abandoning"},
            {"abondons", "abandons"},
            {"abreviated", "abbreviated"},
            {"abreviation", "abbreviation"},
            {"absailing", "abseiling"},
            {"absense", "absence"},
            {"absolutly", "absolutely"},
            {"absorbsion", "absorption"},
            {"absorbtion", "absorption"},
            {"accension", "accession"},
            {"accension", "ascension"},
            {"acceptible", "acceptable"},
            {"accidant", "accident"},
            {"accomdate", "accommodate"},
            {"accoring", "according"},
            {"accquainted", "acquainted"},
            {"accredidation", "accreditation"},
            {"acedemic", "academic"},
            {"achiv", "achieve"},
            {"achive", "achieve"},
            {"achive", "archive"},
            {"achived", "achieved"},
            {"achived", "archived"},
            {"ackward", "awkward"},
            {"ackward", "backward"},
            {"activites", "activities"},
            {"adbandon", "abandon"},
            {"addmission", "admission"},
            {"addopted", "adopted"},
            {"addoptive", "adoptive"},
            {"addres", "address"},
            {"adequit", "adequate"},
            {"adhearing", "adhering"},
            {"adviceable", "advisable"},
            {"agressiev", "aggressive"},
            {"almsot", "almost"},
            {"alos", "also"},
            {"alot", "a lot, allot"},
            {"alreayd", "already"},
            {"alse", "else"},
            {"alsot", "also"},
            {"altho", "although"},
            {"althought", "although"},
            {"alusion", "allusion, illusion"},
            {"alwasy", "always"},
            {"alwyas", "always"},
            {"amatuer", "amateur"},
            {"amature", "amateur"},
            {"amature", "armature, amateur"},
            {"amercia", "america"},
            {"amke", "make"},
            {"amking", "making"},
            {"analagous", "analogous"},
            {"analitic", "analytic"},
            {"analize", "analyze"},
            {"anarchistm", "anarchism"},
            {"anbd", "and"},
            {"ancestory", "ancestry"},
            {"andd", "and"},
            {"annointed", "anointed"},
            {"annointing", "anointing"},
            {"annuall", "annual"},
            {"anohter", "another"},
            {"anomoly", "anomaly"},
            {"ansalisation", "nasalisation"},
            {"ansalization", "nasalization"},
            {"ansestors", "ancestors"},
            {"anthromorphization", "anthropomorphization"},
            {"anuncement", "announcement"},
            {"anwsered", "answered"},
            {"anyother", "any other"},
            {"apenines", "apennines, apennines"},
            {"apon", "upon, apron"},
            {"apparant", "apparent"},
            {"appartment", "apartment"},
            {"appartments", "apartments"},
            {"appealling", "appealing, appalling"},
            {"appearence", "appearance"},
            {"appearences", "appearances"},
            {"appenines", "apennines, apennines"},
            {"appereances", "appearances"},
            {"appologies", "apologies"},
            {"approachs", "approaches"},
            {"approproximate", "approximate"},
            {"approxamately", "approximately"},
            {"approximitely", "approximately"},
            {"aquainted", "acquainted"},
            {"aquire", "acquire"},
            {"aquitted", "acquitted"},
            {"archaoelogy", "archeology, archaeology"},
            {"archaology", "archeology, archaeology"},
            {"archeaologist", "archeologist, archaeologist"},
            {"archeaologists", "archeologists, archaeologists"},
            {"archiac", "archaic"},
            {"archimedian", "archimedean"},
            {"arguement", "argument"},
            {"arised", "arose"},
            {"armamant", "armament"},
            {"arogent", "arrogant"},
            {"aroud", "around"},
            {"arrengement", "arrangement"},
            {"arrengements", "arrangements"},
            {"artical", "article"},
            {"artice", "article"},
            {"articel", "article"},
            {"asetic", "ascetic"},
            {"asfar", "as far"},
            {"aslo", "also"},
            {"asorbed", "absorbed"},
            {"assasined", "assassinated"},
            {"assemple", "assemble"},
            {"assertation", "assertion"},
            {"asside", "aside"},
            {"assisnate", "assassinate"},
            {"assistent", "assistant"},
            {"assit", "assist"},
            {"assymetric", "asymmetric"},
            {"asteriod", "asteroid"},
            {"asthetic", "aesthetic"},
            {"asthetical", "aesthetical"},
            {"asthetically", "aesthetically"},
            {"aswell", "as well"},
            {"atheistical", "atheistic"},
            {"athenean", "athenian"},
            {"atheneans", "athenians"},
            {"athiest", "atheist"},
            {"attaindre", "attainder, attained"},
            {"attemp", "attempt"},
            {"attemt", "attempt"},
            {"attendent", "attendant"},
            {"attendents", "attendants"},
            {"attened", "attended"},
            {"attitide", "attitude"},
            {"attributred", "attributed"},
            {"austrailia", "australia"},
            {"austrailian", "australian"},
            {"auther", "author"},
            {"authorative", "authoritative"},
            {"authorites", "authorities"},
            {"authorithy", "authority"},
            {"authoritiers", "authorities"},
            {"authoritive", "authoritative"},
            {"authour", "author"},
            {"autoctonous", "autochthonous"},
            {"automaticly", "automatically"},
            {"automonomous", "autonomous"},
            {"availabe", "available"},
            {"avalance", "avalanche"},
            {"avengence", "a vengeance"},
            {"awared", "awarded"},
            {"awfull", "awful"},
            {"awya", "away"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'b') {
        struct Correction dict[] = {
            {"baceause", "because"},
            {"bakc", "back"},
            {"banannas", "bananas"},
            {"baout", "about, bout"},
            {"basicly", "basically"},
            {"bcak", "back"},
            {"beated", "beaten"},
            {"beaurocracy", "bureaucracy"},
            {"beaurocratic", "bureaucratic"},
            {"becamae", "became"},
            {"becames", "becomes, became"},
            {"becasue", "because"},
            {"becomeing", "becoming"},
            {"becomming", "becoming"},
            {"bedore", "before"},
            {"beeing", "being"},
            {"befoer", "before"},
            {"beggin", "begin, begging"},
            {"begining", "beginning"},
            {"behavour", "behavior, behaviour"},
            {"beleive", "believe"},
            {"believ", "belief"},
            {"believ", "believe"},
            {"beligum", "belgium"},
            {"belive", "believe"},
            {"belived", "believed, beloved"},
            {"belives", "believes, beliefs"},
            {"bergamont", "bergamot"},
            {"bernouilli", "bernoulli"},
            {"bigining", "beginning"},
            {"biginning", "beginning"},
            {"binominal", "binomial"},
            {"blaim", "blame"},
            {"blessure", "blessing"},
            {"blitzkreig", "blitzkrieg"},
            {"boaut", "bout, boat, about"},
            {"bonnano", "bonanno"},
            {"borke", "broke"},
            {"bouyancy", "buoyancy"},
            {"bouyant", "buoyant"},
            {"brasillian", "brazilian"},
            {"breif", "brief"},
            {"britian", "britain"},
            {"brittish", "british"},
            {"broacasted", "broadcast"},
            {"broady", "broadly"},
            {"buddah", "buddha"},
            {"buddist", "buddhist"},
            {"buring", "burying, burning, burin, during"},
            {"busines", "business"},
            {"busineses", "business, businesses"},
            {"busness", "business"},
            {"bussiness", "business"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'c') {
        struct Correction dict[] = {
            {"caculater", "calculator"},
            {"cacuses", "caucuses"},
            {"cahracters", "characters"},
            {"calander", "calendar, colander"},
            {"chauffer", "chauffeur"},
            {"completly", "completely"},
            {"conscientous", "conscientious"},
            {"calculater", "calculator"},
            {"calculs", "calculus"},
            {"calender", "calendar"},
            {"calenders", "calendars"},
            {"calulater", "calculator"},
            {"cambrige", "cambridge"},
            {"campagin", "campaign"},
            {"campain", "campaign"},
            {"campains", "campaigns"},
            {"cannister", "canister"},
            {"cannisters", "canisters"},
            {"cannotation", "connotation"},
            {"cannotations", "connotations"},
            {"caost", "coast"},
            {"capetown", "cape town"},
            {"captued", "captured"},
            {"capturd", "captured"},
            {"carachter", "character"},
            {"caracterized", "characterized"},
            {"carcas", "carcass, caracas"},
            {"carefull", "careful"},
            {"careing", "caring"},
            {"carismatic", "charismatic"},
            {"carmalite", "carmelite"},
            {"carnagie", "carnegie"},
            {"carnagie", "ellon->carnegie-mellon"},
            {"carnege", "carnage, carnegie"},
            {"carnige", "carnage, carnegie"},
            {"carnigie", "carnegie"},
            {"carnigie", "ellon->carnegie-mellon"},
            {"carrers", "careers"},
            {"carribbean", "caribbean"},
            {"carribean", "caribbean"},
            {"carribean", "caribbean"},
            {"carthagian", "carthaginian"},
            {"cartilidge", "cartilage"},
            {"cartrige", "cartridge"},
            {"casion", "caisson"},
            {"cassawory", "cassowary"},
            {"casue", "cause"},
            {"casued", "caused"},
            {"casues", "causes"},
            {"casuing", "causing"},
            {"casulaty", "casualty"},
            {"catagories", "categories"},
            {"catagorized", "categorized"},
            {"catagory", "category"},
            {"cataline", "catiline, catalina"},
            {"catapillers", "caterpillars"},
            {"catholocism", "catholicism"},
            {"cattleship", "battleship"},
            {"causalities", "casualties"},
            {"ceasar", "caesar"},
            {"celcius", "celsius"},
            {"cellpading", "cellpadding"},
            {"cementary", "cemetery"},
            {"cemetarey", "cemetery"},
            {"cemetary", "cemetery"},
            {"cencus", "census"},
            {"censur", "censor, censure"},
            {"centuties", "centuries"},
            {"centuty", "century"},
            {"ceratin", "certain, keratin"},
            {"cerimonies", "ceremonies"},
            {"cerimonious", "ceremonious"},
            {"certian", "certain"},
            {"cervial", "cervical, servile, serval"},
            {"champange", "champagne"},
            {"charactor", "character"},
            {"charactors", "characters"},
            {"charistics", "characteristics"},
            {"chasr", "chaser, chase"},
            {"cheif", "chief"},
            {"cheifs", "chiefs"},
            {"childbird", "childbirth"},
            {"childen", "children"},
            {"choclate", "chocolate"},
            {"chracter", "character"},
            {"churchs", "churches"},
            {"cincinatti", "cincinnati"},
            {"cincinnatti", "cincinnati"},
            {"circumsicion", "circumcision"},
            {"circut", "circuit"},
            {"claer", "clear"},
            {"claerer", "clearer"},
            {"claimes", "claims"},
            {"clas", "class"},
            {"clera", "clear, sclera"},
            {"cmo", "com"},
            {"cmoputer", "computer"},
            {"cognizent", "cognizant"},
            {"coligue", "colleague"},
            {"collonies", "colonies"},
            {"colonizators", "colonizers"},
            {"colum", "column"},
            {"comander", "commander, commandeer"},
            {"combanations", "combinations"},
            {"combusion", "combustion"},
            {"comdemnation", "condemnation"},
            {"comision", "commission"},
            {"comisioned", "commissioned"},
            {"comisioning", "commissioning"},
            {"comisions", "commissions"},
            {"comite", "committee"},
            {"comited", "committed"},
            {"comitee", "committee"},
            {"comiting", "committing"},
            {"commandoes", "commandos"},
            {"comming", "coming"},
            {"comminication", "communication"},
            {"commongly", "commonly"},
            {"communiation", "communication"},
            {"communites", "communities"},
            {"compability", "compatibility"},
            {"comparision", "comparison"},
            {"comparisions", "comparisons"},
            {"comparitive", "comparative"},
            {"compatabilities", "compatibilities"},
            {"compatability", "compatibility"},
            {"compatable", "compatible"},
            {"competance", "competence"},
            {"competant", "competent"},
            {"competative", "competitive"},
            {"competion", "competition, completion"},
            {"competive", "competitive"},
            {"competiveness", "competitiveness"},
            {"compitent", "competent"},
            {"completedthe", "completed the"},
            {"completelyl", "completely"},
            {"completetion", "completion"},
            {"complier", "compiler"},
            {"componant", "component"},
            {"comprimise", "compromise"},
            {"compulsary", "compulsory"},
            {"compulsery", "compulsory"},
            {"concider", "consider"},
            {"concidered", "considered"},
            {"concidering", "considering"},
            {"conciders", "considers"},
            {"condem", "condemn"},
            {"condemmed", "condemned"},
            {"condidtion", "condition"},
            {"condidtions", "conditions"},
            {"conditionsof", "conditions of"},
            {"confidental", "confidential"},
            {"confids", "confides"},
            {"configureable", "configurable"},
            {"confortable", "comfortable"},
            {"congradulations", "congratulations"},
            {"conneticut", "connecticut"},
            {"conquerd", "conquered"},
            {"conquerer", "conqueror"},
            {"conquerers", "conquerors"},
            {"conscent", "consent"},
            {"consdider", "consider"},
            {"consentrate", "concentrate"},
            {"consentrated", "concentrated"},
            {"consentrates", "concentrates"},
            {"consequentually", "consequently"},
            {"conserning", "concerning"},
            {"consiciousness", "consciousness"},
            {"considerd", "considered"},
            {"consideres", "considered"},
            {"consistant", "consistent"},
            {"consistantly", "consistently"},
            {"consolodate", "consolidate"},
            {"consolodated", "consolidated"},
            {"consonent", "consonant"},
            {"consonents", "consonants"},
            {"consorcium", "consortium"},
            {"conspiracys", "conspiracies"},
            {"constanly", "constantly"},
            {"constarnation", "consternation"},
            {"constatn", "constant"},
            {"constinually", "continually"},
            {"constituant", "constituent"},
            {"constituants", "constituents"},
            {"constituion", "constitution"},
            {"containes", "contains"},
            {"contamporaries", "contemporaries"},
            {"contempory", "contemporary"},
            {"contendor", "contender"},
            {"contian", "contain"},
            {"contians", "contains"},
            {"contibute", "contribute"},
            {"contibuted", "contributed"},
            {"contibutes", "contributes"},
            {"contined", "continued"},
            {"continential", "continental"},
            {"continueing", "continuing"},
            {"contravercial", "controversial"},
            {"contributer", "contributor"},
            {"contributers", "contributors"},
            {"contritutions", "contributions"},
            {"controll", "control"},
            {"controlls", "controls"},
            {"controvercy", "controversy"},
            {"controversey", "controversy"},
            {"controvertial", "controversial"},
            {"controvery", "controversy"},
            {"conveinent", "convenient"},
            {"convenant", "covenant"},
            {"conveniance", "convenience"},
            {"convential", "conventional"},
            {"convertion", "conversion"},
            {"coorperation", "cooperation, corporation"},
            {"coorperations", "corporations"},
            {"copmetitors", "competitors"},
            {"coputer", "computer"},
            {"copywrite", "copyright"},
            {"coridal", "cordial"},
            {"cornmitted", "committed"},
            {"corparate", "corporate"},
            {"corperations", "corporations"},
            {"correcters", "correctors"},
            {"correspondant", "correspondent"},
            {"correspondants", "correspondents"},
            {"corrispondant", "correspondent"},
            {"corrispondants", "correspondents"},
            {"coudl", "could, cloud"},
            {"councellor", "councillor, counselor, councilor"},
            {"councellors", "councillors, counselors, councilors"},
            {"countains", "contains"},
            {"countires", "countries"},
            {"coururier", "courier, couturier"},
            {"coverted", "converted, covered, coveted"},
            {"cpoy", "coy, copy"},
            {"creche", "crèche"},
            {"criterias", "criteria"},
            {"criticists", "critics"},
            {"critising", "criticising, criticizing"},
            {"critisising", "criticising"},
            {"critisize", "criticise, criticize"},
            {"critisized", "criticised, criticized"},
            {"critisizes", "criticises, criticizes"},
            {"critisizing", "criticising, criticizing"},
            {"critized", "criticized"},
            {"critizing", "criticizing"},
            {"crowm", "crown"},
            {"crusies", "cruises"},
            {"crystalisation", "crystallisation"},
            {"cumulatative", "cumulative"},
            {"curch", "church"},
            {"curcuit", "circuit"},
            {"cxan", "cyan"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'd') {
        struct Correction dict[] = {
            {"daed", "dead"},
            {"dael", "deal, dial, dahl"},
            {"dalmation", "dalmatian"},
            {"dardenelles", "dardanelles"},
            {"decendant", "descendant"},
            {"decendants", "descendants"},
            {"decendent", "descendant"},
            {"decendents", "descendants"},
            {"decomposit", "decompose"},
            {"decomposited", "decomposed"},
            {"decompositing", "decomposing"},
            {"decomposits", "decomposes"},
            {"decress", "decrees"},
            {"decribing", "describing"},
            {"defendent", "defendant"},
            {"defendents", "defendants"},
            {"definance", "defiance"},
            {"definate", "definite"},
            {"definately", "definitely"},
            {"definatly", "definitely"},
            {"definetly", "definitely"},
            {"definining", "defining"},
            {"definit", "definite"},
            {"definitly", "definitely"},
            {"degrate", "degrade"},
            {"delagates", "delegates"},
            {"delapidated", "dilapidated"},
            {"delevopment", "development"},
            {"deliberatly", "deliberately"},
            {"delusionally", "delusively"},
            {"demographical", "demographic"},
            {"demolision", "demolition"},
            {"denegrating", "denigrating"},
            {"dependance", "dependence"},
            {"deram", "dram, dream"},
            {"deriviated", "derived"},
            {"descision", "decision"},
            {"descisions", "decisions"},
            {"descripters", "descriptors"},
            {"deside", "decide"},
            {"desigining", "designing"},
            {"desintegrated", "disintegrated"},
            {"desintegration", "disintegration"},
            {"desorder", "disorder"},
            {"desoriented", "disoriented"},
            {"desparate", "desperate, disparate"},
            {"despict", "depict"},
            {"despiration", "desperation"},
            {"dessicated", "desiccated"},
            {"dessigned", "designed"},
            {"destory", "destroy"},
            {"detailled", "detailed"},
            {"deteriate", "deteriorate"},
            {"determinining", "determining"},
            {"devasted", "devastated"},
            {"develope", "develop"},
            {"devels", "delves"},
            {"devestating", "devastating"},
            {"devide", "divide"},
            {"devided", "divided"},
            {"devistating", "devastating"},
            {"diamons", "diamonds"},
            {"diaster", "disaster"},
            {"dicovered", "discovered"},
            {"dicovering", "discovering"},
            {"dicovers", "discovers"},
            {"dictionarys", "dictionaries"},
            {"didnt", "didn't"},
            {"diea", "idea, die"},
            {"dieing", "dying, dyeing"},
            {"dieties", "deities"},
            {"diety", "deity"},
            {"differentiatiations", "differentiations"},
            {"difficulity", "difficulty"},
            {"dilema", "dilemma"},
            {"dimention", "dimension"},
            {"dimentions", "dimensions"},
            {"dirived", "derived"},
            {"discontentment", "discontent"},
            {"discribe", "describe"},
            {"discribed", "described"},
            {"discribes", "describes"},
            {"discribing", "describing"},
            {"disenchanged", "disenchanted"},
            {"disobediant", "disobedient"},
            {"disover", "discover"},
            {"dispair", "despair"},
            {"disparingly", "disparagingly"},
            {"dispence", "dispense"},
            {"dispenced", "dispensed"},
            {"dispencing", "dispensing"},
            {"dispicable", "despicable"},
            {"dispite", "despite"},
            {"disproportiate", "disproportionate"},
            {"disputandem", "disputandum"},
            {"dissapeared", "disappeared"},
            {"dissobediant", "disobedient"},
            {"distrubution", "distribution"},
            {"distruction", "destruction"},
            {"distructive", "destructive"},
            {"diversed", "diverse, diverged"},
            {"divice", "device"},
            {"divison", "division"},
            {"doens", "does"},
            {"doesnt", "doesn't"},
            {"doign", "doing"},
            {"dominent", "dominant"},
            {"donig", "doing"},
            {"doub", "doubt, daub"},
            {"dreasm", "dreams"},
            {"driectly", "directly"},
            {"drummless", "drumless"},
            {"dum", "dumb"},
            {"durig", "during"},
            {"duting", "during"},
            {"dyas", "dryas"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'e') {
        struct Correction dict[] = {
            {"excede", "exceed"},
            {"experiance", "experience"},
            {"eahc", "each"},
            {"earlies", "earliest"},
            {"earnt", "earned"},
            {"ecclectic", "eclectic"},
            {"ecidious", "deciduous"},
            {"eclispe", "eclipse"},
            {"ecomonic", "economic"},
            {"econoımic", "economic"},
            {"ect", "etc"},
            {"eearly", "early"},
            {"efel", "evil"},
            {"effeciently", "efficiently"},
            {"efford", "effort, afford"},
            {"effords", "efforts, affords"},
            {"eigth", "eighth, eight"},
            {"electic", "eclectic, electric"},
            {"electon", "election, electron"},
            {"electricly", "electrically"},
            {"elementay", "elementary"},
            {"eleminating", "eliminating"},
            {"eles", "eels"},
            {"elicided", "elicited"},
            {"embargos", "embargoes"},
            {"embarras", "embarrass"},
            {"embezelled", "embezzled"},
            {"eminate", "emanate"},
            {"eminated", "emanated"},
            {"emition", "emission, emotion"},
            {"emmediately", "immediately"},
            {"emmigrated", "emigrated, immigrated"},
            {"emminent", "eminent, imminent"},
            {"emmisions", "emissions"},
            {"emmiting", "emitting"},
            {"emmitting", "emitting"},
            {"empirial", "empirical, imperial"},
            {"emporer", "emperor"},
            {"emprisoned", "imprisoned"},
            {"enameld", "enameled"},
            {"enchancement", "enhancement"},
            {"endolithes", "endoliths"},
            {"enduce", "induce"},
            {"ened", "need"},
            {"ensconsed", "ensconced"},
            {"enteratinment", "entertainment"},
            {"entitlied", "entitled"},
            {"enxt", "next"},
            {"equitorial", "equatorial"},
            {"equivelant", "equivalent"},
            {"equivelent", "equivalent"},
            {"equivilant", "equivalent"},
            {"equivilent", "equivalent"},
            {"erally", "orally, really"},
            {"eraticly", "erratically"},
            {"erested", "arrested, erected"},
            {"esle", "else"},
            {"ethose", "those, ethos"},
            {"eventhough", "even though"},
            {"everytime", "every time"},
            {"eveyr", "every"},
            {"evidentally", "evidently"},
            {"examinated", "examined"},
            {"exapansion", "expansion"},
            {"excecuted", "executed"},
            {"excecutes", "executes"},
            {"excecuting", "executing"},
            {"excecution", "execution"},
            {"excedded", "exceeded"},
            {"excell", "excel"},
            {"excells", "excels"},
            {"excisted", "existed"},
            {"exelent", "excellent"},
            {"exept", "except"},
            {"exerbate", "exacerbate"},
            {"exerbated", "exacerbated"},
            {"exerciese", "exercises"},
            {"exerpts", "excerpts"},
            {"exersize", "exercise"},
            {"exerternal", "external"},
            {"exhalted", "exalted"},
            {"exhilirate", "exhilarate"},
            {"exicting", "exciting"},
            {"existance", "existence"},
            {"existant", "existent"},
            {"expatriot", "expatriate"},
            {"expeced", "expected"},
            {"expecially", "especially"},
            {"expell", "expel"},
            {"expells", "expels"},
            {"expiditions", "expeditions"},
            {"exploititive", "exploitative"},
            {"extention", "extension"},
            {"extentions", "extensions"},
            {"extered", "exerted"},
            {"extint", "extinct, extant"},
            {"extravagent", "extravagant"},
            {"extrem", "extreme"},
            {"extrememly", "extremely"},
            {"extremeophile", "extremophile"},
            {"eyar", "year, eyas"},
            {"eyars", "years, eyas"},
            {"eyasr", "years, eyas"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'f') {
        struct Correction dict[] = {
            {"firey", "fiery, firry"},
            {"facilites", "facilities"},
            {"familes", "families"},
            {"familier", "familiar"},
            {"famoust", "famous"},
            {"fatc", "fact"},
            {"favoutrable", "favourable"},
            {"feromone", "pheromone"},
            {"fertily", "fertility"},
            {"fictious", "fictitious"},
            {"fidn", "find"},
            {"fiel", "feel, field, file, phial"},
            {"fiels", "feels, fields, files, phials"},
            {"fightings", "fighting"},
            {"fimilies", "families"},
            {"finaly", "finally"},
            {"firends", "friends"},
            {"firts", "flirts, first"},
            {"flawess", "flawless"},
            {"fleed", "fled, freed"},
            {"florescent", "fluorescent"},
            {"flourescent", "fluorescent"},
            {"flourishment", "flourishing"},
            {"fomr", "from, form"},
            {"fonetic", "phonetic"},
            {"fontrier", "fontier"},
            {"forbad", "forbade"},
            {"foreward", "foreword"},
            {"forfiet", "forfeit"},
            {"formaly", "formally, formerly"},
            {"formelly", "formerly"},
            {"formidible", "formidable"},
            {"forunner", "forerunner"},
            {"foucs", "focus"},
            {"foudn", "found"},
            {"fougth", "fought"},
            {"fourties", "forties"},
            {"frome", "from"},
            {"fromed", "formed"},
            {"froniter", "frontier"},
            {"fucntion", "function"},
            {"fucntioning", "functioning"},
            {"funguses", "fungi"},
            {"futhroc", "futhark, futhorc"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'g') {
        struct Correction dict[] = {
            {"greatfull", "grateful"},
            {"gae", "game, Gael, gale"},
            {"gallaxies", "galaxies"},
            {"galvinized", "galvanized"},
            {"ganerate", "generate"},
            {"ganes", "games"},
            {"ganster", "gangster"},
            {"garantee", "guarantee"},
            {"garanteed", "guaranteed"},
            {"garantees", "guarantees"},
            {"gardai", "gardaí"},
            {"gauarana", "guaraná"},
            {"gauranteed", "guaranteed"},
            {"gaurantees", "guarantees"},
            {"gaurd", "guard, gourd"},
            {"gaurentee", "guarantee"},
            {"gaurenteed", "guaranteed"},
            {"gaurentees", "guarantees"},
            {"geneologies", "genealogies"},
            {"geometrician", "geometer"},
            {"geometricians", "geometers"},
            {"gerat", "great"},
            {"glamourous", "glamorous"},
            {"glight", "flight"},
            {"gogin", "going, Gauguin"},
            {"goign", "going"},
            {"gonig", "going"},
            {"gouvener", "governor"},
            {"governer", "governor"},
            {"gracefull", "graceful"},
            {"graet", "great"},
            {"grammer", "gammar"},
            {"grammer", "grammar"},
            {"grat", "great"},
            {"gratefull", "grateful"},
            {"greatful", "grateful"},
            {"gropu", "group"},
            {"grwo", "grow"},
            {"guage", "gauge"},
            {"guidence", "guidance"},
            {"gunanine", "guanine"},
            {"gya", "gay"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'h') {
        struct Correction dict[] = {
            {"habaeus", "habeas"},
            {"habeus", "habeas"},
            {"haemorrage", "haemorrhage"},
            {"haev", "have, heave"},
            {"halarious", "hilarious"},
            {"halp", "help"},
            {"harras", "harass"},
            {"harrassed", "harassed"},
            {"harrasses", "harassed"},
            {"haviest", "heaviest"},
            {"healthercare", "healthcare"},
            {"heared", "heard"},
            {"heathy", "healthy"},
            {"heigher", "higher"},
            {"heirarchy", "hierarchy"},
            {"heiroglyphics", "hieroglyphics"},
            {"helment", "helmet"},
            {"helpfull", "helpful"},
            {"herad", "heard, Hera"},
            {"heroe", "hero"},
            {"heros", "heroes"},
            {"hertiage", "heritage"},
            {"hertzs", "hertz"},
            {"hieght", "height"},
            {"hierarcy", "hierarchy"},
            {"hismelf", "himself"},
            {"hitsingles", "hit singles"},
            {"holf", "hold"},
            {"homestate", "home state"},
            {"honory", "honorary"},
            {"hosited", "hoisted"},
            {"housr", "hours, house"},
            {"hten", "then, hen, the"},
            {"htere", "there, here"},
            {"htey", "they"},
            {"htikn", "think"},
            {"hting", "thing"},
            {"htink", "think"},
            {"htis", "this"},
            {"humer", "humor, humour"},
            {"humerous", "humorous, humerus"},
            {"humourous", "humorous"},
            {"humurous", "humorous"},
            {"husban", "husband"},
            {"hvae", "have"},
            {"hvaing", "having"},
            {"hvea", "have, heave"},
            {"hwihc", "which"},
            {"hwile", "while"},
            {"hwole", "whole"},
            {"hydropile", "hydrophile"},
            {"hydropobe", "hydrophobe"},
            {"hypocracy", "hypocrisy"},
            {"hypocrit", "hypocrite"},
            {"hypocrits", "hypocrites"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'i') {
        struct Correction dict[] = {
            {"idaeidae", "idea"},
            {"idaes", "ideas"},
            {"idealogies", "ideologies"},
            {"idealogy", "ideology"},
            {"ideosyncratic", "idiosyncratic"},
            {"idesa", "ideas, ides"},
            {"illegimacy", "illegitimacy"},
            {"imagin", "imagine"},
            {"imaginery", "imaginary, imagery"},
            {"imanent", "eminent, imminent"},
            {"imigrant", "emigrant, immigrant"},
            {"imigrated", "emigrated, immigrated"},
            {"imigration", "emigration, immigration"},
            {"iminent", "eminent, imminent, immanent"},
            {"immediatley", "immediately"},
            {"immediatly", "immediately"},
            {"immidiately", "immediately"},
            {"immitate", "imitate"},
            {"immitated", "imitated"},
            {"immitating", "imitating"},
            {"immitator", "imitator"},
            {"impedence", "impedance"},
            {"impliment", "implement"},
            {"implimented", "implemented"},
            {"imploys", "employs"},
            {"improvision", "improvisation"},
            {"inadvertant", "inadvertent"},
            {"inaugures", "inaugurates"},
            {"inbalance", "imbalance"},
            {"inbalanced", "imbalanced"},
            {"inbetween", "between"},
            {"incarcirated", "incarcerated"},
            {"incidentially", "incidentally"},
            {"incidently", "incidentally"},
            {"includ", "include"},
            {"incompatabilities", "incompatibilities"},
            {"incompatability", "incompatibility"},
            {"incompatable", "incompatible"},
            {"incompatablities", "incompatibilities"},
            {"incompatablity", "incompatibility"},
            {"incompetant", "incompetent"},
            {"inconsistant", "inconsistent"},
            {"incorperation", "incorporation"},
            {"incredable", "incredible"},
            {"indefineable", "undefinable"},
            {"indefinitly", "indefinitely"},
            {"indentical", "identical"},
            {"independant", "independent"},
            {"indespensable", "indispensable"},
            {"indespensible", "indispensable"},
            {"indipendent", "independent"},
            {"indispensible", "indispensable"},
            {"indite", "indict"},
            {"indulgue", "indulge"},
            {"inefficienty", "inefficiently"},
            {"inevatible", "inevitable"},
            {"inevitible", "inevitable"},
            {"inevititably", "inevitably"},
            {"infalability", "infallibility"},
            {"infallable", "infallible"},
            {"infinit", "infinite"},
            {"influented", "influenced"},
            {"inhabitans", "inhabitants"},
            {"inheritage", "heritage, inheritance"},
            {"inital", "initial"},
            {"inlcuding", "including"},
            {"inmigrants", "immigrants"},
            {"innoculated", "inoculated"},
            {"inofficial", "unofficial"},
            {"inot", "into"},
            {"inpending", "impending"},
            {"inpenetrable", "impenetrable"},
            {"inpolite", "impolite"},
            {"inproving", "improving"},
            {"insensative", "insensitive"},
            {"inseperable", "inseparable"},
            {"insistance", "insistence"},
            {"inspite", "in spite, inspire"},
            {"instade", "instead"},
            {"instatance", "instance"},
            {"institue", "institute"},
            {"instutionalized", "institutionalized"},
            {"instutions", "institutions, intuitions"},
            {"insurence", "insurance"},
            {"intented", "intended, indented"},
            {"intepretator", "interpretor"},
            {"interational", "international"},
            {"interbread", "interbreed, interbred"},
            {"intercontinential", "intercontinental"},
            {"intered", "interred, interned"},
            {"interferance", "interference"},
            {"interfereing", "interfering"},
            {"intergrated", "integrated"},
            {"intergration", "integration"},
            {"interm", "interim"},
            {"internation", "international"},
            {"intertaining", "entertaining"},
            {"intervines", "intervenes"},
            {"introdued", "introduced"},
            {"intruduced", "introduced"},
            {"intrument", "instrument"},
            {"intrumental", "instrumental"},
            {"intruments", "instruments"},
            {"intrusted", "entrusted"},
            {"inumerable", "enumerable, innumerable"},
            {"inventer", "inventor"},
            {"irelevent", "irrelevant"},
            {"ironicly", "ironically"},
            {"irregardless", "regardless"},
            {"irrelevent", "irrelevant"},
            {"iunior", "junior"},
            {"iwll", "will"},
            {"iwth", "with"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'j') {
        struct Correction dict[] = {
            {"journied", "journeyed"},
            {"journies", "journeys"},
            {"jstu", "just"},
            {"jsut", "just"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'k') {
        struct Correction dict[] = {
            {"klenex", "kleenex"},
            {"knifes", "knives"},
            {"knwo", "know"},
            {"knwos", "knows"},
            {"konw", "know"},
            {"konws", "knows"},
            {"kwno", "know"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'l') {
        struct Correction dict[] = {
            {"labatory", "lavatory, laboratory"},
            {"lable", "label"},
            {"labled", "labelled, labeled"},
            {"larg", "large"},
            {"larrry", "larry"},
            {"lastr", "last"},
            {"launchs", "launch, launches"},
            {"layed", "laid"},
            {"leage", "league"},
            {"leanr", "lean, learn, leaner"},
            {"lefted", "left"},
            {"leibnitz", "leibniz"},
            {"lenght", "length"},
            {"leran", "learn"},
            {"lerans", "learns"},
            {"lesbain", "lesbian"},
            {"lesbina", "lesbian"},
            {"levetating", "levitating"},
            {"levle", "level"},
            {"liad", "laid"},
            {"liasion", "liaison"},
            {"liason", "liaison"},
            {"libell", "libel"},
            {"libguistic", "linguistic"},
            {"libitarianisn", "libertarianism"},
            {"lible", "libel, liable"},
            {"lieing", "lying"},
            {"liek", "like"},
            {"liekd", "liked"},
            {"liesure", "leisure"},
            {"lightyear", "light year"},
            {"lightyears", "light years"},
            {"linnaena", "linnaean"},
            {"lippizaner", "lipizzaner"},
            {"liquify", "liquefy"},
            {"liscense", "license, licence"},
            {"lisence", "license, licence"},
            {"lisense", "license, licence"},
            {"litature", "literature"},
            {"literaly", "literally"},
            {"littel", "little"},
            {"livley", "lively"},
            {"loev", "love"},
            {"lonley", "lonely"},
            {"lonly", "lonely, only"},
            {"loosing", "losing"},
            {"lotharingen", "lothringen"},
            {"lsat", "last"},
            {"lukid", "likud"},
            {"lveo", "love"},
            {"lvoe", "love"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'm') {
        struct Correction dict[] = {
            {"maching", "machine, marching, matching"},
            {"mackeral", "mackerel"},
            {"magincian", "magician"},
            {"maintance", "maintenance"},
            {"maintinaing", "maintaining"},
            {"maintioned", "mentioned"},
            {"majoroty", "majority"},
            {"maked", "marked, made"},
            {"makse", "makes"},
            {"maltesian", "Maltese"},
            {"managable", "manageable, manageably"},
            {"manouver", "maneuver, manoeuvre"},
            {"manouverability", "maneuverability, manoeuvrability, manoeuverability"},
            {"manouverable", "maneuverable, manoeuvrable"},
            {"manouvers", "maneuvers, manoeuvres"},
            {"manuever", "maneuver, manoeuvre"},
            {"manuevers", "maneuvers, manoeuvres"},
            {"markes", "marks"},
            {"massmedia", "mass media"},
            {"mataphysical", "metaphysical"},
            {"materalists", "materialist"},
            {"mathematicas", "mathematics"},
            {"matheticians", "mathematicians"},
            {"mccarthyst", "mccarthyist"},
            {"mear", "wear, mere, mare"},
            {"medeival", "medieval"},
            {"mediciney", "mediciny"},
            {"medievel", "medieval"},
            {"membranaphone", "membranophone"},
            {"menally", "mentally"},
            {"meranda", "veranda, Miranda"},
            {"metalurgic", "metallurgic"},
            {"midwifes", "midwives"},
            {"miliary", "military"},
            {"miliraty", "military"},
            {"millitary", "military"},
            {"minerial", "mineral"},
            {"ministery", "ministry"},
            {"missen", "mizzen"},
            {"misterious", "mysterious"},
            {"mistery", "mystery"},
            {"misteryous", "mysterious"},
            {"mkae", "make"},
            {"mkaes", "makes"},
            {"mkaing", "making"},
            {"mkea", "make"},
            {"moderm", "modem"},
            {"modle", "model"},
            {"moeny", "money"},
            {"mohammedans", "muslims"},
            {"momento", "memento"},
            {"monestaries", "monasteries"},
            {"monestary", "monastery, monetary"},
            {"monickers", "monikers"},
            {"monolite", "monolithic"},
            {"montains", "mountains"},
            {"montanous", "mountainous"},
            {"monts", "months"},
            {"moreso", "more, more so"},
            {"morroccan", "moroccan"},
            {"mounth", "month"},
            {"movei", "movie"},
            {"mroe", "more"},
            {"mucuous", "mucous"},
            {"muder", "murder"},
            {"mudering", "murdering"},
            {"muhammadan", "muslim"},
            {"multipled", "multiplied"},
            {"munbers", "numbers"},
            {"muscels", "mussels, muscles"},
            {"myraid", "myriad"},
            {"mysef", "myself"},
            {"mysogynist", "misogynist"},
            {"mischievous", "mischievous"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'n') {
        struct Correction dict[] = {
            {"nieghbor", "neighbor"},
            {"naturaly", "naturally"},
            {"naturely", "naturally"},
            {"naturually", "naturally"},
            {"neglible", "negligible"},
            {"negligable", "negligible"},
            {"neice", "niece, nice"},
            {"neigbour", "neighbour, neighbor"},
            {"neigbourhood", "neighbourhood"},
            {"neigbouring", "neighbouring, neighboring"},
            {"neigbours", "neighbours, neighbors"},
            {"neolitic", "neolithic"},
            {"nestin", "nesting"},
            {"nickle", "nickel"},
            {"ninties", "1990s"},
            {"nkow", "know"},
            {"nkwo", "know"},
            {"nmae", "name"},
            {"noncombatents", "noncombatants"},
            {"nonsence", "nonsense"},
            {"noone", "no one"},
            {"northen", "northern"},
            {"notabley", "notably"},
            {"noticeing", "noticing"},
            {"noticible", "noticeable"},
            {"nowdays", "nowadays"},
            {"nowe", "now"},
            {"nto", "not"},
            {"nucular", "nuclear"},
            {"nutritent", "nutrient"},
            {"nuturing", "nurturing"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'o') {
        struct Correction dict[] = {
            {"ocassion", "occasion"},
            {"obediance", "obedience"},
            {"obediant", "obedient"},
            {"obstacal", "obstacle"},
            {"obstruced", "obstructed"},
            {"occassion", "occasion"},
            {"occurr", "occur"},
            {"ocuntries", "countries"},
            {"ocuntry", "country"},
            {"ocurr", "occur"},
            {"officaly", "officially"},
            {"oftenly", "often"},
            {"oging", "going, ogling"},
            {"olther", "other"},
            {"ommiting", "omitting"},
            {"omniverous", "omnivorous"},
            {"omre", "more"},
            {"onot", "note, not"},
            {"onyl", "only"},
            {"opponant", "opponent"},
            {"opthamologist", "ophthalmologist"},
            {"orded", "ordered"},
            {"organim", "organism"},
            {"orgin", "origin, organ"},
            {"orginize", "organise"},
            {"origanaly", "originally"},
            {"originall", "original, originally"},
            {"otehr", "other "},
            {"oublisher", "publisher"},
            {"ouevre", "oeuvre"},
            {"overthere", "over there"},
            {"owrk", "work"},
            {"owudl", "would"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'p') {
        struct Correction dict[] = {
            {"pantomine", "pantomime"},
            {"possession", "possession"},
            {"privilage", "privilege"},
            {"paide", "paid"},
            {"palce", "place, palace"},
            {"paleolitic", "paleolithic"},
            {"pallete", "palette"},
            {"paralel", "parallel"},
            {"paralell", "parallel"},
            {"paralelly", "parallelly"},
            {"paralely", "parallelly"},
            {"parallely", "parallelly"},
            {"paranthesis", "parenthesis"},
            {"parisitic", "parasitic"},
            {"parrakeets", "parakeets"},
            {"parrallell", "parallel"},
            {"parrallelly", "parallelly"},
            {"parrallely", "parallelly"},
            {"particually", "particularly"},
            {"particulary", "particularly"},
            {"particuly", "particularly"},
            {"pary", "party"},
            {"passerbys", "passersby"},
            {"pastural", "pastoral"},
            {"pattented", "patented"},
            {"payed", "paid"},
            {"peacefuland", "peaceful and"},
            {"peageant", "pageant"},
            {"peaples", "peoples"},
            {"peculure", "peculiar"},
            {"pedestrain", "pedestrian"},
            {"peice", "piece"},
            {"penatly", "penalty"},
            {"penerator", "penetrator"},
            {"pensle", "pencil"},
            {"peom", "poem"},
            {"peoms", "poems"},
            {"peopel", "people"},
            {"peopels", "peoples"},
            {"peotry", "poetry"},
            {"perade", "parade"},
            {"percepted", "perceived"},
            {"performence", "performance"},
            {"performes", "performed, performs"},
            {"perhasp", "perhaps"},
            {"perhpas", "perhaps"},
            {"perjery", "perjury"},
            {"perjorative", "pejorative"},
            {"permanant", "permanent"},
            {"permenant", "permanent"},
            {"permenantly", "permanently"},
            {"permissable", "permissible"},
            {"perogative", "prerogative"},
            {"perosnality", "personality"},
            {"perphas", "perhaps"},
            {"persistance", "persistence"},
            {"personel", "personnel, personal"},
            {"personell", "personnel"},
            {"personnell", "personnel"},
            {"persue", "pursue"},
            {"persued", "pursued"},
            {"persuing", "pursuing"},
            {"persuits", "pursuits"},
            {"phylosophical", "philosophical"},
            {"pinoneered", "pioneered"},
            {"planed", "planned"},
            {"plateu", "plateau"},
            {"playwrite", "playwright"},
            {"playwrites", "playwrights"},
            {"pleasent", "pleasant"},
            {"poenis", "penis"},
            {"poeoples", "peoples"},
            {"poety", "poetry"},
            {"poisin", "poison"},
            {"polical", "political"},
            {"polysaccharid", "polysaccharide"},
            {"pomotion", "promotion"},
            {"poportional", "proportional"},
            {"populare", "popular"},
            {"populer", "popular"},
            {"porshan", "portion"},
            {"porshon", "portion"},
            {"portuguease", "portuguese"},
            {"portugues", "Portuguese"},
            {"posion", "poison"},
            {"positon", "position, positron"},
            {"possessess", "possesses"},
            {"possition", "position"},
            {"potatos", "potatoes"},
            {"poverful", "powerful"},
            {"powerfull", "powerful"},
            {"practial", "practical"},
            {"practicly", "practically"},
            {"practioners", "practitioners"},
            {"prairy", "prairie"},
            {"preample", "preamble"},
            {"preceed", "precede"},
            {"preceeded", "preceded"},
            {"preceeding", "preceding"},
            {"preceeds", "precedes"},
            {"precentage", "percentage"},
            {"precice", "precise"},
            {"precurser", "precursor"},
            {"predicatble", "predictable"},
            {"predicitons", "predictions"},
            {"predomiantly", "predominately"},
            {"preiod", "period"},
            {"preliferation", "proliferation"},
            {"premeire", "premiere"},
            {"premission", "permission"},
            {"prepair", "prepare"},
            {"prepatory", "preparatory"},
            {"preperation", "preparation"},
            {"preperations", "preparations"},
            {"preriod", "period"},
            {"presense", "presence"},
            {"presidenital", "presidential"},
            {"presidental", "presidential"},
            {"prespective", "perspective"},
            {"prestigeous", "prestigious"},
            {"presumabely", "presumably"},
            {"pretection", "protection"},
            {"prevelant", "prevalent"},
            {"preverse", "perverse"},
            {"previvous", "previous"},
            {"primarly", "primarily"},
            {"primative", "primitive"},
            {"primatively", "primitively"},
            {"primordal", "primordial"},
            {"principaly", "principality"},
            {"principial", "principal"},
            {"principly", "principally"},
            {"probabilaty", "probability"},
            {"probablly", "probably"},
            {"probalibity", "probability"},
            {"probaly", "probably"},
            {"procede", "proceed, precede"},
            {"proceded", "proceeded, preceded"},
            {"procedes", "proceeds, precedes"},
            {"procedger", "procedure"},
            {"proceding", "proceeding, preceding"},
            {"proces", "process"},
            {"processer", "processor"},
            {"proclomation", "proclamation"},
            {"profesion", "profusion, profession"},
            {"professer", "professor"},
            {"profilic", "prolific"},
            {"progidy", "prodigy"},
            {"progrom", "pogrom, program"},
            {"progroms", "pogroms, programs"},
            {"prohabition", "prohibition"},
            {"prominant", "prominent"},
            {"prominantly", "prominently"},
            {"prominately", "prominently, predominately"},
            {"promotted", "promoted"},
            {"pronomial", "pronominal"},
            {"prophacy", "prophecy"},
            {"propogate", "propagate"},
            {"propogates", "propagates"},
            {"propogation", "propagation"},
            {"propper", "proper"},
            {"proprietory", "proprietary"},
            {"proseletyzing", "proselytizing"},
            {"protaganist", "protagonist"},
            {"protaganists", "protagonists"},
            {"protocal", "protocol"},
            {"protoganist", "protagonist"},
            {"protrayed", "portrayed"},
            {"prouncements", "pronouncements"},
            {"provacative", "provocative"},
            {"provisiosn", "provision"},
            {"pseudononymous", "pseudonymous"},
            {"publically", "publicly"},
            {"publicaly", "publicly"},
            {"publisherr", "publisher"},
            {"publishre", "publisher"},
            {"puchasing", "purchasing"},
            {"purposedly", "purposely"},
            {"pursuade", "persuade"},
            {"pursuades", "persuades"},
            {"pususading", "persuading"},
            {"pwoer", "power"},
            {"pyscic", "psychic"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'q') {
        struct Correction dict[] = {
            {"qtuie", "quite, quiet"},
            {"quantaty", "quantity"},
            {"quantitiy", "quantity"},
            {"quicklyu", "quickly"},
            {"quitted", "quit"},
            {"quize", "quiz"},
            {"qutie", "quite, quiet"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'r') {
        struct Correction dict[] = {
            {"relavent", "relevant"},
            {"radify", "ratify"},
            {"raelly", "really"},
            {"rarified", "rarefied"},
            {"reaccurring", "recurring"},
            {"readmition", "readmission"},
            {"realitvely", "relatively"},
            {"realtions", "relations"},
            {"realyl", "really"},
            {"rebounce", "rebound"},
            {"receeding", "receding"},
            {"receivedfrom", "received from"},
            {"recepient", "recipient"},
            {"recepients", "recipients"},
            {"reched", "reached"},
            {"recide", "reside"},
            {"recided", "resided"},
            {"recident", "resident"},
            {"recidents", "residents"},
            {"reciding", "residing"},
            {"reciepents", "recipients"},
            {"reciept", "receipt"},
            {"recieve", "receive"},
            {"reciever", "receiver"},
            {"recievers", "receivers"},
            {"recieving", "receiving"},
            {"recipiant", "recipient"},
            {"recipiants", "recipients"},
            {"recipt", "receipt"},
            {"recompence", "recompense"},
            {"reconcilation", "reconciliation"},
            {"recordproducer", "record producer"},
            {"recquired", "required"},
            {"recrod", "record"},
            {"rediculous", "ridiculous"},
            {"reedeming", "redeeming"},
            {"reenforced", "reinforced"},
            {"refect", "reflect"},
            {"referece", "reference"},
            {"referemces", "references"},
            {"referencs", "references"},
            {"referiang", "referring"},
            {"refering", "referring"},
            {"refernce", "reference, references"},
            {"referrs", "refers"},
            {"reffered", "referred"},
            {"reffering", "referring"},
            {"refusla", "refusal"},
            {"regardes", "regards"},
            {"reigining", "reigning"},
            {"reknowned", "renowned"},
            {"rela", "real"},
            {"relavant", "relevant"},
            {"relected", "reelected"},
            {"releive", "relieve"},
            {"releived", "relieved"},
            {"relevent", "relevant"},
            {"relient", "reliant"},
            {"relized", "realised, realized"},
            {"relpacement", "replacement"},
            {"remaing", "remaining"},
            {"rememberable", "memorable"},
            {"remembrence", "remembrance"},
            {"reminent", "remnant"},
            {"renedered", "rende"},
            {"renewl", "renewal"},
            {"rennovate", "renovate"},
            {"rentors", "renters"},
            {"reoccurrence", "recurrence"},
            {"reorganision", "reorganisation"},
            {"repatition", "repetition, repartition"},
            {"repectively", "respectively"},
            {"repentent", "repentant"},
            {"repeteadly", "repeatedly"},
            {"repetion", "repetition"},
            {"repid", "rapid"},
            {"reponsible", "responsible"},
            {"reportadly", "reportedly"},
            {"representive", "representative"},
            {"representives", "representatives"},
            {"repsectively", "respectively"},
            {"republi", "republic"},
            {"republian", "republican"},
            {"republis", "republics"},
            {"resemblence", "resemblance"},
            {"resignement", "resignment"},
            {"resistable", "resistible"},
            {"resistence", "resistance"},
            {"resistent", "resistant"},
            {"responce", "response"},
            {"responsability", "responsibility"},
            {"responsibilites", "responsibilities"},
            {"ressemble", "resemble"},
            {"restaraunt", "restaurant"},
            {"restaraunts", "restaurants"},
            {"restauration", "restoration"},
            {"resteraunt", "restaurant"},
            {"resteraunts", "restaurants"},
            {"restraunt", "restraint, restaurant"},
            {"resturaunts", "restaurants"},
            {"retreive", "retrieve"},
            {"returnd", "returned"},
            {"revaluated", "reevaluated"},
            {"reveral", "reversal"},
            {"reversable", "reversible"},
            {"revolutionar", "revolutionary"},
            {"rewriet", "rewrite"},
            {"rigeur", "rigueur, rigour, rigor"},
            {"rigourous", "rigorous"},
            {"rininging", "ringing"},
            {"rised", "raised, rose"},
            {"rucuperate", "recuperate"},
            {"russina", "Russian"},
            {"rwite", "write"},
            {"rythem", "rhythm"},
            {"rythim", "rhythm"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 's') {
        struct Correction dict[] = {
            {"sacrifical", "sacrificial"},
            {"sargant", "sergeant"},
            {"sargent", "sergeant"},
            {"sargeant", "sergeant"},
            {"sasy", "says, sassy"},
            {"saveing", "saving"},
            {"scaleable", "scalable"},
            {"scandanavia", "Scandinavia"},
            {"schedual", "schedule"},
            {"scholarstic", "scholastic, scholarly"},
            {"scientis", "scientist"},
            {"scrutinity", "scrutiny"},
            {"secceeded", "seceded, succeeded"},
            {"seceed", "succeed, secede"},
            {"seceeded", "succeeded, seceded"},
            {"secretery", "secretary"},
            {"seeked", "sought"},
            {"seguoys", "segues"},
            {"seige", "siege"},
            {"seinor", "senior"},
            {"seldomly", "seldom"},
            {"senarios", "scenarios"},
            {"sence", "sense, since"},
            {"sensure", "censure"},
            {"seperate", "separate"},
            {"seperates", "separates"},
            {"seperation", "separation"},
            {"sepina", "subpoena"},
            {"sepulchure", "sepulchre, sepulcher"},
            {"sepulcre", "sepulchre, sepulcher"},
            {"serendipiyt", "serendipity"},
            {"sergent", "sergeant"},
            {"severley", "severely"},
            {"severly", "severely"},
            {"shadasloo", "shadaloo"},
            {"shadoloo", "shadaloo"},
            {"shamen", "shaman, shamans"},
            {"sheat", "sheath, sheet, cheat"},
            {"sherif", "sheriff"},
            {"shineing", "shining"},
            {"shorly", "shortly"},
            {"shortwhile", "short while"},
            {"shoudl", "should"},
            {"shouldnt", "should not"},
            {"shreak", "shriek"},
            {"shrinked", "shrunk"},
            {"sicne", "since"},
            {"sieze", "seize, size"},
            {"siezed", "seized, sized"},
            {"siezing", "seizing, sizing"},
            {"siezure", "seizure"},
            {"siezures", "seizures"},
            {"signitories", "signatories"},
            {"simpley", "simply"},
            {"simplier", "simpler"},
            {"sinse", "sines, since"},
            {"slippy", "slippery"},
            {"slowy", "slowly"},
            {"smae", "same"},
            {"smoe", "some"},
            {"sneeks", "sneaks"},
            {"soem", "some"},
            {"sohw", "show"},
            {"soilders", "soldiers"},
            {"soley", "solely"},
            {"soliders", "soldiers"},
            {"sophicated", "sophisticated"},
            {"sorrounding", "surrounding"},
            {"sotry", "story"},
            {"sotyr", "satyr, story"},
            {"soudn", "sound"},
            {"soudns", "sounds"},
            {"sould", "could, should, sold, soul"},
            {"souvenier", "souvenir"},
            {"souveniers", "souvenirs"},
            {"spainish", "Spanish"},
            {"speciallized", "specialised, specialized"},
            {"specif", "specific, specify"},
            {"speciman", "specimen"},
            {"spects", "aspects, expects"},
            {"spectum", "spectrum"},
            {"speices", "species"},
            {"spermatozoan", "spermatozoon"},
            {"sponser", "sponsor"},
            {"spoonfulls", "spoonfuls"},
            {"spreaded", "spread"},
            {"spred", "spread"},
            {"stainlees", "stainless"},
            {"standars", "standards"},
            {"stange", "strange"},
            {"startegies", "strategies"},
            {"stateman", "statesman"},
            {"stilus", "stylus"},
            {"stirrs", "stirs"},
            {"stlye", "style"},
            {"stomache", "stomach"},
            {"storeis", "stories"},
            {"storise", "stories"},
            {"stoyr", "story"},
            {"stpo", "stop"},
            {"stradegies", "strategies"},
            {"strat", "start, strata"},
            {"strenght", "strength"},
            {"strenghten", "strengthen"},
            {"strenuos", "strenuous"},
            {"strictist", "strictest"},
            {"strikely", "strikingly"},
            {"strnad", "strand"},
            {"stroy", "story, destroy"},
            {"structuer", "structure"},
            {"stuctured", "structured"},
            {"studdy", "study"},
            {"studing", "studying"},
            {"stuggling", "struggling"},
            {"subdivisio", "subdivision"},
            {"submachne", "submachine"},
            {"subsiduary", "subsidiary"},
            {"substace", "substance"},
            {"substancial", "substantial"},
            {"substituded", "substituted"},
            {"subterranian", "subterranean"},
            {"suburburban", "suburban"},
            {"succsessfull", "successful"},
            {"sucesfuly", "successfully"},
            {"sucesion", "succession"},
            {"sucessot", "successor"},
            {"sucidial", "suicidal"},
            {"sudent", "student"},
            {"sudents", "students"},
            {"suop", "soup"},
            {"superceeded", "superseded"},
            {"superintendant", "superintendent"},
            {"suphisticated", "sophisticated"},
            {"supposingly", "supposedly"},
            {"suprassing", "surpassing"},
            {"suprised", "surprised"},
            {"suprising", "surprising"},
            {"suprize", "surprise"},
            {"suprized", "surprised"},
            {"suprizing", "surprising"},
            {"surley", "surly, surely"},
            {"surplanted", "supplanted"},
            {"surpress", "suppress"},
            {"surpressed", "suppressed"},
            {"surprize", "surprise"},
            {"surprized", "surprised"},
            {"surprizing", "surprising"},
            {"surrended", "surrounded, surrendered"},
            {"surrundering", "surrendering"},
            {"surveill", "surveil"},
            {"surveyer", "surveyor"},
            {"surviver", "survivor"},
            {"survivers", "survivors"},
            {"survivied", "survived"},
            {"suspention", "suspension"},
            {"swaer", "swear"},
            {"swaers", "swears"},
            {"swepth", "swept"},
            {"syas", "says"},
            {"symmetral", "symmetric"},
            {"synonomous", "synonymous"},
            {"synonymns", "synonyms"},
            {"synphony", "symphony"},
            {"sysmatically", "systematically"},
            {"sytle", "style"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 't') {
        struct Correction dict[] = {
            {"threshhold", "threshold"},
            {"tahn", "than"},
            {"taht", "that"},
            {"tast", "taste"},
            {"tath", "that"},
            {"tato", "tattoo"},
            {"teached", "taught"},
            {"teh", "the"},
            {"tehy", "they"},
            {"telelevision", "television"},
            {"tendancies", "tendencies"},
            {"tendancy", "tendency"},
            {"tennisplayer", "tennis player"},
            {"territorist", "terrorist"},
            {"tghe", "the"},
            {"theather", "theater"},
            {"theif", "thief"},
            {"themselfs", "themselves"},
            {"ther", "there, their, the"},
            {"theri", "their"},
            {"thgat", "that"},
            {"thge", "the"},
            {"thier", "their"},
            {"thign", "thing"},
            {"thigns", "things"},
            {"thigsn", "things"},
            {"thikn", "think"},
            {"thikning", "thinking, thickening"},
            {"thikns", "thinks"},
            {"thn", "then"},
            {"thna", "than"},
            {"thne", "then"},
            {"threatend", "threatened"},
            {"thrid", "third"},
            {"throughly", "thoroughly"},
            {"throught", "thought, through, throughout"},
            {"thru", "through"},
            {"thsi", "this"},
            {"thsoe", "those"},
            {"thta", "that"},
            {"tiem", "time, Tim"},
            {"tihkn", "think"},
            {"tihs", "this"},
            {"timeschedule", "time schedule"},
            {"timne", "time"},
            {"tiome", "time, tome"},
            {"tje", "the"},
            {"tjhe", "the"},
            {"tjpanishad", "upanishad"},
            {"tkae", "take"},
            {"tkaes", "takes"},
            {"tkaing", "taking"},
            {"tlaking", "talking"},
            {"todya", "today"},
            {"toke", "took"},
            {"tomatos", "tomatoes"},
            {"tormenters", "tormentors"},
            {"tornadoe", "tornado"},
            {"torpeados", "torpedoes"},
            {"torpedos", "torpedoes"},
            {"tothe", "to the"},
            {"toubles", "troubles"},
            {"tounge", "tongue"},
            {"tourch", "torch, touch"},
            {"towrad", "toward"},
            {"tradionally", "traditionally"},
            {"traditionnal", "traditional"},
            {"traditition", "tradition"},
            {"trafficed", "trafficked"},
            {"transcendant", "transcendent"},
            {"transcendentational", "transcendental"},
            {"transcripting", "transcribing, transcription"},
            {"translater", "translator"},
            {"translaters", "translators"},
            {"triology", "trilogy"},
            {"troup", "troupe"},
            {"troups", "troupes, troops"},
            {"turnk", "turnkey, trunk"},
            {"twon", "town"},
            {"twpo", "two"},
            {"tyhe", "they"},
            {"tyrany", "tyranny"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'u') {
        struct Correction dict[] = {
            {"ublisher", "publisher"},
            {"uise", "use"},
            {"unathorised", "unauthorised"},
            {"unavailible", "unavailable"},
            {"uncertainity", "uncertainty"},
            {"uncompetive", "uncompetitive"},
            {"unconfortability", "discomfort"},
            {"unconvential", "unconventional"},
            {"understoon", "understood"},
            {"unequalities", "inequalities"},
            {"unfortunatley", "unfortunately"},
            {"unilatreal", "unilateral"},
            {"univeral", "universal"},
            {"unmanouverable", "unmaneuverable, unmanoeuvrable"},
            {"unnessary", "unnecessary"},
            {"unoperational", "nonoperational"},
            {"unoticeable", "unnoticeable"},
            {"unplease", "displease"},
            {"unrepentent", "unrepentant"},
            {"unsed", "used, unused, unsaid"},
            {"unsucesfuly", "unsuccessfully"},
            {"unsurprized", "unsurprised"},
            {"untill", "until"},
            {"unweildly", "unwieldy"},
            {"unwieldly", "unwieldy"},
            {"upcomming", "upcoming"},
            {"upto", "up to"},
            {"usally", "usually"},
            {"usefull", "useful"},
            {"utill", "until"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'v') {
        struct Correction dict[] = {
            {"viscious", "vicious, viscous"},
            {"vaccume", "vacuum"},
            {"vacinity", "vicinity"},
            {"vaguaries", "vagaries"},
            {"valetta", "valletta"},
            {"varient", "variant"},
            {"variey", "variety"},
            {"varities", "varieties"},
            {"varity", "variety"},
            {"vehicule", "vehicle"},
            {"vell", "well"},
            {"vermillion", "vermilion"},
            {"versitilaty", "versatility"},
            {"vetween", "between"},
            {"veyr", "very"},
            {"vigeur", "vigueur, vigour, vigor"},
            {"villian", "villain"},
            {"villin", "villi, villain, villein"},
            {"vincinity", "vicinity"},
            {"visting", "visiting"},
            {"vitories", "victories"},
            {"volcanoe", "volcano"},
            {"volumne", "volume"},
            {"vreity", "variety"},
            {"vrey", "very"},
            {"vyer", "very"},
            {"vyre", "very"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'w') {
        struct Correction dict[] = {
            {"wether", "whether, weather"},
            {"waht", "what"},
            {"warantee", "warranty"},
            {"warrriors", "warriors"},
            {"wass", "was"},
            {"watn", "want"},
            {"wayword", "wayward"},
            {"weas", "was"},
            {"wehn", "when"},
            {"weild", "wield, wild"},
            {"weilded", "wielded"},
            {"wendsay", "Wednesday"},
            {"wensday", "Wednesday"},
            {"whant", "want"},
            {"whants", "wants"},
            {"wheras", "whereas"},
            {"wherease", "whereas"},
            {"whereever", "wherever"},
            {"whic", "which"},
            {"whith", "with"},
            {"whlch", "which"},
            {"whn", "when"},
            {"wholy", "wholly, holy"},
            {"whta", "what"},
            {"whther", "whether"},
            {"wich", "which, witch"},
            {"wief", "wife"},
            {"wierd", "weird"},
            {"wierd", "weird"},
            {"wiew", "view"},
            {"wiht", "with"},
            {"wille", "will"},
            {"willk", "will"},
            {"wirting", "writing"},
            {"withdrawl", "withdrawal, withdraw"},
            {"withh", "with"},
            {"withing", "within"},
            {"witht", "with"},
            {"witn", "with"},
            {"wnat", "want"},
            {"wnats", "wants"},
            {"wohle", "whole"},
            {"wokr", "work"},
            {"wokring", "working"},
            {"worls", "world"},
            {"woudl", "would"},
            {"wresters", "wrestlers"},
            {"wriet", "write"},
            {"wroet", "wrote"},
            {"wrok", "work"},
            {"wroking", "working"},
            {"wtih", "with"},
            {"wupport", "support"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'x') {
        struct Correction dict[] = {
            {"xenophoby", "xenophobia"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }

    } else if (miss[0] == 'y') {
        struct Correction dict[] = {
            {"yaer", "year"},
            {"yaerly", "yearly"},
            {"yaers", "years"},
            {"yatch", "yacht"},
            {"yearm", "year"},
            {"yeasr", "years"},
            {"yeild", "yield"},
            {"yeilding", "yielding"},
            {"yera", "year"},
            {"yeras", "years"},
            {"yersa", "years"},
            {"yotube", "youtube"},
            {"youseff", "yousef"},
            {"yrea", "year"},
            {"yuo", "you"},
            {NULL, NULL}
        };

        for (int i = 0; dict[i].wrong != NULL; i++) {
            if (strcmp(miss, dict[i].wrong) == 0) return dict[i].right;
        }
    }

    return " ";
}

int get_max_results(char letter) {

    if (letter == 'a') return 10441;
    if (letter == 'b') return 9275;
    if (letter == 'c') return 16229;
    if (letter == 'd') return 10147;
    if (letter == 'e') return 7054;
    if (letter == 'f') return 6766;
    if (letter == 'g') return 5588;
    if (letter == 'h') return 6300;
    if (letter == 'i') return 6977;
    if (letter == 'j') return 1375;
    if (letter == 'k') return 1715;
    if (letter == 'l') return 5052;
    if (letter == 'm') return 9623;
    if (letter == 'n') return 4389;
    if (letter == 'o') return 5836;
    if (letter == 'p') return 14562;
    if (letter == 'q') return 822;
    if (letter == 'r') return 10158;
    if (letter == 's') return 18985;
    if (letter == 't') return 8746;
    if (letter == 'u') return 5068;
    if (letter == 'v') return 2735;
    if (letter == 'w') return 3693;
    if (letter == 'x') return 134;
    if (letter == 'y') return 544;
    if (letter == 'z') return 532;

    return 0;
}

int main() {

    char *misspelled[500] = {"accomodate", "acheive", "accross", "agressive", "aligment", "appearence", "arguement", "basicly", "beleive", "calender", "carribean", "cemetary", "chauffer", "collegue", "commitee", "completly", "conscientous", "definately", "disipline", "drunkeness", "embarass", "equiptment", "excede", "existance", "experiance", "firey", "foriegn", "guage", "greatfull", "guarentee", "harrass", "hieght", "hierachy", "humerous", "ignorence", "imediate", "independant", "indispensible", "inteligence", "judgement", "knowlege", "liesure", "liason", "libary", "lightening", "maintainance", "manover", "medievil", "momento", "milenium", "minature", "mischievous", "mispell", "nieghbor", "noticable", "ocassion", "occurence", "pantomine", "paralell", "percieve", "persistance", "personel", "plagerism", "possession", "preceed", "privilage", "pronounciation", "publically", "questionaire", "reciept", "reccommend", "refered", "relavent", "relidgious", "repetition", "rythm", "rediculous", "seperate", "sargent", "supercede", "threshhold", "tommorrow", "twelth", "tyrany", "unconcious", "untill", "vaccum", "viscious", "wether", "wierd", "didnt"};

    int total_groups_match = 0;
    char **match_tokens;

    for (int i = 0; misspelled[i] != NULL; i++) {
        clock_t start = clock();

        char path[19];
        sprintf(path, "words/groups/%c.txt", misspelled[i][0]);

        FILE *file = fopen(path, "r");

        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }

        int entry_count = 0;

        char line_buffer[30];
        line_buffer[0] = '\0';

        Match *results = malloc(sizeof(Match) * get_max_results(misspelled[i][0]));

        int total_groups_misspelled = 0;
        char **misspelled_tokens = tokenize(misspelled[i], &total_groups_misspelled);
        if (misspelled_tokens == NULL) return 1;

        char *manual_match = manual_list(misspelled[i]);

        if (strcmp(manual_match, " ") != 0) {
            clock_t end = clock();
            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

            // printf("\033[0;32m{\"%s\", \"%s\"} [%fs]\n\033[0m", misspelled[i], manual_match, time_taken);
            continue;
        }

        int miss_len = strlen(misspelled[i]);

        while (fgets(line_buffer, sizeof(line_buffer), file)) {
            line_buffer[strcspn(line_buffer, "\n")] = '\0';

            int line_len = strlen(line_buffer);
            if (line_len < miss_len - 2) continue;
            if (line_len > miss_len + 2) break;

            if (i == 0) {
                total_groups_match = 0;
                match_tokens = tokenize(line_buffer, &total_groups_match);
                if (match_tokens == NULL) return 1;
            }

            int limit = calculate_group_limit(total_groups_misspelled, total_groups_match);

            int score = 0;
            score += full_group_match(limit, misspelled_tokens, match_tokens);
            score += perfect_letter_match(limit, misspelled_tokens, match_tokens);
            score += swapped_letter_match(misspelled[i], line_buffer);
            score += length_difference(misspelled[i], line_buffer);
            score += first_and_last_letter(misspelled[i], line_buffer);
            score += neighbour_scan(misspelled[i], line_buffer);

            strcpy(results[entry_count].word, line_buffer);
            results[entry_count].points = score;
            entry_count++;
        }

        qsort(results, entry_count, sizeof(Match), compare_matches);

        printf("{\"%s\"", misspelled[i]);

        for (int i = 0; i < 3 && i < entry_count; i++) printf(", \"%s\"", results[i].word);

        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("} \[%fs] ", time_taken);
        printf("-> %d entries\n", entry_count);

        entry_count = 0;
        free(results);
        free(misspelled_tokens);
        fclose(file);
    }

    return 0;
}
