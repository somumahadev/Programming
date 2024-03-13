#include <stdio.h>

int main() {
    int num1 = 10, num2 = 5;
    int result;
    
    result = num1 + num2;
    printf("Addition: %d\n", result);
    
    result = num1 - num2;
    printf("Subtraction: %d\n", result);
    
    result = num1 * num2;
    printf("Multiplication: %d\n", result);
    
    result = num1 / num2;
    printf("Division: %d\n", result);
    
    result = num1 % num2;
    printf("Modulus: %d\n", result);
    
    return 0;
}

