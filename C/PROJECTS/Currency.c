#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CURRENCIES 10

// Structure to hold currency data
typedef struct {
    char name[20];
    double rate;
} Currency;

// Function declarations
void addCurrency(Currency currencies[], int *count);
void viewCurrencies(Currency currencies[], int count);
void updateCurrency(Currency currencies[], int count);
void deleteCurrency(Currency currencies[], int *count);

int main() {
    Currency currencies[MAX_CURRENCIES];
    int count = 0;
    char choice;

    while (1) {
        printf("\nCurrency Converter Menu:\n");
        printf("1. Add Currency\n");
        printf("2. View Currencies\n");
        printf("3. Update Currency Exchange Rate\n");
        printf("4. Delete Currency\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addCurrency(currencies, &count);
                break;
            case '2':
                viewCurrencies(currencies, count);
                break;
            case '3':
                updateCurrency(currencies, count);
                break;
            case '4':
                deleteCurrency(currencies, &count);
                break;
            case '5':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to add a new currency
void addCurrency(Currency currencies[], int *count) {
    if (*count >= MAX_CURRENCIES) {
        printf("Cannot add more currencies. Maximum limit reached.\n");
        return;
    }

    printf("Enter currency name: ");
    scanf("%s", currencies[*count].name);
    printf("Enter exchange rate: ");
    scanf("%lf", &currencies[*count].rate);

    (*count)++;
}

// Function to view all currencies
void viewCurrencies(Currency currencies[], int count) {
    if (count == 0) {
        printf("No currencies added yet.\n");
        return;
    }

    printf("Currencies:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: %.2lf\n", i + 1, currencies[i].name, currencies[i].rate);
    }
}

// Function to update exchange rate of a currency
void updateCurrency(Currency currencies[], int count) {
    if (count == 0) {
        printf("No currencies added yet.\n");
        return;
    }

    char name[20];
    printf("Enter currency name to update: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(currencies[i].name, name) == 0) {
            printf("Enter new exchange rate: ");
            scanf("%lf", &currencies[i].rate);
            printf("Exchange rate updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Currency not found.\n");
    }
}

// Function to delete a currency
void deleteCurrency(Currency currencies[], int *count) {
    if (*count == 0) {
        printf("No currencies added yet.\n");
        return;
    }

    char name[20];
    printf("Enter currency name to delete: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(currencies[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(currencies[j].name, currencies[j + 1].name);
                currencies[j].rate = currencies[j + 1].rate;
            }
            (*count)--;
            printf("Currency deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Currency not found.\n");
    }
}

