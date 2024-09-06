#include "../include/basics.h"
#include <openssl/aes.h>
#include <stdio.h>
#include <stdlib.h>
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
  printf("");

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
  unsigned char *key = (unsigned char *)"0123456789012345"; // 16 bytes key
  unsigned char *iv = (unsigned char *)"0123456789012345";  // 16 bytes IV

  // Open the input file
  FILE *inputFile = fopen("input.txt", "rb");
  if (inputFile == NULL) {
    perror("File open error");
    return EXIT_FAILURE;
  }

  // Get the file size
  fseek(inputFile, 0, SEEK_END);
  long fileSize = ftell(inputFile);
  fseek(inputFile, 0, SEEK_SET);

  // Read the file contents
  unsigned char *plaintext = (unsigned char *)malloc(fileSize);
  fread(plaintext, 1, fileSize, inputFile);
  fclose(inputFile);

  // Allocate memory for ciphertext
  unsigned char *ciphertext =
      (unsigned char *)malloc(fileSize + AES_BLOCK_SIZE);

  // Encrypt the plaintext
  int ciphertext_len = encryptor(plaintext, fileSize, key, iv, ciphertext);

  // Write the ciphertext to a file
  FILE *outputFile = fopen("output.enc", "wb");
  if (outputFile == NULL) {
    perror("File open error");
    return EXIT_FAILURE;
  }
  fwrite(ciphertext, 1, ciphertext_len, outputFile);
  fclose(outputFile);

  // Clean up
  free(plaintext);
  free(ciphertext);

  return 0;
  return 0;
}
