#include <stdio.h>

int main() {
    int rows = 5; // Number of rows in the pattern

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        // Inner loop for spaces
        for (int j = 1; j <= rows - i; j++) {
            printf(" "); // Space
        }
        // Inner loop for stars
        for (int k = 1; k <= i; k++) {
            printf("* "); // Star followed by space
        }
        printf("\n");
    }
    return 0;
}
