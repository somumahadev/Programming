#include <stdio.h>

// Function prototype
int add(int num1, int num2);

int main() {
    int result = add(5, 3);
    printf("Result: %d\n", result);
    
    return 0;
}

// Function definition
int add(int num1, int num2) {
    return num1 + num2;
}

