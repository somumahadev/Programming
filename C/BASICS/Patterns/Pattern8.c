#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows/columns: ");
    scanf("%d", &n);

    int matrix[n][n];
    int num = 1;
    int minRow = 0, minCol = 0;
    int maxRow = n - 1, maxCol = n - 1;

    while (num <= n * n) {
        // Traverse right
        for (int i = minCol; i <= maxCol; i++) {
            matrix[minRow][i] = num++;
        }
        minRow++;

        // Traverse down
        for (int i = minRow; i <= maxRow; i++) {
            matrix[i][maxCol] = num++;
        }
        maxCol--;

        // Traverse left
        for (int i = maxCol; i >= minCol; i--) {
            matrix[maxRow][i] = num++;
        }
        maxRow--;

        // Traverse up
        for (int i = maxRow; i >= minRow; i--) {
            matrix[i][minCol] = num++;
        }
        minCol++;
    }

    // Print the matrix
    printf("Spiral Pattern:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
