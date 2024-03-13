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
} Company;

// Function to display the Nifty 50 companies
void displayNifty50Companies(Company companies[], int numCompanies) {
    printf("Nifty 50 Companies:\n");
    printf("%-30s %-15s\n", "Company Name", "Ticker Symbol");
    for (int i = 0; i < numCompanies; ++i) {
        printf("%-30s %-15s\n", companies[i].name, companies[i].ticker);
    }
}

int main() {
    // Initialize an array of structures to hold Nifty 50 companies
    Company nifty50[NUM_NIFTY50_COMPANIES] = {
        {"Adani Ports & SEZ", "ADANIPORTS"},
        {"Asian Paints", "ASIANPAINT"},
        {"Axis Bank", "AXISBANK"},
        {"Bajaj Auto", "BAJAJ-AUTO"},
        {"Bajaj Finance", "BAJFINANCE"},
        {"Bajaj Finserv", "BAJAJFINSV"},
        {"Bharti Airtel", "BHARTIARTL"},
        {"Bharti Infratel", "INFRATEL"},
        {"Britannia Industries", "BRITANNIA"},
        {"Cipla", "CIPLA"},
        {"Coal India", "COALINDIA"},
        {"Dr. Reddy's Laboratories", "DRREDDY"},
        {"Eicher Motors", "EICHERMOT"},
        {"Grasim Industries", "GRASIM"},
        {"HCL Technologies", "HCLTECH"},
        {"HDFC", "HDFC"},
        {"HDFC Bank", "HDFCBANK"},
        {"Hero MotoCorp", "HEROMOTOCO"},
        {"Hindalco Industries", "HINDALCO"},
        {"Hindustan Unilever", "HINDUNILVR"},
        {"ICICI Bank", "ICICIBANK"},
        {"IndusInd Bank", "INDUSINDBK"},
        {"Infosys", "INFY"},
        {"ITC", "ITC"},
        {"JSW Steel", "JSWSTEEL"},
        {"Kotak Mahindra Bank", "KOTAKBANK"},
        {"Larsen & Toubro", "LT"},
        {"Mahindra & Mahindra", "M&M"},
        {"Maruti Suzuki India", "MARUTI"},
        {"Nestle India", "NESTLEIND"},
        {"NTPC", "NTPC"},
        {"Oil & Natural Gas Corporation", "ONGC"},
        {"Power Grid Corporation of India", "POWERGRID"},
        {"Reliance Industries", "RELIANCE"},
        {"Shree Cements", "SHREECEM"},
        {"State Bank of India", "SBIN"},
        {"Sun Pharmaceutical Industries", "SUNPHARMA"},
        {"Tata Consultancy Services", "TCS"},
        {"Tata Motors", "TATAMOTORS"},
        {"Tata Steel", "TATASTEEL"},
        {"Tech Mahindra", "TECHM"},
        {"Titan Company", "TITAN"},
        {"UltraTech Cement", "ULTRACEMCO"},
        {"United Phosphorus", "UPL"},
        {"Vedanta", "VEDL"},
        {"Wipro", "WIPRO"},
        {"Yes Bank", "YESBANK"},
        {"Zee Entertainment Enterprises", "ZEEL"},
        {"Adani Enterprises", "ADANIENT"},
        {"Divi's Laboratories", "DIVISLAB"}
    };

    // Display the Nifty 50 companies
    displayNifty50Companies(nifty50, NUM_NIFTY50_COMPANIES);

    return 0;
}

