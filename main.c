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
  int perfect_match = 0;

  if (misspelled[0] == line_buffer[0]) {
    score += 15;
    perfect_match += 1;
  }

  if (misspelled[strlen(misspelled) - 1] == line_buffer[strlen(line_buffer) - 1]) {
    score += 15;
    perfect_match += 1;
  }

  if (perfect_match == 2) score += 15;

  if (misspelled[1] == line_buffer[1]) {
    score += 10;
    perfect_match += 1;
  }

  if (misspelled[strlen(misspelled) - 2] == line_buffer[strlen(line_buffer) - 2]) {
    score += 10;
    perfect_match += 10;
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

int main() {

  clock_t start = clock();

  FILE *file = fopen("words/words.txt", "r");

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  int max_results = 400000;
  int entry_count = 0;
  char misspelled[] = "beginer";
  char line_buffer[30];
  Match *results = malloc(sizeof(Match) * max_results);

  int total_groups_misspelled = 0;
  char **misspelled_tokens = tokenize(misspelled, &total_groups_misspelled);
  if (misspelled_tokens == NULL) return 1;

  while (fgets(line_buffer, sizeof(line_buffer), file) && entry_count < max_results) {

    line_buffer[strcspn(line_buffer, "\n")] = '\0';

    if (misspelled[0] != line_buffer[0]) continue;

    // This would be avoided if we break down the dictionary into multiple parts, but it will do for now.
    int word_difference = abs((int)strlen(misspelled) - (int)strlen(line_buffer));
    if (word_difference > 2) continue;

    int total_groups_match = 0;
    char **match_tokens = tokenize(line_buffer, &total_groups_match);
    if (match_tokens == NULL) return 1;

    int limit = calculate_group_limit(total_groups_misspelled, total_groups_match);

    int score = 0;
    score += full_group_match(limit, misspelled_tokens, match_tokens);
    score += perfect_letter_match(limit, misspelled_tokens, match_tokens);
    score += swapped_letter_match(misspelled, line_buffer);
    score += length_difference(misspelled, line_buffer);
    score += first_and_last_letter(misspelled, line_buffer);
    score += neighbour_scan(misspelled, line_buffer);

    strcpy(results[entry_count].word, line_buffer);
    results[entry_count].points = score;
    entry_count++;
  }

  fclose(file);

  qsort(results, entry_count, sizeof(Match), compare_matches);

  for (int i = 0; i < 5 && i < entry_count; i++) {
    printf("%s [%d]\n", results[i].word, results[i].points);
  }

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("\n\%fs", time_taken);
  printf("\n%d", entry_count);

  free(results);
  free(misspelled_tokens);
  return 0;

  // char path[16];
  // int len = strlen(misspelled);

  // sprintf(path, "words/%d.txt", len);
}
