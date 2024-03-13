#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11 // format: DD-MM-YYYY

// Structure to represent a student
typedef struct {
    int roll_number;
    char name[MAX_NAME_LENGTH];
    int present; // 1 if present, 0 if absent
} Student;

// Structure to represent attendance for a particular day
typedef struct {
    char date[MAX_DATE_LENGTH];
    int present_count;
} Attendance;

// Global variables
Student students[MAX_STUDENTS];
int num_students = 0;
Attendance attendance[MAX_STUDENTS];

// Function to add a new student
void addStudent(int roll_number, const char *name) {
    if (num_students < MAX_STUDENTS) {
        students[num_students].roll_number = roll_number;
        strcpy(students[num_students].name, name);
        students[num_students].present = 0;
        num_students++;
        printf("Student added successfully!\n");
    } else {
        printf("Cannot add more students. Maximum limit reached.\n");
    }
}

// Function to mark attendance for a student
void markAttendance(int roll_number, const char *date) {
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll_number) {
            students[i].present = 1;
            strcpy(attendance[i].date, date);
            attendance[i].present_count++;
            printf("Attendance marked successfully for %s on %s.\n", students[i].name, date);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll_number);
}

// Function to generate attendance report
void generateReport() {
    printf("Attendance Report:\n");
    printf("Roll Number\tName\t\tDate\t\tAttendance\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t\t%s\t\t%s\t\t%s\n", students[i].roll_number, students[i].name, attendance[i].date, (students[i].present == 1) ? "Present" : "Absent");
    }
}

int main() {
    int choice, roll_number;
    char name[MAX_NAME_LENGTH], date[MAX_DATE_LENGTH];

    do {
        printf("\nCollege Attendance System\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. Generate Report\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student roll number: ");
                scanf("%d", &roll_number);
                printf("Enter student name: ");
                scanf("%s", name);
                addStudent(roll_number, name);
                break;
            case 2:
                printf("Enter student roll number: ");
                scanf("%d", &roll_number);
                printf("Enter date (DD-MM-YYYY): ");
                scanf("%s", date);
                markAttendance(roll_number, date);
                break;
            case 3:
                generateReport();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

