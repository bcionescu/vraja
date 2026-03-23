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

int main() {

  clock_t start = clock();

  int count = 0;

  char misspelled[] = "tn";

  // Use the neighbouring strategy for the very first letter of the word. For example, if someone types "darpentry", and they meant carpentry, we should allow only allow for words that start with w,e,r,f,c,x,s,d. Also always include k, as it is often silent. This will dramatically reduce the number of words it could be, and improve our matching strategy.

  // Maybe even prioritise words that match both the first, and the second letter.

  // char path[16];
  // int len = strlen(misspelled);

  // sprintf(path, "words/%d.txt", len);
  //
  FILE *file = fopen("words/words.txt", "r");

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line_buffer[30];

  int total_groups_misspelled = 0;
  char **misspelled_tokens = tokenize(misspelled, &total_groups_misspelled);

  int max_entries = 100000;
  Match *results = malloc(sizeof(Match) * max_entries);

  // Instead of tokenizing all the words, let's only select words that start with a neighbouring letter.



  while (fgets(line_buffer, sizeof(line_buffer), file) && count < max_entries) {

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

    score += swapped_letter_match(misspelled, line_buffer);

    strcpy(results[count].word, line_buffer);
    results[count].points = score;
    count++;

    // printf("%s [%d]\n", line_buffer, score);
  }

  fclose(file);

  qsort(results, count, sizeof(Match), compare_matches);

  for (int i = 0; i < 5 && i < count; i++) {
    printf("%s [%d]\n", results[i].word, results[i].points);
  }

  clock_t end = clock();

  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("\n\%fs", time_taken);

  // This can be improved upon. Many words in the English language have pairs of 2.
  // cc – as in accommodate, success
  // ee – as in tree, feel
  // ff – as in off, coffee
  // gg – as in bigger, sagging
  // bb – as in hobby
  // ii – as in skiing, literature
  // ll – as in bell, call
  // mm – as in summer, grammar
  // nn – as in dinner, funny
  // oo – as in moon, book
  // pp – as in apple, happy
  // rr – as in mirror, terror
  // ss – as in pass, grass
  // tt – as in letter, better
  // uu – as in vacuum, continuum
  // vv – as in savvy

  // In some words these pairs occur once, and in others they occur twice.
  // Pairs that only appear once: bb, cc, ii, vv
  // Pairs that can appear twice: ee, ff, gg, ll, mm, nn, oo, pp, rr, ss, tt, uu

  // Before we do anything else, look for b, c, i, and v in the word, and double it. Does this now perfectly match a word in the dictionary? If so, print i.

  // Then, double e, f, g, l, m, n, o, p, r, s, t, and u, and check them against the dictionary.

  // In order to increase the speed at which we search, we should not only break the list down in terms of length, but also starting letter. So have 2a.txt, 2b.txt ... 8t.txt 8u.txt, etc.

  // Maybe sometimes prioritise words of the same, or similar length, especially for very short words.

  // If we only have one letter, like x, or t, especially if it's ['q','w','d','x','z','`'] then it's probably just 'a'.

  // Also add a manual list which supersedes all other processes, and shows up first (maybe).

  free(results);
  free(misspelled_tokens);
  return 0;
}
