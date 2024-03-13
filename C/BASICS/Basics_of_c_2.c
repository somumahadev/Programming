#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for a car
struct Car {
    char make[20];
    char model[20];
    int year;
    float price;
};

// Function prototypes
void printWelcomeMessage();
void calculateArea(int length, int width);
void printPattern(int rows);
void printReverseString(char *str);
void swap(int *a, int *b);
void bubbleSort(int arr[], int size);
void printMenu();
void executeOption(int option);
void saveCarRecord(struct Car car);
void readCarRecord();

int main() {
    // Welcome message
    printWelcomeMessage();

    // Variables and Data Types
    int integerVariable = 10;
    float floatVariable = 3.14;
    char charVariable = 'A';
    printf("Integer Variable: %d\n", integerVariable);
    printf("Float Variable: %f\n", floatVariable);
    printf("Char Variable: %c\n", charVariable);

    // Arithmetic Operators
    calculateArea(5, 3);

    // Control Structures
    int number = 10;
    if (number > 0) {
        printf("Number is positive.\n");
    } else if (number < 0) {
        printf("Number is negative.\n");
    } else {
        printf("Number is zero.\n");
    }

    // Functions
    printPattern(5);

    // Arrays
    int arr[] = {5, 3, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, size);
    printf("Array after sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Pointers
    int num1 = 10, num2 = 20;
    swap(&num1, &num2);
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Strings
    char str[] = "Hello, World!";
    printf("Reverse of the string: ");
    printReverseString(str);
    printf("\n");

    // Structures
    struct Car car1 = {"Toyota", "Corolla", 2021, 25000.50};
    saveCarRecord(car1);
    readCarRecord();

    // File Handling
    printMenu();
    int option;
    scanf("%d", &option);
    executeOption(option);

    return 0;
}

// Function definition for printing a welcome message
void printWelcomeMessage() {
    printf("Welcome to our program!\n");
}

// Function definition for calculating the area of a rectangle
void calculateArea(int length, int width) {
    int area = length * width;
    printf("Area of the rectangle: %d\n", area);
}

// Function definition for printing a pattern
void printPattern(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function definition for printing reverse of a string
void printReverseString(char *str) {
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

// Function definition for swapping two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function definition for performing bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function definition for printing menu
void printMenu() {
    printf("Menu:\n");
    printf("1. Save Car Record\n");
    printf("2. Read Car Record\n");
    printf("Enter your choice: ");
}

// Function definition for executing option
void executeOption(int option) {
    switch (option) {
        case 1:
            printf("Saving car record...\n");
            break;
        case 2:
            printf("Reading car record...\n");
            break;
        default:
            printf("Invalid option!\n");
    }
}

// Function definition for saving car record to file
void saveCarRecord(struct Car car) {
    FILE *filePointer;
    filePointer = fopen("car_record.txt", "w");
    fprintf(filePointer, "Make: %s\n", car.make);
    fprintf(filePointer, "Model: %s\n", car.model);
    fprintf(filePointer, "Year: %d\n", car.year);
    fprintf(filePointer, "Price: %.2f\n", car.price);
    fclose(filePointer);
}

// Function definition for reading car record from file
void readCarRecord() {
    FILE *filePointer;
    char line[100];
    filePointer = fopen("car_record.txt", "r");
    while (fgets(line, sizeof(line), filePointer)) {
        printf("%s", line);
    }
    fclose(filePointer);
}

