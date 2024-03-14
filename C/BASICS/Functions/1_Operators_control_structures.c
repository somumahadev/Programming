#include <stdio.h>

int main() {
    // Arithmetic Operators
    int num1 = 10, num2 = 5, result;
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

    // Relational Operators
    if (num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } else {
        printf("%d is not greater than %d\n", num1, num2);
    }

    // Logical Operators
    int age = 20;
    if (age >= 18 && age <= 60) {
        printf("You are eligible to work.\n");
    } else {
        printf("You are not eligible to work.\n");
    }

    // Assignment Operators
    int x = 10;
    x += 5;
    printf("Assignment operator: %d\n", x);

    // Bitwise Operators
    int a = 1, b = 0, bitwise_and, bitwise_or, bitwise_xor;
    bitwise_and = a & b;
    printf("Bitwise AND: %d\n", bitwise_and);
    bitwise_or = a | b;
    printf("Bitwise OR: %d\n", bitwise_or);
    bitwise_xor = a ^ b;
    printf("Bitwise XOR: %d\n", bitwise_xor);

    // Control Structures - If-else Statement
    int number = 15;
    if (number % 2 == 0) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }

    // Control Structures - Switch-case Statement
    char grade = 'B';
    switch (grade) {
        case 'A':
            printf("Excellent!\n");
            break;
        case 'B':
            printf("Well done!\n");
            break;
        case 'C':
            printf("Good!\n");
            break;
        default:
            printf("Invalid grade\n");
    }

    // Loops - For Loop
    int i;
    printf("For Loop: ");
    for (i = 1; i <= 5; ++i) {
        printf("%d ", i);
    }
    printf("\n");

    // Loops - While Loop
    int countdown = 5;
    printf("While Loop: ");
    while (countdown > 0) {
        printf("%d ", countdown);
        countdown--;
    }
    printf("\n");


    // Loops - Do-While Loop
    int count = 5;
    printf("Do-While Loop: ");
    do {
        printf("%d ", count);
        count--;
    } while (count > 0);
    printf("\n");

    // Break and Continue Statements
    int j;
    printf("Break and Continue: ");
    for (j = 1; j <= 10; ++j) {
        if (j == 5)
            break; // Exit loop if j equals 5
        if (j % 2 == 0)
            continue; // Skip even numbers
        printf("%d ", j);
    }
    printf("\n");

    return 0;
}
