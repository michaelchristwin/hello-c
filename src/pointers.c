#include <stdio.h>

void addone(int n) {
  // n is local variable which only exists within the function scope
  n++; // therefore incrementing it has no effect
};
void pointer_module() {
  // Derefrencing
  int a = 1;
  int *pointer_to_a = &a;
  printf("The value of a is %d\n", a);
  printf("The value of a is also %d\n", *pointer_to_a);

  // let us change the value of a
  *pointer_to_a += 1;
  printf("The value of a is now %d\n", a);

  // Moving on to Structs
  struct point {
    int x;
    int y;
  };

  // typedefs
  typedef struct {
    int x;
    int y;
  } another_point;

  int n;
  printf("Before: %d\n", n);
  addone(n);
  printf("After: %d\n", n);
}