#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string arg);
char rotate(int key, char c);

int main(int argc, string argv[]) {
  // printf error(return 1) if cl-args == 0 || > 1
  if (argc == 1 || argc > 2) {
    printf("Usage: ./caesar key");
    return 1;
  }
  // if any chars in cl-args != decimal digit printf "Usage: ./caesar key"
  if (only_digits(argv[1])) {
  } else {
    printf("Usage: ./caesar key");
    return 1;
  }
  // convert argv[1] string ==> int
  int key = atoi(argv[1]);
  // prompt user for plaintext
  string plaintext = get_string("plaintext:  ");
  // printf output ciphertext and return 0
  printf("ciphertext: ");
  for (int i = 0, length = strlen(plaintext); i < length; i++) {
    char rotated_char = rotate(key, plaintext[i]);
    printf("%c", rotated_char);
  }
  printf("\n");
}
bool only_digits(string arg) {
  int length = strlen(arg);
  for (int i = 0; i < length; i++) {
    if (!isdigit(arg[i])) {
      return false;
    }
  }
  return true;
}

char rotate(int key, char c) {
  if (isalpha(c)) {
    if (isupper(c)) {
      return (c - 'A' + key) % 26 + 'A';
    } else if (islower(c)) {
      return (c - 'a' + key) % 26 + 'a';
    }
  }
  return c;
}
