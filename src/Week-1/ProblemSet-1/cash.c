#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;
do {
    cents = get_int("Change owed: ");
}while (cents < 0);
    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    int pennies = calculate_pennies(cents);
    cents -= pennies * 1;

    int coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);

}

int calculate_quarters(int cents) {
    int quarters = 0;
    while (cents >= 25) {
        cents -= 25;
        quarters++;
    }
    return quarters;
}

int calculate_dimes(int cents) {
    int dimes = 0;
    while (cents >= 10) {
        cents -= 10;
        dimes++;
    }
    return dimes;
}

int calculate_nickels(int cents) {
    int nickels = 0;
    while (cents >= 5) {
        cents -= 5;
        nickels++;
    }
    return nickels;
}

int calculate_pennies(int cents) {
    int pennies = 0;
    while (cents >= 1) {
        cents -= 1;
        pennies++;
    }
    return pennies;
}