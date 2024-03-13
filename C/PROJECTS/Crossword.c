#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_GRID_SIZE 15

// Function prototypes
void initializeGrid(char grid[][MAX_GRID_SIZE], int size);
void displayGrid(char grid[][MAX_GRID_SIZE], int size);
bool canPlaceWord(char grid[][MAX_GRID_SIZE], int size, const char *word, int row, int col, bool isHorizontal);
void placeWord(char grid[][MAX_GRID_SIZE], int size, const char *word, int row, int col, bool isHorizontal);
void generateCrossword(char grid[][MAX_GRID_SIZE], int size, char *words[], int numWords);
void generateSymmetricWords(char *words[], int numWords);
void displayClues(char *words[], int numWords);

int main() {
    // Seed for random number generation
    srand(time(NULL));

    // Words for the crossword puzzle
    char *words[] = {"HELLO", "WORLD", "CROSSWORD", "PUZZLE", "GENERATOR"};

    // Number of words
    int numWords = sizeof(words) / sizeof(words[0]);

    // Randomly select words
    generateSymmetricWords(words, numWords);

    // User-defined grid size
    int size;
    printf("Enter grid size (max %d): ", MAX_GRID_SIZE);
    scanf("%d", &size);

    if (size > MAX_GRID_SIZE || size <= 0) {
        printf("Invalid grid size.\n");
        return 1;
    }

    // Create the grid
    char grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
    initializeGrid(grid, size);

    // Generate the crossword puzzle
    generateCrossword(grid, size, words, numWords);

    // Display the crossword puzzle
    printf("\nGenerated Crossword Puzzle:\n");
    displayGrid(grid, size);

    // Display clues
    printf("\nClues:\n");
    displayClues(words, numWords);

    return 0;
}

// Initialize the grid with dots ('.')
void initializeGrid(char grid[][MAX_GRID_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = '.';
        }
    }
}

// Display the grid
void displayGrid(char grid[][MAX_GRID_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Check if a word can be placed at the given position
bool canPlaceWord(char grid[][MAX_GRID_SIZE], int size, const char *word, int row, int col, bool isHorizontal) {
    int len = strlen(word);
    if (isHorizontal) {
        if (col + len > size) return false;
        for (int j = col; j < col + len; j++) {
            if (grid[row][j] != '.' && grid[row][j] != word[j - col]) return false;
        }
    } else {
        if (row + len > size) return false;
        for (int i = row; i < row + len; i++) {
            if (grid[i][col] != '.' && grid[i][col] != word[i - row]) return false;
        }
    }
    return true;
}

// Place a word on the grid
void placeWord(char grid[][MAX_GRID_SIZE], int size, const char *word, int row, int col, bool isHorizontal) {
    int len = strlen(word);
    if (isHorizontal) {
        for (int j = col; j < col + len; j++) {
            grid[row][j] = word[j - col];
        }
    } else {
        for (int i = row; i < row + len; i++) {
            grid[i][col] = word[i - row];
        }
    }
}

// Generate the crossword puzzle
void generateCrossword(char grid[][MAX_GRID_SIZE], int size, char *words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        int len = strlen(words[i]);
        bool placed = false;
        while (!placed) {
            // Randomly choose position and direction
            int row = rand() % size;
            int col = rand() % size;
            bool isHorizontal = rand() % 2 == 0;

            if (canPlaceWord(grid, size, words[i], row, col, isHorizontal)) {
                placeWord(grid, size, words[i], row, col, isHorizontal);
                placed = true;
            }
        }
    }
}

// Generate symmetric words by duplicating and reversing them
void generateSymmetricWords(char *words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        char *word = words[i];
        int len = strlen(word);
        char *symmetricWord = malloc((2 * len + 1) * sizeof(char));
        strcpy(symmetricWord, word);
        strrev(word);
        strcat(symmetricWord, word);
        words[numWords + i] = symmetricWord;
    }
}

// Display clues for each word
void displayClues(char *words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%d. %s\n", i + 1, words[i]);
    }
}

