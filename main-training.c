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

  if (word_difference == 0) {
    score += 10;
  } else if (word_difference == 1) {
    score += 7;
  } else if (word_difference == 2) {
    score += 2;
  } else if ((word_difference >= 4) && (word_difference < 7)) {
    score -= 7;
  } else if ((word_difference > 7) && (word_difference < 12)) {
    score -= 10;
  } else {
    score -= 100;
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

int manual_list(char *miss, char *line) {
  int score = 0;

  // if (strcmp(miss, "alot") == 0 && strcmp(line, "a lot") == 0) score += 100;
  // if (strcmp(miss, "alright") == 0 && strcmp(line, "all right") == 0) score += 100;
  if (strcmp(miss, "abondon") == 0 && strcmp(line, "abandon") == 0) score += 100;
  if (strcmp(miss, "abondoning") == 0 && strcmp(line, "abandoning") == 0) score += 100;
  if (strcmp(miss, "abondons") == 0 && strcmp(line, "abandons") == 0) score += 100;
  if (strcmp(miss, "abreviated") == 0 && strcmp(line, "abbreviated") == 0) score += 100;
  if (strcmp(miss, "abreviation") == 0 && strcmp(line, "abbreviation") == 0) score += 100;
  if (strcmp(miss, "absailing") == 0 && strcmp(line, "abseiling") == 0) score += 100;
  if (strcmp(miss, "absense") == 0 && strcmp(line, "absence") == 0) score += 100;
  if (strcmp(miss, "absolutly") == 0 && strcmp(line, "absolutely") == 0) score += 100;
  if (strcmp(miss, "absorbsion") == 0 && strcmp(line, "absorption") == 0) score += 100;
  if (strcmp(miss, "absorbtion") == 0 && strcmp(line, "absorption") == 0) score += 100;
  if (strcmp(miss, "accension") == 0 && strcmp(line, "accession") == 0) score += 100;
  if (strcmp(miss, "accension") == 0 && strcmp(line, "ascension") == 0) score += 100;
  if (strcmp(miss, "acceptible") == 0 && strcmp(line, "acceptable") == 0) score += 100;
  if (strcmp(miss, "accidant") == 0 && strcmp(line, "accident") == 0) score += 100;
  if (strcmp(miss, "accomdate") == 0 && strcmp(line, "accommodate") == 0) score += 100;
  if (strcmp(miss, "accoring") == 0 && strcmp(line, "according") == 0) score += 100;
  if (strcmp(miss, "accquainted") == 0 && strcmp(line, "acquainted") == 0) score += 100;
  if (strcmp(miss, "accredidation") == 0 && strcmp(line, "accreditation") == 0) score += 100;
  if (strcmp(miss, "acedemic") == 0 && strcmp(line, "academic") == 0) score += 100;
  if (strcmp(miss, "achiv") == 0 && strcmp(line, "achieve") == 0) score += 100;
  if (strcmp(miss, "achive") == 0 && strcmp(line, "achieve") == 0) score += 100;
  if (strcmp(miss, "achive") == 0 && strcmp(line, "archive") == 0) score += 100;
  if (strcmp(miss, "achived") == 0 && strcmp(line, "achieved") == 0) score += 100;
  if (strcmp(miss, "achived") == 0 && strcmp(line, "archived") == 0) score += 100;
  if (strcmp(miss, "ackward") == 0 && strcmp(line, "awkward") == 0) score += 100;
  if (strcmp(miss, "ackward") == 0 && strcmp(line, "backward") == 0) score += 100;
  if (strcmp(miss, "activites") == 0 && strcmp(line, "activities") == 0) score += 100;
  if (strcmp(miss, "adbandon") == 0 && strcmp(line, "abandon") == 0) score += 100;
  if (strcmp(miss, "addmission") == 0 && strcmp(line, "admission") == 0) score += 100;
  if (strcmp(miss, "addopted") == 0 && strcmp(line, "adopted") == 0) score += 100;
  if (strcmp(miss, "addoptive") == 0 && strcmp(line, "adoptive") == 0) score += 100;
  if (strcmp(miss, "addres") == 0 && strcmp(line, "address") == 0) score += 100;
  if (strcmp(miss, "adequit") == 0 && strcmp(line, "adequate") == 0) score += 100;
  if (strcmp(miss, "adhearing") == 0 && strcmp(line, "adhering") == 0) score += 100;
  if (strcmp(miss, "adviceable") == 0 && strcmp(line, "advisable") == 0) score += 100;
  if (strcmp(miss, "agressiev") == 0 && strcmp(line, "aggressive") == 0) score += 100;
  if (strcmp(miss, "amatuer") == 0 && strcmp(line, "amateur") == 0) score += 100;
  if (strcmp(miss, "amature") == 0 && strcmp(line, "amateur") == 0) score += 100;
  if (strcmp(miss, "analize") == 0 && strcmp(line, "analyze") == 0) score += 100;
  if (strcmp(miss, "annuall") == 0 && strcmp(line, "annual") == 0) score += 100;
  if (strcmp(miss, "anuncement") == 0 && strcmp(line, "announcement") == 0) score += 100;
  if (strcmp(miss, "apparant") == 0 && strcmp(line, "apparent") == 0) score += 100;
  if (strcmp(miss, "appearence") == 0 && strcmp(line, "appearance") == 0) score += 100;
  if (strcmp(miss, "appearences") == 0 && strcmp(line, "appearances") == 0) score += 100;
  if (strcmp(miss, "arguement") == 0 && strcmp(line, "argument") == 0) score += 100;
  if (strcmp(miss, "assistent") == 0 && strcmp(line, "assistant") == 0) score += 100;
  if (strcmp(miss, "authour") == 0 && strcmp(line, "author") == 0) score += 100;
  if (strcmp(miss, "awfull") == 0 && strcmp(line, "awful") == 0) score += 100;
  if (strcmp(miss, "basicly") == 0 && strcmp(line, "basically") == 0) score += 100;
  if (strcmp(miss, "beated") == 0 && strcmp(line, "beaten") == 0) score += 100;
  if (strcmp(miss, "becomming") == 0 && strcmp(line, "becoming") == 0) score += 100;
  if (strcmp(miss, "begining") == 0 && strcmp(line, "beginning") == 0) score += 100;
  if (strcmp(miss, "believ") == 0 && strcmp(line, "belief") == 0) score += 100;
  if (strcmp(miss, "believ") == 0 && strcmp(line, "believe") == 0) score += 100;
  if (strcmp(miss, "calender") == 0 && strcmp(line, "calendar") == 0) score += 100;
  if (strcmp(miss, "carribean") == 0 && strcmp(line, "caribbean") == 0) score += 100;
  if (strcmp(miss, "catagory") == 0 && strcmp(line, "category") == 0) score += 100;
  if (strcmp(miss, "cemetary") == 0 && strcmp(line, "cemetery") == 0) score += 100;
  if (strcmp(miss, "coligue") == 0 && strcmp(line, "colleague") == 0) score += 100;
  if (strcmp(miss, "colum") == 0 && strcmp(line, "column") == 0) score += 100;
  if (strcmp(miss, "comite") == 0 && strcmp(line, "committee") == 0) score += 100;
  if (strcmp(miss, "comitee") == 0 && strcmp(line, "committee") == 0) score += 100;
  if (strcmp(miss, "comming") == 0 && strcmp(line, "coming") == 0) score += 100;
  if (strcmp(miss, "condem") == 0 && strcmp(line, "condemn") == 0) score += 100;
  if (strcmp(miss, "congradulations") == 0 && strcmp(line, "congratulations") == 0) score += 100;
  if (strcmp(miss, "conveniance") == 0 && strcmp(line, "convenience") == 0) score += 100;
  if (strcmp(miss, "definate") == 0 && strcmp(line, "definite") == 0) score += 100;
  if (strcmp(miss, "definately") == 0 && strcmp(line, "definitely") == 0) score += 100;
  if (strcmp(miss, "dilema") == 0 && strcmp(line, "dilemma") == 0) score += 100;
  if (strcmp(miss, "doesnt") == 0 && strcmp(line, "doesn't") == 0) score += 100;
  if (strcmp(miss, "exelent") == 0 && strcmp(line, "excellent") == 0) score += 100;
  if (strcmp(miss, "exhilirate") == 0 && strcmp(line, "exhilarate") == 0) score += 100;
  if (strcmp(miss, "existance") == 0 && strcmp(line, "existence") == 0) score += 100;
  if (strcmp(miss, "extrem") == 0 && strcmp(line, "extreme") == 0) score += 100;
  if (strcmp(miss, "familier") == 0 && strcmp(line, "familiar") == 0) score += 100;
  if (strcmp(miss, "grammer") == 0 && strcmp(line, "gammar") == 0) score += 100;
  if (strcmp(miss, "gratefull") == 0 && strcmp(line, "grateful") == 0) score += 100;
  if (strcmp(miss, "guidence") == 0 && strcmp(line, "guidance") == 0) score += 100;
  if (strcmp(miss, "humourous") == 0 && strcmp(line, "humorous") == 0) score += 100;
  if (strcmp(miss, "immediatly") == 0 && strcmp(line, "immediately") == 0) score += 100;
  if (strcmp(miss, "incidently") == 0 && strcmp(line, "incidentally") == 0) score += 100;
  if (strcmp(miss, "indispensible") == 0 && strcmp(line, "indispensable") == 0) score += 100;
  if (strcmp(miss, "lenght") == 0 && strcmp(line, "length") == 0) score += 100;
  if (strcmp(miss, "liason") == 0 && strcmp(line, "liaison") == 0) score += 100;
  if (strcmp(miss, "paralel") == 0 && strcmp(line, "parallel") == 0) score += 100;
  if (strcmp(miss, "particuly") == 0 && strcmp(line, "particularly") == 0) score += 100;
  if (strcmp(miss, "quize") == 0 && strcmp(line, "quiz") == 0) score += 100;
  if (strcmp(miss, "reciept") == 0 && strcmp(line, "receipt") == 0) score += 100;
  if (strcmp(miss, "recieve") == 0 && strcmp(line, "receive") == 0) score += 100;
  if (strcmp(miss, "recipt") == 0 && strcmp(line, "receipt") == 0) score += 100;
  if (strcmp(miss, "relavant") == 0 && strcmp(line, "relevant") == 0) score += 100;
  if (strcmp(miss, "seperate") == 0 && strcmp(line, "separate") == 0) score += 100;
  if (strcmp(miss, "tato") == 0 && strcmp(line, "tattoo") == 0) score += 100;
  if (strcmp(miss, "tendancy") == 0 && strcmp(line, "tendency") == 0) score += 100;
  if (strcmp(miss, "unnessary") == 0 && strcmp(line, "unnecessary") == 0) score += 100;
  if (strcmp(miss, "untill") == 0 && strcmp(line, "until") == 0) score += 100;
  if (strcmp(miss, "utill") == 0 && strcmp(line, "until") == 0) score += 100;
  if (strcmp(miss, "wierd") == 0 && strcmp(line, "weird") == 0) score += 25;

  // Double check these, as we need to make sure they're legit
  if (strcmp(miss, "Dravadian") == 0 && strcmp(line, "Dravidian") == 0) score += 100;
  if (strcmp(miss, "Enlish") == 0 && strcmp(line, "English, enlist") == 0) score += 100;
  if (strcmp(miss, "Europian") == 0 && strcmp(line, "European") == 0) score += 100;
  if (strcmp(miss, "Europians") == 0 && strcmp(line, "Europeans") == 0) score += 100;
  if (strcmp(miss, "Eurpean") == 0 && strcmp(line, "European") == 0) score += 100;
  if (strcmp(miss, "Eurpoean") == 0 && strcmp(line, "European") == 0) score += 100;
  if (strcmp(miss, "Farenheit") == 0 && strcmp(line, "Fahrenheit") == 0) score += 100;
  if (strcmp(miss, "Febuary") == 0 && strcmp(line, "February") == 0) score += 100;
  if (strcmp(miss, "Feburary") == 0 && strcmp(line, "February") == 0) score += 100;
  if (strcmp(miss, "Flemmish") == 0 && strcmp(line, "Flemish") == 0) score += 100;
  if (strcmp(miss, "Formalhaut") == 0 && strcmp(line, "Fomalhaut") == 0) score += 100;
  if (strcmp(miss, "Foundland") == 0 && strcmp(line, "Newfoundland") == 0) score += 100;
  if (strcmp(miss, "Fransiscan") == 0 && strcmp(line, "Franciscan") == 0) score += 100;
  if (strcmp(miss, "Fransiscans") == 0 && strcmp(line, "Franciscans") == 0) score += 100;
  if (strcmp(miss, "Galations") == 0 && strcmp(line, "Galatians") == 0) score += 100;
  if (strcmp(miss, "Gameboy") == 0 && strcmp(line, "Game Boy") == 0) score += 100;
  if (strcmp(miss, "Ghandi") == 0 && strcmp(line, "Gandhi") == 0) score += 100;
  if (strcmp(miss, "Godounov") == 0 && strcmp(line, "Godunov") == 0) score += 100;
  if (strcmp(miss, "Gothenberg") == 0 && strcmp(line, "Gothenburg") == 0) score += 100;
  if (strcmp(miss, "Gottleib") == 0 && strcmp(line, "Gottlieb") == 0) score += 100;
  if (strcmp(miss, "Guaduloupe") == 0 && strcmp(line, "Guadalupe, Guadeloupe") == 0) score += 100;
  if (strcmp(miss, "Guadulupe") == 0 && strcmp(line, "Guadalupe, Guadeloupe") == 0) score += 100;
  if (strcmp(miss, "Guatamala") == 0 && strcmp(line, "Guatemala") == 0) score += 100;
  if (strcmp(miss, "Guatamalan") == 0 && strcmp(line, "Guatemalan") == 0) score += 100;
  if (strcmp(miss, "Guilia") == 0 && strcmp(line, "Giulia") == 0) score += 100;
  if (strcmp(miss, "Guilio") == 0 && strcmp(line, "Giulio") == 0) score += 100;
  if (strcmp(miss, "Guiness") == 0 && strcmp(line, "Guinness") == 0) score += 100;
  if (strcmp(miss, "Guiseppe") == 0 && strcmp(line, "Giuseppe") == 0) score += 100;
  if (strcmp(miss, "Habsbourg") == 0 && strcmp(line, "Habsburg") == 0) score += 100;
  if (strcmp(miss, "Hatian") == 0 && strcmp(line, "Haitian") == 0) score += 100;
  if (strcmp(miss, "Heidelburg") == 0 && strcmp(line, "Heidelberg") == 0) score += 100;
  if (strcmp(miss, "Ihaca") == 0 && strcmp(line, "Ithaca") == 0) score += 100;
  if (strcmp(miss, "Israelies") == 0 && strcmp(line, "Israelis") == 0) score += 100;
  if (strcmp(miss, "Janurary") == 0 && strcmp(line, "January") == 0) score += 100;
  if (strcmp(miss, "Januray") == 0 && strcmp(line, "January") == 0) score += 100;
  if (strcmp(miss, "Japanes") == 0 && strcmp(line, "Japanese") == 0) score += 100;
  if (strcmp(miss, "Johanine") == 0 && strcmp(line, "Johannine") == 0) score += 100;
  if (strcmp(miss, "Jospeh") == 0 && strcmp(line, "Joseph") == 0) score += 100;
  if (strcmp(miss, "Juadaism") == 0 && strcmp(line, "Judaism") == 0) score += 100;
  if (strcmp(miss, "Juadism") == 0 && strcmp(line, "Judaism") == 0) score += 100;
  if (strcmp(miss, "Lybia") == 0 && strcmp(line, "Libya") == 0) score += 100;
  if (strcmp(miss, "Malcom") == 0 && strcmp(line, "Malcolm") == 0) score += 100;
  if (strcmp(miss, "Massachussets") == 0 && strcmp(line, "Massachusetts") == 0) score += 100;
  if (strcmp(miss, "Massachussetts") == 0 && strcmp(line, "Massachusetts") == 0) score += 100;
  if (strcmp(miss, "Mediteranean") == 0 && strcmp(line, "Mediterranean") == 0) score += 100;
  if (strcmp(miss, "Michagan") == 0 && strcmp(line, "Michigan") == 0) score += 100;
  if (strcmp(miss, "Misouri") == 0 && strcmp(line, "Missouri") == 0) score += 100;
  if (strcmp(miss, "Missisipi") == 0 && strcmp(line, "Mississippi") == 0) score += 100;
  if (strcmp(miss, "Missisippi") == 0 && strcmp(line, "Mississippi") == 0) score += 100;
  if (strcmp(miss, "Monserrat") == 0 && strcmp(line, "Montserrat") == 0) score += 100;
  if (strcmp(miss, "Montnana") == 0 && strcmp(line, "Montana") == 0) score += 100;
  if (strcmp(miss, "Morisette") == 0 && strcmp(line, "Morissette") == 0) score += 100;
  if (strcmp(miss, "Morrisette") == 0 && strcmp(line, "Morissette") == 0) score += 100;
  if (strcmp(miss, "Mythraic") == 0 && strcmp(line, "Mithraic") == 0) score += 100;
  if (strcmp(miss, "Naploeon") == 0 && strcmp(line, "Napoleon") == 0) score += 100;
  if (strcmp(miss, "Napolean") == 0 && strcmp(line, "Napoleon") == 0) score += 100;
  if (strcmp(miss, "Napoleonian") == 0 && strcmp(line, "Napoleonic") == 0) score += 100;
  if (strcmp(miss, "Nazereth") == 0 && strcmp(line, "Nazareth") == 0) score += 100;
  if (strcmp(miss, "Novermber") == 0 && strcmp(line, "November") == 0) score += 100;
  if (strcmp(miss, "Nullabour") == 0 && strcmp(line, "Nullarbor") == 0) score += 100;
  if (strcmp(miss, "Nuremburg") == 0 && strcmp(line, "Nuremberg") == 0) score += 100;
  if (strcmp(miss, "Palistian") == 0 && strcmp(line, "Palestinian") == 0) score += 100;
  if (strcmp(miss, "Palistinian") == 0 && strcmp(line, "Palestinian") == 0) score += 100;
  if (strcmp(miss, "Palistinians") == 0 && strcmp(line, "Palestinians") == 0) score += 100;
  if (strcmp(miss, "Papanicalou") == 0 && strcmp(line, "Papanicolaou") == 0) score += 100;
  if (strcmp(miss, "Peloponnes") == 0 && strcmp(line, "Peloponnesus") == 0) score += 100;
  if (strcmp(miss, "Pennyslvania") == 0 && strcmp(line, "Pennsylvania") == 0) score += 100;
  if (strcmp(miss, "Pharoah") == 0 && strcmp(line, "Pharaoh") == 0) score += 100;
  if (strcmp(miss, "Philipines") == 0 && strcmp(line, "Philippines") == 0) score += 100;
  if (strcmp(miss, "Phillipine") == 0 && strcmp(line, "Philippine") == 0) score += 100;
  if (strcmp(miss, "Phillipines") == 0 && strcmp(line, "Philippines") == 0) score += 100;
  if (strcmp(miss, "Phillippines") == 0 && strcmp(line, "Philippines") == 0) score += 100;
  if (strcmp(miss, "Phonecian") == 0 && strcmp(line, "Phoenecian") == 0) score += 100;
  if (strcmp(miss, "Portugese") == 0 && strcmp(line, "Portuguese") == 0) score += 100;
  if (strcmp(miss, "Postdam") == 0 && strcmp(line, "Potsdam") == 0) score += 100;
  if (strcmp(miss, "Premonasterians") == 0 && strcmp(line, "Premonstratensians") == 0) score += 100;
  if (strcmp(miss, "Pucini") == 0 && strcmp(line, "Puccini") == 0) score += 100;
  if (strcmp(miss, "Puertorrican") == 0 && strcmp(line, "Puerto Rican") == 0) score += 100;
  if (strcmp(miss, "Puertorricans") == 0 && strcmp(line, "Puerto Ricans") == 0) score += 100;
  if (strcmp(miss, "Queenland") == 0 && strcmp(line, "Queensland") == 0) score += 100;
  if (strcmp(miss, "Rockerfeller") == 0 && strcmp(line, "Rockefeller") == 0) score += 100;
  if (strcmp(miss, "Russion") == 0 && strcmp(line, "Russian") == 0) score += 100;
  if (strcmp(miss, "Sacremento") == 0 && strcmp(line, "Sacramento") == 0) score += 100;
  if (strcmp(miss, "Sanhedrim") == 0 && strcmp(line, "Sanhedrin") == 0) score += 100;
  if (strcmp(miss, "Saterday") == 0 && strcmp(line, "Saturday") == 0) score += 100;
  if (strcmp(miss, "Saterdays") == 0 && strcmp(line, "Saturdays") == 0) score += 100;
  if (strcmp(miss, "Sionist") == 0 && strcmp(line, "Zionist") == 0) score += 100;
  if (strcmp(miss, "Sionists") == 0 && strcmp(line, "Zionists") == 0) score += 100;
  if (strcmp(miss, "Sixtin") == 0 && strcmp(line, "Sistine") == 0) score += 100;
  if (strcmp(miss, "Skagerak") == 0 && strcmp(line, "Skagerrak") == 0) score += 100;
  if (strcmp(miss, "Tolkein") == 0 && strcmp(line, "Tolkien") == 0) score += 100;
  if (strcmp(miss, "Tuscon") == 0 && strcmp(line, "Tucson") == 0) score += 100;
  if (strcmp(miss, "Ukranian") == 0 && strcmp(line, "Ukrainian") == 0) score += 100;
  if (strcmp(miss, "UnitesStates") == 0 && strcmp(line, "UnitedStates") == 0) score += 100;
  if (strcmp(miss, "Yementite") == 0 && strcmp(line, "Yemenite, Yemeni") == 0) score += 100;
  if (strcmp(miss, "almsot") == 0 && strcmp(line, "almost") == 0) score += 100;
  if (strcmp(miss, "alos") == 0 && strcmp(line, "also") == 0) score += 100;
  if (strcmp(miss, "alot") == 0 && strcmp(line, "a lot, allot") == 0) score += 100;
  if (strcmp(miss, "alreayd") == 0 && strcmp(line, "already") == 0) score += 100;
  if (strcmp(miss, "alse") == 0 && strcmp(line, "else") == 0) score += 100;
  if (strcmp(miss, "alsot") == 0 && strcmp(line, "also") == 0) score += 100;
  if (strcmp(miss, "altho") == 0 && strcmp(line, "although") == 0) score += 100;
  if (strcmp(miss, "althought") == 0 && strcmp(line, "although") == 0) score += 100;
  if (strcmp(miss, "alusion") == 0 && strcmp(line, "allusion, illusion") == 0) score += 100;
  if (strcmp(miss, "alwasy") == 0 && strcmp(line, "always") == 0) score += 100;
  if (strcmp(miss, "alwyas") == 0 && strcmp(line, "always") == 0) score += 100;
  if (strcmp(miss, "amature") == 0 && strcmp(line, "armature, amateur") == 0) score += 100;
  if (strcmp(miss, "amercia") == 0 && strcmp(line, "america") == 0) score += 100;
  if (strcmp(miss, "amke") == 0 && strcmp(line, "make") == 0) score += 100;
  if (strcmp(miss, "amking") == 0 && strcmp(line, "making") == 0) score += 100;
  if (strcmp(miss, "analagous") == 0 && strcmp(line, "analogous") == 0) score += 100;
  if (strcmp(miss, "analitic") == 0 && strcmp(line, "analytic") == 0) score += 100;
  if (strcmp(miss, "anarchistm") == 0 && strcmp(line, "anarchism") == 0) score += 100;
  if (strcmp(miss, "anbd") == 0 && strcmp(line, "and") == 0) score += 100;
  if (strcmp(miss, "ancestory") == 0 && strcmp(line, "ancestry") == 0) score += 100;
  if (strcmp(miss, "andd") == 0 && strcmp(line, "and") == 0) score += 100;
  if (strcmp(miss, "annointed") == 0 && strcmp(line, "anointed") == 0) score += 100;
  if (strcmp(miss, "annointing") == 0 && strcmp(line, "anointing") == 0) score += 100;
  if (strcmp(miss, "anohter") == 0 && strcmp(line, "another") == 0) score += 100;
  if (strcmp(miss, "anomoly") == 0 && strcmp(line, "anomaly") == 0) score += 100;
  if (strcmp(miss, "ansalisation") == 0 && strcmp(line, "nasalisation") == 0) score += 100;
  if (strcmp(miss, "ansalization") == 0 && strcmp(line, "nasalization") == 0) score += 100;
  if (strcmp(miss, "ansestors") == 0 && strcmp(line, "ancestors") == 0) score += 100;
  if (strcmp(miss, "anthromorphization") == 0 && strcmp(line, "anthropomorphization") == 0) score += 100;
  if (strcmp(miss, "anwsered") == 0 && strcmp(line, "answered") == 0) score += 100;
  if (strcmp(miss, "anyother") == 0 && strcmp(line, "any other") == 0) score += 100;
  if (strcmp(miss, "apenines") == 0 && strcmp(line, "apennines, apennines") == 0) score += 100;
  if (strcmp(miss, "apon") == 0 && strcmp(line, "upon, apron") == 0) score += 100;
  if (strcmp(miss, "appartment") == 0 && strcmp(line, "apartment") == 0) score += 100;
  if (strcmp(miss, "appartments") == 0 && strcmp(line, "apartments") == 0) score += 100;
  if (strcmp(miss, "appealling") == 0 && strcmp(line, "appealing, appalling") == 0) score += 100;
  if (strcmp(miss, "appenines") == 0 && strcmp(line, "apennines, apennines") == 0) score += 100;
  if (strcmp(miss, "appereances") == 0 && strcmp(line, "appearances") == 0) score += 100;
  if (strcmp(miss, "appologies") == 0 && strcmp(line, "apologies") == 0) score += 100;
  if (strcmp(miss, "approachs") == 0 && strcmp(line, "approaches") == 0) score += 100;
  if (strcmp(miss, "approproximate") == 0 && strcmp(line, "approximate") == 0) score += 100;
  if (strcmp(miss, "approxamately") == 0 && strcmp(line, "approximately") == 0) score += 100;
  if (strcmp(miss, "approximitely") == 0 && strcmp(line, "approximately") == 0) score += 100;
  if (strcmp(miss, "aquainted") == 0 && strcmp(line, "acquainted") == 0) score += 100;
  if (strcmp(miss, "aquire") == 0 && strcmp(line, "acquire") == 0) score += 100;
  if (strcmp(miss, "aquitted") == 0 && strcmp(line, "acquitted") == 0) score += 100;
  if (strcmp(miss, "archaoelogy") == 0 && strcmp(line, "archeology, archaeology") == 0) score += 100;
  if (strcmp(miss, "archaology") == 0 && strcmp(line, "archeology, archaeology") == 0) score += 100;
  if (strcmp(miss, "archeaologist") == 0 && strcmp(line, "archeologist, archaeologist") == 0) score += 100;
  if (strcmp(miss, "archeaologists") == 0 && strcmp(line, "archeologists, archaeologists") == 0) score += 100;
  if (strcmp(miss, "archiac") == 0 && strcmp(line, "archaic") == 0) score += 100;
  if (strcmp(miss, "archimedian") == 0 && strcmp(line, "archimedean") == 0) score += 100;
  if (strcmp(miss, "arised") == 0 && strcmp(line, "arose") == 0) score += 100;
  if (strcmp(miss, "armamant") == 0 && strcmp(line, "armament") == 0) score += 100;
  if (strcmp(miss, "arogent") == 0 && strcmp(line, "arrogant") == 0) score += 100;
  if (strcmp(miss, "aroud") == 0 && strcmp(line, "around") == 0) score += 100;
  if (strcmp(miss, "arrengement") == 0 && strcmp(line, "arrangement") == 0) score += 100;
  if (strcmp(miss, "arrengements") == 0 && strcmp(line, "arrangements") == 0) score += 100;
  if (strcmp(miss, "artical") == 0 && strcmp(line, "article") == 0) score += 100;
  if (strcmp(miss, "artice") == 0 && strcmp(line, "article") == 0) score += 100;
  if (strcmp(miss, "articel") == 0 && strcmp(line, "article") == 0) score += 100;
  if (strcmp(miss, "asetic") == 0 && strcmp(line, "ascetic") == 0) score += 100;
  if (strcmp(miss, "asfar") == 0 && strcmp(line, "as far") == 0) score += 100;
  if (strcmp(miss, "aslo") == 0 && strcmp(line, "also") == 0) score += 100;
  if (strcmp(miss, "asorbed") == 0 && strcmp(line, "absorbed") == 0) score += 100;
  if (strcmp(miss, "assasined") == 0 && strcmp(line, "assassinated") == 0) score += 100;
  if (strcmp(miss, "assemple") == 0 && strcmp(line, "assemble") == 0) score += 100;
  if (strcmp(miss, "assertation") == 0 && strcmp(line, "assertion") == 0) score += 100;
  if (strcmp(miss, "asside") == 0 && strcmp(line, "aside") == 0) score += 100;
  if (strcmp(miss, "assisnate") == 0 && strcmp(line, "assassinate") == 0) score += 100;
  if (strcmp(miss, "assit") == 0 && strcmp(line, "assist") == 0) score += 100;
  if (strcmp(miss, "assymetric") == 0 && strcmp(line, "asymmetric") == 0) score += 100;
  if (strcmp(miss, "asteriod") == 0 && strcmp(line, "asteroid") == 0) score += 100;
  if (strcmp(miss, "asthetic") == 0 && strcmp(line, "aesthetic") == 0) score += 100;
  if (strcmp(miss, "asthetical") == 0 && strcmp(line, "aesthetical") == 0) score += 100;
  if (strcmp(miss, "asthetically") == 0 && strcmp(line, "aesthetically") == 0) score += 100;
  if (strcmp(miss, "aswell") == 0 && strcmp(line, "as well") == 0) score += 100;
  if (strcmp(miss, "atheistical") == 0 && strcmp(line, "atheistic") == 0) score += 100;
  if (strcmp(miss, "athenean") == 0 && strcmp(line, "athenian") == 0) score += 100;
  if (strcmp(miss, "atheneans") == 0 && strcmp(line, "athenians") == 0) score += 100;
  if (strcmp(miss, "athiest") == 0 && strcmp(line, "atheist") == 0) score += 100;
  if (strcmp(miss, "attaindre") == 0 && strcmp(line, "attainder, attained") == 0) score += 100;
  if (strcmp(miss, "attemp") == 0 && strcmp(line, "attempt") == 0) score += 100;
  if (strcmp(miss, "attemt") == 0 && strcmp(line, "attempt") == 0) score += 100;
  if (strcmp(miss, "attendent") == 0 && strcmp(line, "attendant") == 0) score += 100;
  if (strcmp(miss, "attendents") == 0 && strcmp(line, "attendants") == 0) score += 100;
  if (strcmp(miss, "attened") == 0 && strcmp(line, "attended") == 0) score += 100;
  if (strcmp(miss, "attitide") == 0 && strcmp(line, "attitude") == 0) score += 100;
  if (strcmp(miss, "attributred") == 0 && strcmp(line, "attributed") == 0) score += 100;
  if (strcmp(miss, "austrailia") == 0 && strcmp(line, "australia") == 0) score += 100;
  if (strcmp(miss, "austrailian") == 0 && strcmp(line, "australian") == 0) score += 100;
  if (strcmp(miss, "auther") == 0 && strcmp(line, "author") == 0) score += 100;
  if (strcmp(miss, "authorative") == 0 && strcmp(line, "authoritative") == 0) score += 100;
  if (strcmp(miss, "authorites") == 0 && strcmp(line, "authorities") == 0) score += 100;
  if (strcmp(miss, "authorithy") == 0 && strcmp(line, "authority") == 0) score += 100;
  if (strcmp(miss, "authoritiers") == 0 && strcmp(line, "authorities") == 0) score += 100;
  if (strcmp(miss, "authoritive") == 0 && strcmp(line, "authoritative") == 0) score += 100;
  if (strcmp(miss, "autoctonous") == 0 && strcmp(line, "autochthonous") == 0) score += 100;
  if (strcmp(miss, "automaticly") == 0 && strcmp(line, "automatically") == 0) score += 100;
  if (strcmp(miss, "automonomous") == 0 && strcmp(line, "autonomous") == 0) score += 100;
  if (strcmp(miss, "availabe") == 0 && strcmp(line, "available") == 0) score += 100;
  if (strcmp(miss, "avalance") == 0 && strcmp(line, "avalanche") == 0) score += 100;
  if (strcmp(miss, "avengence") == 0 && strcmp(line, "a vengeance") == 0) score += 100;
  if (strcmp(miss, "awared") == 0 && strcmp(line, "awarded") == 0) score += 100;
  if (strcmp(miss, "awya") == 0 && strcmp(line, "away") == 0) score += 100;
  if (strcmp(miss, "baceause") == 0 && strcmp(line, "because") == 0) score += 100;
  if (strcmp(miss, "bakc") == 0 && strcmp(line, "back") == 0) score += 100;
  if (strcmp(miss, "banannas") == 0 && strcmp(line, "bananas") == 0) score += 100;
  if (strcmp(miss, "baout") == 0 && strcmp(line, "about, bout") == 0) score += 100;
  if (strcmp(miss, "bcak") == 0 && strcmp(line, "back") == 0) score += 100;
  if (strcmp(miss, "beaurocracy") == 0 && strcmp(line, "bureaucracy") == 0) score += 100;
  if (strcmp(miss, "beaurocratic") == 0 && strcmp(line, "bureaucratic") == 0) score += 100;
  if (strcmp(miss, "becamae") == 0 && strcmp(line, "became") == 0) score += 100;
  if (strcmp(miss, "becames") == 0 && strcmp(line, "becomes, became") == 0) score += 100;
  if (strcmp(miss, "becasue") == 0 && strcmp(line, "because") == 0) score += 100;
  if (strcmp(miss, "becomeing") == 0 && strcmp(line, "becoming") == 0) score += 100;
  if (strcmp(miss, "bedore") == 0 && strcmp(line, "before") == 0) score += 100;
  if (strcmp(miss, "beeing") == 0 && strcmp(line, "being") == 0) score += 100;
  if (strcmp(miss, "befoer") == 0 && strcmp(line, "before") == 0) score += 100;
  if (strcmp(miss, "beggin") == 0 && strcmp(line, "begin, begging") == 0) score += 100;
  if (strcmp(miss, "behavour") == 0 && strcmp(line, "behavior, behaviour") == 0) score += 100;
  if (strcmp(miss, "beleive") == 0 && strcmp(line, "believe") == 0) score += 100;
  if (strcmp(miss, "beligum") == 0 && strcmp(line, "belgium") == 0) score += 100;
  if (strcmp(miss, "belive") == 0 && strcmp(line, "believe") == 0) score += 100;
  if (strcmp(miss, "belived") == 0 && strcmp(line, "believed, beloved") == 0) score += 100;
  if (strcmp(miss, "belives") == 0 && strcmp(line, "believes, beliefs") == 0) score += 100;
  if (strcmp(miss, "bergamont") == 0 && strcmp(line, "bergamot") == 0) score += 100;
  if (strcmp(miss, "bernouilli") == 0 && strcmp(line, "bernoulli") == 0) score += 100;
  if (strcmp(miss, "bigining") == 0 && strcmp(line, "beginning") == 0) score += 100;
  if (strcmp(miss, "biginning") == 0 && strcmp(line, "beginning") == 0) score += 100;
  if (strcmp(miss, "binominal") == 0 && strcmp(line, "binomial") == 0) score += 100;
  if (strcmp(miss, "blaim") == 0 && strcmp(line, "blame") == 0) score += 100;
  if (strcmp(miss, "blessure") == 0 && strcmp(line, "blessing") == 0) score += 100;
  if (strcmp(miss, "blitzkreig") == 0 && strcmp(line, "blitzkrieg") == 0) score += 100;
  if (strcmp(miss, "boaut") == 0 && strcmp(line, "bout, boat, about") == 0) score += 100;
  if (strcmp(miss, "bonnano") == 0 && strcmp(line, "bonanno") == 0) score += 100;
  if (strcmp(miss, "borke") == 0 && strcmp(line, "broke") == 0) score += 100;
  if (strcmp(miss, "bouyancy") == 0 && strcmp(line, "buoyancy") == 0) score += 100;
  if (strcmp(miss, "bouyant") == 0 && strcmp(line, "buoyant") == 0) score += 100;
  if (strcmp(miss, "brasillian") == 0 && strcmp(line, "brazilian") == 0) score += 100;
  if (strcmp(miss, "breif") == 0 && strcmp(line, "brief") == 0) score += 100;
  if (strcmp(miss, "britian") == 0 && strcmp(line, "britain") == 0) score += 100;
  if (strcmp(miss, "brittish") == 0 && strcmp(line, "british") == 0) score += 100;
  if (strcmp(miss, "broacasted") == 0 && strcmp(line, "broadcast") == 0) score += 100;
  if (strcmp(miss, "broady") == 0 && strcmp(line, "broadly") == 0) score += 100;
  if (strcmp(miss, "buddah") == 0 && strcmp(line, "buddha") == 0) score += 100;
  if (strcmp(miss, "buddist") == 0 && strcmp(line, "buddhist") == 0) score += 100;
  if (strcmp(miss, "buring") == 0 && strcmp(line, "burying, burning, burin, during") == 0) score += 100;
  if (strcmp(miss, "busines") == 0 && strcmp(line, "business") == 0) score += 100;
  if (strcmp(miss, "busineses") == 0 && strcmp(line, "business, businesses") == 0) score += 100;
  if (strcmp(miss, "busness") == 0 && strcmp(line, "business") == 0) score += 100;
  if (strcmp(miss, "bussiness") == 0 && strcmp(line, "business") == 0) score += 100;
  if (strcmp(miss, "caculater") == 0 && strcmp(line, "calculator") == 0) score += 100;
  if (strcmp(miss, "cacuses") == 0 && strcmp(line, "caucuses") == 0) score += 100;
  if (strcmp(miss, "cahracters") == 0 && strcmp(line, "characters") == 0) score += 100;
  if (strcmp(miss, "calander") == 0 && strcmp(line, "calendar, calender, colander") == 0) score += 100;
  if (strcmp(miss, "calculater") == 0 && strcmp(line, "calculator") == 0) score += 100;
  if (strcmp(miss, "calculs") == 0 && strcmp(line, "calculus") == 0) score += 100;
  if (strcmp(miss, "calenders") == 0 && strcmp(line, "calendars") == 0) score += 100;
  if (strcmp(miss, "calulater") == 0 && strcmp(line, "calculator") == 0) score += 100;
  if (strcmp(miss, "cambrige") == 0 && strcmp(line, "cambridge") == 0) score += 100;
  if (strcmp(miss, "campagin") == 0 && strcmp(line, "campaign") == 0) score += 100;
  if (strcmp(miss, "campain") == 0 && strcmp(line, "campaign") == 0) score += 100;
  if (strcmp(miss, "campains") == 0 && strcmp(line, "campaigns") == 0) score += 100;
  if (strcmp(miss, "cannister") == 0 && strcmp(line, "canister") == 0) score += 100;
  if (strcmp(miss, "cannisters") == 0 && strcmp(line, "canisters") == 0) score += 100;
  if (strcmp(miss, "cannotation") == 0 && strcmp(line, "connotation") == 0) score += 100;
  if (strcmp(miss, "cannotations") == 0 && strcmp(line, "connotations") == 0) score += 100;
  if (strcmp(miss, "caost") == 0 && strcmp(line, "coast") == 0) score += 100;
  if (strcmp(miss, "capetown") == 0 && strcmp(line, "cape town") == 0) score += 100;
  if (strcmp(miss, "captued") == 0 && strcmp(line, "captured") == 0) score += 100;
  if (strcmp(miss, "capturd") == 0 && strcmp(line, "captured") == 0) score += 100;
  if (strcmp(miss, "carachter") == 0 && strcmp(line, "character") == 0) score += 100;
  if (strcmp(miss, "caracterized") == 0 && strcmp(line, "characterized") == 0) score += 100;
  if (strcmp(miss, "carcas") == 0 && strcmp(line, "carcass, caracas") == 0) score += 100;
  if (strcmp(miss, "carefull") == 0 && strcmp(line, "careful") == 0) score += 100;
  if (strcmp(miss, "careing") == 0 && strcmp(line, "caring") == 0) score += 100;
  if (strcmp(miss, "carismatic") == 0 && strcmp(line, "charismatic") == 0) score += 100;
  if (strcmp(miss, "carmalite") == 0 && strcmp(line, "carmelite") == 0) score += 100;
  if (strcmp(miss, "carnagie") == 0 && strcmp(line, "carnegie") == 0) score += 100;
  if (strcmp(miss, "carnagie") == 0 && strcmp(line, "ellon->carnegie-mellon") == 0) score += 100;
  if (strcmp(miss, "carnege") == 0 && strcmp(line, "carnage, carnegie") == 0) score += 100;
  if (strcmp(miss, "carnige") == 0 && strcmp(line, "carnage, carnegie") == 0) score += 100;
  if (strcmp(miss, "carnigie") == 0 && strcmp(line, "carnegie") == 0) score += 100;
  if (strcmp(miss, "carnigie") == 0 && strcmp(line, "ellon->carnegie-mellon") == 0) score += 100;
  if (strcmp(miss, "carrers") == 0 && strcmp(line, "careers") == 0) score += 100;
  if (strcmp(miss, "carribbean") == 0 && strcmp(line, "caribbean") == 0) score += 100;
  if (strcmp(miss, "carribean") == 0 && strcmp(line, "caribbean") == 0) score += 100;
  if (strcmp(miss, "carthagian") == 0 && strcmp(line, "carthaginian") == 0) score += 100;
  if (strcmp(miss, "cartilidge") == 0 && strcmp(line, "cartilage") == 0) score += 100;
  if (strcmp(miss, "cartrige") == 0 && strcmp(line, "cartridge") == 0) score += 100;
  if (strcmp(miss, "casion") == 0 && strcmp(line, "caisson") == 0) score += 100;
  if (strcmp(miss, "cassawory") == 0 && strcmp(line, "cassowary") == 0) score += 100;
  if (strcmp(miss, "casue") == 0 && strcmp(line, "cause") == 0) score += 100;
  if (strcmp(miss, "casued") == 0 && strcmp(line, "caused") == 0) score += 100;
  if (strcmp(miss, "casues") == 0 && strcmp(line, "causes") == 0) score += 100;
  if (strcmp(miss, "casuing") == 0 && strcmp(line, "causing") == 0) score += 100;
  if (strcmp(miss, "casulaty") == 0 && strcmp(line, "casualty") == 0) score += 100;
  if (strcmp(miss, "catagories") == 0 && strcmp(line, "categories") == 0) score += 100;
  if (strcmp(miss, "catagorized") == 0 && strcmp(line, "categorized") == 0) score += 100;
  if (strcmp(miss, "cataline") == 0 && strcmp(line, "catiline, catalina") == 0) score += 100;
  if (strcmp(miss, "catapillers") == 0 && strcmp(line, "caterpillars") == 0) score += 100;
  if (strcmp(miss, "catholocism") == 0 && strcmp(line, "catholicism") == 0) score += 100;
  if (strcmp(miss, "cattleship") == 0 && strcmp(line, "battleship") == 0) score += 100;
  if (strcmp(miss, "causalities") == 0 && strcmp(line, "casualties") == 0) score += 100;
  if (strcmp(miss, "ceasar") == 0 && strcmp(line, "caesar") == 0) score += 100;
  if (strcmp(miss, "celcius") == 0 && strcmp(line, "celsius") == 0) score += 100;
  if (strcmp(miss, "cellpading") == 0 && strcmp(line, "cellpadding") == 0) score += 100;
  if (strcmp(miss, "cementary") == 0 && strcmp(line, "cemetery") == 0) score += 100;
  if (strcmp(miss, "cemetarey") == 0 && strcmp(line, "cemetery") == 0) score += 100;
  if (strcmp(miss, "cencus") == 0 && strcmp(line, "census") == 0) score += 100;
  if (strcmp(miss, "censur") == 0 && strcmp(line, "censor, censure") == 0) score += 100;
  if (strcmp(miss, "centuties") == 0 && strcmp(line, "centuries") == 0) score += 100;
  if (strcmp(miss, "centuty") == 0 && strcmp(line, "century") == 0) score += 100;
  if (strcmp(miss, "ceratin") == 0 && strcmp(line, "certain, keratin") == 0) score += 100;
  if (strcmp(miss, "cerimonies") == 0 && strcmp(line, "ceremonies") == 0) score += 100;
  if (strcmp(miss, "cerimonious") == 0 && strcmp(line, "ceremonious") == 0) score += 100;
  if (strcmp(miss, "certian") == 0 && strcmp(line, "certain") == 0) score += 100;
  if (strcmp(miss, "cervial") == 0 && strcmp(line, "cervical, servile, serval") == 0) score += 100;
  if (strcmp(miss, "champange") == 0 && strcmp(line, "champagne") == 0) score += 100;
  if (strcmp(miss, "charactor") == 0 && strcmp(line, "character") == 0) score += 100;
  if (strcmp(miss, "charactors") == 0 && strcmp(line, "characters") == 0) score += 100;
  if (strcmp(miss, "charistics") == 0 && strcmp(line, "characteristics") == 0) score += 100;
  if (strcmp(miss, "chasr") == 0 && strcmp(line, "chaser, chase") == 0) score += 100;
  if (strcmp(miss, "cheif") == 0 && strcmp(line, "chief") == 0) score += 100;
  if (strcmp(miss, "cheifs") == 0 && strcmp(line, "chiefs") == 0) score += 100;
  if (strcmp(miss, "childbird") == 0 && strcmp(line, "childbirth") == 0) score += 100;
  if (strcmp(miss, "childen") == 0 && strcmp(line, "children") == 0) score += 100;
  if (strcmp(miss, "choclate") == 0 && strcmp(line, "chocolate") == 0) score += 100;
  if (strcmp(miss, "chracter") == 0 && strcmp(line, "character") == 0) score += 100;
  if (strcmp(miss, "churchs") == 0 && strcmp(line, "churches") == 0) score += 100;
  if (strcmp(miss, "cincinatti") == 0 && strcmp(line, "cincinnati") == 0) score += 100;
  if (strcmp(miss, "cincinnatti") == 0 && strcmp(line, "cincinnati") == 0) score += 100;
  if (strcmp(miss, "circumsicion") == 0 && strcmp(line, "circumcision") == 0) score += 100;
  if (strcmp(miss, "circut") == 0 && strcmp(line, "circuit") == 0) score += 100;
  if (strcmp(miss, "claer") == 0 && strcmp(line, "clear") == 0) score += 100;
  if (strcmp(miss, "claerer") == 0 && strcmp(line, "clearer") == 0) score += 100;
  if (strcmp(miss, "claimes") == 0 && strcmp(line, "claims") == 0) score += 100;
  if (strcmp(miss, "clas") == 0 && strcmp(line, "class") == 0) score += 100;
  if (strcmp(miss, "clera") == 0 && strcmp(line, "clear, sclera") == 0) score += 100;
  if (strcmp(miss, "cmo") == 0 && strcmp(line, "com") == 0) score += 100;
  if (strcmp(miss, "cmoputer") == 0 && strcmp(line, "computer") == 0) score += 100;
  if (strcmp(miss, "cognizent") == 0 && strcmp(line, "cognizant") == 0) score += 100;
  if (strcmp(miss, "collonies") == 0 && strcmp(line, "colonies") == 0) score += 100;
  if (strcmp(miss, "colonizators") == 0 && strcmp(line, "colonizers") == 0) score += 100;
  if (strcmp(miss, "comander") == 0 && strcmp(line, "commander, commandeer") == 0) score += 100;
  if (strcmp(miss, "combanations") == 0 && strcmp(line, "combinations") == 0) score += 100;
  if (strcmp(miss, "combusion") == 0 && strcmp(line, "combustion") == 0) score += 100;
  if (strcmp(miss, "comdemnation") == 0 && strcmp(line, "condemnation") == 0) score += 100;
  if (strcmp(miss, "comision") == 0 && strcmp(line, "commission") == 0) score += 100;
  if (strcmp(miss, "comisioned") == 0 && strcmp(line, "commissioned") == 0) score += 100;
  if (strcmp(miss, "comisioning") == 0 && strcmp(line, "commissioning") == 0) score += 100;
  if (strcmp(miss, "comisions") == 0 && strcmp(line, "commissions") == 0) score += 100;
  if (strcmp(miss, "comited") == 0 && strcmp(line, "committed") == 0) score += 100;
  if (strcmp(miss, "comiting") == 0 && strcmp(line, "committing") == 0) score += 100;
  if (strcmp(miss, "commandoes") == 0 && strcmp(line, "commandos") == 0) score += 100;
  if (strcmp(miss, "comminication") == 0 && strcmp(line, "communication") == 0) score += 100;
  if (strcmp(miss, "commongly") == 0 && strcmp(line, "commonly") == 0) score += 100;
  if (strcmp(miss, "communiation") == 0 && strcmp(line, "communication") == 0) score += 100;
  if (strcmp(miss, "communites") == 0 && strcmp(line, "communities") == 0) score += 100;
  if (strcmp(miss, "compability") == 0 && strcmp(line, "compatibility") == 0) score += 100;
  if (strcmp(miss, "comparision") == 0 && strcmp(line, "comparison") == 0) score += 100;
  if (strcmp(miss, "comparisions") == 0 && strcmp(line, "comparisons") == 0) score += 100;
  if (strcmp(miss, "comparitive") == 0 && strcmp(line, "comparative") == 0) score += 100;
  if (strcmp(miss, "compatabilities") == 0 && strcmp(line, "compatibilities") == 0) score += 100;
  if (strcmp(miss, "compatability") == 0 && strcmp(line, "compatibility") == 0) score += 100;
  if (strcmp(miss, "compatable") == 0 && strcmp(line, "compatible") == 0) score += 100;
  if (strcmp(miss, "competance") == 0 && strcmp(line, "competence") == 0) score += 100;
  if (strcmp(miss, "competant") == 0 && strcmp(line, "competent") == 0) score += 100;
  if (strcmp(miss, "competative") == 0 && strcmp(line, "competitive") == 0) score += 100;
  if (strcmp(miss, "competion") == 0 && strcmp(line, "competition, completion") == 0) score += 100;
  if (strcmp(miss, "competive") == 0 && strcmp(line, "competitive") == 0) score += 100;
  if (strcmp(miss, "competiveness") == 0 && strcmp(line, "competitiveness") == 0) score += 100;
  if (strcmp(miss, "compitent") == 0 && strcmp(line, "competent") == 0) score += 100;
  if (strcmp(miss, "completedthe") == 0 && strcmp(line, "completed the") == 0) score += 100;
  if (strcmp(miss, "completelyl") == 0 && strcmp(line, "completely") == 0) score += 100;
  if (strcmp(miss, "completetion") == 0 && strcmp(line, "completion") == 0) score += 100;
  if (strcmp(miss, "complier") == 0 && strcmp(line, "compiler") == 0) score += 100;
  if (strcmp(miss, "componant") == 0 && strcmp(line, "component") == 0) score += 100;
  if (strcmp(miss, "comprimise") == 0 && strcmp(line, "compromise") == 0) score += 100;
  if (strcmp(miss, "compulsary") == 0 && strcmp(line, "compulsory") == 0) score += 100;
  if (strcmp(miss, "compulsery") == 0 && strcmp(line, "compulsory") == 0) score += 100;
  if (strcmp(miss, "concider") == 0 && strcmp(line, "consider") == 0) score += 100;
  if (strcmp(miss, "concidered") == 0 && strcmp(line, "considered") == 0) score += 100;
  if (strcmp(miss, "concidering") == 0 && strcmp(line, "considering") == 0) score += 100;
  if (strcmp(miss, "conciders") == 0 && strcmp(line, "considers") == 0) score += 100;
  if (strcmp(miss, "condemmed") == 0 && strcmp(line, "condemned") == 0) score += 100;
  if (strcmp(miss, "condidtion") == 0 && strcmp(line, "condition") == 0) score += 100;
  if (strcmp(miss, "condidtions") == 0 && strcmp(line, "conditions") == 0) score += 100;
  if (strcmp(miss, "conditionsof") == 0 && strcmp(line, "conditions of") == 0) score += 100;
  if (strcmp(miss, "confidental") == 0 && strcmp(line, "confidential") == 0) score += 100;
  if (strcmp(miss, "confids") == 0 && strcmp(line, "confides") == 0) score += 100;
  if (strcmp(miss, "configureable") == 0 && strcmp(line, "configurable") == 0) score += 100;
  if (strcmp(miss, "confortable") == 0 && strcmp(line, "comfortable") == 0) score += 100;
  if (strcmp(miss, "conneticut") == 0 && strcmp(line, "connecticut") == 0) score += 100;
  if (strcmp(miss, "conquerd") == 0 && strcmp(line, "conquered") == 0) score += 100;
  if (strcmp(miss, "conquerer") == 0 && strcmp(line, "conqueror") == 0) score += 100;
  if (strcmp(miss, "conquerers") == 0 && strcmp(line, "conquerors") == 0) score += 100;
  if (strcmp(miss, "conscent") == 0 && strcmp(line, "consent") == 0) score += 100;
  if (strcmp(miss, "consdider") == 0 && strcmp(line, "consider") == 0) score += 100;
  if (strcmp(miss, "consentrate") == 0 && strcmp(line, "concentrate") == 0) score += 100;
  if (strcmp(miss, "consentrated") == 0 && strcmp(line, "concentrated") == 0) score += 100;
  if (strcmp(miss, "consentrates") == 0 && strcmp(line, "concentrates") == 0) score += 100;
  if (strcmp(miss, "consequentually") == 0 && strcmp(line, "consequently") == 0) score += 100;
  if (strcmp(miss, "conserning") == 0 && strcmp(line, "concerning") == 0) score += 100;
  if (strcmp(miss, "consiciousness") == 0 && strcmp(line, "consciousness") == 0) score += 100;
  if (strcmp(miss, "considerd") == 0 && strcmp(line, "considered") == 0) score += 100;
  if (strcmp(miss, "consideres") == 0 && strcmp(line, "considered") == 0) score += 100;
  if (strcmp(miss, "consistant") == 0 && strcmp(line, "consistent") == 0) score += 100;
  if (strcmp(miss, "consistantly") == 0 && strcmp(line, "consistently") == 0) score += 100;
  if (strcmp(miss, "consolodate") == 0 && strcmp(line, "consolidate") == 0) score += 100;
  if (strcmp(miss, "consolodated") == 0 && strcmp(line, "consolidated") == 0) score += 100;
  if (strcmp(miss, "consonent") == 0 && strcmp(line, "consonant") == 0) score += 100;
  if (strcmp(miss, "consonents") == 0 && strcmp(line, "consonants") == 0) score += 100;
  if (strcmp(miss, "consorcium") == 0 && strcmp(line, "consortium") == 0) score += 100;
  if (strcmp(miss, "conspiracys") == 0 && strcmp(line, "conspiracies") == 0) score += 100;
  if (strcmp(miss, "constanly") == 0 && strcmp(line, "constantly") == 0) score += 100;
  if (strcmp(miss, "constarnation") == 0 && strcmp(line, "consternation") == 0) score += 100;
  if (strcmp(miss, "constatn") == 0 && strcmp(line, "constant") == 0) score += 100;
  if (strcmp(miss, "constinually") == 0 && strcmp(line, "continually") == 0) score += 100;
  if (strcmp(miss, "constituant") == 0 && strcmp(line, "constituent") == 0) score += 100;
  if (strcmp(miss, "constituants") == 0 && strcmp(line, "constituents") == 0) score += 100;
  if (strcmp(miss, "constituion") == 0 && strcmp(line, "constitution") == 0) score += 100;
  if (strcmp(miss, "containes") == 0 && strcmp(line, "contains") == 0) score += 100;
  if (strcmp(miss, "contamporaries") == 0 && strcmp(line, "contemporaries") == 0) score += 100;
  if (strcmp(miss, "contempory") == 0 && strcmp(line, "contemporary") == 0) score += 100;
  if (strcmp(miss, "contendor") == 0 && strcmp(line, "contender") == 0) score += 100;
  if (strcmp(miss, "contian") == 0 && strcmp(line, "contain") == 0) score += 100;
  if (strcmp(miss, "contians") == 0 && strcmp(line, "contains") == 0) score += 100;
  if (strcmp(miss, "contibute") == 0 && strcmp(line, "contribute") == 0) score += 100;
  if (strcmp(miss, "contibuted") == 0 && strcmp(line, "contributed") == 0) score += 100;
  if (strcmp(miss, "contibutes") == 0 && strcmp(line, "contributes") == 0) score += 100;
  if (strcmp(miss, "contined") == 0 && strcmp(line, "continued") == 0) score += 100;
  if (strcmp(miss, "continential") == 0 && strcmp(line, "continental") == 0) score += 100;
  if (strcmp(miss, "continueing") == 0 && strcmp(line, "continuing") == 0) score += 100;
  if (strcmp(miss, "contravercial") == 0 && strcmp(line, "controversial") == 0) score += 100;
  if (strcmp(miss, "contributer") == 0 && strcmp(line, "contributor") == 0) score += 100;
  if (strcmp(miss, "contributers") == 0 && strcmp(line, "contributors") == 0) score += 100;
  if (strcmp(miss, "contritutions") == 0 && strcmp(line, "contributions") == 0) score += 100;
  if (strcmp(miss, "controll") == 0 && strcmp(line, "control") == 0) score += 100;
  if (strcmp(miss, "controlls") == 0 && strcmp(line, "controls") == 0) score += 100;
  if (strcmp(miss, "controvercy") == 0 && strcmp(line, "controversy") == 0) score += 100;
  if (strcmp(miss, "controversey") == 0 && strcmp(line, "controversy") == 0) score += 100;
  if (strcmp(miss, "controvertial") == 0 && strcmp(line, "controversial") == 0) score += 100;
  if (strcmp(miss, "controvery") == 0 && strcmp(line, "controversy") == 0) score += 100;
  if (strcmp(miss, "conveinent") == 0 && strcmp(line, "convenient") == 0) score += 100;
  if (strcmp(miss, "convenant") == 0 && strcmp(line, "covenant") == 0) score += 100;
  if (strcmp(miss, "convential") == 0 && strcmp(line, "conventional") == 0) score += 100;
  if (strcmp(miss, "convertion") == 0 && strcmp(line, "conversion") == 0) score += 100;
  if (strcmp(miss, "coorperation") == 0 && strcmp(line, "cooperation, corporation") == 0) score += 100;
  if (strcmp(miss, "coorperations") == 0 && strcmp(line, "corporations") == 0) score += 100;
  if (strcmp(miss, "copmetitors") == 0 && strcmp(line, "competitors") == 0) score += 100;
  if (strcmp(miss, "coputer") == 0 && strcmp(line, "computer") == 0) score += 100;
  if (strcmp(miss, "copywrite") == 0 && strcmp(line, "copyright") == 0) score += 100;
  if (strcmp(miss, "coridal") == 0 && strcmp(line, "cordial") == 0) score += 100;
  if (strcmp(miss, "cornmitted") == 0 && strcmp(line, "committed") == 0) score += 100;
  if (strcmp(miss, "corparate") == 0 && strcmp(line, "corporate") == 0) score += 100;
  if (strcmp(miss, "corperations") == 0 && strcmp(line, "corporations") == 0) score += 100;
  if (strcmp(miss, "correcters") == 0 && strcmp(line, "correctors") == 0) score += 100;
  if (strcmp(miss, "correspondant") == 0 && strcmp(line, "correspondent") == 0) score += 100;
  if (strcmp(miss, "correspondants") == 0 && strcmp(line, "correspondents") == 0) score += 100;
  if (strcmp(miss, "corrispondant") == 0 && strcmp(line, "correspondent") == 0) score += 100;
  if (strcmp(miss, "corrispondants") == 0 && strcmp(line, "correspondents") == 0) score += 100;
  if (strcmp(miss, "coudl") == 0 && strcmp(line, "could, cloud") == 0) score += 100;
  if (strcmp(miss, "councellor") == 0 && strcmp(line, "councillor, counselor, councilor") == 0) score += 100;
  if (strcmp(miss, "councellors") == 0 && strcmp(line, "councillors, counselors, councilors") == 0) score += 100;
  if (strcmp(miss, "countains") == 0 && strcmp(line, "contains") == 0) score += 100;
  if (strcmp(miss, "countires") == 0 && strcmp(line, "countries") == 0) score += 100;
  if (strcmp(miss, "coururier") == 0 && strcmp(line, "courier, couturier") == 0) score += 100;
  if (strcmp(miss, "coverted") == 0 && strcmp(line, "converted, covered, coveted") == 0) score += 100;
  if (strcmp(miss, "cpoy") == 0 && strcmp(line, "coy, copy") == 0) score += 100;
  if (strcmp(miss, "creche") == 0 && strcmp(line, "crèche") == 0) score += 100;
  if (strcmp(miss, "criterias") == 0 && strcmp(line, "criteria") == 0) score += 100;
  if (strcmp(miss, "criticists") == 0 && strcmp(line, "critics") == 0) score += 100;
  if (strcmp(miss, "critising") == 0 && strcmp(line, "criticising, criticizing") == 0) score += 100;
  if (strcmp(miss, "critisising") == 0 && strcmp(line, "criticising") == 0) score += 100;
  if (strcmp(miss, "critisize") == 0 && strcmp(line, "criticise, criticize") == 0) score += 100;
  if (strcmp(miss, "critisized") == 0 && strcmp(line, "criticised, criticized") == 0) score += 100;
  if (strcmp(miss, "critisizes") == 0 && strcmp(line, "criticises, criticizes") == 0) score += 100;
  if (strcmp(miss, "critisizing") == 0 && strcmp(line, "criticising, criticizing") == 0) score += 100;
  if (strcmp(miss, "critized") == 0 && strcmp(line, "criticized") == 0) score += 100;
  if (strcmp(miss, "critizing") == 0 && strcmp(line, "criticizing") == 0) score += 100;
  if (strcmp(miss, "crowm") == 0 && strcmp(line, "crown") == 0) score += 100;
  if (strcmp(miss, "crusies") == 0 && strcmp(line, "cruises") == 0) score += 100;
  if (strcmp(miss, "crystalisation") == 0 && strcmp(line, "crystallisation") == 0) score += 100;
  if (strcmp(miss, "cumulatative") == 0 && strcmp(line, "cumulative") == 0) score += 100;
  if (strcmp(miss, "curch") == 0 && strcmp(line, "church") == 0) score += 100;
  if (strcmp(miss, "curcuit") == 0 && strcmp(line, "circuit") == 0) score += 100;
  if (strcmp(miss, "cxan") == 0 && strcmp(line, "cyan") == 0) score += 100;
  if (strcmp(miss, "daed") == 0 && strcmp(line, "dead") == 0) score += 100;
  if (strcmp(miss, "dael") == 0 && strcmp(line, "deal, dial, dahl") == 0) score += 100;
  if (strcmp(miss, "dalmation") == 0 && strcmp(line, "dalmatian") == 0) score += 100;
  if (strcmp(miss, "dardenelles") == 0 && strcmp(line, "dardanelles") == 0) score += 100;
  if (strcmp(miss, "decendant") == 0 && strcmp(line, "descendant") == 0) score += 100;
  if (strcmp(miss, "decendants") == 0 && strcmp(line, "descendants") == 0) score += 100;
  if (strcmp(miss, "decendent") == 0 && strcmp(line, "descendant") == 0) score += 100;
  if (strcmp(miss, "decendents") == 0 && strcmp(line, "descendants") == 0) score += 100;
  if (strcmp(miss, "decomposit") == 0 && strcmp(line, "decompose") == 0) score += 100;
  if (strcmp(miss, "decomposited") == 0 && strcmp(line, "decomposed") == 0) score += 100;
  if (strcmp(miss, "decompositing") == 0 && strcmp(line, "decomposing") == 0) score += 100;
  if (strcmp(miss, "decomposits") == 0 && strcmp(line, "decomposes") == 0) score += 100;
  if (strcmp(miss, "decress") == 0 && strcmp(line, "decrees") == 0) score += 100;
  if (strcmp(miss, "decribing") == 0 && strcmp(line, "describing") == 0) score += 100;
  if (strcmp(miss, "defendent") == 0 && strcmp(line, "defendant") == 0) score += 100;
  if (strcmp(miss, "defendents") == 0 && strcmp(line, "defendants") == 0) score += 100;
  if (strcmp(miss, "definance") == 0 && strcmp(line, "defiance") == 0) score += 100;
  if (strcmp(miss, "definatly") == 0 && strcmp(line, "definitely") == 0) score += 100;
  if (strcmp(miss, "definetly") == 0 && strcmp(line, "definitely") == 0) score += 100;
  if (strcmp(miss, "definining") == 0 && strcmp(line, "defining") == 0) score += 100;
  if (strcmp(miss, "definit") == 0 && strcmp(line, "definite") == 0) score += 100;
  if (strcmp(miss, "definitly") == 0 && strcmp(line, "definitely") == 0) score += 100;
  if (strcmp(miss, "degrate") == 0 && strcmp(line, "degrade") == 0) score += 100;
  if (strcmp(miss, "delagates") == 0 && strcmp(line, "delegates") == 0) score += 100;
  if (strcmp(miss, "delapidated") == 0 && strcmp(line, "dilapidated") == 0) score += 100;
  if (strcmp(miss, "delevopment") == 0 && strcmp(line, "development") == 0) score += 100;
  if (strcmp(miss, "deliberatly") == 0 && strcmp(line, "deliberately") == 0) score += 100;
  if (strcmp(miss, "delusionally") == 0 && strcmp(line, "delusively") == 0) score += 100;
  if (strcmp(miss, "demographical") == 0 && strcmp(line, "demographic") == 0) score += 100;
  if (strcmp(miss, "demolision") == 0 && strcmp(line, "demolition") == 0) score += 100;
  if (strcmp(miss, "denegrating") == 0 && strcmp(line, "denigrating") == 0) score += 100;
  if (strcmp(miss, "dependance") == 0 && strcmp(line, "dependence") == 0) score += 100;
  if (strcmp(miss, "deram") == 0 && strcmp(line, "dram, dream") == 0) score += 100;
  if (strcmp(miss, "deriviated") == 0 && strcmp(line, "derived") == 0) score += 100;
  if (strcmp(miss, "descision") == 0 && strcmp(line, "decision") == 0) score += 100;
  if (strcmp(miss, "descisions") == 0 && strcmp(line, "decisions") == 0) score += 100;
  if (strcmp(miss, "descripters") == 0 && strcmp(line, "descriptors") == 0) score += 100;
  if (strcmp(miss, "deside") == 0 && strcmp(line, "decide") == 0) score += 100;
  if (strcmp(miss, "desigining") == 0 && strcmp(line, "designing") == 0) score += 100;
  if (strcmp(miss, "desintegrated") == 0 && strcmp(line, "disintegrated") == 0) score += 100;
  if (strcmp(miss, "desintegration") == 0 && strcmp(line, "disintegration") == 0) score += 100;
  if (strcmp(miss, "desorder") == 0 && strcmp(line, "disorder") == 0) score += 100;
  if (strcmp(miss, "desoriented") == 0 && strcmp(line, "disoriented") == 0) score += 100;
  if (strcmp(miss, "desparate") == 0 && strcmp(line, "desperate, disparate") == 0) score += 100;
  if (strcmp(miss, "despict") == 0 && strcmp(line, "depict") == 0) score += 100;
  if (strcmp(miss, "despiration") == 0 && strcmp(line, "desperation") == 0) score += 100;
  if (strcmp(miss, "dessicated") == 0 && strcmp(line, "desiccated") == 0) score += 100;
  if (strcmp(miss, "dessigned") == 0 && strcmp(line, "designed") == 0) score += 100;
  if (strcmp(miss, "destory") == 0 && strcmp(line, "destroy") == 0) score += 100;
  if (strcmp(miss, "detailled") == 0 && strcmp(line, "detailed") == 0) score += 100;
  if (strcmp(miss, "deteriate") == 0 && strcmp(line, "deteriorate") == 0) score += 100;
  if (strcmp(miss, "determinining") == 0 && strcmp(line, "determining") == 0) score += 100;
  if (strcmp(miss, "devasted") == 0 && strcmp(line, "devastated") == 0) score += 100;
  if (strcmp(miss, "develope") == 0 && strcmp(line, "develop") == 0) score += 100;
  if (strcmp(miss, "devels") == 0 && strcmp(line, "delves") == 0) score += 100;
  if (strcmp(miss, "devestating") == 0 && strcmp(line, "devastating") == 0) score += 100;
  if (strcmp(miss, "devide") == 0 && strcmp(line, "divide") == 0) score += 100;
  if (strcmp(miss, "devided") == 0 && strcmp(line, "divided") == 0) score += 100;
  if (strcmp(miss, "devistating") == 0 && strcmp(line, "devastating") == 0) score += 100;
  if (strcmp(miss, "diamons") == 0 && strcmp(line, "diamonds") == 0) score += 100;
  if (strcmp(miss, "diaster") == 0 && strcmp(line, "disaster") == 0) score += 100;
  if (strcmp(miss, "dicovered") == 0 && strcmp(line, "discovered") == 0) score += 100;
  if (strcmp(miss, "dicovering") == 0 && strcmp(line, "discovering") == 0) score += 100;
  if (strcmp(miss, "dicovers") == 0 && strcmp(line, "discovers") == 0) score += 100;
  if (strcmp(miss, "dictionarys") == 0 && strcmp(line, "dictionaries") == 0) score += 100;
  if (strcmp(miss, "diea") == 0 && strcmp(line, "idea, die") == 0) score += 100;
  if (strcmp(miss, "dieing") == 0 && strcmp(line, "dying, dyeing") == 0) score += 100;
  if (strcmp(miss, "dieties") == 0 && strcmp(line, "deities") == 0) score += 100;
  if (strcmp(miss, "diety") == 0 && strcmp(line, "deity") == 0) score += 100;
  if (strcmp(miss, "differentiatiations") == 0 && strcmp(line, "differentiations") == 0) score += 100;
  if (strcmp(miss, "difficulity") == 0 && strcmp(line, "difficulty") == 0) score += 100;
  if (strcmp(miss, "dimention") == 0 && strcmp(line, "dimension") == 0) score += 100;
  if (strcmp(miss, "dimentions") == 0 && strcmp(line, "dimensions") == 0) score += 100;
  if (strcmp(miss, "dirived") == 0 && strcmp(line, "derived") == 0) score += 100;
  if (strcmp(miss, "discontentment") == 0 && strcmp(line, "discontent") == 0) score += 100;
  if (strcmp(miss, "discribe") == 0 && strcmp(line, "describe") == 0) score += 100;
  if (strcmp(miss, "discribed") == 0 && strcmp(line, "described") == 0) score += 100;
  if (strcmp(miss, "discribes") == 0 && strcmp(line, "describes") == 0) score += 100;
  if (strcmp(miss, "discribing") == 0 && strcmp(line, "describing") == 0) score += 100;
  if (strcmp(miss, "disenchanged") == 0 && strcmp(line, "disenchanted") == 0) score += 100;
  if (strcmp(miss, "disobediant") == 0 && strcmp(line, "disobedient") == 0) score += 100;
  if (strcmp(miss, "disover") == 0 && strcmp(line, "discover") == 0) score += 100;
  if (strcmp(miss, "dispair") == 0 && strcmp(line, "despair") == 0) score += 100;
  if (strcmp(miss, "disparingly") == 0 && strcmp(line, "disparagingly") == 0) score += 100;
  if (strcmp(miss, "dispence") == 0 && strcmp(line, "dispense") == 0) score += 100;
  if (strcmp(miss, "dispenced") == 0 && strcmp(line, "dispensed") == 0) score += 100;
  if (strcmp(miss, "dispencing") == 0 && strcmp(line, "dispensing") == 0) score += 100;
  if (strcmp(miss, "dispicable") == 0 && strcmp(line, "despicable") == 0) score += 100;
  if (strcmp(miss, "dispite") == 0 && strcmp(line, "despite") == 0) score += 100;
  if (strcmp(miss, "disproportiate") == 0 && strcmp(line, "disproportionate") == 0) score += 100;
  if (strcmp(miss, "disputandem") == 0 && strcmp(line, "disputandum") == 0) score += 100;
  if (strcmp(miss, "dissapeared") == 0 && strcmp(line, "disappeared") == 0) score += 100;
  if (strcmp(miss, "dissobediant") == 0 && strcmp(line, "disobedient") == 0) score += 100;
  if (strcmp(miss, "distrubution") == 0 && strcmp(line, "distribution") == 0) score += 100;
  if (strcmp(miss, "distruction") == 0 && strcmp(line, "destruction") == 0) score += 100;
  if (strcmp(miss, "distructive") == 0 && strcmp(line, "destructive") == 0) score += 100;
  if (strcmp(miss, "diversed") == 0 && strcmp(line, "diverse, diverged") == 0) score += 100;
  if (strcmp(miss, "divice") == 0 && strcmp(line, "device") == 0) score += 100;
  if (strcmp(miss, "divison") == 0 && strcmp(line, "division") == 0) score += 100;
  if (strcmp(miss, "doens") == 0 && strcmp(line, "does") == 0) score += 100;
  if (strcmp(miss, "doign") == 0 && strcmp(line, "doing") == 0) score += 100;
  if (strcmp(miss, "dominent") == 0 && strcmp(line, "dominant") == 0) score += 100;
  if (strcmp(miss, "donig") == 0 && strcmp(line, "doing") == 0) score += 100;
  if (strcmp(miss, "doub") == 0 && strcmp(line, "doubt, daub") == 0) score += 100;
  if (strcmp(miss, "dreasm") == 0 && strcmp(line, "dreams") == 0) score += 100;
  if (strcmp(miss, "driectly") == 0 && strcmp(line, "directly") == 0) score += 100;
  if (strcmp(miss, "drummless") == 0 && strcmp(line, "drumless") == 0) score += 100;
  if (strcmp(miss, "dum") == 0 && strcmp(line, "dumb") == 0) score += 100;
  if (strcmp(miss, "durig") == 0 && strcmp(line, "during") == 0) score += 100;
  if (strcmp(miss, "duting") == 0 && strcmp(line, "during") == 0) score += 100;
  if (strcmp(miss, "dyas") == 0 && strcmp(line, "dryas") == 0) score += 100;
  if (strcmp(miss, "eahc") == 0 && strcmp(line, "each") == 0) score += 100;
  if (strcmp(miss, "earlies") == 0 && strcmp(line, "earliest") == 0) score += 100;
  if (strcmp(miss, "earnt") == 0 && strcmp(line, "earned") == 0) score += 100;
  if (strcmp(miss, "ecclectic") == 0 && strcmp(line, "eclectic") == 0) score += 100;
  if (strcmp(miss, "ecidious") == 0 && strcmp(line, "deciduous") == 0) score += 100;
  if (strcmp(miss, "eclispe") == 0 && strcmp(line, "eclipse") == 0) score += 100;
  if (strcmp(miss, "ecomonic") == 0 && strcmp(line, "economic") == 0) score += 100;
  if (strcmp(miss, "econoımic") == 0 && strcmp(line, "economic") == 0) score += 100;
  if (strcmp(miss, "ect") == 0 && strcmp(line, "etc") == 0) score += 100;
  if (strcmp(miss, "eearly") == 0 && strcmp(line, "early") == 0) score += 100;
  if (strcmp(miss, "efel") == 0 && strcmp(line, "evil") == 0) score += 100;
  if (strcmp(miss, "effeciently") == 0 && strcmp(line, "efficiently") == 0) score += 100;
  if (strcmp(miss, "efford") == 0 && strcmp(line, "effort, afford") == 0) score += 100;
  if (strcmp(miss, "effords") == 0 && strcmp(line, "efforts, affords") == 0) score += 100;
  if (strcmp(miss, "eigth") == 0 && strcmp(line, "eighth, eight") == 0) score += 100;
  if (strcmp(miss, "electic") == 0 && strcmp(line, "eclectic, electric") == 0) score += 100;
  if (strcmp(miss, "electon") == 0 && strcmp(line, "election, electron") == 0) score += 100;
  if (strcmp(miss, "electricly") == 0 && strcmp(line, "electrically") == 0) score += 100;
  if (strcmp(miss, "elementay") == 0 && strcmp(line, "elementary") == 0) score += 100;
  if (strcmp(miss, "eleminating") == 0 && strcmp(line, "eliminating") == 0) score += 100;
  if (strcmp(miss, "eles") == 0 && strcmp(line, "eels") == 0) score += 100;
  if (strcmp(miss, "elicided") == 0 && strcmp(line, "elicited") == 0) score += 100;
  if (strcmp(miss, "embargos") == 0 && strcmp(line, "embargoes") == 0) score += 100;
  if (strcmp(miss, "embarras") == 0 && strcmp(line, "embarrass") == 0) score += 100;
  if (strcmp(miss, "embezelled") == 0 && strcmp(line, "embezzled") == 0) score += 100;
  if (strcmp(miss, "eminate") == 0 && strcmp(line, "emanate") == 0) score += 100;
  if (strcmp(miss, "eminated") == 0 && strcmp(line, "emanated") == 0) score += 100;
  if (strcmp(miss, "emition") == 0 && strcmp(line, "emission, emotion") == 0) score += 100;
  if (strcmp(miss, "emmediately") == 0 && strcmp(line, "immediately") == 0) score += 100;
  if (strcmp(miss, "emmigrated") == 0 && strcmp(line, "emigrated, immigrated") == 0) score += 100;
  if (strcmp(miss, "emminent") == 0 && strcmp(line, "eminent, imminent") == 0) score += 100;
  if (strcmp(miss, "emmisions") == 0 && strcmp(line, "emissions") == 0) score += 100;
  if (strcmp(miss, "emmiting") == 0 && strcmp(line, "emitting") == 0) score += 100;
  if (strcmp(miss, "emmitting") == 0 && strcmp(line, "emitting") == 0) score += 100;
  if (strcmp(miss, "empirial") == 0 && strcmp(line, "empirical, imperial") == 0) score += 100;
  if (strcmp(miss, "emporer") == 0 && strcmp(line, "emperor") == 0) score += 100;
  if (strcmp(miss, "emprisoned") == 0 && strcmp(line, "imprisoned") == 0) score += 100;
  if (strcmp(miss, "enameld") == 0 && strcmp(line, "enameled") == 0) score += 100;
  if (strcmp(miss, "enchancement") == 0 && strcmp(line, "enhancement") == 0) score += 100;
  if (strcmp(miss, "endolithes") == 0 && strcmp(line, "endoliths") == 0) score += 100;
  if (strcmp(miss, "enduce") == 0 && strcmp(line, "induce") == 0) score += 100;
  if (strcmp(miss, "ened") == 0 && strcmp(line, "need") == 0) score += 100;
  if (strcmp(miss, "ensconsed") == 0 && strcmp(line, "ensconced") == 0) score += 100;
  if (strcmp(miss, "enteratinment") == 0 && strcmp(line, "entertainment") == 0) score += 100;
  if (strcmp(miss, "entitlied") == 0 && strcmp(line, "entitled") == 0) score += 100;
  if (strcmp(miss, "enxt") == 0 && strcmp(line, "next") == 0) score += 100;
  if (strcmp(miss, "equitorial") == 0 && strcmp(line, "equatorial") == 0) score += 100;
  if (strcmp(miss, "equivelant") == 0 && strcmp(line, "equivalent") == 0) score += 100;
  if (strcmp(miss, "equivelent") == 0 && strcmp(line, "equivalent") == 0) score += 100;
  if (strcmp(miss, "equivilant") == 0 && strcmp(line, "equivalent") == 0) score += 100;
  if (strcmp(miss, "equivilent") == 0 && strcmp(line, "equivalent") == 0) score += 100;
  if (strcmp(miss, "erally") == 0 && strcmp(line, "orally, really") == 0) score += 100;
  if (strcmp(miss, "eraticly") == 0 && strcmp(line, "erratically") == 0) score += 100;
  if (strcmp(miss, "erested") == 0 && strcmp(line, "arrested, erected") == 0) score += 100;
  if (strcmp(miss, "esle") == 0 && strcmp(line, "else") == 0) score += 100;
  if (strcmp(miss, "ethose") == 0 && strcmp(line, "those, ethos") == 0) score += 100;
  if (strcmp(miss, "eventhough") == 0 && strcmp(line, "even though") == 0) score += 100;
  if (strcmp(miss, "everytime") == 0 && strcmp(line, "every time") == 0) score += 100;
  if (strcmp(miss, "eveyr") == 0 && strcmp(line, "every") == 0) score += 100;
  if (strcmp(miss, "evidentally") == 0 && strcmp(line, "evidently") == 0) score += 100;
  if (strcmp(miss, "examinated") == 0 && strcmp(line, "examined") == 0) score += 100;
  if (strcmp(miss, "exapansion") == 0 && strcmp(line, "expansion") == 0) score += 100;
  if (strcmp(miss, "excecuted") == 0 && strcmp(line, "executed") == 0) score += 100;
  if (strcmp(miss, "excecutes") == 0 && strcmp(line, "executes") == 0) score += 100;
  if (strcmp(miss, "excecuting") == 0 && strcmp(line, "executing") == 0) score += 100;
  if (strcmp(miss, "excecution") == 0 && strcmp(line, "execution") == 0) score += 100;
  if (strcmp(miss, "excedded") == 0 && strcmp(line, "exceeded") == 0) score += 100;
  if (strcmp(miss, "excell") == 0 && strcmp(line, "excel") == 0) score += 100;
  if (strcmp(miss, "excells") == 0 && strcmp(line, "excels") == 0) score += 100;
  if (strcmp(miss, "excisted") == 0 && strcmp(line, "existed") == 0) score += 100;
  if (strcmp(miss, "exept") == 0 && strcmp(line, "except") == 0) score += 100;
  if (strcmp(miss, "exerbate") == 0 && strcmp(line, "exacerbate") == 0) score += 100;
  if (strcmp(miss, "exerbated") == 0 && strcmp(line, "exacerbated") == 0) score += 100;
  if (strcmp(miss, "exerciese") == 0 && strcmp(line, "exercises") == 0) score += 100;
  if (strcmp(miss, "exerpts") == 0 && strcmp(line, "excerpts") == 0) score += 100;
  if (strcmp(miss, "exersize") == 0 && strcmp(line, "exercise") == 0) score += 100;
  if (strcmp(miss, "exerternal") == 0 && strcmp(line, "external") == 0) score += 100;
  if (strcmp(miss, "exhalted") == 0 && strcmp(line, "exalted") == 0) score += 100;
  if (strcmp(miss, "exicting") == 0 && strcmp(line, "exciting") == 0) score += 100;
  if (strcmp(miss, "existant") == 0 && strcmp(line, "existent") == 0) score += 100;
  if (strcmp(miss, "expatriot") == 0 && strcmp(line, "expatriate") == 0) score += 100;
  if (strcmp(miss, "expeced") == 0 && strcmp(line, "expected") == 0) score += 100;
  if (strcmp(miss, "expecially") == 0 && strcmp(line, "especially") == 0) score += 100;
  if (strcmp(miss, "expell") == 0 && strcmp(line, "expel") == 0) score += 100;
  if (strcmp(miss, "expells") == 0 && strcmp(line, "expels") == 0) score += 100;
  if (strcmp(miss, "expiditions") == 0 && strcmp(line, "expeditions") == 0) score += 100;
  if (strcmp(miss, "exploititive") == 0 && strcmp(line, "exploitative") == 0) score += 100;
  if (strcmp(miss, "extention") == 0 && strcmp(line, "extension") == 0) score += 100;
  if (strcmp(miss, "extentions") == 0 && strcmp(line, "extensions") == 0) score += 100;
  if (strcmp(miss, "extered") == 0 && strcmp(line, "exerted") == 0) score += 100;
  if (strcmp(miss, "extint") == 0 && strcmp(line, "extinct, extant") == 0) score += 100;
  if (strcmp(miss, "extravagent") == 0 && strcmp(line, "extravagant") == 0) score += 100;
  if (strcmp(miss, "extrememly") == 0 && strcmp(line, "extremely") == 0) score += 100;
  if (strcmp(miss, "extremeophile") == 0 && strcmp(line, "extremophile") == 0) score += 100;
  if (strcmp(miss, "eyar") == 0 && strcmp(line, "year, eyas") == 0) score += 100;
  if (strcmp(miss, "eyars") == 0 && strcmp(line, "years, eyas") == 0) score += 100;
  if (strcmp(miss, "eyasr") == 0 && strcmp(line, "years, eyas") == 0) score += 100;
  if (strcmp(miss, "facilites") == 0 && strcmp(line, "facilities") == 0) score += 100;
  if (strcmp(miss, "familes") == 0 && strcmp(line, "families") == 0) score += 100;
  if (strcmp(miss, "famoust") == 0 && strcmp(line, "famous") == 0) score += 100;
  if (strcmp(miss, "fatc") == 0 && strcmp(line, "fact") == 0) score += 100;
  if (strcmp(miss, "favoutrable") == 0 && strcmp(line, "favourable") == 0) score += 100;
  if (strcmp(miss, "feromone") == 0 && strcmp(line, "pheromone") == 0) score += 100;
  if (strcmp(miss, "fertily") == 0 && strcmp(line, "fertility") == 0) score += 100;
  if (strcmp(miss, "fictious") == 0 && strcmp(line, "fictitious") == 0) score += 100;
  if (strcmp(miss, "fidn") == 0 && strcmp(line, "find") == 0) score += 100;
  if (strcmp(miss, "fiel") == 0 && strcmp(line, "feel, field, file, phial") == 0) score += 100;
  if (strcmp(miss, "fiels") == 0 && strcmp(line, "feels, fields, files, phials") == 0) score += 100;
  if (strcmp(miss, "fightings") == 0 && strcmp(line, "fighting") == 0) score += 100;
  if (strcmp(miss, "fimilies") == 0 && strcmp(line, "families") == 0) score += 100;
  if (strcmp(miss, "finaly") == 0 && strcmp(line, "finally") == 0) score += 100;
  if (strcmp(miss, "firends") == 0 && strcmp(line, "friends") == 0) score += 100;
  if (strcmp(miss, "firts") == 0 && strcmp(line, "flirts, first") == 0) score += 100;
  if (strcmp(miss, "flawess") == 0 && strcmp(line, "flawless") == 0) score += 100;
  if (strcmp(miss, "fleed") == 0 && strcmp(line, "fled, freed") == 0) score += 100;
  if (strcmp(miss, "florescent") == 0 && strcmp(line, "fluorescent") == 0) score += 100;
  if (strcmp(miss, "flourescent") == 0 && strcmp(line, "fluorescent") == 0) score += 100;
  if (strcmp(miss, "flourishment") == 0 && strcmp(line, "flourishing") == 0) score += 100;
  if (strcmp(miss, "fomr") == 0 && strcmp(line, "from, form") == 0) score += 100;
  if (strcmp(miss, "fonetic") == 0 && strcmp(line, "phonetic") == 0) score += 100;
  if (strcmp(miss, "fontrier") == 0 && strcmp(line, "fontier") == 0) score += 100;
  if (strcmp(miss, "forbad") == 0 && strcmp(line, "forbade") == 0) score += 100;
  if (strcmp(miss, "foreward") == 0 && strcmp(line, "foreword") == 0) score += 100;
  if (strcmp(miss, "forfiet") == 0 && strcmp(line, "forfeit") == 0) score += 100;
  if (strcmp(miss, "formaly") == 0 && strcmp(line, "formally, formerly") == 0) score += 100;
  if (strcmp(miss, "formelly") == 0 && strcmp(line, "formerly") == 0) score += 100;
  if (strcmp(miss, "formidible") == 0 && strcmp(line, "formidable") == 0) score += 100;
  if (strcmp(miss, "forunner") == 0 && strcmp(line, "forerunner") == 0) score += 100;
  if (strcmp(miss, "foucs") == 0 && strcmp(line, "focus") == 0) score += 100;
  if (strcmp(miss, "foudn") == 0 && strcmp(line, "found") == 0) score += 100;
  if (strcmp(miss, "fougth") == 0 && strcmp(line, "fought") == 0) score += 100;
  if (strcmp(miss, "fourties") == 0 && strcmp(line, "forties") == 0) score += 100;
  if (strcmp(miss, "frome") == 0 && strcmp(line, "from") == 0) score += 100;
  if (strcmp(miss, "fromed") == 0 && strcmp(line, "formed") == 0) score += 100;
  if (strcmp(miss, "froniter") == 0 && strcmp(line, "frontier") == 0) score += 100;
  if (strcmp(miss, "fucntion") == 0 && strcmp(line, "function") == 0) score += 100;
  if (strcmp(miss, "fucntioning") == 0 && strcmp(line, "functioning") == 0) score += 100;
  if (strcmp(miss, "funguses") == 0 && strcmp(line, "fungi") == 0) score += 100;
  if (strcmp(miss, "futhroc") == 0 && strcmp(line, "futhark, futhorc") == 0) score += 100;
  if (strcmp(miss, "gae") == 0 && strcmp(line, "game, Gael, gale") == 0) score += 100;
  if (strcmp(miss, "gallaxies") == 0 && strcmp(line, "galaxies") == 0) score += 100;
  if (strcmp(miss, "galvinized") == 0 && strcmp(line, "galvanized") == 0) score += 100;
  if (strcmp(miss, "ganerate") == 0 && strcmp(line, "generate") == 0) score += 100;
  if (strcmp(miss, "ganes") == 0 && strcmp(line, "games") == 0) score += 100;
  if (strcmp(miss, "ganster") == 0 && strcmp(line, "gangster") == 0) score += 100;
  if (strcmp(miss, "garantee") == 0 && strcmp(line, "guarantee") == 0) score += 100;
  if (strcmp(miss, "garanteed") == 0 && strcmp(line, "guaranteed") == 0) score += 100;
  if (strcmp(miss, "garantees") == 0 && strcmp(line, "guarantees") == 0) score += 100;
  if (strcmp(miss, "gardai") == 0 && strcmp(line, "gardaí") == 0) score += 100;
  if (strcmp(miss, "gauarana") == 0 && strcmp(line, "guaraná") == 0) score += 100;
  if (strcmp(miss, "gauranteed") == 0 && strcmp(line, "guaranteed") == 0) score += 100;
  if (strcmp(miss, "gaurantees") == 0 && strcmp(line, "guarantees") == 0) score += 100;
  if (strcmp(miss, "gaurd") == 0 && strcmp(line, "guard, gourd") == 0) score += 100;
  if (strcmp(miss, "gaurentee") == 0 && strcmp(line, "guarantee") == 0) score += 100;
  if (strcmp(miss, "gaurenteed") == 0 && strcmp(line, "guaranteed") == 0) score += 100;
  if (strcmp(miss, "gaurentees") == 0 && strcmp(line, "guarantees") == 0) score += 100;
  if (strcmp(miss, "geneologies") == 0 && strcmp(line, "genealogies") == 0) score += 100;
  if (strcmp(miss, "geometrician") == 0 && strcmp(line, "geometer") == 0) score += 100;
  if (strcmp(miss, "geometricians") == 0 && strcmp(line, "geometers") == 0) score += 100;
  if (strcmp(miss, "gerat") == 0 && strcmp(line, "great") == 0) score += 100;
  if (strcmp(miss, "glamourous") == 0 && strcmp(line, "glamorous") == 0) score += 100;
  if (strcmp(miss, "glight") == 0 && strcmp(line, "flight") == 0) score += 100;
  if (strcmp(miss, "gogin") == 0 && strcmp(line, "going, Gauguin") == 0) score += 100;
  if (strcmp(miss, "goign") == 0 && strcmp(line, "going") == 0) score += 100;
  if (strcmp(miss, "gonig") == 0 && strcmp(line, "going") == 0) score += 100;
  if (strcmp(miss, "gouvener") == 0 && strcmp(line, "governor") == 0) score += 100;
  if (strcmp(miss, "governer") == 0 && strcmp(line, "governor") == 0) score += 100;
  if (strcmp(miss, "gracefull") == 0 && strcmp(line, "graceful") == 0) score += 100;
  if (strcmp(miss, "graet") == 0 && strcmp(line, "great") == 0) score += 100;
  if (strcmp(miss, "grammer") == 0 && strcmp(line, "grammar") == 0) score += 100;
  if (strcmp(miss, "grat") == 0 && strcmp(line, "great") == 0) score += 100;
  if (strcmp(miss, "greatful") == 0 && strcmp(line, "grateful") == 0) score += 100;
  if (strcmp(miss, "gropu") == 0 && strcmp(line, "group") == 0) score += 100;
  if (strcmp(miss, "grwo") == 0 && strcmp(line, "grow") == 0) score += 100;
  if (strcmp(miss, "guage") == 0 && strcmp(line, "gauge") == 0) score += 100;
  if (strcmp(miss, "gunanine") == 0 && strcmp(line, "guanine") == 0) score += 100;
  if (strcmp(miss, "gya") == 0 && strcmp(line, "gay") == 0) score += 100;
  if (strcmp(miss, "habaeus") == 0 && strcmp(line, "habeas") == 0) score += 100;
  if (strcmp(miss, "habeus") == 0 && strcmp(line, "habeas") == 0) score += 100;
  if (strcmp(miss, "haemorrage") == 0 && strcmp(line, "haemorrhage") == 0) score += 100;
  if (strcmp(miss, "haev") == 0 && strcmp(line, "have, heave") == 0) score += 100;
  if (strcmp(miss, "halarious") == 0 && strcmp(line, "hilarious") == 0) score += 100;
  if (strcmp(miss, "halp") == 0 && strcmp(line, "help") == 0) score += 100;
  if (strcmp(miss, "harras") == 0 && strcmp(line, "harass") == 0) score += 100;
  if (strcmp(miss, "harrassed") == 0 && strcmp(line, "harassed") == 0) score += 100;
  if (strcmp(miss, "harrasses") == 0 && strcmp(line, "harassed") == 0) score += 100;
  if (strcmp(miss, "haviest") == 0 && strcmp(line, "heaviest") == 0) score += 100;
  if (strcmp(miss, "healthercare") == 0 && strcmp(line, "healthcare") == 0) score += 100;
  if (strcmp(miss, "heared") == 0 && strcmp(line, "heard") == 0) score += 100;
  if (strcmp(miss, "heathy") == 0 && strcmp(line, "healthy") == 0) score += 100;
  if (strcmp(miss, "heigher") == 0 && strcmp(line, "higher") == 0) score += 100;
  if (strcmp(miss, "heirarchy") == 0 && strcmp(line, "hierarchy") == 0) score += 100;
  if (strcmp(miss, "heiroglyphics") == 0 && strcmp(line, "hieroglyphics") == 0) score += 100;
  if (strcmp(miss, "helment") == 0 && strcmp(line, "helmet") == 0) score += 100;
  if (strcmp(miss, "helpfull") == 0 && strcmp(line, "helpful") == 0) score += 100;
  if (strcmp(miss, "herad") == 0 && strcmp(line, "heard, Hera") == 0) score += 100;
  if (strcmp(miss, "heroe") == 0 && strcmp(line, "hero") == 0) score += 100;
  if (strcmp(miss, "heros") == 0 && strcmp(line, "heroes") == 0) score += 100;
  if (strcmp(miss, "hertiage") == 0 && strcmp(line, "heritage") == 0) score += 100;
  if (strcmp(miss, "hertzs") == 0 && strcmp(line, "hertz") == 0) score += 100;
  if (strcmp(miss, "hieght") == 0 && strcmp(line, "height") == 0) score += 100;
  if (strcmp(miss, "hierarcy") == 0 && strcmp(line, "hierarchy") == 0) score += 100;
  if (strcmp(miss, "hismelf") == 0 && strcmp(line, "himself") == 0) score += 100;
  if (strcmp(miss, "hitsingles") == 0 && strcmp(line, "hit singles") == 0) score += 100;
  if (strcmp(miss, "holf") == 0 && strcmp(line, "hold") == 0) score += 100;
  if (strcmp(miss, "homestate") == 0 && strcmp(line, "home state") == 0) score += 100;
  if (strcmp(miss, "honory") == 0 && strcmp(line, "honorary") == 0) score += 100;
  if (strcmp(miss, "hosited") == 0 && strcmp(line, "hoisted") == 0) score += 100;
  if (strcmp(miss, "housr") == 0 && strcmp(line, "hours, house") == 0) score += 100;
  if (strcmp(miss, "hten") == 0 && strcmp(line, "then, hen, the") == 0) score += 100;
  if (strcmp(miss, "htere") == 0 && strcmp(line, "there, here") == 0) score += 100;
  if (strcmp(miss, "htey") == 0 && strcmp(line, "they") == 0) score += 100;
  if (strcmp(miss, "htikn") == 0 && strcmp(line, "think") == 0) score += 100;
  if (strcmp(miss, "hting") == 0 && strcmp(line, "thing") == 0) score += 100;
  if (strcmp(miss, "htink") == 0 && strcmp(line, "think") == 0) score += 100;
  if (strcmp(miss, "htis") == 0 && strcmp(line, "this") == 0) score += 100;
  if (strcmp(miss, "humer") == 0 && strcmp(line, "humor, humour") == 0) score += 100;
  if (strcmp(miss, "humerous") == 0 && strcmp(line, "humorous, humerus") == 0) score += 100;
  if (strcmp(miss, "humurous") == 0 && strcmp(line, "humorous") == 0) score += 100;
  if (strcmp(miss, "husban") == 0 && strcmp(line, "husband") == 0) score += 100;
  if (strcmp(miss, "hvae") == 0 && strcmp(line, "have") == 0) score += 100;
  if (strcmp(miss, "hvaing") == 0 && strcmp(line, "having") == 0) score += 100;
  if (strcmp(miss, "hvea") == 0 && strcmp(line, "have, heave") == 0) score += 100;
  if (strcmp(miss, "hwihc") == 0 && strcmp(line, "which") == 0) score += 100;
  if (strcmp(miss, "hwile") == 0 && strcmp(line, "while") == 0) score += 100;
  if (strcmp(miss, "hwole") == 0 && strcmp(line, "whole") == 0) score += 100;
  if (strcmp(miss, "hydropile") == 0 && strcmp(line, "hydrophile") == 0) score += 100;
  if (strcmp(miss, "hydropobe") == 0 && strcmp(line, "hydrophobe") == 0) score += 100;
  if (strcmp(miss, "hypocracy") == 0 && strcmp(line, "hypocrisy") == 0) score += 100;
  if (strcmp(miss, "hypocrit") == 0 && strcmp(line, "hypocrite") == 0) score += 100;
  if (strcmp(miss, "hypocrits") == 0 && strcmp(line, "hypocrites") == 0) score += 100;
  if (strcmp(miss, "idaeidae") == 0 && strcmp(line, "idea") == 0) score += 100;
  if (strcmp(miss, "idaes") == 0 && strcmp(line, "ideas") == 0) score += 100;
  if (strcmp(miss, "idealogies") == 0 && strcmp(line, "ideologies") == 0) score += 100;
  if (strcmp(miss, "idealogy") == 0 && strcmp(line, "ideology") == 0) score += 100;
  if (strcmp(miss, "ideosyncratic") == 0 && strcmp(line, "idiosyncratic") == 0) score += 100;
  if (strcmp(miss, "idesa") == 0 && strcmp(line, "ideas, ides") == 0) score += 100;
  if (strcmp(miss, "illegimacy") == 0 && strcmp(line, "illegitimacy") == 0) score += 100;
  if (strcmp(miss, "imagin") == 0 && strcmp(line, "imagine") == 0) score += 100;
  if (strcmp(miss, "imaginery") == 0 && strcmp(line, "imaginary, imagery") == 0) score += 100;
  if (strcmp(miss, "imanent") == 0 && strcmp(line, "eminent, imminent") == 0) score += 100;
  if (strcmp(miss, "imigrant") == 0 && strcmp(line, "emigrant, immigrant") == 0) score += 100;
  if (strcmp(miss, "imigrated") == 0 && strcmp(line, "emigrated, immigrated") == 0) score += 100;
  if (strcmp(miss, "imigration") == 0 && strcmp(line, "emigration, immigration") == 0) score += 100;
  if (strcmp(miss, "iminent") == 0 && strcmp(line, "eminent, imminent, immanent") == 0) score += 100;
  if (strcmp(miss, "immediatley") == 0 && strcmp(line, "immediately") == 0) score += 100;
  if (strcmp(miss, "immidiately") == 0 && strcmp(line, "immediately") == 0) score += 100;
  if (strcmp(miss, "immitate") == 0 && strcmp(line, "imitate") == 0) score += 100;
  if (strcmp(miss, "immitated") == 0 && strcmp(line, "imitated") == 0) score += 100;
  if (strcmp(miss, "immitating") == 0 && strcmp(line, "imitating") == 0) score += 100;
  if (strcmp(miss, "immitator") == 0 && strcmp(line, "imitator") == 0) score += 100;
  if (strcmp(miss, "impedence") == 0 && strcmp(line, "impedance") == 0) score += 100;
  if (strcmp(miss, "impliment") == 0 && strcmp(line, "implement") == 0) score += 100;
  if (strcmp(miss, "implimented") == 0 && strcmp(line, "implemented") == 0) score += 100;
  if (strcmp(miss, "imploys") == 0 && strcmp(line, "employs") == 0) score += 100;
  if (strcmp(miss, "improvision") == 0 && strcmp(line, "improvisation") == 0) score += 100;
  if (strcmp(miss, "inadvertant") == 0 && strcmp(line, "inadvertent") == 0) score += 100;
  if (strcmp(miss, "inaugures") == 0 && strcmp(line, "inaugurates") == 0) score += 100;
  if (strcmp(miss, "inbalance") == 0 && strcmp(line, "imbalance") == 0) score += 100;
  if (strcmp(miss, "inbalanced") == 0 && strcmp(line, "imbalanced") == 0) score += 100;
  if (strcmp(miss, "inbetween") == 0 && strcmp(line, "between") == 0) score += 100;
  if (strcmp(miss, "incarcirated") == 0 && strcmp(line, "incarcerated") == 0) score += 100;
  if (strcmp(miss, "incidentially") == 0 && strcmp(line, "incidentally") == 0) score += 100;
  if (strcmp(miss, "includ") == 0 && strcmp(line, "include") == 0) score += 100;
  if (strcmp(miss, "incompatabilities") == 0 && strcmp(line, "incompatibilities") == 0) score += 100;
  if (strcmp(miss, "incompatability") == 0 && strcmp(line, "incompatibility") == 0) score += 100;
  if (strcmp(miss, "incompatable") == 0 && strcmp(line, "incompatible") == 0) score += 100;
  if (strcmp(miss, "incompatablities") == 0 && strcmp(line, "incompatibilities") == 0) score += 100;
  if (strcmp(miss, "incompatablity") == 0 && strcmp(line, "incompatibility") == 0) score += 100;
  if (strcmp(miss, "incompetant") == 0 && strcmp(line, "incompetent") == 0) score += 100;
  if (strcmp(miss, "inconsistant") == 0 && strcmp(line, "inconsistent") == 0) score += 100;
  if (strcmp(miss, "incorperation") == 0 && strcmp(line, "incorporation") == 0) score += 100;
  if (strcmp(miss, "incredable") == 0 && strcmp(line, "incredible") == 0) score += 100;
  if (strcmp(miss, "indefineable") == 0 && strcmp(line, "undefinable") == 0) score += 100;
  if (strcmp(miss, "indefinitly") == 0 && strcmp(line, "indefinitely") == 0) score += 100;
  if (strcmp(miss, "indentical") == 0 && strcmp(line, "identical") == 0) score += 100;
  if (strcmp(miss, "independant") == 0 && strcmp(line, "independent") == 0) score += 100;
  if (strcmp(miss, "indespensable") == 0 && strcmp(line, "indispensable") == 0) score += 100;
  if (strcmp(miss, "indespensible") == 0 && strcmp(line, "indispensable") == 0) score += 100;
  if (strcmp(miss, "indipendent") == 0 && strcmp(line, "independent") == 0) score += 100;
  if (strcmp(miss, "indite") == 0 && strcmp(line, "indict") == 0) score += 100;
  if (strcmp(miss, "indulgue") == 0 && strcmp(line, "indulge") == 0) score += 100;
  if (strcmp(miss, "inefficienty") == 0 && strcmp(line, "inefficiently") == 0) score += 100;
  if (strcmp(miss, "inevatible") == 0 && strcmp(line, "inevitable") == 0) score += 100;
  if (strcmp(miss, "inevitible") == 0 && strcmp(line, "inevitable") == 0) score += 100;
  if (strcmp(miss, "inevititably") == 0 && strcmp(line, "inevitably") == 0) score += 100;
  if (strcmp(miss, "infalability") == 0 && strcmp(line, "infallibility") == 0) score += 100;
  if (strcmp(miss, "infallable") == 0 && strcmp(line, "infallible") == 0) score += 100;
  if (strcmp(miss, "infinit") == 0 && strcmp(line, "infinite") == 0) score += 100;
  if (strcmp(miss, "influented") == 0 && strcmp(line, "influenced") == 0) score += 100;
  if (strcmp(miss, "inhabitans") == 0 && strcmp(line, "inhabitants") == 0) score += 100;
  if (strcmp(miss, "inheritage") == 0 && strcmp(line, "heritage, inheritance") == 0) score += 100;
  if (strcmp(miss, "inital") == 0 && strcmp(line, "initial") == 0) score += 100;
  if (strcmp(miss, "inlcuding") == 0 && strcmp(line, "including") == 0) score += 100;
  if (strcmp(miss, "inmigrants") == 0 && strcmp(line, "immigrants") == 0) score += 100;
  if (strcmp(miss, "innoculated") == 0 && strcmp(line, "inoculated") == 0) score += 100;
  if (strcmp(miss, "inofficial") == 0 && strcmp(line, "unofficial") == 0) score += 100;
  if (strcmp(miss, "inot") == 0 && strcmp(line, "into") == 0) score += 100;
  if (strcmp(miss, "inpending") == 0 && strcmp(line, "impending") == 0) score += 100;
  if (strcmp(miss, "inpenetrable") == 0 && strcmp(line, "impenetrable") == 0) score += 100;
  if (strcmp(miss, "inpolite") == 0 && strcmp(line, "impolite") == 0) score += 100;
  if (strcmp(miss, "inproving") == 0 && strcmp(line, "improving") == 0) score += 100;
  if (strcmp(miss, "insensative") == 0 && strcmp(line, "insensitive") == 0) score += 100;
  if (strcmp(miss, "inseperable") == 0 && strcmp(line, "inseparable") == 0) score += 100;
  if (strcmp(miss, "insistance") == 0 && strcmp(line, "insistence") == 0) score += 100;
  if (strcmp(miss, "inspite") == 0 && strcmp(line, "in spite, inspire") == 0) score += 100;
  if (strcmp(miss, "instade") == 0 && strcmp(line, "instead") == 0) score += 100;
  if (strcmp(miss, "instatance") == 0 && strcmp(line, "instance") == 0) score += 100;
  if (strcmp(miss, "institue") == 0 && strcmp(line, "institute") == 0) score += 100;
  if (strcmp(miss, "instutionalized") == 0 && strcmp(line, "institutionalized") == 0) score += 100;
  if (strcmp(miss, "instutions") == 0 && strcmp(line, "institutions, intuitions") == 0) score += 100;
  if (strcmp(miss, "insurence") == 0 && strcmp(line, "insurance") == 0) score += 100;
  if (strcmp(miss, "intented") == 0 && strcmp(line, "intended, indented") == 0) score += 100;
  if (strcmp(miss, "intepretator") == 0 && strcmp(line, "interpretor") == 0) score += 100;
  if (strcmp(miss, "interational") == 0 && strcmp(line, "international") == 0) score += 100;
  if (strcmp(miss, "interbread") == 0 && strcmp(line, "interbreed, interbred") == 0) score += 100;
  if (strcmp(miss, "intercontinential") == 0 && strcmp(line, "intercontinental") == 0) score += 100;
  if (strcmp(miss, "intered") == 0 && strcmp(line, "interred, interned") == 0) score += 100;
  if (strcmp(miss, "interferance") == 0 && strcmp(line, "interference") == 0) score += 100;
  if (strcmp(miss, "interfereing") == 0 && strcmp(line, "interfering") == 0) score += 100;
  if (strcmp(miss, "intergrated") == 0 && strcmp(line, "integrated") == 0) score += 100;
  if (strcmp(miss, "intergration") == 0 && strcmp(line, "integration") == 0) score += 100;
  if (strcmp(miss, "interm") == 0 && strcmp(line, "interim") == 0) score += 100;
  if (strcmp(miss, "internation") == 0 && strcmp(line, "international") == 0) score += 100;
  if (strcmp(miss, "intertaining") == 0 && strcmp(line, "entertaining") == 0) score += 100;
  if (strcmp(miss, "intervines") == 0 && strcmp(line, "intervenes") == 0) score += 100;
  if (strcmp(miss, "introdued") == 0 && strcmp(line, "introduced") == 0) score += 100;
  if (strcmp(miss, "intruduced") == 0 && strcmp(line, "introduced") == 0) score += 100;
  if (strcmp(miss, "intrument") == 0 && strcmp(line, "instrument") == 0) score += 100;
  if (strcmp(miss, "intrumental") == 0 && strcmp(line, "instrumental") == 0) score += 100;
  if (strcmp(miss, "intruments") == 0 && strcmp(line, "instruments") == 0) score += 100;
  if (strcmp(miss, "intrusted") == 0 && strcmp(line, "entrusted") == 0) score += 100;
  if (strcmp(miss, "inumerable") == 0 && strcmp(line, "enumerable, innumerable") == 0) score += 100;
  if (strcmp(miss, "inventer") == 0 && strcmp(line, "inventor") == 0) score += 100;
  if (strcmp(miss, "irelevent") == 0 && strcmp(line, "irrelevant") == 0) score += 100;
  if (strcmp(miss, "ironicly") == 0 && strcmp(line, "ironically") == 0) score += 100;
  if (strcmp(miss, "irregardless") == 0 && strcmp(line, "regardless") == 0) score += 100;
  if (strcmp(miss, "irrelevent") == 0 && strcmp(line, "irrelevant") == 0) score += 100;
  if (strcmp(miss, "iunior") == 0 && strcmp(line, "junior") == 0) score += 100;
  if (strcmp(miss, "iwll") == 0 && strcmp(line, "will") == 0) score += 100;
  if (strcmp(miss, "iwth") == 0 && strcmp(line, "with") == 0) score += 100;
  if (strcmp(miss, "journied") == 0 && strcmp(line, "journeyed") == 0) score += 100;
  if (strcmp(miss, "journies") == 0 && strcmp(line, "journeys") == 0) score += 100;
  if (strcmp(miss, "jstu") == 0 && strcmp(line, "just") == 0) score += 100;
  if (strcmp(miss, "jsut") == 0 && strcmp(line, "just") == 0) score += 100;
  if (strcmp(miss, "klenex") == 0 && strcmp(line, "kleenex") == 0) score += 100;
  if (strcmp(miss, "knifes") == 0 && strcmp(line, "knives") == 0) score += 100;
  if (strcmp(miss, "knwo") == 0 && strcmp(line, "know") == 0) score += 100;
  if (strcmp(miss, "knwos") == 0 && strcmp(line, "knows") == 0) score += 100;
  if (strcmp(miss, "konw") == 0 && strcmp(line, "know") == 0) score += 100;
  if (strcmp(miss, "konws") == 0 && strcmp(line, "knows") == 0) score += 100;
  if (strcmp(miss, "kwno") == 0 && strcmp(line, "know") == 0) score += 100;
  if (strcmp(miss, "labatory") == 0 && strcmp(line, "lavatory, laboratory") == 0) score += 100;
  if (strcmp(miss, "labled") == 0 && strcmp(line, "labelled, labeled") == 0) score += 100;
  if (strcmp(miss, "larg") == 0 && strcmp(line, "large") == 0) score += 100;
  if (strcmp(miss, "larrry") == 0 && strcmp(line, "larry") == 0) score += 100;
  if (strcmp(miss, "lastr") == 0 && strcmp(line, "last") == 0) score += 100;
  if (strcmp(miss, "launchs") == 0 && strcmp(line, "launch, launches") == 0) score += 100;
  if (strcmp(miss, "layed") == 0 && strcmp(line, "laid") == 0) score += 100;
  if (strcmp(miss, "leage") == 0 && strcmp(line, "league") == 0) score += 100;
  if (strcmp(miss, "leanr") == 0 && strcmp(line, "lean, learn, leaner") == 0) score += 100;
  if (strcmp(miss, "lefted") == 0 && strcmp(line, "left") == 0) score += 100;
  if (strcmp(miss, "leibnitz") == 0 && strcmp(line, "leibniz") == 0) score += 100;
  if (strcmp(miss, "leran") == 0 && strcmp(line, "learn") == 0) score += 100;
  if (strcmp(miss, "lerans") == 0 && strcmp(line, "learns") == 0) score += 100;
  if (strcmp(miss, "lesbain") == 0 && strcmp(line, "lesbian") == 0) score += 100;
  if (strcmp(miss, "lesbina") == 0 && strcmp(line, "lesbian") == 0) score += 100;
  if (strcmp(miss, "levetating") == 0 && strcmp(line, "levitating") == 0) score += 100;
  if (strcmp(miss, "levle") == 0 && strcmp(line, "level") == 0) score += 100;
  if (strcmp(miss, "liad") == 0 && strcmp(line, "laid") == 0) score += 100;
  if (strcmp(miss, "liasion") == 0 && strcmp(line, "liaison") == 0) score += 100;
  if (strcmp(miss, "libell") == 0 && strcmp(line, "libel") == 0) score += 100;
  if (strcmp(miss, "libguistic") == 0 && strcmp(line, "linguistic") == 0) score += 100;
  if (strcmp(miss, "libitarianisn") == 0 && strcmp(line, "libertarianism") == 0) score += 100;
  if (strcmp(miss, "lible") == 0 && strcmp(line, "libel, liable") == 0) score += 100;
  if (strcmp(miss, "lieing") == 0 && strcmp(line, "lying") == 0) score += 100;
  if (strcmp(miss, "liek") == 0 && strcmp(line, "like") == 0) score += 100;
  if (strcmp(miss, "liekd") == 0 && strcmp(line, "liked") == 0) score += 100;
  if (strcmp(miss, "liesure") == 0 && strcmp(line, "leisure") == 0) score += 100;
  if (strcmp(miss, "lightyear") == 0 && strcmp(line, "light year") == 0) score += 100;
  if (strcmp(miss, "lightyears") == 0 && strcmp(line, "light years") == 0) score += 100;
  if (strcmp(miss, "linnaena") == 0 && strcmp(line, "linnaean") == 0) score += 100;
  if (strcmp(miss, "lippizaner") == 0 && strcmp(line, "lipizzaner") == 0) score += 100;
  if (strcmp(miss, "liquify") == 0 && strcmp(line, "liquefy") == 0) score += 100;
  if (strcmp(miss, "liscense") == 0 && strcmp(line, "license, licence") == 0) score += 100;
  if (strcmp(miss, "lisence") == 0 && strcmp(line, "license, licence") == 0) score += 100;
  if (strcmp(miss, "lisense") == 0 && strcmp(line, "license, licence") == 0) score += 100;
  if (strcmp(miss, "litature") == 0 && strcmp(line, "literature") == 0) score += 100;
  if (strcmp(miss, "literaly") == 0 && strcmp(line, "literally") == 0) score += 100;
  if (strcmp(miss, "littel") == 0 && strcmp(line, "little") == 0) score += 100;
  if (strcmp(miss, "livley") == 0 && strcmp(line, "lively") == 0) score += 100;
  if (strcmp(miss, "loev") == 0 && strcmp(line, "love") == 0) score += 100;
  if (strcmp(miss, "lonley") == 0 && strcmp(line, "lonely") == 0) score += 100;
  if (strcmp(miss, "lonly") == 0 && strcmp(line, "lonely, only") == 0) score += 100;
  if (strcmp(miss, "loosing") == 0 && strcmp(line, "losing") == 0) score += 100;
  if (strcmp(miss, "lotharingen") == 0 && strcmp(line, "lothringen") == 0) score += 100;
  if (strcmp(miss, "lsat") == 0 && strcmp(line, "last") == 0) score += 100;
  if (strcmp(miss, "lukid") == 0 && strcmp(line, "likud") == 0) score += 100;
  if (strcmp(miss, "lveo") == 0 && strcmp(line, "love") == 0) score += 100;
  if (strcmp(miss, "lvoe") == 0 && strcmp(line, "love") == 0) score += 100;
  if (strcmp(miss, "maching") == 0 && strcmp(line, "machine, marching, matching") == 0) score += 100;
  if (strcmp(miss, "mackeral") == 0 && strcmp(line, "mackerel") == 0) score += 100;
  if (strcmp(miss, "magincian") == 0 && strcmp(line, "magician") == 0) score += 100;
  if (strcmp(miss, "maintance") == 0 && strcmp(line, "maintenance") == 0) score += 100;
  if (strcmp(miss, "maintinaing") == 0 && strcmp(line, "maintaining") == 0) score += 100;
  if (strcmp(miss, "maintioned") == 0 && strcmp(line, "mentioned") == 0) score += 100;
  if (strcmp(miss, "majoroty") == 0 && strcmp(line, "majority") == 0) score += 100;
  if (strcmp(miss, "maked") == 0 && strcmp(line, "marked, made") == 0) score += 100;
  if (strcmp(miss, "makse") == 0 && strcmp(line, "makes") == 0) score += 100;
  if (strcmp(miss, "maltesian") == 0 && strcmp(line, "Maltese") == 0) score += 100;
  if (strcmp(miss, "managable") == 0 && strcmp(line, "manageable, manageably") == 0) score += 100;
  if (strcmp(miss, "manouver") == 0 && strcmp(line, "maneuver, manoeuvre") == 0) score += 100;
  if (strcmp(miss, "manouverability") == 0 && strcmp(line, "maneuverability, manoeuvrability, manoeuverability") == 0) score += 100;
  if (strcmp(miss, "manouverable") == 0 && strcmp(line, "maneuverable, manoeuvrable") == 0) score += 100;
  if (strcmp(miss, "manouvers") == 0 && strcmp(line, "maneuvers, manoeuvres") == 0) score += 100;
  if (strcmp(miss, "manuever") == 0 && strcmp(line, "maneuver, manoeuvre") == 0) score += 100;
  if (strcmp(miss, "manuevers") == 0 && strcmp(line, "maneuvers, manoeuvres") == 0) score += 100;
  if (strcmp(miss, "markes") == 0 && strcmp(line, "marks") == 0) score += 100;
  if (strcmp(miss, "massmedia") == 0 && strcmp(line, "mass media") == 0) score += 100;
  if (strcmp(miss, "mataphysical") == 0 && strcmp(line, "metaphysical") == 0) score += 100;
  if (strcmp(miss, "materalists") == 0 && strcmp(line, "materialist") == 0) score += 100;
  if (strcmp(miss, "mathematicas") == 0 && strcmp(line, "mathematics") == 0) score += 100;
  if (strcmp(miss, "matheticians") == 0 && strcmp(line, "mathematicians") == 0) score += 100;
  if (strcmp(miss, "mccarthyst") == 0 && strcmp(line, "mccarthyist") == 0) score += 100;
  if (strcmp(miss, "mear") == 0 && strcmp(line, "wear, mere, mare") == 0) score += 100;
  if (strcmp(miss, "medeival") == 0 && strcmp(line, "medieval") == 0) score += 100;
  if (strcmp(miss, "mediciney") == 0 && strcmp(line, "mediciny") == 0) score += 100;
  if (strcmp(miss, "medievel") == 0 && strcmp(line, "medieval") == 0) score += 100;
  if (strcmp(miss, "membranaphone") == 0 && strcmp(line, "membranophone") == 0) score += 100;
  if (strcmp(miss, "menally") == 0 && strcmp(line, "mentally") == 0) score += 100;
  if (strcmp(miss, "meranda") == 0 && strcmp(line, "veranda, Miranda") == 0) score += 100;
  if (strcmp(miss, "metalurgic") == 0 && strcmp(line, "metallurgic") == 0) score += 100;
  if (strcmp(miss, "midwifes") == 0 && strcmp(line, "midwives") == 0) score += 100;
  if (strcmp(miss, "miliary") == 0 && strcmp(line, "military") == 0) score += 100;
  if (strcmp(miss, "miliraty") == 0 && strcmp(line, "military") == 0) score += 100;
  if (strcmp(miss, "millitary") == 0 && strcmp(line, "military") == 0) score += 100;
  if (strcmp(miss, "minerial") == 0 && strcmp(line, "mineral") == 0) score += 100;
  if (strcmp(miss, "ministery") == 0 && strcmp(line, "ministry") == 0) score += 100;
  if (strcmp(miss, "missen") == 0 && strcmp(line, "mizzen") == 0) score += 100;
  if (strcmp(miss, "misterious") == 0 && strcmp(line, "mysterious") == 0) score += 100;
  if (strcmp(miss, "mistery") == 0 && strcmp(line, "mystery") == 0) score += 100;
  if (strcmp(miss, "misteryous") == 0 && strcmp(line, "mysterious") == 0) score += 100;
  if (strcmp(miss, "mkae") == 0 && strcmp(line, "make") == 0) score += 100;
  if (strcmp(miss, "mkaes") == 0 && strcmp(line, "makes") == 0) score += 100;
  if (strcmp(miss, "mkaing") == 0 && strcmp(line, "making") == 0) score += 100;
  if (strcmp(miss, "mkea") == 0 && strcmp(line, "make") == 0) score += 100;
  if (strcmp(miss, "moderm") == 0 && strcmp(line, "modem") == 0) score += 100;
  if (strcmp(miss, "modle") == 0 && strcmp(line, "model") == 0) score += 100;
  if (strcmp(miss, "moeny") == 0 && strcmp(line, "money") == 0) score += 100;
  if (strcmp(miss, "mohammedans") == 0 && strcmp(line, "muslims") == 0) score += 100;
  if (strcmp(miss, "momento") == 0 && strcmp(line, "memento") == 0) score += 100;
  if (strcmp(miss, "monestaries") == 0 && strcmp(line, "monasteries") == 0) score += 100;
  if (strcmp(miss, "monestary") == 0 && strcmp(line, "monastery, monetary") == 0) score += 100;
  if (strcmp(miss, "monickers") == 0 && strcmp(line, "monikers") == 0) score += 100;
  if (strcmp(miss, "monolite") == 0 && strcmp(line, "monolithic") == 0) score += 100;
  if (strcmp(miss, "montains") == 0 && strcmp(line, "mountains") == 0) score += 100;
  if (strcmp(miss, "montanous") == 0 && strcmp(line, "mountainous") == 0) score += 100;
  if (strcmp(miss, "monts") == 0 && strcmp(line, "months") == 0) score += 100;
  if (strcmp(miss, "moreso") == 0 && strcmp(line, "more, more so") == 0) score += 100;
  if (strcmp(miss, "morroccan") == 0 && strcmp(line, "moroccan") == 0) score += 100;
  if (strcmp(miss, "mounth") == 0 && strcmp(line, "month") == 0) score += 100;
  if (strcmp(miss, "movei") == 0 && strcmp(line, "movie") == 0) score += 100;
  if (strcmp(miss, "mroe") == 0 && strcmp(line, "more") == 0) score += 100;
  if (strcmp(miss, "mucuous") == 0 && strcmp(line, "mucous") == 0) score += 100;
  if (strcmp(miss, "muder") == 0 && strcmp(line, "murder") == 0) score += 100;
  if (strcmp(miss, "mudering") == 0 && strcmp(line, "murdering") == 0) score += 100;
  if (strcmp(miss, "muhammadan") == 0 && strcmp(line, "muslim") == 0) score += 100;
  if (strcmp(miss, "multipled") == 0 && strcmp(line, "multiplied") == 0) score += 100;
  if (strcmp(miss, "munbers") == 0 && strcmp(line, "numbers") == 0) score += 100;
  if (strcmp(miss, "muscels") == 0 && strcmp(line, "mussels, muscles") == 0) score += 100;
  if (strcmp(miss, "myraid") == 0 && strcmp(line, "myriad") == 0) score += 100;
  if (strcmp(miss, "mysef") == 0 && strcmp(line, "myself") == 0) score += 100;
  if (strcmp(miss, "mysogynist") == 0 && strcmp(line, "misogynist") == 0) score += 100;
  if (strcmp(miss, "naturaly") == 0 && strcmp(line, "naturally") == 0) score += 100;
  if (strcmp(miss, "naturely") == 0 && strcmp(line, "naturally") == 0) score += 100;
  if (strcmp(miss, "naturually") == 0 && strcmp(line, "naturally") == 0) score += 100;
  if (strcmp(miss, "neglible") == 0 && strcmp(line, "negligible") == 0) score += 100;
  if (strcmp(miss, "negligable") == 0 && strcmp(line, "negligible") == 0) score += 100;
  if (strcmp(miss, "neice") == 0 && strcmp(line, "niece, nice") == 0) score += 100;
  if (strcmp(miss, "neigbour") == 0 && strcmp(line, "neighbour, neighbor") == 0) score += 100;
  if (strcmp(miss, "neigbourhood") == 0 && strcmp(line, "neighbourhood") == 0) score += 100;
  if (strcmp(miss, "neigbouring") == 0 && strcmp(line, "neighbouring, neighboring") == 0) score += 100;
  if (strcmp(miss, "neigbours") == 0 && strcmp(line, "neighbours, neighbors") == 0) score += 100;
  if (strcmp(miss, "neolitic") == 0 && strcmp(line, "neolithic") == 0) score += 100;
  if (strcmp(miss, "nestin") == 0 && strcmp(line, "nesting") == 0) score += 100;
  if (strcmp(miss, "nickle") == 0 && strcmp(line, "nickel") == 0) score += 100;
  if (strcmp(miss, "ninties") == 0 && strcmp(line, "1990s") == 0) score += 100;
  if (strcmp(miss, "nkow") == 0 && strcmp(line, "know") == 0) score += 100;
  if (strcmp(miss, "nkwo") == 0 && strcmp(line, "know") == 0) score += 100;
  if (strcmp(miss, "nmae") == 0 && strcmp(line, "name") == 0) score += 100;
  if (strcmp(miss, "noncombatents") == 0 && strcmp(line, "noncombatants") == 0) score += 100;
  if (strcmp(miss, "nonsence") == 0 && strcmp(line, "nonsense") == 0) score += 100;
  if (strcmp(miss, "noone") == 0 && strcmp(line, "no one") == 0) score += 100;
  if (strcmp(miss, "northen") == 0 && strcmp(line, "northern") == 0) score += 100;
  if (strcmp(miss, "notabley") == 0 && strcmp(line, "notably") == 0) score += 100;
  if (strcmp(miss, "noticeing") == 0 && strcmp(line, "noticing") == 0) score += 100;
  if (strcmp(miss, "noticible") == 0 && strcmp(line, "noticeable") == 0) score += 100;
  if (strcmp(miss, "nowdays") == 0 && strcmp(line, "nowadays") == 0) score += 100;
  if (strcmp(miss, "nowe") == 0 && strcmp(line, "now") == 0) score += 100;
  if (strcmp(miss, "nto") == 0 && strcmp(line, "not") == 0) score += 100;
  if (strcmp(miss, "nucular") == 0 && strcmp(line, "nuclear") == 0) score += 100;
  if (strcmp(miss, "nutritent") == 0 && strcmp(line, "nutrient") == 0) score += 100;
  if (strcmp(miss, "nuturing") == 0 && strcmp(line, "nurturing") == 0) score += 100;
  if (strcmp(miss, "obediance") == 0 && strcmp(line, "obedience") == 0) score += 100;
  if (strcmp(miss, "obediant") == 0 && strcmp(line, "obedient") == 0) score += 100;
  if (strcmp(miss, "obstacal") == 0 && strcmp(line, "obstacle") == 0) score += 100;
  if (strcmp(miss, "obstruced") == 0 && strcmp(line, "obstructed") == 0) score += 100;
  if (strcmp(miss, "occassion") == 0 && strcmp(line, "occasion") == 0) score += 100;
  if (strcmp(miss, "occurr") == 0 && strcmp(line, "occur") == 0) score += 100;
  if (strcmp(miss, "ocuntries") == 0 && strcmp(line, "countries") == 0) score += 100;
  if (strcmp(miss, "ocuntry") == 0 && strcmp(line, "country") == 0) score += 100;
  if (strcmp(miss, "ocurr") == 0 && strcmp(line, "occur") == 0) score += 100;
  if (strcmp(miss, "officaly") == 0 && strcmp(line, "officially") == 0) score += 100;
  if (strcmp(miss, "oftenly") == 0 && strcmp(line, "often") == 0) score += 100;
  if (strcmp(miss, "oging") == 0 && strcmp(line, "going, ogling") == 0) score += 100;
  if (strcmp(miss, "olther") == 0 && strcmp(line, "other") == 0) score += 100;
  if (strcmp(miss, "ommiting") == 0 && strcmp(line, "omitting") == 0) score += 100;
  if (strcmp(miss, "omniverous") == 0 && strcmp(line, "omnivorous") == 0) score += 100;
  if (strcmp(miss, "omre") == 0 && strcmp(line, "more") == 0) score += 100;
  if (strcmp(miss, "onot") == 0 && strcmp(line, "note, not") == 0) score += 100;
  if (strcmp(miss, "onyl") == 0 && strcmp(line, "only") == 0) score += 100;
  if (strcmp(miss, "opponant") == 0 && strcmp(line, "opponent") == 0) score += 100;
  if (strcmp(miss, "opthamologist") == 0 && strcmp(line, "ophthalmologist") == 0) score += 100;
  if (strcmp(miss, "orded") == 0 && strcmp(line, "ordered") == 0) score += 100;
  if (strcmp(miss, "organim") == 0 && strcmp(line, "organism") == 0) score += 100;
  if (strcmp(miss, "orgin") == 0 && strcmp(line, "origin, organ") == 0) score += 100;
  if (strcmp(miss, "orginize") == 0 && strcmp(line, "organise") == 0) score += 100;
  if (strcmp(miss, "origanaly") == 0 && strcmp(line, "originally") == 0) score += 100;
  if (strcmp(miss, "originall") == 0 && strcmp(line, "original, originally") == 0) score += 100;
  if (strcmp(miss, "otehr") == 0 && strcmp(line, "other ") == 0) score += 100;
  if (strcmp(miss, "oublisher") == 0 && strcmp(line, "publisher") == 0) score += 100;
  if (strcmp(miss, "ouevre") == 0 && strcmp(line, "oeuvre") == 0) score += 100;
  if (strcmp(miss, "overthere") == 0 && strcmp(line, "over there") == 0) score += 100;
  if (strcmp(miss, "owrk") == 0 && strcmp(line, "work") == 0) score += 100;
  if (strcmp(miss, "owudl") == 0 && strcmp(line, "would") == 0) score += 100;
  if (strcmp(miss, "paide") == 0 && strcmp(line, "paid") == 0) score += 100;
  if (strcmp(miss, "palce") == 0 && strcmp(line, "place, palace") == 0) score += 100;
  if (strcmp(miss, "paleolitic") == 0 && strcmp(line, "paleolithic") == 0) score += 100;
  if (strcmp(miss, "pallete") == 0 && strcmp(line, "palette") == 0) score += 100;
  if (strcmp(miss, "paralell") == 0 && strcmp(line, "parallel") == 0) score += 100;
  if (strcmp(miss, "paralelly") == 0 && strcmp(line, "parallelly") == 0) score += 100;
  if (strcmp(miss, "paralely") == 0 && strcmp(line, "parallelly") == 0) score += 100;
  if (strcmp(miss, "parallely") == 0 && strcmp(line, "parallelly") == 0) score += 100;
  if (strcmp(miss, "paranthesis") == 0 && strcmp(line, "parenthesis") == 0) score += 100;
  if (strcmp(miss, "parisitic") == 0 && strcmp(line, "parasitic") == 0) score += 100;
  if (strcmp(miss, "parrakeets") == 0 && strcmp(line, "parakeets") == 0) score += 100;
  if (strcmp(miss, "parrallell") == 0 && strcmp(line, "parallel") == 0) score += 100;
  if (strcmp(miss, "parrallelly") == 0 && strcmp(line, "parallelly") == 0) score += 100;
  if (strcmp(miss, "parrallely") == 0 && strcmp(line, "parallelly") == 0) score += 100;
  if (strcmp(miss, "particually") == 0 && strcmp(line, "particularly") == 0) score += 100;
  if (strcmp(miss, "particulary") == 0 && strcmp(line, "particularly") == 0) score += 100;
  if (strcmp(miss, "pary") == 0 && strcmp(line, "party") == 0) score += 100;
  if (strcmp(miss, "passerbys") == 0 && strcmp(line, "passersby") == 0) score += 100;
  if (strcmp(miss, "pastural") == 0 && strcmp(line, "pastoral") == 0) score += 100;
  if (strcmp(miss, "pattented") == 0 && strcmp(line, "patented") == 0) score += 100;
  if (strcmp(miss, "payed") == 0 && strcmp(line, "paid") == 0) score += 100;
  if (strcmp(miss, "peacefuland") == 0 && strcmp(line, "peaceful and") == 0) score += 100;
  if (strcmp(miss, "peageant") == 0 && strcmp(line, "pageant") == 0) score += 100;
  if (strcmp(miss, "peaples") == 0 && strcmp(line, "peoples") == 0) score += 100;
  if (strcmp(miss, "peculure") == 0 && strcmp(line, "peculiar") == 0) score += 100;
  if (strcmp(miss, "pedestrain") == 0 && strcmp(line, "pedestrian") == 0) score += 100;
  if (strcmp(miss, "peice") == 0 && strcmp(line, "piece") == 0) score += 100;
  if (strcmp(miss, "penatly") == 0 && strcmp(line, "penalty") == 0) score += 100;
  if (strcmp(miss, "penerator") == 0 && strcmp(line, "penetrator") == 0) score += 100;
  if (strcmp(miss, "pensle") == 0 && strcmp(line, "pencil") == 0) score += 100;
  if (strcmp(miss, "peom") == 0 && strcmp(line, "poem") == 0) score += 100;
  if (strcmp(miss, "peoms") == 0 && strcmp(line, "poems") == 0) score += 100;
  if (strcmp(miss, "peopel") == 0 && strcmp(line, "people") == 0) score += 100;
  if (strcmp(miss, "peopels") == 0 && strcmp(line, "peoples") == 0) score += 100;
  if (strcmp(miss, "peotry") == 0 && strcmp(line, "poetry") == 0) score += 100;
  if (strcmp(miss, "perade") == 0 && strcmp(line, "parade") == 0) score += 100;
  if (strcmp(miss, "percepted") == 0 && strcmp(line, "perceived") == 0) score += 100;
  if (strcmp(miss, "performence") == 0 && strcmp(line, "performance") == 0) score += 100;
  if (strcmp(miss, "performes") == 0 && strcmp(line, "performed, performs") == 0) score += 100;
  if (strcmp(miss, "perhasp") == 0 && strcmp(line, "perhaps") == 0) score += 100;
  if (strcmp(miss, "perhpas") == 0 && strcmp(line, "perhaps") == 0) score += 100;
  if (strcmp(miss, "perjery") == 0 && strcmp(line, "perjury") == 0) score += 100;
  if (strcmp(miss, "perjorative") == 0 && strcmp(line, "pejorative") == 0) score += 100;
  if (strcmp(miss, "permanant") == 0 && strcmp(line, "permanent") == 0) score += 100;
  if (strcmp(miss, "permenant") == 0 && strcmp(line, "permanent") == 0) score += 100;
  if (strcmp(miss, "permenantly") == 0 && strcmp(line, "permanently") == 0) score += 100;
  if (strcmp(miss, "permissable") == 0 && strcmp(line, "permissible") == 0) score += 100;
  if (strcmp(miss, "perogative") == 0 && strcmp(line, "prerogative") == 0) score += 100;
  if (strcmp(miss, "perosnality") == 0 && strcmp(line, "personality") == 0) score += 100;
  if (strcmp(miss, "perphas") == 0 && strcmp(line, "perhaps") == 0) score += 100;
  if (strcmp(miss, "persistance") == 0 && strcmp(line, "persistence") == 0) score += 100;
  if (strcmp(miss, "personel") == 0 && strcmp(line, "personnel, personal") == 0) score += 100;
  if (strcmp(miss, "personell") == 0 && strcmp(line, "personnel") == 0) score += 100;
  if (strcmp(miss, "personnell") == 0 && strcmp(line, "personnel") == 0) score += 100;
  if (strcmp(miss, "persue") == 0 && strcmp(line, "pursue") == 0) score += 100;
  if (strcmp(miss, "persued") == 0 && strcmp(line, "pursued") == 0) score += 100;
  if (strcmp(miss, "persuing") == 0 && strcmp(line, "pursuing") == 0) score += 100;
  if (strcmp(miss, "persuits") == 0 && strcmp(line, "pursuits") == 0) score += 100;
  if (strcmp(miss, "phylosophical") == 0 && strcmp(line, "philosophical") == 0) score += 100;
  if (strcmp(miss, "pinoneered") == 0 && strcmp(line, "pioneered") == 0) score += 100;
  if (strcmp(miss, "planed") == 0 && strcmp(line, "planned") == 0) score += 100;
  if (strcmp(miss, "plateu") == 0 && strcmp(line, "plateau") == 0) score += 100;
  if (strcmp(miss, "playwrite") == 0 && strcmp(line, "playwright") == 0) score += 100;
  if (strcmp(miss, "playwrites") == 0 && strcmp(line, "playwrights") == 0) score += 100;
  if (strcmp(miss, "pleasent") == 0 && strcmp(line, "pleasant") == 0) score += 100;
  if (strcmp(miss, "poenis") == 0 && strcmp(line, "penis") == 0) score += 100;
  if (strcmp(miss, "poeoples") == 0 && strcmp(line, "peoples") == 0) score += 100;
  if (strcmp(miss, "poety") == 0 && strcmp(line, "poetry") == 0) score += 100;
  if (strcmp(miss, "poisin") == 0 && strcmp(line, "poison") == 0) score += 100;
  if (strcmp(miss, "polical") == 0 && strcmp(line, "political") == 0) score += 100;
  if (strcmp(miss, "polysaccharid") == 0 && strcmp(line, "polysaccharide") == 0) score += 100;
  if (strcmp(miss, "pomotion") == 0 && strcmp(line, "promotion") == 0) score += 100;
  if (strcmp(miss, "poportional") == 0 && strcmp(line, "proportional") == 0) score += 100;
  if (strcmp(miss, "populare") == 0 && strcmp(line, "popular") == 0) score += 100;
  if (strcmp(miss, "populer") == 0 && strcmp(line, "popular") == 0) score += 100;
  if (strcmp(miss, "porshan") == 0 && strcmp(line, "portion") == 0) score += 100;
  if (strcmp(miss, "porshon") == 0 && strcmp(line, "portion") == 0) score += 100;
  if (strcmp(miss, "portuguease") == 0 && strcmp(line, "portuguese") == 0) score += 100;
  if (strcmp(miss, "portugues") == 0 && strcmp(line, "Portuguese") == 0) score += 100;
  if (strcmp(miss, "posion") == 0 && strcmp(line, "poison") == 0) score += 100;
  if (strcmp(miss, "positon") == 0 && strcmp(line, "position, positron") == 0) score += 100;
  if (strcmp(miss, "possessess") == 0 && strcmp(line, "possesses") == 0) score += 100;
  if (strcmp(miss, "possition") == 0 && strcmp(line, "position") == 0) score += 100;
  if (strcmp(miss, "potatos") == 0 && strcmp(line, "potatoes") == 0) score += 100;
  if (strcmp(miss, "poverful") == 0 && strcmp(line, "powerful") == 0) score += 100;
  if (strcmp(miss, "powerfull") == 0 && strcmp(line, "powerful") == 0) score += 100;
  if (strcmp(miss, "practial") == 0 && strcmp(line, "practical") == 0) score += 100;
  if (strcmp(miss, "practicly") == 0 && strcmp(line, "practically") == 0) score += 100;
  if (strcmp(miss, "practioners") == 0 && strcmp(line, "practitioners") == 0) score += 100;
  if (strcmp(miss, "prairy") == 0 && strcmp(line, "prairie") == 0) score += 100;
  if (strcmp(miss, "preample") == 0 && strcmp(line, "preamble") == 0) score += 100;
  if (strcmp(miss, "preceed") == 0 && strcmp(line, "precede") == 0) score += 100;
  if (strcmp(miss, "preceeded") == 0 && strcmp(line, "preceded") == 0) score += 100;
  if (strcmp(miss, "preceeding") == 0 && strcmp(line, "preceding") == 0) score += 100;
  if (strcmp(miss, "preceeds") == 0 && strcmp(line, "precedes") == 0) score += 100;
  if (strcmp(miss, "precentage") == 0 && strcmp(line, "percentage") == 0) score += 100;
  if (strcmp(miss, "precice") == 0 && strcmp(line, "precise") == 0) score += 100;
  if (strcmp(miss, "precurser") == 0 && strcmp(line, "precursor") == 0) score += 100;
  if (strcmp(miss, "predicatble") == 0 && strcmp(line, "predictable") == 0) score += 100;
  if (strcmp(miss, "predicitons") == 0 && strcmp(line, "predictions") == 0) score += 100;
  if (strcmp(miss, "predomiantly") == 0 && strcmp(line, "predominately") == 0) score += 100;
  if (strcmp(miss, "preiod") == 0 && strcmp(line, "period") == 0) score += 100;
  if (strcmp(miss, "preliferation") == 0 && strcmp(line, "proliferation") == 0) score += 100;
  if (strcmp(miss, "premeire") == 0 && strcmp(line, "premiere") == 0) score += 100;
  if (strcmp(miss, "premission") == 0 && strcmp(line, "permission") == 0) score += 100;
  if (strcmp(miss, "prepair") == 0 && strcmp(line, "prepare") == 0) score += 100;
  if (strcmp(miss, "prepatory") == 0 && strcmp(line, "preparatory") == 0) score += 100;
  if (strcmp(miss, "preperation") == 0 && strcmp(line, "preparation") == 0) score += 100;
  if (strcmp(miss, "preperations") == 0 && strcmp(line, "preparations") == 0) score += 100;
  if (strcmp(miss, "preriod") == 0 && strcmp(line, "period") == 0) score += 100;
  if (strcmp(miss, "presense") == 0 && strcmp(line, "presence") == 0) score += 100;
  if (strcmp(miss, "presidenital") == 0 && strcmp(line, "presidential") == 0) score += 100;
  if (strcmp(miss, "presidental") == 0 && strcmp(line, "presidential") == 0) score += 100;
  if (strcmp(miss, "prespective") == 0 && strcmp(line, "perspective") == 0) score += 100;
  if (strcmp(miss, "prestigeous") == 0 && strcmp(line, "prestigious") == 0) score += 100;
  if (strcmp(miss, "presumabely") == 0 && strcmp(line, "presumably") == 0) score += 100;
  if (strcmp(miss, "pretection") == 0 && strcmp(line, "protection") == 0) score += 100;
  if (strcmp(miss, "prevelant") == 0 && strcmp(line, "prevalent") == 0) score += 100;
  if (strcmp(miss, "preverse") == 0 && strcmp(line, "perverse") == 0) score += 100;
  if (strcmp(miss, "previvous") == 0 && strcmp(line, "previous") == 0) score += 100;
  if (strcmp(miss, "primarly") == 0 && strcmp(line, "primarily") == 0) score += 100;
  if (strcmp(miss, "primative") == 0 && strcmp(line, "primitive") == 0) score += 100;
  if (strcmp(miss, "primatively") == 0 && strcmp(line, "primitively") == 0) score += 100;
  if (strcmp(miss, "primordal") == 0 && strcmp(line, "primordial") == 0) score += 100;
  if (strcmp(miss, "principaly") == 0 && strcmp(line, "principality") == 0) score += 100;
  if (strcmp(miss, "principial") == 0 && strcmp(line, "principal") == 0) score += 100;
  if (strcmp(miss, "principly") == 0 && strcmp(line, "principally") == 0) score += 100;
  if (strcmp(miss, "probabilaty") == 0 && strcmp(line, "probability") == 0) score += 100;
  if (strcmp(miss, "probablly") == 0 && strcmp(line, "probably") == 0) score += 100;
  if (strcmp(miss, "probalibity") == 0 && strcmp(line, "probability") == 0) score += 100;
  if (strcmp(miss, "probaly") == 0 && strcmp(line, "probably") == 0) score += 100;
  if (strcmp(miss, "procede") == 0 && strcmp(line, "proceed, precede") == 0) score += 100;
  if (strcmp(miss, "proceded") == 0 && strcmp(line, "proceeded, preceded") == 0) score += 100;
  if (strcmp(miss, "procedes") == 0 && strcmp(line, "proceeds, precedes") == 0) score += 100;
  if (strcmp(miss, "procedger") == 0 && strcmp(line, "procedure") == 0) score += 100;
  if (strcmp(miss, "proceding") == 0 && strcmp(line, "proceeding, preceding") == 0) score += 100;
  if (strcmp(miss, "proces") == 0 && strcmp(line, "process") == 0) score += 100;
  if (strcmp(miss, "processer") == 0 && strcmp(line, "processor") == 0) score += 100;
  if (strcmp(miss, "proclomation") == 0 && strcmp(line, "proclamation") == 0) score += 100;
  if (strcmp(miss, "profesion") == 0 && strcmp(line, "profusion, profession") == 0) score += 100;
  if (strcmp(miss, "professer") == 0 && strcmp(line, "professor") == 0) score += 100;
  if (strcmp(miss, "profilic") == 0 && strcmp(line, "prolific") == 0) score += 100;
  if (strcmp(miss, "progidy") == 0 && strcmp(line, "prodigy") == 0) score += 100;
  if (strcmp(miss, "progrom") == 0 && strcmp(line, "pogrom, program") == 0) score += 100;
  if (strcmp(miss, "progroms") == 0 && strcmp(line, "pogroms, programs") == 0) score += 100;
  if (strcmp(miss, "prohabition") == 0 && strcmp(line, "prohibition") == 0) score += 100;
  if (strcmp(miss, "prominant") == 0 && strcmp(line, "prominent") == 0) score += 100;
  if (strcmp(miss, "prominantly") == 0 && strcmp(line, "prominently") == 0) score += 100;
  if (strcmp(miss, "prominately") == 0 && strcmp(line, "prominently, predominately") == 0) score += 100;
  if (strcmp(miss, "promotted") == 0 && strcmp(line, "promoted") == 0) score += 100;
  if (strcmp(miss, "pronomial") == 0 && strcmp(line, "pronominal") == 0) score += 100;
  if (strcmp(miss, "prophacy") == 0 && strcmp(line, "prophecy") == 0) score += 100;
  if (strcmp(miss, "propogate") == 0 && strcmp(line, "propagate") == 0) score += 100;
  if (strcmp(miss, "propogates") == 0 && strcmp(line, "propagates") == 0) score += 100;
  if (strcmp(miss, "propogation") == 0 && strcmp(line, "propagation") == 0) score += 100;
  if (strcmp(miss, "propper") == 0 && strcmp(line, "proper") == 0) score += 100;
  if (strcmp(miss, "proprietory") == 0 && strcmp(line, "proprietary") == 0) score += 100;
  if (strcmp(miss, "proseletyzing") == 0 && strcmp(line, "proselytizing") == 0) score += 100;
  if (strcmp(miss, "protaganist") == 0 && strcmp(line, "protagonist") == 0) score += 100;
  if (strcmp(miss, "protaganists") == 0 && strcmp(line, "protagonists") == 0) score += 100;
  if (strcmp(miss, "protocal") == 0 && strcmp(line, "protocol") == 0) score += 100;
  if (strcmp(miss, "protoganist") == 0 && strcmp(line, "protagonist") == 0) score += 100;
  if (strcmp(miss, "protrayed") == 0 && strcmp(line, "portrayed") == 0) score += 100;
  if (strcmp(miss, "prouncements") == 0 && strcmp(line, "pronouncements") == 0) score += 100;
  if (strcmp(miss, "provacative") == 0 && strcmp(line, "provocative") == 0) score += 100;
  if (strcmp(miss, "provisiosn") == 0 && strcmp(line, "provision") == 0) score += 100;
  if (strcmp(miss, "pseudononymous") == 0 && strcmp(line, "pseudonymous") == 0) score += 100;
  if (strcmp(miss, "publically") == 0 && strcmp(line, "publicly") == 0) score += 100;
  if (strcmp(miss, "publicaly") == 0 && strcmp(line, "publicly") == 0) score += 100;
  if (strcmp(miss, "publisherr") == 0 && strcmp(line, "publisher") == 0) score += 100;
  if (strcmp(miss, "publishre") == 0 && strcmp(line, "publisher") == 0) score += 100;
  if (strcmp(miss, "puchasing") == 0 && strcmp(line, "purchasing") == 0) score += 100;
  if (strcmp(miss, "purposedly") == 0 && strcmp(line, "purposely") == 0) score += 100;
  if (strcmp(miss, "pursuade") == 0 && strcmp(line, "persuade") == 0) score += 100;
  if (strcmp(miss, "pursuades") == 0 && strcmp(line, "persuades") == 0) score += 100;
  if (strcmp(miss, "pususading") == 0 && strcmp(line, "persuading") == 0) score += 100;
  if (strcmp(miss, "pwoer") == 0 && strcmp(line, "power") == 0) score += 100;
  if (strcmp(miss, "pyscic") == 0 && strcmp(line, "psychic") == 0) score += 100;
  if (strcmp(miss, "qtuie") == 0 && strcmp(line, "quite, quiet") == 0) score += 100;
  if (strcmp(miss, "quantaty") == 0 && strcmp(line, "quantity") == 0) score += 100;
  if (strcmp(miss, "quantitiy") == 0 && strcmp(line, "quantity") == 0) score += 100;
  if (strcmp(miss, "quicklyu") == 0 && strcmp(line, "quickly") == 0) score += 100;
  if (strcmp(miss, "quitted") == 0 && strcmp(line, "quit") == 0) score += 100;
  if (strcmp(miss, "qutie") == 0 && strcmp(line, "quite, quiet") == 0) score += 100;
  if (strcmp(miss, "radify") == 0 && strcmp(line, "ratify") == 0) score += 100;
  if (strcmp(miss, "raelly") == 0 && strcmp(line, "really") == 0) score += 100;
  if (strcmp(miss, "rarified") == 0 && strcmp(line, "rarefied") == 0) score += 100;
  if (strcmp(miss, "reaccurring") == 0 && strcmp(line, "recurring") == 0) score += 100;
  if (strcmp(miss, "readmition") == 0 && strcmp(line, "readmission") == 0) score += 100;
  if (strcmp(miss, "realitvely") == 0 && strcmp(line, "relatively") == 0) score += 100;
  if (strcmp(miss, "realtions") == 0 && strcmp(line, "relations") == 0) score += 100;
  if (strcmp(miss, "realyl") == 0 && strcmp(line, "really") == 0) score += 100;
  if (strcmp(miss, "rebounce") == 0 && strcmp(line, "rebound") == 0) score += 100;
  if (strcmp(miss, "receeding") == 0 && strcmp(line, "receding") == 0) score += 100;
  if (strcmp(miss, "receivedfrom") == 0 && strcmp(line, "received from") == 0) score += 100;
  if (strcmp(miss, "recepient") == 0 && strcmp(line, "recipient") == 0) score += 100;
  if (strcmp(miss, "recepients") == 0 && strcmp(line, "recipients") == 0) score += 100;
  if (strcmp(miss, "reched") == 0 && strcmp(line, "reached") == 0) score += 100;
  if (strcmp(miss, "recide") == 0 && strcmp(line, "reside") == 0) score += 100;
  if (strcmp(miss, "recided") == 0 && strcmp(line, "resided") == 0) score += 100;
  if (strcmp(miss, "recident") == 0 && strcmp(line, "resident") == 0) score += 100;
  if (strcmp(miss, "recidents") == 0 && strcmp(line, "residents") == 0) score += 100;
  if (strcmp(miss, "reciding") == 0 && strcmp(line, "residing") == 0) score += 100;
  if (strcmp(miss, "reciepents") == 0 && strcmp(line, "recipients") == 0) score += 100;
  if (strcmp(miss, "reciever") == 0 && strcmp(line, "receiver") == 0) score += 100;
  if (strcmp(miss, "recievers") == 0 && strcmp(line, "receivers") == 0) score += 100;
  if (strcmp(miss, "recieving") == 0 && strcmp(line, "receiving") == 0) score += 100;
  if (strcmp(miss, "recipiant") == 0 && strcmp(line, "recipient") == 0) score += 100;
  if (strcmp(miss, "recipiants") == 0 && strcmp(line, "recipients") == 0) score += 100;
  if (strcmp(miss, "recompence") == 0 && strcmp(line, "recompense") == 0) score += 100;
  if (strcmp(miss, "reconcilation") == 0 && strcmp(line, "reconciliation") == 0) score += 100;
  if (strcmp(miss, "recordproducer") == 0 && strcmp(line, "record producer") == 0) score += 100;
  if (strcmp(miss, "recquired") == 0 && strcmp(line, "required") == 0) score += 100;
  if (strcmp(miss, "recrod") == 0 && strcmp(line, "record") == 0) score += 100;
  if (strcmp(miss, "rediculous") == 0 && strcmp(line, "ridiculous") == 0) score += 100;
  if (strcmp(miss, "reedeming") == 0 && strcmp(line, "redeeming") == 0) score += 100;
  if (strcmp(miss, "reenforced") == 0 && strcmp(line, "reinforced") == 0) score += 100;
  if (strcmp(miss, "refect") == 0 && strcmp(line, "reflect") == 0) score += 100;
  if (strcmp(miss, "referece") == 0 && strcmp(line, "reference") == 0) score += 100;
  if (strcmp(miss, "referemces") == 0 && strcmp(line, "references") == 0) score += 100;
  if (strcmp(miss, "referencs") == 0 && strcmp(line, "references") == 0) score += 100;
  if (strcmp(miss, "referiang") == 0 && strcmp(line, "referring") == 0) score += 100;
  if (strcmp(miss, "refering") == 0 && strcmp(line, "referring") == 0) score += 100;
  if (strcmp(miss, "refernce") == 0 && strcmp(line, "reference, references") == 0) score += 100;
  if (strcmp(miss, "referrs") == 0 && strcmp(line, "refers") == 0) score += 100;
  if (strcmp(miss, "reffered") == 0 && strcmp(line, "referred") == 0) score += 100;
  if (strcmp(miss, "reffering") == 0 && strcmp(line, "referring") == 0) score += 100;
  if (strcmp(miss, "refusla") == 0 && strcmp(line, "refusal") == 0) score += 100;
  if (strcmp(miss, "regardes") == 0 && strcmp(line, "regards") == 0) score += 100;
  if (strcmp(miss, "reigining") == 0 && strcmp(line, "reigning") == 0) score += 100;
  if (strcmp(miss, "reknowned") == 0 && strcmp(line, "renowned") == 0) score += 100;
  if (strcmp(miss, "rela") == 0 && strcmp(line, "real") == 0) score += 100;
  if (strcmp(miss, "relected") == 0 && strcmp(line, "reelected") == 0) score += 100;
  if (strcmp(miss, "releive") == 0 && strcmp(line, "relieve") == 0) score += 100;
  if (strcmp(miss, "releived") == 0 && strcmp(line, "relieved") == 0) score += 100;
  if (strcmp(miss, "relevent") == 0 && strcmp(line, "relevant") == 0) score += 100;
  if (strcmp(miss, "relient") == 0 && strcmp(line, "reliant") == 0) score += 100;
  if (strcmp(miss, "relized") == 0 && strcmp(line, "realised, realized") == 0) score += 100;
  if (strcmp(miss, "relpacement") == 0 && strcmp(line, "replacement") == 0) score += 100;
  if (strcmp(miss, "remaing") == 0 && strcmp(line, "remaining") == 0) score += 100;
  if (strcmp(miss, "rememberable") == 0 && strcmp(line, "memorable") == 0) score += 100;
  if (strcmp(miss, "remembrence") == 0 && strcmp(line, "remembrance") == 0) score += 100;
  if (strcmp(miss, "reminent") == 0 && strcmp(line, "remnant") == 0) score += 100;
  if (strcmp(miss, "renedered") == 0 && strcmp(line, "rende") == 0) score += 100;
  if (strcmp(miss, "renewl") == 0 && strcmp(line, "renewal") == 0) score += 100;
  if (strcmp(miss, "rennovate") == 0 && strcmp(line, "renovate") == 0) score += 100;
  if (strcmp(miss, "rentors") == 0 && strcmp(line, "renters") == 0) score += 100;
  if (strcmp(miss, "reoccurrence") == 0 && strcmp(line, "recurrence") == 0) score += 100;
  if (strcmp(miss, "reorganision") == 0 && strcmp(line, "reorganisation") == 0) score += 100;
  if (strcmp(miss, "repatition") == 0 && strcmp(line, "repetition, repartition") == 0) score += 100;
  if (strcmp(miss, "repectively") == 0 && strcmp(line, "respectively") == 0) score += 100;
  if (strcmp(miss, "repentent") == 0 && strcmp(line, "repentant") == 0) score += 100;
  if (strcmp(miss, "repeteadly") == 0 && strcmp(line, "repeatedly") == 0) score += 100;
  if (strcmp(miss, "repetion") == 0 && strcmp(line, "repetition") == 0) score += 100;
  if (strcmp(miss, "repid") == 0 && strcmp(line, "rapid") == 0) score += 100;
  if (strcmp(miss, "reponsible") == 0 && strcmp(line, "responsible") == 0) score += 100;
  if (strcmp(miss, "reportadly") == 0 && strcmp(line, "reportedly") == 0) score += 100;
  if (strcmp(miss, "representive") == 0 && strcmp(line, "representative") == 0) score += 100;
  if (strcmp(miss, "representives") == 0 && strcmp(line, "representatives") == 0) score += 100;
  if (strcmp(miss, "repsectively") == 0 && strcmp(line, "respectively") == 0) score += 100;
  if (strcmp(miss, "republi") == 0 && strcmp(line, "republic") == 0) score += 100;
  if (strcmp(miss, "republian") == 0 && strcmp(line, "republican") == 0) score += 100;
  if (strcmp(miss, "republis") == 0 && strcmp(line, "republics") == 0) score += 100;
  if (strcmp(miss, "resemblence") == 0 && strcmp(line, "resemblance") == 0) score += 100;
  if (strcmp(miss, "resignement") == 0 && strcmp(line, "resignment") == 0) score += 100;
  if (strcmp(miss, "resistable") == 0 && strcmp(line, "resistible") == 0) score += 100;
  if (strcmp(miss, "resistence") == 0 && strcmp(line, "resistance") == 0) score += 100;
  if (strcmp(miss, "resistent") == 0 && strcmp(line, "resistant") == 0) score += 100;
  if (strcmp(miss, "responce") == 0 && strcmp(line, "response") == 0) score += 100;
  if (strcmp(miss, "responsability") == 0 && strcmp(line, "responsibility") == 0) score += 100;
  if (strcmp(miss, "responsibilites") == 0 && strcmp(line, "responsibilities") == 0) score += 100;
  if (strcmp(miss, "ressemble") == 0 && strcmp(line, "resemble") == 0) score += 100;
  if (strcmp(miss, "restaraunt") == 0 && strcmp(line, "restaurant") == 0) score += 100;
  if (strcmp(miss, "restaraunts") == 0 && strcmp(line, "restaurants") == 0) score += 100;
  if (strcmp(miss, "restauration") == 0 && strcmp(line, "restoration") == 0) score += 100;
  if (strcmp(miss, "resteraunt") == 0 && strcmp(line, "restaurant") == 0) score += 100;
  if (strcmp(miss, "resteraunts") == 0 && strcmp(line, "restaurants") == 0) score += 100;
  if (strcmp(miss, "restraunt") == 0 && strcmp(line, "restraint, restaurant") == 0) score += 100;
  if (strcmp(miss, "resturaunts") == 0 && strcmp(line, "restaurants") == 0) score += 100;
  if (strcmp(miss, "retreive") == 0 && strcmp(line, "retrieve") == 0) score += 100;
  if (strcmp(miss, "returnd") == 0 && strcmp(line, "returned") == 0) score += 100;
  if (strcmp(miss, "revaluated") == 0 && strcmp(line, "reevaluated") == 0) score += 100;
  if (strcmp(miss, "reveral") == 0 && strcmp(line, "reversal") == 0) score += 100;
  if (strcmp(miss, "reversable") == 0 && strcmp(line, "reversible") == 0) score += 100;
  if (strcmp(miss, "revolutionar") == 0 && strcmp(line, "revolutionary") == 0) score += 100;
  if (strcmp(miss, "rewriet") == 0 && strcmp(line, "rewrite") == 0) score += 100;
  if (strcmp(miss, "rigeur") == 0 && strcmp(line, "rigueur, rigour, rigor") == 0) score += 100;
  if (strcmp(miss, "rigourous") == 0 && strcmp(line, "rigorous") == 0) score += 100;
  if (strcmp(miss, "rininging") == 0 && strcmp(line, "ringing") == 0) score += 100;
  if (strcmp(miss, "rised") == 0 && strcmp(line, "raised, rose") == 0) score += 100;
  if (strcmp(miss, "rucuperate") == 0 && strcmp(line, "recuperate") == 0) score += 100;
  if (strcmp(miss, "russina") == 0 && strcmp(line, "Russian") == 0) score += 100;
  if (strcmp(miss, "rwite") == 0 && strcmp(line, "write") == 0) score += 100;
  if (strcmp(miss, "rythem") == 0 && strcmp(line, "rhythm") == 0) score += 100;
  if (strcmp(miss, "rythim") == 0 && strcmp(line, "rhythm") == 0) score += 100;
  if (strcmp(miss, "sacrifical") == 0 && strcmp(line, "sacrificial") == 0) score += 100;
  if (strcmp(miss, "sargant") == 0 && strcmp(line, "sergeant") == 0) score += 100;
  if (strcmp(miss, "sargeant") == 0 && strcmp(line, "sergeant") == 0) score += 100;
  if (strcmp(miss, "sasy") == 0 && strcmp(line, "says, sassy") == 0) score += 100;
  if (strcmp(miss, "saveing") == 0 && strcmp(line, "saving") == 0) score += 100;
  if (strcmp(miss, "scaleable") == 0 && strcmp(line, "scalable") == 0) score += 100;
  if (strcmp(miss, "scandanavia") == 0 && strcmp(line, "Scandinavia") == 0) score += 100;
  if (strcmp(miss, "schedual") == 0 && strcmp(line, "schedule") == 0) score += 100;
  if (strcmp(miss, "scholarstic") == 0 && strcmp(line, "scholastic, scholarly") == 0) score += 100;
  if (strcmp(miss, "scientis") == 0 && strcmp(line, "scientist") == 0) score += 100;
  if (strcmp(miss, "scrutinity") == 0 && strcmp(line, "scrutiny") == 0) score += 100;
  if (strcmp(miss, "secceeded") == 0 && strcmp(line, "seceded, succeeded") == 0) score += 100;
  if (strcmp(miss, "seceed") == 0 && strcmp(line, "succeed, secede") == 0) score += 100;
  if (strcmp(miss, "seceeded") == 0 && strcmp(line, "succeeded, seceded") == 0) score += 100;
  if (strcmp(miss, "secretery") == 0 && strcmp(line, "secretary") == 0) score += 100;
  if (strcmp(miss, "seeked") == 0 && strcmp(line, "sought") == 0) score += 100;
  if (strcmp(miss, "seguoys") == 0 && strcmp(line, "segues") == 0) score += 100;
  if (strcmp(miss, "seige") == 0 && strcmp(line, "siege") == 0) score += 100;
  if (strcmp(miss, "seinor") == 0 && strcmp(line, "senior") == 0) score += 100;
  if (strcmp(miss, "seldomly") == 0 && strcmp(line, "seldom") == 0) score += 100;
  if (strcmp(miss, "senarios") == 0 && strcmp(line, "scenarios") == 0) score += 100;
  if (strcmp(miss, "sence") == 0 && strcmp(line, "sense, since") == 0) score += 100;
  if (strcmp(miss, "sensure") == 0 && strcmp(line, "censure") == 0) score += 100;
  if (strcmp(miss, "seperates") == 0 && strcmp(line, "separates") == 0) score += 100;
  if (strcmp(miss, "seperation") == 0 && strcmp(line, "separation") == 0) score += 100;
  if (strcmp(miss, "sepina") == 0 && strcmp(line, "subpoena") == 0) score += 100;
  if (strcmp(miss, "sepulchure") == 0 && strcmp(line, "sepulchre, sepulcher") == 0) score += 100;
  if (strcmp(miss, "sepulcre") == 0 && strcmp(line, "sepulchre, sepulcher") == 0) score += 100;
  if (strcmp(miss, "serendipiyt") == 0 && strcmp(line, "serendipity") == 0) score += 100;
  if (strcmp(miss, "sergent") == 0 && strcmp(line, "sergeant") == 0) score += 100;
  if (strcmp(miss, "severley") == 0 && strcmp(line, "severely") == 0) score += 100;
  if (strcmp(miss, "severly") == 0 && strcmp(line, "severely") == 0) score += 100;
  if (strcmp(miss, "shadasloo") == 0 && strcmp(line, "shadaloo") == 0) score += 100;
  if (strcmp(miss, "shadoloo") == 0 && strcmp(line, "shadaloo") == 0) score += 100;
  if (strcmp(miss, "shamen") == 0 && strcmp(line, "shaman, shamans") == 0) score += 100;
  if (strcmp(miss, "sheat") == 0 && strcmp(line, "sheath, sheet, cheat") == 0) score += 100;
  if (strcmp(miss, "sherif") == 0 && strcmp(line, "sheriff") == 0) score += 100;
  if (strcmp(miss, "shineing") == 0 && strcmp(line, "shining") == 0) score += 100;
  if (strcmp(miss, "shorly") == 0 && strcmp(line, "shortly") == 0) score += 100;
  if (strcmp(miss, "shortwhile") == 0 && strcmp(line, "short while") == 0) score += 100;
  if (strcmp(miss, "shoudl") == 0 && strcmp(line, "should") == 0) score += 100;
  if (strcmp(miss, "shouldnt") == 0 && strcmp(line, "should not") == 0) score += 100;
  if (strcmp(miss, "shreak") == 0 && strcmp(line, "shriek") == 0) score += 100;
  if (strcmp(miss, "shrinked") == 0 && strcmp(line, "shrunk") == 0) score += 100;
  if (strcmp(miss, "sicne") == 0 && strcmp(line, "since") == 0) score += 100;
  if (strcmp(miss, "sieze") == 0 && strcmp(line, "seize, size") == 0) score += 100;
  if (strcmp(miss, "siezed") == 0 && strcmp(line, "seized, sized") == 0) score += 100;
  if (strcmp(miss, "siezing") == 0 && strcmp(line, "seizing, sizing") == 0) score += 100;
  if (strcmp(miss, "siezure") == 0 && strcmp(line, "seizure") == 0) score += 100;
  if (strcmp(miss, "siezures") == 0 && strcmp(line, "seizures") == 0) score += 100;
  if (strcmp(miss, "signitories") == 0 && strcmp(line, "signatories") == 0) score += 100;
  if (strcmp(miss, "simpley") == 0 && strcmp(line, "simply") == 0) score += 100;
  if (strcmp(miss, "simplier") == 0 && strcmp(line, "simpler") == 0) score += 100;
  if (strcmp(miss, "sinse") == 0 && strcmp(line, "sines, since") == 0) score += 100;
  if (strcmp(miss, "slippy") == 0 && strcmp(line, "slippery") == 0) score += 100;
  if (strcmp(miss, "slowy") == 0 && strcmp(line, "slowly") == 0) score += 100;
  if (strcmp(miss, "smae") == 0 && strcmp(line, "same") == 0) score += 100;
  if (strcmp(miss, "smoe") == 0 && strcmp(line, "some") == 0) score += 100;
  if (strcmp(miss, "sneeks") == 0 && strcmp(line, "sneaks") == 0) score += 100;
  if (strcmp(miss, "soem") == 0 && strcmp(line, "some") == 0) score += 100;
  if (strcmp(miss, "sohw") == 0 && strcmp(line, "show") == 0) score += 100;
  if (strcmp(miss, "soilders") == 0 && strcmp(line, "soldiers") == 0) score += 100;
  if (strcmp(miss, "soley") == 0 && strcmp(line, "solely") == 0) score += 100;
  if (strcmp(miss, "soliders") == 0 && strcmp(line, "soldiers") == 0) score += 100;
  if (strcmp(miss, "sophicated") == 0 && strcmp(line, "sophisticated") == 0) score += 100;
  if (strcmp(miss, "sorrounding") == 0 && strcmp(line, "surrounding") == 0) score += 100;
  if (strcmp(miss, "sotry") == 0 && strcmp(line, "story") == 0) score += 100;
  if (strcmp(miss, "sotyr") == 0 && strcmp(line, "satyr, story") == 0) score += 100;
  if (strcmp(miss, "soudn") == 0 && strcmp(line, "sound") == 0) score += 100;
  if (strcmp(miss, "soudns") == 0 && strcmp(line, "sounds") == 0) score += 100;
  if (strcmp(miss, "sould") == 0 && strcmp(line, "could, should, sold, soul") == 0) score += 100;
  if (strcmp(miss, "souvenier") == 0 && strcmp(line, "souvenir") == 0) score += 100;
  if (strcmp(miss, "souveniers") == 0 && strcmp(line, "souvenirs") == 0) score += 100;
  if (strcmp(miss, "spainish") == 0 && strcmp(line, "Spanish") == 0) score += 100;
  if (strcmp(miss, "speciallized") == 0 && strcmp(line, "specialised, specialized") == 0) score += 100;
  if (strcmp(miss, "specif") == 0 && strcmp(line, "specific, specify") == 0) score += 100;
  if (strcmp(miss, "speciman") == 0 && strcmp(line, "specimen") == 0) score += 100;
  if (strcmp(miss, "spects") == 0 && strcmp(line, "aspects, expects") == 0) score += 100;
  if (strcmp(miss, "spectum") == 0 && strcmp(line, "spectrum") == 0) score += 100;
  if (strcmp(miss, "speices") == 0 && strcmp(line, "species") == 0) score += 100;
  if (strcmp(miss, "spermatozoan") == 0 && strcmp(line, "spermatozoon") == 0) score += 100;
  if (strcmp(miss, "sponser") == 0 && strcmp(line, "sponsor") == 0) score += 100;
  if (strcmp(miss, "spoonfulls") == 0 && strcmp(line, "spoonfuls") == 0) score += 100;
  if (strcmp(miss, "spreaded") == 0 && strcmp(line, "spread") == 0) score += 100;
  if (strcmp(miss, "spred") == 0 && strcmp(line, "spread") == 0) score += 100;
  if (strcmp(miss, "stainlees") == 0 && strcmp(line, "stainless") == 0) score += 100;
  if (strcmp(miss, "standars") == 0 && strcmp(line, "standards") == 0) score += 100;
  if (strcmp(miss, "stange") == 0 && strcmp(line, "strange") == 0) score += 100;
  if (strcmp(miss, "startegies") == 0 && strcmp(line, "strategies") == 0) score += 100;
  if (strcmp(miss, "stateman") == 0 && strcmp(line, "statesman") == 0) score += 100;
  if (strcmp(miss, "stilus") == 0 && strcmp(line, "stylus") == 0) score += 100;
  if (strcmp(miss, "stirrs") == 0 && strcmp(line, "stirs") == 0) score += 100;
  if (strcmp(miss, "stlye") == 0 && strcmp(line, "style") == 0) score += 100;
  if (strcmp(miss, "stomache") == 0 && strcmp(line, "stomach") == 0) score += 100;
  if (strcmp(miss, "storeis") == 0 && strcmp(line, "stories") == 0) score += 100;
  if (strcmp(miss, "storise") == 0 && strcmp(line, "stories") == 0) score += 100;
  if (strcmp(miss, "stoyr") == 0 && strcmp(line, "story") == 0) score += 100;
  if (strcmp(miss, "stpo") == 0 && strcmp(line, "stop") == 0) score += 100;
  if (strcmp(miss, "stradegies") == 0 && strcmp(line, "strategies") == 0) score += 100;
  if (strcmp(miss, "strat") == 0 && strcmp(line, "start, strata") == 0) score += 100;
  if (strcmp(miss, "strenght") == 0 && strcmp(line, "strength") == 0) score += 100;
  if (strcmp(miss, "strenghten") == 0 && strcmp(line, "strengthen") == 0) score += 100;
  if (strcmp(miss, "strenuos") == 0 && strcmp(line, "strenuous") == 0) score += 100;
  if (strcmp(miss, "strictist") == 0 && strcmp(line, "strictest") == 0) score += 100;
  if (strcmp(miss, "strikely") == 0 && strcmp(line, "strikingly") == 0) score += 100;
  if (strcmp(miss, "strnad") == 0 && strcmp(line, "strand") == 0) score += 100;
  if (strcmp(miss, "stroy") == 0 && strcmp(line, "story, destroy") == 0) score += 100;
  if (strcmp(miss, "structuer") == 0 && strcmp(line, "structure") == 0) score += 100;
  if (strcmp(miss, "stuctured") == 0 && strcmp(line, "structured") == 0) score += 100;
  if (strcmp(miss, "studdy") == 0 && strcmp(line, "study") == 0) score += 100;
  if (strcmp(miss, "studing") == 0 && strcmp(line, "studying") == 0) score += 100;
  if (strcmp(miss, "stuggling") == 0 && strcmp(line, "struggling") == 0) score += 100;
  if (strcmp(miss, "subdivisio") == 0 && strcmp(line, "subdivision") == 0) score += 100;
  if (strcmp(miss, "submachne") == 0 && strcmp(line, "submachine") == 0) score += 100;
  if (strcmp(miss, "subsiduary") == 0 && strcmp(line, "subsidiary") == 0) score += 100;
  if (strcmp(miss, "substace") == 0 && strcmp(line, "substance") == 0) score += 100;
  if (strcmp(miss, "substancial") == 0 && strcmp(line, "substantial") == 0) score += 100;
  if (strcmp(miss, "substituded") == 0 && strcmp(line, "substituted") == 0) score += 100;
  if (strcmp(miss, "subterranian") == 0 && strcmp(line, "subterranean") == 0) score += 100;
  if (strcmp(miss, "suburburban") == 0 && strcmp(line, "suburban") == 0) score += 100;
  if (strcmp(miss, "succsessfull") == 0 && strcmp(line, "successful") == 0) score += 100;
  if (strcmp(miss, "sucesfuly") == 0 && strcmp(line, "successfully") == 0) score += 100;
  if (strcmp(miss, "sucesion") == 0 && strcmp(line, "succession") == 0) score += 100;
  if (strcmp(miss, "sucessot") == 0 && strcmp(line, "successor") == 0) score += 100;
  if (strcmp(miss, "sucidial") == 0 && strcmp(line, "suicidal") == 0) score += 100;
  if (strcmp(miss, "sudent") == 0 && strcmp(line, "student") == 0) score += 100;
  if (strcmp(miss, "sudents") == 0 && strcmp(line, "students") == 0) score += 100;
  if (strcmp(miss, "suop") == 0 && strcmp(line, "soup") == 0) score += 100;
  if (strcmp(miss, "superceeded") == 0 && strcmp(line, "superseded") == 0) score += 100;
  if (strcmp(miss, "superintendant") == 0 && strcmp(line, "superintendent") == 0) score += 100;
  if (strcmp(miss, "suphisticated") == 0 && strcmp(line, "sophisticated") == 0) score += 100;
  if (strcmp(miss, "supposingly") == 0 && strcmp(line, "supposedly") == 0) score += 100;
  if (strcmp(miss, "suprassing") == 0 && strcmp(line, "surpassing") == 0) score += 100;
  if (strcmp(miss, "suprised") == 0 && strcmp(line, "surprised") == 0) score += 100;
  if (strcmp(miss, "suprising") == 0 && strcmp(line, "surprising") == 0) score += 100;
  if (strcmp(miss, "suprize") == 0 && strcmp(line, "surprise") == 0) score += 100;
  if (strcmp(miss, "suprized") == 0 && strcmp(line, "surprised") == 0) score += 100;
  if (strcmp(miss, "suprizing") == 0 && strcmp(line, "surprising") == 0) score += 100;
  if (strcmp(miss, "surley") == 0 && strcmp(line, "surly, surely") == 0) score += 100;
  if (strcmp(miss, "surplanted") == 0 && strcmp(line, "supplanted") == 0) score += 100;
  if (strcmp(miss, "surpress") == 0 && strcmp(line, "suppress") == 0) score += 100;
  if (strcmp(miss, "surpressed") == 0 && strcmp(line, "suppressed") == 0) score += 100;
  if (strcmp(miss, "surprize") == 0 && strcmp(line, "surprise") == 0) score += 100;
  if (strcmp(miss, "surprized") == 0 && strcmp(line, "surprised") == 0) score += 100;
  if (strcmp(miss, "surprizing") == 0 && strcmp(line, "surprising") == 0) score += 100;
  if (strcmp(miss, "surrended") == 0 && strcmp(line, "surrounded, surrendered") == 0) score += 100;
  if (strcmp(miss, "surrundering") == 0 && strcmp(line, "surrendering") == 0) score += 100;
  if (strcmp(miss, "surveill") == 0 && strcmp(line, "surveil") == 0) score += 100;
  if (strcmp(miss, "surveyer") == 0 && strcmp(line, "surveyor") == 0) score += 100;
  if (strcmp(miss, "surviver") == 0 && strcmp(line, "survivor") == 0) score += 100;
  if (strcmp(miss, "survivers") == 0 && strcmp(line, "survivors") == 0) score += 100;
  if (strcmp(miss, "survivied") == 0 && strcmp(line, "survived") == 0) score += 100;
  if (strcmp(miss, "suspention") == 0 && strcmp(line, "suspension") == 0) score += 100;
  if (strcmp(miss, "swaer") == 0 && strcmp(line, "swear") == 0) score += 100;
  if (strcmp(miss, "swaers") == 0 && strcmp(line, "swears") == 0) score += 100;
  if (strcmp(miss, "swepth") == 0 && strcmp(line, "swept") == 0) score += 100;
  if (strcmp(miss, "syas") == 0 && strcmp(line, "says") == 0) score += 100;
  if (strcmp(miss, "symmetral") == 0 && strcmp(line, "symmetric") == 0) score += 100;
  if (strcmp(miss, "synonomous") == 0 && strcmp(line, "synonymous") == 0) score += 100;
  if (strcmp(miss, "synonymns") == 0 && strcmp(line, "synonyms") == 0) score += 100;
  if (strcmp(miss, "synphony") == 0 && strcmp(line, "symphony") == 0) score += 100;
  if (strcmp(miss, "sysmatically") == 0 && strcmp(line, "systematically") == 0) score += 100;
  if (strcmp(miss, "sytle") == 0 && strcmp(line, "style") == 0) score += 100;
  if (strcmp(miss, "tahn") == 0 && strcmp(line, "than") == 0) score += 100;
  if (strcmp(miss, "taht") == 0 && strcmp(line, "that") == 0) score += 100;
  if (strcmp(miss, "tast") == 0 && strcmp(line, "taste") == 0) score += 100;
  if (strcmp(miss, "tath") == 0 && strcmp(line, "that") == 0) score += 100;
  if (strcmp(miss, "teached") == 0 && strcmp(line, "taught") == 0) score += 100;
  if (strcmp(miss, "teh") == 0 && strcmp(line, "the") == 0) score += 100;
  if (strcmp(miss, "tehy") == 0 && strcmp(line, "they") == 0) score += 100;
  if (strcmp(miss, "telelevision") == 0 && strcmp(line, "television") == 0) score += 100;
  if (strcmp(miss, "tendancies") == 0 && strcmp(line, "tendencies") == 0) score += 100;
  if (strcmp(miss, "tennisplayer") == 0 && strcmp(line, "tennis player") == 0) score += 100;
  if (strcmp(miss, "territorist") == 0 && strcmp(line, "terrorist") == 0) score += 100;
  if (strcmp(miss, "tghe") == 0 && strcmp(line, "the") == 0) score += 100;
  if (strcmp(miss, "theather") == 0 && strcmp(line, "theater") == 0) score += 100;
  if (strcmp(miss, "theif") == 0 && strcmp(line, "thief") == 0) score += 100;
  if (strcmp(miss, "themselfs") == 0 && strcmp(line, "themselves") == 0) score += 100;
  if (strcmp(miss, "ther") == 0 && strcmp(line, "there, their, the") == 0) score += 100;
  if (strcmp(miss, "theri") == 0 && strcmp(line, "their") == 0) score += 100;
  if (strcmp(miss, "thgat") == 0 && strcmp(line, "that") == 0) score += 100;
  if (strcmp(miss, "thge") == 0 && strcmp(line, "the") == 0) score += 100;
  if (strcmp(miss, "thier") == 0 && strcmp(line, "their") == 0) score += 100;
  if (strcmp(miss, "thign") == 0 && strcmp(line, "thing") == 0) score += 100;
  if (strcmp(miss, "thigns") == 0 && strcmp(line, "things") == 0) score += 100;
  if (strcmp(miss, "thigsn") == 0 && strcmp(line, "things") == 0) score += 100;
  if (strcmp(miss, "thikn") == 0 && strcmp(line, "think") == 0) score += 100;
  if (strcmp(miss, "thikning") == 0 && strcmp(line, "thinking, thickening") == 0) score += 100;
  if (strcmp(miss, "thikns") == 0 && strcmp(line, "thinks") == 0) score += 100;
  if (strcmp(miss, "thn") == 0 && strcmp(line, "then") == 0) score += 100;
  if (strcmp(miss, "thna") == 0 && strcmp(line, "than") == 0) score += 100;
  if (strcmp(miss, "thne") == 0 && strcmp(line, "then") == 0) score += 100;
  if (strcmp(miss, "threatend") == 0 && strcmp(line, "threatened") == 0) score += 100;
  if (strcmp(miss, "thrid") == 0 && strcmp(line, "third") == 0) score += 100;
  if (strcmp(miss, "throughly") == 0 && strcmp(line, "thoroughly") == 0) score += 100;
  if (strcmp(miss, "throught") == 0 && strcmp(line, "thought, through, throughout") == 0) score += 100;
  if (strcmp(miss, "thru") == 0 && strcmp(line, "through") == 0) score += 100;
  if (strcmp(miss, "thsi") == 0 && strcmp(line, "this") == 0) score += 100;
  if (strcmp(miss, "thsoe") == 0 && strcmp(line, "those") == 0) score += 100;
  if (strcmp(miss, "thta") == 0 && strcmp(line, "that") == 0) score += 100;
  if (strcmp(miss, "tiem") == 0 && strcmp(line, "time, Tim") == 0) score += 100;
  if (strcmp(miss, "tihkn") == 0 && strcmp(line, "think") == 0) score += 100;
  if (strcmp(miss, "tihs") == 0 && strcmp(line, "this") == 0) score += 100;
  if (strcmp(miss, "timeschedule") == 0 && strcmp(line, "time schedule") == 0) score += 100;
  if (strcmp(miss, "timne") == 0 && strcmp(line, "time") == 0) score += 100;
  if (strcmp(miss, "tiome") == 0 && strcmp(line, "time, tome") == 0) score += 100;
  if (strcmp(miss, "tje") == 0 && strcmp(line, "the") == 0) score += 100;
  if (strcmp(miss, "tjhe") == 0 && strcmp(line, "the") == 0) score += 100;
  if (strcmp(miss, "tjpanishad") == 0 && strcmp(line, "upanishad") == 0) score += 100;
  if (strcmp(miss, "tkae") == 0 && strcmp(line, "take") == 0) score += 100;
  if (strcmp(miss, "tkaes") == 0 && strcmp(line, "takes") == 0) score += 100;
  if (strcmp(miss, "tkaing") == 0 && strcmp(line, "taking") == 0) score += 100;
  if (strcmp(miss, "tlaking") == 0 && strcmp(line, "talking") == 0) score += 100;
  if (strcmp(miss, "todya") == 0 && strcmp(line, "today") == 0) score += 100;
  if (strcmp(miss, "toke") == 0 && strcmp(line, "took") == 0) score += 100;
  if (strcmp(miss, "tomatos") == 0 && strcmp(line, "tomatoes") == 0) score += 100;
  if (strcmp(miss, "tormenters") == 0 && strcmp(line, "tormentors") == 0) score += 100;
  if (strcmp(miss, "tornadoe") == 0 && strcmp(line, "tornado") == 0) score += 100;
  if (strcmp(miss, "torpeados") == 0 && strcmp(line, "torpedoes") == 0) score += 100;
  if (strcmp(miss, "torpedos") == 0 && strcmp(line, "torpedoes") == 0) score += 100;
  if (strcmp(miss, "tothe") == 0 && strcmp(line, "to the") == 0) score += 100;
  if (strcmp(miss, "toubles") == 0 && strcmp(line, "troubles") == 0) score += 100;
  if (strcmp(miss, "tounge") == 0 && strcmp(line, "tongue") == 0) score += 100;
  if (strcmp(miss, "tourch") == 0 && strcmp(line, "torch, touch") == 0) score += 100;
  if (strcmp(miss, "towrad") == 0 && strcmp(line, "toward") == 0) score += 100;
  if (strcmp(miss, "tradionally") == 0 && strcmp(line, "traditionally") == 0) score += 100;
  if (strcmp(miss, "traditionnal") == 0 && strcmp(line, "traditional") == 0) score += 100;
  if (strcmp(miss, "traditition") == 0 && strcmp(line, "tradition") == 0) score += 100;
  if (strcmp(miss, "trafficed") == 0 && strcmp(line, "trafficked") == 0) score += 100;
  if (strcmp(miss, "transcendant") == 0 && strcmp(line, "transcendent") == 0) score += 100;
  if (strcmp(miss, "transcendentational") == 0 && strcmp(line, "transcendental") == 0) score += 100;
  if (strcmp(miss, "transcripting") == 0 && strcmp(line, "transcribing, transcription") == 0) score += 100;
  if (strcmp(miss, "translater") == 0 && strcmp(line, "translator") == 0) score += 100;
  if (strcmp(miss, "translaters") == 0 && strcmp(line, "translators") == 0) score += 100;
  if (strcmp(miss, "triology") == 0 && strcmp(line, "trilogy") == 0) score += 100;
  if (strcmp(miss, "troup") == 0 && strcmp(line, "troupe") == 0) score += 100;
  if (strcmp(miss, "troups") == 0 && strcmp(line, "troupes, troops") == 0) score += 100;
  if (strcmp(miss, "turnk") == 0 && strcmp(line, "turnkey, trunk") == 0) score += 100;
  if (strcmp(miss, "twon") == 0 && strcmp(line, "town") == 0) score += 100;
  if (strcmp(miss, "twpo") == 0 && strcmp(line, "two") == 0) score += 100;
  if (strcmp(miss, "tyhe") == 0 && strcmp(line, "they") == 0) score += 100;
  if (strcmp(miss, "tyrany") == 0 && strcmp(line, "tyranny") == 0) score += 100;
  if (strcmp(miss, "ublisher") == 0 && strcmp(line, "publisher") == 0) score += 100;
  if (strcmp(miss, "uise") == 0 && strcmp(line, "use") == 0) score += 100;
  if (strcmp(miss, "unathorised") == 0 && strcmp(line, "unauthorised") == 0) score += 100;
  if (strcmp(miss, "unavailible") == 0 && strcmp(line, "unavailable") == 0) score += 100;
  if (strcmp(miss, "uncertainity") == 0 && strcmp(line, "uncertainty") == 0) score += 100;
  if (strcmp(miss, "uncompetive") == 0 && strcmp(line, "uncompetitive") == 0) score += 100;
  if (strcmp(miss, "unconfortability") == 0 && strcmp(line, "discomfort") == 0) score += 100;
  if (strcmp(miss, "unconvential") == 0 && strcmp(line, "unconventional") == 0) score += 100;
  if (strcmp(miss, "understoon") == 0 && strcmp(line, "understood") == 0) score += 100;
  if (strcmp(miss, "unequalities") == 0 && strcmp(line, "inequalities") == 0) score += 100;
  if (strcmp(miss, "unfortunatley") == 0 && strcmp(line, "unfortunately") == 0) score += 100;
  if (strcmp(miss, "unilatreal") == 0 && strcmp(line, "unilateral") == 0) score += 100;
  if (strcmp(miss, "univeral") == 0 && strcmp(line, "universal") == 0) score += 100;
  if (strcmp(miss, "unmanouverable") == 0 && strcmp(line, "unmaneuverable, unmanoeuvrable") == 0) score += 100;
  if (strcmp(miss, "unoperational") == 0 && strcmp(line, "nonoperational") == 0) score += 100;
  if (strcmp(miss, "unoticeable") == 0 && strcmp(line, "unnoticeable") == 0) score += 100;
  if (strcmp(miss, "unplease") == 0 && strcmp(line, "displease") == 0) score += 100;
  if (strcmp(miss, "unrepentent") == 0 && strcmp(line, "unrepentant") == 0) score += 100;
  if (strcmp(miss, "unsed") == 0 && strcmp(line, "used, unused, unsaid") == 0) score += 100;
  if (strcmp(miss, "unsucesfuly") == 0 && strcmp(line, "unsuccessfully") == 0) score += 100;
  if (strcmp(miss, "unsurprized") == 0 && strcmp(line, "unsurprised") == 0) score += 100;
  if (strcmp(miss, "unweildly") == 0 && strcmp(line, "unwieldy") == 0) score += 100;
  if (strcmp(miss, "unwieldly") == 0 && strcmp(line, "unwieldy") == 0) score += 100;
  if (strcmp(miss, "upcomming") == 0 && strcmp(line, "upcoming") == 0) score += 100;
  if (strcmp(miss, "upto") == 0 && strcmp(line, "up to") == 0) score += 100;
  if (strcmp(miss, "usally") == 0 && strcmp(line, "usually") == 0) score += 100;
  if (strcmp(miss, "usefull") == 0 && strcmp(line, "useful") == 0) score += 100;
  if (strcmp(miss, "vaccume") == 0 && strcmp(line, "vacuum") == 0) score += 100;
  if (strcmp(miss, "vacinity") == 0 && strcmp(line, "vicinity") == 0) score += 100;
  if (strcmp(miss, "vaguaries") == 0 && strcmp(line, "vagaries") == 0) score += 100;
  if (strcmp(miss, "valetta") == 0 && strcmp(line, "valletta") == 0) score += 100;
  if (strcmp(miss, "varient") == 0 && strcmp(line, "variant") == 0) score += 100;
  if (strcmp(miss, "variey") == 0 && strcmp(line, "variety") == 0) score += 100;
  if (strcmp(miss, "varities") == 0 && strcmp(line, "varieties") == 0) score += 100;
  if (strcmp(miss, "varity") == 0 && strcmp(line, "variety") == 0) score += 100;
  if (strcmp(miss, "vehicule") == 0 && strcmp(line, "vehicle") == 0) score += 100;
  if (strcmp(miss, "vell") == 0 && strcmp(line, "well") == 0) score += 100;
  if (strcmp(miss, "vermillion") == 0 && strcmp(line, "vermilion") == 0) score += 100;
  if (strcmp(miss, "versitilaty") == 0 && strcmp(line, "versatility") == 0) score += 100;
  if (strcmp(miss, "vetween") == 0 && strcmp(line, "between") == 0) score += 100;
  if (strcmp(miss, "veyr") == 0 && strcmp(line, "very") == 0) score += 100;
  if (strcmp(miss, "vigeur") == 0 && strcmp(line, "vigueur, vigour, vigor") == 0) score += 100;
  if (strcmp(miss, "villian") == 0 && strcmp(line, "villain") == 0) score += 100;
  if (strcmp(miss, "villin") == 0 && strcmp(line, "villi, villain, villein") == 0) score += 100;
  if (strcmp(miss, "vincinity") == 0 && strcmp(line, "vicinity") == 0) score += 100;
  if (strcmp(miss, "visting") == 0 && strcmp(line, "visiting") == 0) score += 100;
  if (strcmp(miss, "vitories") == 0 && strcmp(line, "victories") == 0) score += 100;
  if (strcmp(miss, "volcanoe") == 0 && strcmp(line, "volcano") == 0) score += 100;
  if (strcmp(miss, "volumne") == 0 && strcmp(line, "volume") == 0) score += 100;
  if (strcmp(miss, "vreity") == 0 && strcmp(line, "variety") == 0) score += 100;
  if (strcmp(miss, "vrey") == 0 && strcmp(line, "very") == 0) score += 100;
  if (strcmp(miss, "vyer") == 0 && strcmp(line, "very") == 0) score += 100;
  if (strcmp(miss, "vyre") == 0 && strcmp(line, "very") == 0) score += 100;
  if (strcmp(miss, "waht") == 0 && strcmp(line, "what") == 0) score += 100;
  if (strcmp(miss, "warantee") == 0 && strcmp(line, "warranty") == 0) score += 100;
  if (strcmp(miss, "warrriors") == 0 && strcmp(line, "warriors") == 0) score += 100;
  if (strcmp(miss, "wass") == 0 && strcmp(line, "was") == 0) score += 100;
  if (strcmp(miss, "watn") == 0 && strcmp(line, "want") == 0) score += 100;
  if (strcmp(miss, "wayword") == 0 && strcmp(line, "wayward") == 0) score += 100;
  if (strcmp(miss, "weas") == 0 && strcmp(line, "was") == 0) score += 100;
  if (strcmp(miss, "wehn") == 0 && strcmp(line, "when") == 0) score += 100;
  if (strcmp(miss, "weild") == 0 && strcmp(line, "wield, wild") == 0) score += 100;
  if (strcmp(miss, "weilded") == 0 && strcmp(line, "wielded") == 0) score += 100;
  if (strcmp(miss, "wendsay") == 0 && strcmp(line, "Wednesday") == 0) score += 100;
  if (strcmp(miss, "wensday") == 0 && strcmp(line, "Wednesday") == 0) score += 100;
  if (strcmp(miss, "whant") == 0 && strcmp(line, "want") == 0) score += 100;
  if (strcmp(miss, "whants") == 0 && strcmp(line, "wants") == 0) score += 100;
  if (strcmp(miss, "wheras") == 0 && strcmp(line, "whereas") == 0) score += 100;
  if (strcmp(miss, "wherease") == 0 && strcmp(line, "whereas") == 0) score += 100;
  if (strcmp(miss, "whereever") == 0 && strcmp(line, "wherever") == 0) score += 100;
  if (strcmp(miss, "whic") == 0 && strcmp(line, "which") == 0) score += 100;
  if (strcmp(miss, "whith") == 0 && strcmp(line, "with") == 0) score += 100;
  if (strcmp(miss, "whlch") == 0 && strcmp(line, "which") == 0) score += 100;
  if (strcmp(miss, "whn") == 0 && strcmp(line, "when") == 0) score += 100;
  if (strcmp(miss, "wholy") == 0 && strcmp(line, "wholly, holy") == 0) score += 100;
  if (strcmp(miss, "whta") == 0 && strcmp(line, "what") == 0) score += 100;
  if (strcmp(miss, "whther") == 0 && strcmp(line, "whether") == 0) score += 100;
  if (strcmp(miss, "wich") == 0 && strcmp(line, "which, witch") == 0) score += 100;
  if (strcmp(miss, "wief") == 0 && strcmp(line, "wife") == 0) score += 100;
  if (strcmp(miss, "wierd") == 0 && strcmp(line, "weird") == 0) score += 100;
  if (strcmp(miss, "wiew") == 0 && strcmp(line, "view") == 0) score += 100;
  if (strcmp(miss, "wiht") == 0 && strcmp(line, "with") == 0) score += 100;
  if (strcmp(miss, "wille") == 0 && strcmp(line, "will") == 0) score += 100;
  if (strcmp(miss, "willk") == 0 && strcmp(line, "will") == 0) score += 100;
  if (strcmp(miss, "wirting") == 0 && strcmp(line, "writing") == 0) score += 100;
  if (strcmp(miss, "withdrawl") == 0 && strcmp(line, "withdrawal, withdraw") == 0) score += 100;
  if (strcmp(miss, "withh") == 0 && strcmp(line, "with") == 0) score += 100;
  if (strcmp(miss, "withing") == 0 && strcmp(line, "within") == 0) score += 100;
  if (strcmp(miss, "witht") == 0 && strcmp(line, "with") == 0) score += 100;
  if (strcmp(miss, "witn") == 0 && strcmp(line, "with") == 0) score += 100;
  if (strcmp(miss, "wnat") == 0 && strcmp(line, "want") == 0) score += 100;
  if (strcmp(miss, "wnats") == 0 && strcmp(line, "wants") == 0) score += 100;
  if (strcmp(miss, "wohle") == 0 && strcmp(line, "whole") == 0) score += 100;
  if (strcmp(miss, "wokr") == 0 && strcmp(line, "work") == 0) score += 100;
  if (strcmp(miss, "wokring") == 0 && strcmp(line, "working") == 0) score += 100;
  if (strcmp(miss, "worls") == 0 && strcmp(line, "world") == 0) score += 100;
  if (strcmp(miss, "woudl") == 0 && strcmp(line, "would") == 0) score += 100;
  if (strcmp(miss, "wresters") == 0 && strcmp(line, "wrestlers") == 0) score += 100;
  if (strcmp(miss, "wriet") == 0 && strcmp(line, "write") == 0) score += 100;
  if (strcmp(miss, "wroet") == 0 && strcmp(line, "wrote") == 0) score += 100;
  if (strcmp(miss, "wrok") == 0 && strcmp(line, "work") == 0) score += 100;
  if (strcmp(miss, "wroking") == 0 && strcmp(line, "working") == 0) score += 100;
  if (strcmp(miss, "wtih") == 0 && strcmp(line, "with") == 0) score += 100;
  if (strcmp(miss, "wupport") == 0 && strcmp(line, "support") == 0) score += 100;
  if (strcmp(miss, "xenophoby") == 0 && strcmp(line, "xenophobia") == 0) score += 100;
  if (strcmp(miss, "yaer") == 0 && strcmp(line, "year") == 0) score += 100;
  if (strcmp(miss, "yaerly") == 0 && strcmp(line, "yearly") == 0) score += 100;
  if (strcmp(miss, "yaers") == 0 && strcmp(line, "years") == 0) score += 100;
  if (strcmp(miss, "yatch") == 0 && strcmp(line, "yacht") == 0) score += 100;
  if (strcmp(miss, "yearm") == 0 && strcmp(line, "year") == 0) score += 100;
  if (strcmp(miss, "yeasr") == 0 && strcmp(line, "years") == 0) score += 100;
  if (strcmp(miss, "yeild") == 0 && strcmp(line, "yield") == 0) score += 100;
  if (strcmp(miss, "yeilding") == 0 && strcmp(line, "yielding") == 0) score += 100;
  if (strcmp(miss, "yera") == 0 && strcmp(line, "year") == 0) score += 100;
  if (strcmp(miss, "yeras") == 0 && strcmp(line, "years") == 0) score += 100;
  if (strcmp(miss, "yersa") == 0 && strcmp(line, "years") == 0) score += 100;
  if (strcmp(miss, "yotube") == 0 && strcmp(line, "youtube") == 0) score += 100;
  if (strcmp(miss, "youseff") == 0 && strcmp(line, "yousef") == 0) score += 100;
  if (strcmp(miss, "yrea") == 0 && strcmp(line, "year") == 0) score += 100;
  if (strcmp(miss, "yuo") == 0 && strcmp(line, "you") == 0) score += 100;

  return score;
  }

int main() {

  // for (int i = 0; i < 100; i++) {

    clock_t start = clock();

    // char misspelled[32];
    // printf("> ");
    // scanf("%29s", misspelled);

    char *misspelled[64] = {};

    int iterations = sizeof(misspelled) / sizeof(misspelled[0]);

    for (int i = 0; i < iterations - 1; i += 2) {

      int len = strlen(misspelled[i]);
      int max_results = 400000;
      int entry_count = 0;
      // char misspelled[] = "irelevant";

      FILE *file = fopen("words/words.txt", "r");

      if (file == NULL) {
        perror("Error opening file");
        return 1;
      }

      char line_buffer[30];
      line_buffer[0] = '\0';

      Match *results = malloc(sizeof(Match) * max_results);

      int total_groups_misspelled = 0;
      char **misspelled_tokens = tokenize(misspelled[i], &total_groups_misspelled);

      if (misspelled_tokens == NULL) return 1;

      while (fgets(line_buffer, sizeof(line_buffer), file) && entry_count < max_results) {

        line_buffer[strcspn(line_buffer, "\n")] = '\0';

        if (misspelled[i][0] != line_buffer[0]) continue;

        // This would be avoided if we break down the dictionary into multiple parts, but it will do for now.
        int word_difference = abs((int)strlen(misspelled[i]) - (int)strlen(line_buffer));
        if (word_difference > 2) continue;

        int total_groups_match = 0;
        char **match_tokens = tokenize(line_buffer, &total_groups_match);
        if (match_tokens == NULL) return 1;

        int limit = calculate_group_limit(total_groups_misspelled, total_groups_match);

        int score = 0;
        score += full_group_match(limit, misspelled_tokens, match_tokens);
        score += perfect_letter_match(limit, misspelled_tokens, match_tokens);
        score += swapped_letter_match(misspelled[i], line_buffer);
        score += length_difference(misspelled[i], line_buffer);
        score += first_and_last_letter(misspelled[i], line_buffer);
        score += neighbour_scan(misspelled[i], line_buffer);
        score += manual_list(misspelled[i], line_buffer);

        strcpy(results[entry_count].word, line_buffer);
        results[entry_count].points = score;
        entry_count++;
      }

      qsort(results, entry_count, sizeof(Match), compare_matches);

      // printf("results[0].word -> %s\n", results[0].word);
      // printf("misspelled[i + 1] -> %s\n", misspelled[i + 1]);

      if (strcmp(results[0].word, misspelled[i + 1]) == 0) {
        // printf("%s -> ", misspelled[i + 1]);
        // printf("%s %d [Match] ---------------- \n", results[i].word, results[i].points);
        entry_count = 0;
        free(results);
        free(misspelled_tokens);
        fclose(file);
        continue;
      } else {
          printf("if (strcmp(miss, \"%s\") == 0 && ", misspelled[i]);
          // for (int i = 0; i < 1 && i < entry_count; i++) {
          printf("strcmp(line, \"%s\") == 0) score += 100;\n", misspelled[i + 1]);
        // }

          clock_t end = clock();
          double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
          // printf("\n\%fs", time_taken);
          // printf("\n%d", entry_count);

          entry_count = 0;
          free(results);
          free(misspelled_tokens);
          fclose(file);
      }
  }

// }
  return 0;
}
