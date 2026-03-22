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
      list = realloc(list, (group_counter + 1) * sizeof(char *));
    }
    list[group_counter] = malloc(buffer_counter + 1);
    strcpy(list[group_counter], buffer);
    group_counter++;
  }

  *final_count = group_counter;
  return list;
 
}

void print_tokens() {
  // Deal with this bit later, as we don't currently need it
  //
  // int word_counter = 0;
  //
  // FILE *file = fopen("words/master.txt", "r");
  //
  // if (file == NULL) {
  //   perror("Error opening file");
  //   return 1;
  // }
  //
  // char line_buffer[30];
  //
  // while (fgets(line_buffer, sizeof(line_buffer), file)) {
  //   int total_groups = 0;
  //   char **tokens = tokenize(line_buffer, &total_groups);
  //
  //   if (tokens == NULL) return 1;
  //
  //   for (int i = 0; i < total_groups; i++) {
  //     printf("%s ", tokens[i]);
  //   }
  //
  //   printf("%d ", word_counter);
  //   word_counter++;
  // }
  //
  // fclose(file);
}

int calculate_group_limit(int total_groups_misspelled, int total_groups_match) {
  int limit = (total_groups_misspelled < total_groups_match)
    ? total_groups_misspelled
    : total_groups_match;
  return limit;
}

int main() {

  // Let's figure out how to calculate the potential match score of a word, based on the misspelled one

  // We have a misspelled word, and a potential match

  char misspelled[] = "calpentyr";
  char potential_match[] = "callipers";

  // We tokenize the word, and the potential match

  int total_groups_misspelled = 0;
  char **misspelled_tokens = tokenize(misspelled, &total_groups_misspelled);

  int total_groups_match = 0;
  char **match_tokens = tokenize(potential_match, &total_groups_match);

  if (misspelled_tokens == NULL) return 1;
  if (match_tokens == NULL) return 1;

  int limit = calculate_group_limit(total_groups_misspelled, total_groups_match);

  // We compare group[1] from the misspelled word with group[1] from the potential match, and so on

  int score = 0;

  for (int i = 0; i < limit; i++) {
      printf("[%d] %s %s -> ", i, misspelled_tokens[i], match_tokens[i]);
    if (strcmp(misspelled_tokens[i], match_tokens[i]) == 0) {
      score += 3;
      printf("[%d]\n", score);
    } else {
        printf("[0]\n");
    }
  }

  // For a full match of a group, allocate a further 3 points
  // Eg. cae vs car -> 0 points
  // Eg. pen vs pen -> 3 points
  // Eg. tyr vs try -> 0 points

  // Eg. car vs per -> 0 points
  // Eg. pen va man -> 0 points
  // Eg. tyr vs ent -> 0 points

  // Eg. car vs car -> 9 points
  // Eg. pen vs pen -> 9 points
  // Eg. try vs try -> 9 points

  // For each perfect letter match (same position) allocate 3 points
  // Eg. cae vs car -> 2 points
  // Eg. pen vs pen -> 3 points
  // Eg. tyr vs try -> 1 point

  // Eg. car vs per -> 1 point
  // Eg. pen va man -> 1 point
  // Eg. tyr vs ent -> 0 points

  // Eg. car vs car -> 9 points
  // Eg. pen vs pen -> 9 points
  // Eg. try vs try -> 9 points

  // For a neighbouring match, allocate 2 points. Eg: If the misspelled word starts with "s" but the possible  match starts with "d" as those two letters are next to eachother on a QWERTY keyboard, thus it could be a possible finger slip
  // Eg. cae vs car -> 2 points
  // Eg. pen vs pen -> 0 points
  // Eg. tyr vs try -> 0 points

  // Eg. car vs per -> 0 points
  // Eg. pen va man -> 0 points
  // Eg. tyr vs ent -> 1 point

  // Eg. car vs car -> 0 points
  // Eg. pen vs pen -> 0 points
  // Eg. try vs try -> 0 points
  //
  // For each letter that matches (but not in the same place) allocate 1 point
  // Eg. cae vs car -> 0 points 
  // Eg. pen vs pen -> 0 points
  // Eg. tyr vs try -> 2 points

  // Eg. car vs per -> 0 points
  // Eg. pen va man -> 0 points
  // Eg. tyr vs ent -> 1 point

  // Eg. car vs car -> 0 points
  // Eg. pen vs pen -> 0 points
  // Eg. try vs try -> 0 points
  //
  // caepentyr -> 13 points (very likely match)
  // permanent -> 4 points (unlikely match)
  // carpentry -> 54 points (perfect match)

  // In theory, this should provide us with a score that we can then use the figure out the most likely match

  // What is the maximum score achievable for a nine-digit word?

  // length * 6 = 54
  // Does this mean that longer potential matches would get higher scores? Should the score be adjusted to take the length into account?
  // Scoring against the misspelled word only might remove this issue altogether

  // To make the list of words more efficient, we break it down into lists based on length (2 letter words, 3 letter words, etc.)

  // We load the list that matches the misspelled word's length, and check. If we don't get a sufficiently high score, we expand to -1/+1 length. If we still don't get a good match, we do -2/+2, etc.

  return 0;
}
