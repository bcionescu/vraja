#include "../include/first_and_last_letter.h"
#include <string.h>

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

    if (strlen(misspelled) >= 4) {
        if (misspelled[strlen(misspelled) - 2] == line_buffer[strlen(line_buffer) - 2]) {
            score += 10;
            second_perfect_match += 1;
        }

        if (second_perfect_match == 2) score += 15;

        if (misspelled[2] == line_buffer[2]) {
            score += 10;
            third_perfect_match += 1;
        }

        if (third_perfect_match == 2) score += 10;

        if (first_perfect_match == 2 && second_perfect_match == 2) { score += 15; }
    }

    if (strlen(misspelled) >= 6) {
        if (misspelled[strlen(misspelled) - 3] == line_buffer[strlen(line_buffer) - 3]) {
            score += 10;
            third_perfect_match += 1;
        }

        if (first_perfect_match == 2 && second_perfect_match == 2 && third_perfect_match == 2) { score += 15; }
    }

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
