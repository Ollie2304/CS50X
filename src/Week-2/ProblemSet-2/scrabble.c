#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// create int array to store points values for each letter
int points[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// init func for score calculation req a str as an arg
int scoreCalculate(string answer);

int main(void) {
  // get two str from the user
  string playerOneAnswer = get_string("Player One: ");
  string playerTwoAnswer = get_string("Player Two: ");

  // pass the str to scoreCalculate as args
  int playerOneScore = scoreCalculate(playerOneAnswer);
  int playerTwoScore = scoreCalculate(playerTwoAnswer);

  // print the winner
  if (playerOneScore > playerTwoScore)
    printf("Player One Wins!");
  else if (playerTwoScore > playerOneScore)
    printf("Player Two Wins!");
  else
    printf("Tie!");
}

// func to calculate score
int scoreCalculate(string answer) {

  // set score to 0
  int score = 0;

  // loop for each char of the answer string using strlen
  for (int i = 0; i < strlen(answer); i++) {

    // if char is uppercase
    if (isupper(answer[i])) {
      // convert the ASCII pos to pos in array
      // difference is 65 (- A)
      score += points[answer[i] - 'A'];

      // if char is lowercase
      // difference is 97 (- a)
    } else if (islower(answer[i])) {
      score += points[answer[i] - 'a'];
    }
  }
  // retrun score from func
  return score;
}
