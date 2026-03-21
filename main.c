#include <stdio.h>

// Haven't touched C in a few months. Building this spellchecker will be a great way to not only refresh my knowledge, but to learn ever further.

int main() {
  char word[] = "calpentry";
  char *p = word;
  int third = 0;

  while (*p) {
    printf("%c", *p);
    p++;

    if (third < 2) {
      third++;
    } else {
      third = 0;
      printf("\n");
    }
  }
}


