#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        capacity *= 2;
        list = realloc(list, capacity * sizeof(char *));
    }
    
    list[group_counter] = malloc(buffer_counter + 1);
    strcpy(list[group_counter], buffer);
    group_counter++;
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
      score += 3;
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
    // printf("Match at %d\n", i-1);
    }
  }

return score;
}

int main() {

  FILE *file = fopen("words/list.txt", "r");

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line_buffer[30];

  char misspelled[] = "caprentyr";

  int total_groups_misspelled = 0;
  char **misspelled_tokens = tokenize(misspelled, &total_groups_misspelled);

  while (fgets(line_buffer, sizeof(line_buffer), file)) {

    line_buffer[strcspn(line_buffer, "\n")] = '\0';

    // We tokenize the word, and the potential match

    int total_groups_match = 0;
    char **match_tokens = tokenize(line_buffer, &total_groups_match);

    if (misspelled_tokens == NULL) return 1;
    if (match_tokens == NULL) return 1;

    int limit = calculate_group_limit(total_groups_misspelled, total_groups_match);

    // We compare group[1] from the misspelled word with group[1] from the potential match, and so on

    int score = 0;

    score += full_group_match(limit, misspelled_tokens, match_tokens);

    // For each perfect letter match (same position) allocate 3 points. We also allocate 2 points for a neighbouring match.

    score += perfect_letter_match(limit, misspelled_tokens, match_tokens);

    // We allocate 2 points for letters which are swapped around
    // Eg. carpent[yr] -> carpent[ry]

    score += swapped_letter_match(misspelled, line_buffer);

    printf("%s [%d]\n", line_buffer, score);

    // for (int i = 0; i < total_groups; i++) {
    //   printf("%s ", tokens[i]);
    // }
  }

  fclose(file);

  // In theory, this should provide us with a score that we can then use the figure out the most likely match



  // To make the list of words more efficient, we break it down into lists based on length (2 letter words, 3 letter words, etc.)

  // We load the list that matches the misspelled word's length, and check. If we don't get a sufficiently high score, we expand to -1/+1 length. If we still don't get a good match, we do -2/+2, etc.

  return 0;
}
