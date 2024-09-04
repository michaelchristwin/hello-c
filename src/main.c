#include "../include/basics.h"
#include <stdio.h>
#define MAX 10

int a[MAX];
int rand_seed = 10;

/* From K&R
   - Returns a random number between 0 and 32767. */
int rand() {
  rand_seed = rand_seed * 1103515245 + 12345;
  return (unsigned int)(rand_seed / 65536) % 32768;
}

int main() {
  FILE *f;
  char s[1000];
  int i, t, x, y;

  int sum = add(30, 26);
  int difference = subtract(60, 29);
  printf("Sum = %d\n", sum);
  printf("Difference = %d\n", difference);

  // Open file for both reading and writing
  f = fopen("output.txt", "r+");
  if (!f) {
    perror("Error opening file");
    return 1;
  }

  // Write to the file
  for (x = 1; x <= MAX; x++) {
    fprintf(f, "%d\n", x);
  }

  // Reposition file pointer to the beginning for reading
  rewind(f);

  // Read from the file
  printf("File contents:\n");
  while (fgets(s, sizeof(s), f) != NULL) {
    printf("%s", s); // fgets includes the newline character, so no need for \n
  }

  fclose(f);
  printf("Memory\n");
  printf("--------------------\n");
  tinker_mem();
  printf("Loops\n");
  printf("--------------------\n");
  loops();
  random_basics();
  return 0;
}
