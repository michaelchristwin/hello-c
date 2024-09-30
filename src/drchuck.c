#include <stdio.h>

/*Muliplier's prototype*/
int mymult(int a, int b);

// Main function
int main() {
  int retval;
  char line[1000];
  FILE *hand;
  hand = fopen("romeo.txt", "r");
  while (fgets(line, 1000, hand) != NULL) {
    printf("%s", line);
  }
  retval = mymult(6, 7);
}

// Muliplier's function statment
int mymult(int a, int b) {
  int c = a * b;
  return c;
}