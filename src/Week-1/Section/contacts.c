#include <cs50.h>
#include <stdio.h>

int main(void) {
    string name = get_string("What is your name?\n");
    int age = get_int("What is your age?\n");
    string number = get_string("What is your phone number?\n");

    printf("Name: %s\n", name);
    printf("Age: %i\n", age);
    printf("Phone Number: %s\n", number);
}