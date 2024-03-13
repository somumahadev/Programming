#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DONORS 100
#define MAX_NAME_LENGTH 50
#define THRESHOLD 500 // Threshold for blood quantity alert (in mL)

// Structure to hold donor information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char bloodGroup[4]; // Blood group (e.g., "A+", "AB-")
    int quantity; // Quantity of blood donated (in mL)
    int donationCount; // Number of times donor has donated blood
} Donor;

// Structure to hold blood request information
typedef struct {
    char bloodGroup[4]; // Blood group requested
    int quantity; // Quantity requested (in mL)
    char requesterName[MAX_NAME_LENGTH]; // Name of the requester
} BloodRequest;

// Global arrays to store donors and blood requests
Donor donors[MAX_DONORS];
int donorCount = 0;
BloodRequest requests[MAX_DONORS];
int requestCount = 0;

// Function declarations
void addDonor();
void searchDonor();
void processRequest();
void displayInventory();
void displayRequests();
void updateDonor();
void cancelRequest();
void checkCompatibility(const char *donorGroup, const char *recipientGroup);
void bloodTypeInventory();
void ageFiltering();
void donationHistory();
void bloodQuantityAlert();

int main() {
    char choice;

    // Main menu loop
    while (1) {
        printf("\nBlood Bank Management System Menu:\n");
        printf("1. Add Donor\n");
        printf("2. Search Donor\n");
        printf("3. Process Blood Request\n");
        printf("4. Display Blood Inventory\n");
        printf("5. Display Blood Requests\n");
        printf("6. Update Donor Information\n");
        printf("7. Cancel Blood Request\n");
        printf("8. Blood Type Inventory Summary\n");
        printf("9. Age Filtering\n");
        printf("10. Donation History Report\n");
        printf("11. Blood Quantity Threshold Alert\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addDonor();
                break;
            case '2':
                searchDonor();
                break;
            case '3':
                processRequest();
                break;
            case '4':
                displayInventory();
                break;
            case '5':
                displayRequests();
                break;
            case '6':
                updateDonor();
                break;
            case '7':
                cancelRequest();
                break;
            case '8':
                bloodTypeInventory();
                break;
            case '9':
                ageFiltering();
                break;
            case '10':
                donationHistory();
                break;
            case '11':
                bloodQuantityAlert();
                break;
            case '12':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to add a donor to the system
void addDonor() {
    if (donorCount >= MAX_DONORS) {
        printf("Cannot add more donors. Maximum limit reached.\n");
        return;
    }

    Donor newDonor;
    printf("Enter donor name: ");
    scanf("%s", newDonor.name);
    printf("Enter donor age: ");
    scanf("%d", &newDonor.age);
    printf("Enter donor blood group: ");
    scanf("%s", newDonor.bloodGroup);
    printf("Enter quantity of blood donated (in mL): ");
    scanf("%d", &newDonor.quantity);
    newDonor.donationCount = 1; // Set initial donation count

    donors[donorCount++] = newDonor;
    printf("Donor added successfully.\n");
}

// Function to search for a donor by blood group
void searchDonor() {
    char searchGroup[4];
    printf("Enter blood group to search: ");
    scanf("%s", searchGroup);

    printf("Matching Donors:\n");
    int found = 0;
    for (int i = 0; i < donorCount; i++) {
        if (strcmp(donors[i].bloodGroup, searchGroup) == 0) {
            printf("Name: %s, Age: %d, Blood Group: %s, Quantity: %d mL, Donation Count: %d\n",
                   donors[i].name, donors[i].age, donors[i].bloodGroup, donors[i].quantity, donors[i].donationCount);
            found = 1;
        }
    }

    if (!found) {
        printf("No donors found for blood group %s.\n", searchGroup);
    }
}

// Function to process a blood request
void processRequest() {
    BloodRequest newRequest;
    printf("Enter blood group for the request: ");
    scanf("%s", newRequest.bloodGroup);
    printf("Enter quantity of blood needed (in mL): ");
    scanf("%d", &newRequest.quantity);
    printf("Enter your name: ");
    scanf("%s", newRequest.requesterName);

    requests[requestCount++] = newRequest;
    printf("Blood request placed successfully.\n");
}

// Function to display blood inventory
void displayInventory() {
    printf("Blood Inventory:\n");
    for (int i = 0; i < donorCount; i++) {
        printf("Name: %s, Blood Group: %s, Quantity: %d mL\n",
               donors[i].name, donors[i].bloodGroup, donors[i].quantity);
    }
}

// Function to display blood requests
void displayRequests() {
    printf("Blood Requests:\n");
    for (int i = 0; i < requestCount; i++) {
        printf("Requester: %s, Blood Group: %s, Quantity: %d mL\n",
               requests[i].requesterName, requests[i].bloodGroup, requests[i].quantity);
    }
}

// Function to update donor information
void updateDonor() {
    char donorName[MAX_NAME_LENGTH];
    printf("Enter the name of the donor to update: ");
    scanf("%s", donorName);

    int found = 0;
    for (int i = 0; i < donorCount; i++) {
        if (strcmp(donors[i].name, donorName) == 0) {
            printf("Enter updated quantity of blood donated (in mL): ");
            scanf("%d", &donors[i].quantity);
            donors[i].donationCount++; // Increment donation count
            printf("Donor information updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Donor not found.\n");
    }
}

// Function to cancel a blood request
void cancelRequest() {
    char requesterName[MAX_NAME_LENGTH];
    printf("Enter the name of the requester to cancel the request: ");
    scanf("%s", requesterName);

    int found = 0;
    for (int i = 0; i < requestCount; i++) {
        if (strcmp(requests[i].requesterName, requesterName) == 0) {
            // Remove the request by shifting the remaining requests
            for (int j = i; j < requestCount - 1; j++) {
                requests[j] = requests[j + 1];
            }
            requestCount--;
            printf("Blood request canceled successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Requester not found.\n");
    }
}

// Function to display a summary of blood type inventory
void bloodTypeInventory() {
    int countA = 0, countB = 0, countAB = 0, countO = 0;
    for (int i = 0; i < donorCount; i++) {
        if (strcmp(donors[i].bloodGroup, "A+") == 0 || strcmp(donors[i].bloodGroup, "A-") == 0) {
            countA += donors[i].quantity;
        } else if (strcmp(donors[i].bloodGroup, "B+") == 0 || strcmp(donors[i].bloodGroup, "B-") == 0) {
            countB += donors[i].quantity;
        } else if (strcmp(donors[i].bloodGroup, "AB+") == 0 || strcmp(donors[i].bloodGroup, "AB-") == 0) {
            countAB += donors[i].quantity;
        } else if (strcmp(donors[i].bloodGroup, "O+") == 0 || strcmp(donors[i].bloodGroup, "O-") == 0) {
            countO += donors[i].quantity;
        }
    }
    printf("Blood Type Inventory Summary:\n");
    printf("A: %d mL\n", countA);
    printf("B: %d mL\n", countB);
    printf("AB: %d mL\n", countAB);
    printf("O: %d mL\n", countO);
}

// Function to filter donors by age range
void ageFiltering() {
    int minAge, maxAge;
    printf("Enter minimum age: ");
    scanf("%d", &minAge);
    printf("Enter maximum age: ");
    scanf("%d", &maxAge);

    printf("Donors within age range %d - %d:\n", minAge, maxAge);
    for (int i = 0; i < donorCount; i++) {
        if (donors[i].age >= minAge && donors[i].age <= maxAge) {
            printf("Name: %s, Age: %d, Blood Group: %s, Quantity: %d mL\n",
                   donors[i].name, donors[i].age, donors[i].bloodGroup, donors[i].quantity);
        }
    }
}

// Function to display donation history of a donor
void donationHistory() {
    char donorName[MAX_NAME_LENGTH];
    printf("Enter the name of the donor to view donation history: ");
    scanf("%s", donorName);

    int found = 0;
    for (int i = 0; i < donorCount; i++) {
        if (strcmp(donors[i].name, donorName) == 0) {
            printf("Donation History for %s:\n", donorName);
            printf("Blood Group: %s, Quantity: %d mL, Donation Count: %d\n",
                   donors[i].bloodGroup, donors[i].quantity, donors[i].donationCount);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Donor not found.\n");
    }
}

// Function to check blood quantity and alert if below threshold
void bloodQuantityAlert() {
    int alertFlag = 0;
    printf("Blood Quantity Alert:\n");
    for (int i = 0; i < donorCount; i++) {
        if (strcmp(donors[i].bloodGroup, "A+") == 0 && donors[i].quantity < THRESHOLD) {
            printf("Blood quantity for A+ type is below threshold!\n");
            alertFlag = 1;
        } else if (strcmp(donors[i].bloodGroup, "B+") == 0 && donors[i].quantity < THRESHOLD) {
            printf("Blood quantity for B+ type is below threshold!\n");
            alertFlag = 1;
        } else if (strcmp(donors[i].bloodGroup, "AB+") == 0 && donors[i].quantity < THRESHOLD) {
            printf("Blood quantity for AB+ type is below threshold!\n");
            alertFlag = 1;
        } else if (strcmp(donors[i].bloodGroup, "O+") == 0 && donors[i].quantity < THRESHOLD) {
            printf("Blood quantity for O+ type is below threshold!\n");
            alertFlag = 1;
        }
    }

    if (!alertFlag) {
        printf("Blood quantities are within acceptable range.\n");
    }
}

