#include <stdio.h>

int main() {
    int rows = 5; // Number of rows in the pattern

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        // Inner loop for spaces
        for (int j = 1; j <= rows - i; j++) {
            printf("  "); // Two spaces for visual effect
        }
        // Inner loop for stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
