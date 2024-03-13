#include <stdio.h>

struct Student {
    int rollNumber;
    char name[20];
    float marks;
};

int main() {
    struct Student student1;
    
    student1.rollNumber = 101;
    strcpy(student1.name, "John");
    student1.marks = 85.5;
    
    printf("Roll Number: %d\n", student1.rollNumber);
    printf("Name: %s\n", student1.name);
    printf("Marks: %.2f\n", student1.marks);
    
    return 0;
}

