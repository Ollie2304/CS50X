#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool key_validation(int argc, string key);

int main(int argc, string argv[]) {
  if (!key_validation(argc, argv[1])) {
    return 1;
  }
  string plaintext = get_string("plaintext:  ");
  int length = strlen(plaintext);
  char ciphertext[length + 1];
  string key = argv[1];
  // convert letters from ASCII position to position in alphabet
  for (int i = 0; i < length; i++) {
    if (isupper(plaintext[i])) {
      int index = plaintext[i] - 'A';
      ciphertext[i] = toupper(key[index]);
    } else if (islower(plaintext[i])) {
      int index = plaintext[i] - 'a';
      ciphertext[i] = tolower(key[index]);
    } else {
      ciphertext[i] = plaintext[i];
    }
  }
  ciphertext[length] = '\0';
  printf("ciphertext: %s\n", ciphertext);
  return 0;
}

bool key_validation(int argc, string key) {
  // check if user has entered 1 arguments
  if (argc != 2) {
    printf("Usage: ./subsitution key\n");
    return false;
  }
  int length = strlen(key);
  // check if key is 26 characters
  if (length != 26) {
    printf("Key must contain 26 characters.\n");
    return false;
  }
  for (int i = 0; i < length; i++) {
    // convert key to uppercase
    key[i] = toupper(key[i]);
  }
  for (int i = 0; i < length; i++) {
    // check if key is alphabetical
    if (!isalpha(key[i])) {
      printf("Key must be alphabetical.\n");
      return false;
    }
    // check if there are any duplicate letters
    for (int j = i + 1; j < length; j++) {
      if (key[i] == key[j]) {
        printf("Key contains duplicate characters.\n");
        return false;
      }
    }
  }
  return true;
}
