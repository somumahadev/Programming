#include <stdio.h>

int main() {
    int rows = 5; // Number of rows in the pattern

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        // Inner loop for printing spaces
        for (int j = 1; j <= rows - i; j++) {
            printf("  "); // Two spaces for visual effect
        }
        // Inner loop for printing numbers
        for (int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
    return 0;
}
