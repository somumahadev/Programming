#include <stdio.h>
#include <math.h>

// Function declarations
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double squareRoot(double x);
double factorial(int x);

int main() {
    char operation;
    double num1, num2, result;
    int intNum;
    
    printf("Enter an operation (+, -, *, /, ^, !, sqrt): ");
    scanf("%c", &operation);
    
    switch(operation) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            switch(operation) {
                case '+':
                    result = add(num1, num2);
                    break;
                case '-':
                    result = subtract(num1, num2);
                    break;
                case '*':
                    result = multiply(num1, num2);
                    break;
                case '/':
                    result = divide(num1, num2);
                    break;
                case '^':
                    result = power(num1, num2);
                    break;
            }
            printf("Result: %.2lf\n", result);
            break;
            
        case '!':
            printf("Enter an integer: ");
            scanf("%d", &intNum);
            result = factorial(intNum);
            printf("Result: %.0lf\n", result);
            break;
            
        case 's':
        case 'S':
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = squareRoot(num1);
            printf("Result: %.2lf\n", result);
            break;
            
        default:
            printf("Invalid operation!\n");
    }
    
    return 0;
}

// Function definitions
double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if (y != 0)
        return x / y;
    else {
        printf("Error: Division by zero!\n");
        return NAN;
    }
}

double power(double x, double y) {
    return pow(x, y);
}

double squareRoot(double x) {
    if (x >= 0)
        return sqrt(x);
    else {
        printf("Error: Square root of a negative number!\n");
        return NAN;
    }
}

double factorial(int x) {
    double result = 1;
    if (x < 0) {
        printf("Error: Factorial of a negative number!\n");
        return NAN;
    }
    for (int i = 2; i <= x; i++) {
        result *= i;
    }
    return result;
}

