// calculate approximate grade level to comprehend text
// should output "Grade X" where "X" is the grade level rounded to the nearest
// integer. if grade level is 16 or higher it should output 16+ if grade level
// is less than 1 it should output "Before Grade 1"

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countLetters(string text);
int countWords(string text);
int countSentences(string text);
int calculateIndex(int letters, int words, int sentences);

int main(void) {
  // prompt the user for some text
  string text = get_string("Text: ");
  // count number of letters, words, and setences in the text
  int letters = countLetters(text);
  int words = countWords(text);
  int sentences = countSentences(text);
  // compute the coleman-liau index
  int index = calculateIndex(letters, words, sentences);
  // print the grade level
  if (index < 1) {
    printf("Before Grade 1");
  } else if (index >= 16) {
    printf("Grade 16+");
  } else {
    printf("Grade: %i", index);
  }
}
int countLetters(string text) {
  // return number of letters in text
  int letters = 0;
  for (int i = 0; i < strlen(text); i++)
    if (isalpha(text[i])) {
      letters++;
    }
  return letters;
}
int countWords(string text) {
  // return number of words in text
  // any seq of char separated by space
  // starting at 1 as the last word has no trailing space
  int words = 1;
  for (int i = 0; i < strlen(text); i++)
    if (isblank(text[i])) {
      words++;
    }
  return words;
}
int countSentences(string text) {
  // return number of sentences in text
  // any seq of char the ends with ".", "!" or "?"
  int sentences = 0;
  for (int i = 0; i < strlen(text); i++)
    if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
      sentences++;
    }
  return sentences;
}
int calculateIndex(int letters, int words, int sentences) {
  float L = ((float)letters / (float)words) * 100;
  float S = ((float)sentences / (float)words) * 100;
  float index = 0.0588 * L - 0.296 * S - 15.8;
  return round(index);
}
