#include <stdio.h>

// Function prototypes
void arithmeticOperations(int num1, int num2);
void relationalOperators(int num1, int num2);
void logicalOperators(int age);
void assignmentOperators();
void bitwiseOperators(int a, int b);
void ifElseStatement(int number);
void switchCaseStatement(char grade);

int main() {
    int num1, num2, age, a, b, number;
    char grade;

    printf("Enter num1 and num2: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    printf("Enter number: ");
    scanf("%d", &number);

    printf("Enter grade: ");
    scanf(" %c", &grade);

    // Function calls
    arithmeticOperations(num1, num2);
    relationalOperators(num1, num2);
    logicalOperators(age);
    assignmentOperators();
    bitwiseOperators(a, b);
    ifElseStatement(number);
    switchCaseStatement(grade);

    return 0;
}

// Function to perform arithmetic operations
void arithmeticOperations(int num1, int num2) {
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
}

// Function to demonstrate relational operators
void relationalOperators(int num1, int num2) {
    if (num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } else {
        printf("%d is not greater than %d\n", num1, num2);
    }
}

// Function to demonstrate logical operators
void logicalOperators(int age) {
    if (age >= 18 && age <= 60) {
        printf("You are eligible to work.\n");
    } else {
        printf("You are not eligible to work.\n");
    }
}

// Function to demonstrate assignment operators
void assignmentOperators() {
    int x = 10;
    x += 5;
    printf("Assignment operator: %d\n", x);
}

// Function to demonstrate bitwise operators
void bitwiseOperators(int a, int b) {
    int bitwise_and, bitwise_or, bitwise_xor;
    bitwise_and = a & b;
    printf("Bitwise AND: %d\n", bitwise_and);
    bitwise_or = a | b;
    printf("Bitwise OR: %d\n", bitwise_or);
    bitwise_xor = a ^ b;
    printf("Bitwise XOR: %d\n", bitwise_xor);
}

// Function to demonstrate if-else statement
void ifElseStatement(int number) {
    if (number % 2 == 0) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }
}

// Function to demonstrate switch-case statement
void switchCaseStatement(char grade) {
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
}
