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

int main() {

  // Let's figure out how to calculate the potential match score of a word, based on the misspelled one

  // We have a misspelled word, and a list of potential matches

  // We take the misspelled word, and a word from the list and tokenize them

  // We compare group[1] from the misspelled word with group[1] from the potential match, and so on

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

  return 0;
}
