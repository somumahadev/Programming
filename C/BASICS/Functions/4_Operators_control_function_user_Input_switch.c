#include <stdio.h>

// Function prototypes
void arithmeticOperations();
void relationalOperators();
void logicalOperators();
void assignmentOperators();
void bitwiseOperators();
void ifElseStatement();
void switchCaseStatement();

int main() {
    int choice;


    while(choice!=999){
    printf("Select an operation:\n");
    printf("1. Arithmetic Operations\n");
    printf("2. Relational Operators\n");
    printf("3. Logical Operators\n");
    printf("4. Assignment Operators\n");
    printf("5. Bitwise Operators\n");
    printf("6. If-else Statement\n");
    printf("7. Switch-case Statement\n");
    printf("Enter your choice: ");


    scanf("%d", &choice);


    switch (choice) {
        case 1:
            arithmeticOperations();
            break;
        case 2:
            relationalOperators();
            break;
        case 3:
            logicalOperators();
            break;
        case 4:
            assignmentOperators();
            break;
        case 5:
            bitwiseOperators();
            break;
        case 6:
            ifElseStatement();
            break;
        case 7:
            switchCaseStatement();
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    }

    return 0;
}

// Function to perform arithmetic operations
void arithmeticOperations() {
    int num1, num2, result;
    printf("Enter num1 and num2: ");
    scanf("%d %d", &num1, &num2);

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
void relationalOperators() {
    int num1, num2;
    printf("Enter num1 and num2: ");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } else {
        printf("%d is not greater than %d\n", num1, num2);
    }
}

// Function to demonstrate logical operators
void logicalOperators() {
    int age;
    printf("Enter age: ");
    scanf("%d", &age);

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
void bitwiseOperators() {
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    int bitwise_and, bitwise_or, bitwise_xor;
    bitwise_and = a & b;
    printf("Bitwise AND: %d\n", bitwise_and);
    bitwise_or = a | b;
    printf("Bitwise OR: %d\n", bitwise_or);
    bitwise_xor = a ^ b;
    printf("Bitwise XOR: %d\n", bitwise_xor);
}

// Function to demonstrate if-else statement
void ifElseStatement() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }
}

// Function to demonstrate switch-case statement
void switchCaseStatement() {
    char grade;
    printf("Enter grade: ");
    scanf(" %c", &grade);

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
            break;
    }
}
