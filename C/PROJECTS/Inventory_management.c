#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Structure to hold inventory item data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} InventoryItem;

// Function declarations
void addItem(InventoryItem items[], int *count);
void viewItems(InventoryItem items[], int count);
void updateItem(InventoryItem items[], int count);
void deleteItem(InventoryItem items[], int *count);
void searchItem(InventoryItem items[], int count);

int main() {
    InventoryItem items[MAX_ITEMS];
    int count = 0;
    char choice;

    while (1) {
        printf("\nInventory Management System Menu:\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Search Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addItem(items, &count);
                break;
            case '2':
                viewItems(items, count);
                break;
            case '3':
                updateItem(items, count);
                break;
            case '4':
                deleteItem(items, &count);
                break;
            case '5':
                searchItem(items, count);
                break;
            case '6':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to add a new item to inventory
void addItem(InventoryItem items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Cannot add more items. Maximum limit reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[*count].name);
    printf("Enter quantity: ");
    scanf("%d", &items[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &items[*count].price);

    (*count)++;
}

// Function to view all items in inventory
void viewItems(InventoryItem items[], int count) {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("Inventory Items:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Quantity: %d, Price: %.2f\n", i + 1, items[i].name, items[i].quantity, items[i].price);
    }
}

// Function to update an item in inventory
void updateItem(InventoryItem items[], int count) {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    int index;
    printf("Enter index of item to update: ");
    scanf("%d", &index);
    index--; // Adjust index to 0-based

    if (index < 0 || index >= count) {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new item name: ");
    scanf("%s", items[index].name);
    printf("Enter new quantity: ");
    scanf("%d", &items[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &items[index].price);
    printf("Item updated successfully.\n");
}

// Function to delete an item from inventory
void deleteItem(InventoryItem items[], int *count) {
    if (*count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    int index;
    printf("Enter index of item to delete: ");
    scanf("%d", &index);
    index--; // Adjust index to 0-based

    if (index < 0 || index >= *count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        strcpy(items[i].name, items[i + 1].name);
        items[i].quantity = items[i + 1].quantity;
        items[i].price = items[i + 1].price;
    }
    (*count)--;
    printf("Item deleted successfully.\n");
}

// Function to search for an item in inventory
void searchItem(InventoryItem items[], int count) {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            printf("Item found:\n");
            printf("Name: %s, Quantity: %d, Price: %.2f\n", items[i].name, items[i].quantity, items[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

