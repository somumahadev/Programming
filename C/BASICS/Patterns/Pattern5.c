#include <stdio.h>

int main() {
    int rows = 5; // Number of rows in the pattern
    int spaces;

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        // Printing spaces
        for (spaces = 1; spaces <= rows - i; spaces++) {
            printf(" ");
        }
        // Printing stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Outer loop for second half of the pattern
    for (int i = rows - 1; i >= 1; i--) {
        // Printing spaces
        for (spaces = 1; spaces <= rows - i; spaces++) {
            printf(" ");
        }
        // Printing stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
