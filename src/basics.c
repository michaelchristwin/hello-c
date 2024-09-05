#include "../include/basics.h"
#include <openssl/aes.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* C99 only */
#define NUM_SUITS 4
#define NUM_RANKS 13
#define N 10

void handleErrors(void) {
  ERR_print_errors_fp(stderr);
  abort();
}

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
// Encryption
int encryptor(unsigned char *plaintext, int plaintext_len, unsigned char *key,
              unsigned char *iv, unsigned char *ciphertext) {
  EVP_CIPHER_CTX *ctx;

  int len;
  int ciphertext_len;

  // Create and initialize the context
  if (!(ctx = EVP_CIPHER_CTX_new()))
    handleErrors();

  // Initialize the encryption operation with AES-128-CBC
  if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
    handleErrors();

  // Provide the message to be encrypted and obtain the encrypted output
  if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
    handleErrors();
  ciphertext_len = len;

  // Finalize the encryption
  if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
    handleErrors();
  ciphertext_len += len;

  // Clean up
  EVP_CIPHER_CTX_free(ctx);

  return ciphertext_len;
}