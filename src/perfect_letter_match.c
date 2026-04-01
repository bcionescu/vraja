#include <stdlib.h>
#include "../include/perfect_letter_match.h"

int perfect_letter_match(char *misspelled_tokens, char *match_tokens)
{
    int score = 0;

    char *p1 = misspelled_tokens;
    char *p2 = match_tokens;

    while (*p1 && *p2)
    {
        if (*p1 == *p2)
        {
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

    return score;
}
