#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_TICKER_LENGTH 10
#define NUM_NIFTY50_COMPANIES 50

// Structure to represent a company
typedef struct {
    char name[MAX_NAME_LENGTH];
    char ticker[MAX_TICKER_LENGTH];
    float price;
    int quantity;
} Company;

// Function to display the list of Nifty 50 companies
void displayNifty50Companies(Company companies[], int numCompanies) {
    printf("Nifty 50 Companies:\n");
    printf("%-30s %-15s\n", "Company Name", "Ticker Symbol");
    for (int i = 0; i < numCompanies; ++i) {
        printf("%-30s %-15s\n", companies[i].name, companies[i].ticker);
    }
}

// Function to simulate buying a stock
void buyStock(Company companies[], int numCompanies) {
    char ticker[MAX_TICKER_LENGTH];
    int quantity;

    printf("Enter the ticker symbol of the stock you want to buy: ");
    scanf("%s", ticker);

    // Search for the company in the list
    for (int i = 0; i < numCompanies; ++i) {
        if (strcmp(companies[i].ticker, ticker) == 0) {
            printf("Enter the quantity you want to buy: ");
            scanf("%d", &quantity);

            float totalCost = quantity * companies[i].price;
            printf("Buying %d shares of %s at %.2f each for a total of %.2f\n", quantity, companies[i].name, companies[i].price, totalCost);
            companies[i].quantity += quantity;
            return;
        }
    }

    printf("Stock with ticker symbol %s not found.\n", ticker);
}

// Function to simulate selling a stock
void sellStock(Company companies[], int numCompanies) {
    char ticker[MAX_TICKER_LENGTH];
    int quantity;

    printf("Enter the ticker symbol of the stock you want to sell: ");
    scanf("%s", ticker);

    // Search for the company in the list
    for (int i = 0; i < numCompanies; ++i) {
        if (strcmp(companies[i].ticker, ticker) == 0) {
            printf("Enter the quantity you want to sell: ");
            scanf("%d", &quantity);

            if (companies[i].quantity >= quantity) {
                float totalRevenue = quantity * companies[i].price;
                printf("Selling %d shares of %s at %.2f each for a total of %.2f\n", quantity, companies[i].name, companies[i].price, totalRevenue);
                companies[i].quantity -= quantity;
                return;
            } else {
                printf("Not enough shares of %s available for sale.\n", companies[i].name);
                return;
            }
        }
    }

    printf("Stock with ticker symbol %s not found.\n", ticker);
}

// Function to display the current stock prices
void displayStockPrices(Company companies[], int numCompanies) {
    printf("Current Stock Prices:\n");
    printf("%-30s %-15s %-10s\n", "Company Name", "Ticker Symbol", "Price");
    for (int i = 0; i < numCompanies; ++i) {
        printf("%-30s %-15s %.2f\n", companies[i].name, companies[i].ticker, companies[i].price);
    }
}

int main() {
    // Initialize the list of Nifty 50 companies with some sample data
    Company nifty50[NUM_NIFTY50_COMPANIES] = {
        {"Adani Ports & SEZ", "ADANIPORTS", 750.50, 0},
        {"Asian Paints", "ASIANPAINT", 3350.25, 0},
        {"Axis Bank", "AXISBANK", 800.75, 0},
        // Add more companies with their respective data here
    };

    int choice;
    do {
        printf("\nNifty 50 Stock Market Simulation\n");
        printf("1. Display Nifty 50 Companies\n");
        printf("2. Buy Stock\n");
        printf("3. Sell Stock\n");
        printf("4. Display Stock Prices\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayNifty50Companies(nifty50, NUM_NIFTY50_COMPANIES);
                break;
            case 2:
                buyStock(nifty50, NUM_NIFTY50_COMPANIES);
                break;
            case 3:
                sellStock(nifty50, NUM_NIFTY50_COMPANIES);
                break;
            case 4:
                displayStockPrices(nifty50, NUM_NIFTY50_COMPANIES);
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

