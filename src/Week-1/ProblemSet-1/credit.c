#include <cs50.h>
#include <stdio.h>
#include <math.h>

int everyOtherDigit(long long cardNumber);
int sumOfDigitsX2(int lastDigit);
int numberOfDigits(long long cardNumber);
bool isAmex(long long cardNumber, int numDigits);
bool isMasterCard(long long cardNumber, int numDigits);
bool isVisa(long long cardNumber, int numDigits);

int main(void) {
    long long cardNumber;
    do {
        cardNumber = get_long_long("Credit Card Number: ");
    }while (cardNumber <= 0);
    int sumOfEveryOtherDigit = everyOtherDigit(cardNumber);
    int numDigits = numberOfDigits(cardNumber);
    bool amex = isAmex(cardNumber, numDigits);
    bool masterCard = isMasterCard(cardNumber, numDigits);
    bool visa = isVisa(cardNumber, numDigits);
    if(sumOfEveryOtherDigit % 10 != 0) {
        printf("INVALID\n");
    }
    else if(amex == true) {
        printf("AMEX\n");
    }
    else if(masterCard == true) {
        printf("MASTERCARD\n");
    }
    else if(visa == true) {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }
}


int everyOtherDigit(long long cardNumber) {
    int sum = 0;
    bool isAlternateDigit = false;
    while (cardNumber > 0) {
        if(isAlternateDigit == true) {
            int lastDigit = cardNumber % 10;
            int product = sumOfDigitsX2(lastDigit);
            sum += product;
        }
        else {
            int lastDigit = cardNumber % 10;
            sum += lastDigit;
        }
        isAlternateDigit = !isAlternateDigit;
        cardNumber /= 10;
    }
    return sum;
}

int sumOfDigitsX2(int lastDigit) {
    int multiply = lastDigit * 2;
    int sum = 0;
    while(multiply > 0) {
        int lastDigitMultiply = multiply % 10;
        sum += lastDigitMultiply;
        multiply /= 10;
    }
    return sum;
}

int numberOfDigits(long long cardNumber) {
    int count = 0;
    while(cardNumber > 0) {
        cardNumber /= 10;
        count++;
    }
    return count;
}

bool isAmex(long long cardNumber, int numDigits) {
    int firstTwoDigits = cardNumber / pow(10,13);
    if (numDigits == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37)) {
        return true;
    }
    else {
        return false;
    }
}

bool isMasterCard(long long cardNumber, int numDigits) {
    int firstTwoDigits = cardNumber / pow(10,14);
    if (numDigits == 16 && (firstTwoDigits >= 51 && firstTwoDigits <= 55)) {
        return true;
    }
    else {
        return false;
    }
}

bool isVisa(long long cardNumber, int numDigits) {
    int firstDigit;
    if (numDigits == 16) {
        firstDigit = cardNumber / pow(10,15);
    } else if (numDigits == 13) {
        firstDigit = cardNumber / pow(10,12);
    } else {
        return false;
    }
    if (firstDigit == 4) {
        return true;
    } else {
        return false;
    }
}

// 1. Get the credit card number
// 2. Check if the credit card number is valid
// 3. Check if the credit card number is American Express, MasterCard, or Visa
// 4. Print the result


// American Express: 15 digits, start with 34 or 37
// MasterCard: 16 digits, start with 51, 52, 53, 54, or 55
// Visa: 13 or 16 digits, start with 4

// Checksum: Luhn’s Algorithm
// 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
// 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
// 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

// Example: 4003600000000014
// 8 0 12 0 0 0 0 2
// 8 + 0 + 1 + 2 + 0 + 0 + 0 + 2 = 13
// 13 + 0 + 3 + 0 + 0 + 0 + 0 + 4 = 20
// 20 % 10 = 0