#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for a student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Function prototypes
int add(int num1, int num2);
void printWelcomeMessage();
void updateQuantity(int *quantity, int increment);
void displayMessage(char *message);
void printArray(int arr[], int size);
void swap(int *a, int *b);
void bubbleSort(int arr[], int size);
void printString(char *str);
void saveStudentRecord(struct Student student);
void readStudentRecord();

int main() {
    // Variables and Data Types
    int integerVariable = 10;
    float floatVariable = 3.14;
    char charVariable = 'A';
    printf("Integer Variable: %d\n", integerVariable);
    printf("Float Variable: %f\n", floatVariable);
    printf("Char Variable: %c\n", charVariable);

    // Operators
    int num1 = 10, num2 = 5;
    printf("Addition: %d\n", num1 + num2);
    printf("Subtraction: %d\n", num1 - num2);
    printf("Multiplication: %d\n", num1 * num2);
    printf("Division: %d\n", num1 / num2);
    printf("Modulus: %d\n", num1 % num2);

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
    int result = add(5, 3);
    printf("Result: %d\n", result);

    // Arrays
    int arr[] = {5, 3, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting: ");
    printArray(arr, size);
    bubbleSort(arr, size);
    printf("Array after sorting: ");
    printArray(arr, size);

    // Pointers
    int num = 10;
    int *ptr = &num;
    printf("Value of num: %d\n", num);
    printf("Value pointed by ptr: %d\n", *ptr);

    // Strings
    char str[] = "Hello, World!";
    printf("String: ");
    printString(str);

    // Structures
    struct Student student1;
    student1.rollNumber = 101;
    strcpy(student1.name, "John");
    student1.marks = 85.5;
    printf("Student Record:\n");
    printf("Roll Number: %d\n", student1.rollNumber);
    printf("Name: %s\n", student1.name);
    printf("Marks: %.2f\n", student1.marks);

    // File Handling
    struct Student student2 = {102, "Alice", 90.0};
    printf("Saving student record...\n");
    saveStudentRecord(student2);
    printf("Reading student record...\n");
    readStudentRecord();

    return 0;
}

// Function definition for calculating the sum of two numbers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function definition for printing a welcome message
void printWelcomeMessage() {
    printf("Welcome to our program!\n");
}

// Function definition for updating the quantity of an item
void updateQuantity(int *quantity, int increment) {
    *quantity += increment;
}

// Function definition for printing a message
void displayMessage(char *message) {
    printf("Message: %s\n", message);
}

// Function definition for printing an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

// Function definition for printing a string
void printString(char *str) {
    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }
    printf("\n");
}

// Function definition for saving student record to file
void saveStudentRecord(struct Student student) {
    FILE *filePointer;
    filePointer = fopen("student_record.txt", "w");
    fprintf(filePointer, "Roll Number: %d\n", student.rollNumber);
    fprintf(filePointer, "Name: %s\n", student.name);
    fprintf(filePointer, "Marks: %.2f\n", student.marks);
    fclose(filePointer);
}

// Function definition for reading student record from file
void readStudentRecord() {
    FILE *filePointer;
    char line[100];
    filePointer = fopen("student_record.txt", "r");
    while (fgets(line, sizeof(line), filePointer)) {
        printf("%s", line);
    }
    fclose(filePointer);
}

