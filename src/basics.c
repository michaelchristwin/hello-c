#include "../include/basics.h"
#include <stdio.h>
#include <stdlib.h>

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