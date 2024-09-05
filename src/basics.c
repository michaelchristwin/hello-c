#include "../include/basics.h"
#include <stdio.h>
#include <stdlib.h>
#define N 10

int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }

void tinker_mem() {
  int *p, *q;

  p = (int *)malloc(sizeof(int));
  q = p;
  *p = 10;
  printf("%d\n", *q);
  *q = 20;
  printf("%d\n", *q);
}
void loops() {
  int i, n;
  i = 0;
  n = 10;
  while (i < n) {
    i++;
    printf("i = %i\n", i);
  }
}
void random_basics() {
  int ar[N], i;
  for (i = 0; i < N; i++) {
    printf("Enter an int value for array index %i: ", i);
    scanf("%d", &ar[i]);
  }
  int size = sizeof(ar) / sizeof(ar[0]);
  printf("Array elements: ");
  for (i = N - 1; i >= 0; i--) {
    printf("%d ", ar[i]);
  }
  printf("\n");
  // multi dimenesional arrays
  double ident[N][N];
  int row, col;
  for (row = 0; row < N; row++)
    for (col = 0; col < N; col++) {
      if (row == col) {
        ident[row][col] = 1.0;
      } else {
        ident[row][col] = 0.0;
      };
    };
}