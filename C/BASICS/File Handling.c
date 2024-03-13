#include <stdio.h>

int main() {
    FILE *filePointer;
    char data[50] = "This is a file handling example.";

    // Writing to a file
    filePointer = fopen("example.txt", "w");
    fprintf(filePointer, "%s", data);
    fclose(filePointer);

    // Reading from a file
    filePointer = fopen("example.txt", "r");
    fgets(data, 50, filePointer);
    printf("Data from file: %s\n", data);
    fclose(filePointer);

    return 0;
}

