#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for bank account
struct BankAccount {
    char accountNumber[20];
    char accountHolderName[50];
    float balance;
};

// Function prototypes
void printMenu();
void executeOption(int option, struct BankAccount *accounts, int *numAccounts);
void createAccount(struct BankAccount *accounts, int *numAccounts);
void displayAccounts(struct BankAccount *accounts, int numAccounts);
void deposit(struct BankAccount *accounts, int numAccounts);
void withdraw(struct BankAccount *accounts, int numAccounts);
void saveAccounts(struct BankAccount *accounts, int numAccounts);
void loadAccounts(struct BankAccount *accounts, int *numAccounts);

int main() {
    struct BankAccount accounts[100];
    int numAccounts = 0;

    // Load existing accounts from file
    loadAccounts(accounts, &numAccounts);

    // Main loop
    int option;
    do {
        printMenu();
        scanf("%d", &option);
        executeOption(option, accounts, &numAccounts);
    } while (option != 7);

    return 0;
}

// Function definition for printing menu
void printMenu() {
    printf("\n===== Banking System Menu =====\n");
    printf("1. Create Account\n");
    printf("2. Display Accounts\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Save Accounts\n");
    printf("6. Load Accounts\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Function definition for executing option
void executeOption(int option, struct BankAccount *accounts, int *numAccounts) {
    switch (option) {
        case 1:
            createAccount(accounts, numAccounts);
            break;
        case 2:
            displayAccounts(accounts, *numAccounts);
            break;
        case 3:
            deposit(accounts, *numAccounts);
            break;
        case 4:
            withdraw(accounts, *numAccounts);
            break;
        case 5:
            saveAccounts(accounts, *numAccounts);
            break;
        case 6:
            loadAccounts(accounts, numAccounts);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option!\n");
    }
}

// Function definition for creating a new account
void createAccount(struct BankAccount *accounts, int *numAccounts) {
    printf("Enter account number: ");
    scanf("%s", accounts[*numAccounts].accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", accounts[*numAccounts].accountHolderName);
    printf("Enter initial balance: ");
    scanf("%f", &accounts[*numAccounts].balance);
    (*numAccounts)++;
    printf("Account created successfully!\n");
}

// Function definition for displaying all accounts
void displayAccounts(struct BankAccount *accounts, int numAccounts) {
    printf("\n===== Accounts List =====\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Account Number: %s, Holder Name: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].accountHolderName, accounts[i].balance);
    }
}

// Function definition for depositing money into an account
void deposit(struct BankAccount *accounts, int numAccounts) {
    char accountNumber[20];
    float amount;
    printf("Enter account number: ");
    scanf("%s", accountNumber);
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function definition for withdrawing money from an account
void withdraw(struct BankAccount *accounts, int numAccounts) {
    char accountNumber[20];
    float amount;
    printf("Enter account number: ");
    scanf("%s", accountNumber);
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function definition for saving accounts to file
void saveAccounts(struct BankAccount *accounts, int numAccounts) {
    FILE *filePointer;
    filePointer = fopen("accounts.txt", "w");
    for (int i = 0; i < numAccounts; i++) {
        fprintf(filePointer, "%s %s %.2f\n", 
                accounts[i].accountNumber, accounts[i].accountHolderName, accounts[i].balance);
    }
    fclose(filePointer);
    printf("Accounts saved successfully!\n");
}

// Function definition for loading accounts from file
void loadAccounts(struct BankAccount *accounts, int *numAccounts) {
    FILE *filePointer;
    filePointer = fopen("accounts.txt", "r");
    if (filePointer == NULL) {
        printf("No accounts found!\n");
        return;
    }
    *numAccounts = 0;
    while (fscanf(filePointer, "%s %s %f\n", 
                  accounts[*numAccounts].accountNumber, accounts[*numAccounts].accountHolderName, 
                  &accounts[*numAccounts].balance) != EOF) {
        (*numAccounts)++;
    }
    fclose(filePointer);
    printf("Accounts loaded successfully!\n");
}

