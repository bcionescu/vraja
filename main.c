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

int main() {

  int word_counter = 0;

  FILE *file = fopen("words/master.txt", "r");

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line_buffer[30];

  while (fgets(line_buffer, sizeof(line_buffer), file)) {
    int total_groups = 0;
    char **tokens = tokenize(line_buffer, &total_groups);

    if (tokens == NULL) return 1;

    for (int i = 0; i < total_groups; i++) {
      printf("%s ", tokens[i]);
    }

    printf("%d ", word_counter);
    word_counter++;
  }

  fclose(file);

  return 0;
}
