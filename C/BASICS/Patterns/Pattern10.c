#include <stdio.h>

int main() {
    int n = 5; // Number of rows in the hourglass

    // Upper half of the hourglass
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j < i; j++) {
            printf("  ");
        }
        // Print stars
        for (int k = 1; k <= 2 * (n - i) + 1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    // Lower half of the hourglass
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (int j = 1; j < i; j++) {
            printf("  ");
        }
        // Print stars
        for (int k = 1; k <= 2 * (n - i) + 1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
