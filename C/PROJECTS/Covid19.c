#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CASES 100

// Structure to hold COVID-19 case data
typedef struct {
    char country[50];
    int confirmed;
    int recovered;
    int deaths;
} CovidCase;

// Function declarations
void addCase(CovidCase cases[], int *count);
void viewCases(CovidCase cases[], int count);
void updateCase(CovidCase cases[], int count);
void deleteCase(CovidCase cases[], int *count);
void generateReport(CovidCase cases[], int count);
void generateGraph(CovidCase cases[], int count);

int main() {
    CovidCase cases[MAX_CASES];
    int count = 0;
    char choice;

    while (1) {
        printf("\nCOVID-19 Cases Menu:\n");
        printf("1. Add Case\n");
        printf("2. View Cases\n");
        printf("3. Update Case\n");
        printf("4. Delete Case\n");
        printf("5. Generate Report\n");
        printf("6. Generate Graph\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addCase(cases, &count);
                break;
            case '2':
                viewCases(cases, count);
                break;
            case '3':
                updateCase(cases, count);
                break;
            case '4':
                deleteCase(cases, &count);
                break;
            case '5':
                generateReport(cases, count);
                break;
            case '6':
                generateGraph(cases, count);
                break;
            case '7':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to add a new COVID-19 case
void addCase(CovidCase cases[], int *count) {
    if (*count >= MAX_CASES) {
        printf("Cannot add more cases. Maximum limit reached.\n");
        return;
    }

    printf("Enter country name: ");
    scanf("%s", cases[*count].country);
    printf("Enter number of confirmed cases: ");
    scanf("%d", &cases[*count].confirmed);
    printf("Enter number of recovered cases: ");
    scanf("%d", &cases[*count].recovered);
    printf("Enter number of deaths: ");
    scanf("%d", &cases[*count].deaths);

    (*count)++;
}

// Function to view all COVID-19 cases
void viewCases(CovidCase cases[], int count) {
    if (count == 0) {
        printf("No cases added yet.\n");
        return;
    }

    printf("COVID-19 Cases:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Country: %s, Confirmed: %d, Recovered: %d, Deaths: %d\n",
               i + 1, cases[i].country, cases[i].confirmed, cases[i].recovered, cases[i].deaths);
    }
}

// Function to update COVID-19 case data
void updateCase(CovidCase cases[], int count) {
    if (count == 0) {
        printf("No cases added yet.\n");
        return;
    }

    char country[50];
    printf("Enter country name to update case data: ");
    scanf("%s", country);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(cases[i].country, country) == 0) {
            printf("Enter new number of confirmed cases: ");
            scanf("%d", &cases[i].confirmed);
            printf("Enter new number of recovered cases: ");
            scanf("%d", &cases[i].recovered);
            printf("Enter new number of deaths: ");
            scanf("%d", &cases[i].deaths);
            printf("Case data updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Case not found.\n");
    }
}

// Function to delete a COVID-19 case
void deleteCase(CovidCase cases[], int *count) {
    if (*count == 0) {
        printf("No cases added yet.\n");
        return;
    }

    char country[50];
    printf("Enter country name to delete case: ");
    scanf("%s", country);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(cases[i].country, country) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(cases[j].country, cases[j + 1].country);
                cases[j].confirmed = cases[j + 1].confirmed;
                cases[j].recovered = cases[j + 1].recovered;
                cases[j].deaths = cases[j + 1].deaths;
            }
            (*count)--;
            printf("Case deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Case not found.\n");
    }
}

// Function to generate reports
void generateReport(CovidCase cases[], int count) {
    if (count == 0) {
        printf("No cases added yet.\n");
        return;
    }

    int totalConfirmed = 0, totalRecovered = 0, totalDeaths = 0;

    printf("\nCOVID-19 Report:\n");
    printf("Country\t\tConfirmed\tRecovered\tDeaths\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s%-15d%-15d%-d\n",
               cases[i].country, cases[i].confirmed, cases[i].recovered, cases[i].deaths);
        totalConfirmed += cases[i].confirmed;
        totalRecovered += cases[i].recovered;
        totalDeaths += cases[i].deaths;
    }
    printf("\nTotal Confirmed Cases: %d\n", totalConfirmed);
    printf("Total Recovered Cases: %d\n", totalRecovered);
    printf("Total Deaths: %d\n", totalDeaths);
}

// Function to generate a graph using gnuplot
void generateGraph(CovidCase cases[], int count) {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (!gnuplotPipe) {
        printf("gnuplot not found, please install gnuplot to generate graphs.\n");
        return;
    }

    fprintf(gnuplotPipe, "set title 'COVID-19 Cases'\n");
    fprintf(gnuplotPipe, "set ylabel 'Number of Cases'\n");
    fprintf(gnuplotPipe, "set xlabel 'Countries'\n");
    fprintf(gnuplotPipe, "set style data histograms\n");
    fprintf(gnuplotPipe, "set style fill solid\n");
    fprintf(gnuplotPipe, "plot '-' using 2:xtic(1) title 'Confirmed', '' using 3 title 'Recovered', '' using 4 title 'Deaths'\n");

    for (int i = 0; i < count; i++) {
        fprintf(gnuplotPipe, "%s %d %d %d\n", cases[i].country, cases[i].confirmed, cases[i].recovered, cases[i].deaths);
    }
    fprintf(gnuplotPipe, "e\n");
    fprintf(gnuplotPipe, "e\n");
    fprintf(gnuplotPipe, "e\n");

    pclose(gnuplotPipe);
}

