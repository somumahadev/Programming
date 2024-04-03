#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (i % 2 == 0)
                printf("* ");
            else if (j == cols - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    return 0;
}
