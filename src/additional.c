#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

#define NUM_SUITS 4
#define NUM_RANKS 13

void new_module() {
  bool digit_seen[10] = {false};
  int digit;
  long n;
  printf("Enter a number: ");
  scanf("%1ld", &n);
  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit]) {
      break;
    }
    digit_seen[digit] = true;
    n /= 10;
  }
  if (n > 0) {
    printf("Repeated digit\n");
  } else {
    printf("No repeated digit\n");
  }
}

void multi_dimensional_array() {
  double ident[N][N];
  int row, col;
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (row == col) {
        ident[row][col] = 1.0;
      } else {
        ident[row][col] = 0.0;
      }
    }
  }
  int m[5][9] = {{1, 1, 1, 1, 1, 0, 1, 1, 1},
                 {1, 1, 1, 1, 1, 0, 1, 1, 1},
                 {1, 1, 1, 1, 1, 0, 1, 1, 1},
                 {1, 1, 1, 1, 1, 0, 1, 1, 1},
                 {1, 1, 1, 1, 1, 0, 1, 1, 1}};
}
// MDAs can be mde a constant by adding keyword `const`

void pick_rand_card() {
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8',
                            '9', 't', 'j', 'q', 'k', 'a'};
  const char suit_code[] = {'c', 'd', 'h', 's'};
  srand((unsigned)time(NULL));
  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);
  printf("Your hand:");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;
    /* picks a random suit */
    rank = rand() % NUM_RANKS;
    /* picks a random rank */
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = true;
      num_cards--;
      printf(" %c%c", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");
}