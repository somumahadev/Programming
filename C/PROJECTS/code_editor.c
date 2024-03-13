#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000
#define MAX_LINES 100

// Function prototypes
void createFile();
void openFile();
void editFile();
void saveFile();
void closeFile();
void displayFileContents();
void searchAndReplace();
void copyAndPaste();

// Global variables
char filename[MAX_FILENAME_LENGTH];
char fileContent[MAX_FILE_CONTENT_LENGTH];
char fileLines[MAX_LINES][MAX_FILE_CONTENT_LENGTH];
int lineCount = 0;

int main() {
    int choice;
    
    while (1) {
        printf("\nCode Editor\n");
        printf("1. Create File\n");
        printf("2. Open File\n");
        printf("3. Edit File\n");
        printf("4. Save File\n");
        printf("5. Close File\n");
        printf("6. Display File Contents\n");
        printf("7. Search and Replace\n");
        printf("8. Copy and Paste\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                openFile();
                break;
            case 3:
                editFile();
                break;
            case 4:
                saveFile();
                break;
            case 5:
                closeFile();
                break;
            case 6:
                displayFileContents();
                break;
            case 7:
                searchAndReplace();
                break;
            case 8:
                copyAndPaste();
                break;
            case 9:
                printf("Exiting the code editor.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void createFile() {
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File created successfully.\n");
    fclose(file);
}

void openFile() {
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("File opened successfully. Contents:\n");
    lineCount = 0;
    while (fgets(fileLines[lineCount], MAX_FILE_CONTENT_LENGTH, file) != NULL) {
        lineCount++;
    }
    fclose(file);
}

void editFile() {
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter new content (press Ctrl+D to finish):\n");
    while (fgets(fileContent, MAX_FILE_CONTENT_LENGTH, stdin) != NULL) {
        fputs(fileContent, file);
    }
    fclose(file);
    printf("File edited successfully.\n");
}

void saveFile() {
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter content to save:\n");
    scanf("%s", fileContent);
    fprintf(file, "%s", fileContent);
    fclose(file);
    printf("File saved successfully.\n");
}

void closeFile() {
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fclose(file);
    printf("File closed successfully.\n");
}

void displayFileContents() {
    if (lineCount == 0) {
        printf("No file is opened.\n");
        return;
    }
    printf("File Contents:\n");
    for (int i = 0; i < lineCount; i++) {
        printf("%d: %s", i+1, fileLines[i]);
    }
}

void searchAndReplace() {
    char search[MAX_FILE_CONTENT_LENGTH];
    char replace[MAX_FILE_CONTENT_LENGTH];

    printf("Enter search string: ");
    scanf("%s", search);
    printf("Enter replace string: ");
    scanf("%s", replace);

    for (int i = 0; i < lineCount; i++) {
        char *found = strstr(fileLines[i], search);
        while (found != NULL) {
            int index = found - fileLines[i];
            strncpy(found, replace, strlen(replace));
            found += strlen(replace);
            strncpy(found, &fileLines[i][index + strlen(search)], strlen(&fileLines[i][index + strlen(search)]));
            found = strstr(found, search);
        }
    }
    printf("Search and replace completed.\n");
}

void copyAndPaste() {
    int startLine, endLine, destinationLine;
    
    printf("Enter starting line number to copy: ");
    scanf("%d", &startLine);
    printf("Enter ending line number to copy: ");
    scanf("%d", &endLine);
    printf("Enter destination line number to paste: ");
    scanf("%d", &destinationLine);

    if (startLine < 1 || endLine > lineCount || startLine > endLine || destinationLine < 1 || destinationLine > lineCount + 1) {
        printf("Invalid input.\n");
        return;
    }

    int numLinesToCopy = endLine - startLine + 1;

    // Shift lines to make space for pasting
    for (int i = lineCount + numLinesToCopy - 1; i >= destinationLine + numLinesToCopy - 1; i--) {
        strcpy(fileLines[i], fileLines[i - numLinesToCopy]);
    }

    // Copy lines
    for (int i = startLine - 1, j = destinationLine - 1; i < endLine; i++, j++) {
        strcpy(fileLines[j], fileLines[i]);
    }

    lineCount += numLinesToCopy;
    printf("Copy and paste completed.\n");
}

