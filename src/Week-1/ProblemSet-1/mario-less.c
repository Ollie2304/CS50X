#include <stdio.h>
#include <cs50.h>

void print_spaces(int amount);
void print_hashes(int amount);

int main(void) {
    int height;
    do {
        height = get_int("Height:");
    } while (height <= 0);
    for (int i = 0; i < height; i++) {
        print_spaces(height - (i + 1));
        print_hashes(i + 1);
        printf("\n");
    }
}

void print_spaces(int amount) {
    for (int i = 0; i < amount; i++) {
        printf(" ");
    }
}

void print_hashes(int amount) {
    for (int i = 0; i < amount; i++) {
        printf("#");
    }
}