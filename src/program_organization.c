#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 100
#define MAX_NUMBER 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }
void push(int i) {
  if (is_full()) {
    // stack_overflow();
  } else {
    contents[top++] = i;
  }
}

int pop(void) {
  if (is_empty()) {
    // stack_underflow()
  } else {
    return contents[--top];
  }
}

// Guess the secret number between 1 and 100

/* external variable */
int secret_number;
/* prototypes */
void initialize_number_generator(void) { srand((unsigned)time(NULL)); }

void choose_new_secret_num(void) { secret_number = rand() % MAX_NUMBER + 1; }

void read_guesses(void) {
  int guess, num_guesses = 0;
  for (;;) {
    num_guesses++;
    printf("Enter guess: ");
    scanf("%d", &guess);
    if (guess == secret_number) {
      printf("You won in %d guesses!\n\n", num_guesses);
      return;
    } else if (guess < secret_number)
      printf("Too low; try again.\n");
    else
      printf("Too high; try again.\n");
  }
}

int guess_game(void) {
  char command;
  printf("Guess a secret number between 1 and %d. \n\n", MAX_NUMBER);
  initialize_number_generator();
  do {
    choose_new_secret_num();
    printf("A new number has been chosen. \n");
    read_guesses();
    printf("Play again? (Y/N) ");
    scanf(" %c", &command);
    printf("\n");
  } while (command == 'y' || command == 'Y');
  return 0;
}