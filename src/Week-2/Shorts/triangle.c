#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float side1, float side2, float side3);

int main (void) {
    float side1 = get_float("Side 1 Length:");
    float side2 = get_float("Side 2 Length:");
    float side3 = get_float("Side 3 Length:");

    bool isTriangle = valid_triangle(side1, side2, side3);
    printf("%s\n", isTriangle ? "true" : "false");

}

bool valid_triangle(float side1, float side2, float side3) {
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return false;
    } else if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
        return true;
    }
    return false;
}
