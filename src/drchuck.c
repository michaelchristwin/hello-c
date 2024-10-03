#include <stdio.h>
#include <string.h>

/*Muliplier's prototype*/
int mymult(int a, int b);

/*Dr Chuck's Course Main fuction*/
int drchuck_main();

/*Reverse a string in place*/
void reverse_string(char dontcheat[]);

int drchuck_main() {
  int retval;
  char line[1000];
  FILE *hand;
  hand = fopen("romeo.txt", "r");
  while (fgets(line, 1000, hand) != NULL) {
    printf("%s", line);
  }
  retval = mymult(6, 7);
  return retval;
}

int mymult(int a, int b) {
  int c = a * b;
  return c;
}

void reverse_string(char dontcheat[]) {
  int length = strlen(dontcheat);
  int end = length - 1;
  char temp;
  printf("Length of string is %d\n", length);
  for (int p = 0; p <= (length - 1) / 2; p++) {
    temp = dontcheat[p];
    dontcheat[p] = dontcheat[length - 1 - p];
    dontcheat[length - 1 - p] = temp;
  }
  printf("%s\n", dontcheat);
}