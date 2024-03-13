#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Structure to hold product data
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Product;

// Structure to hold user data
typedef struct {
    char username[MAX_NAME_LENGTH];
    float balance;
} User;

// Function declarations
void browseProducts(Product products[], int count);
void addToCart(Product products[], int count, int *cart, int *cartSize);
void viewCart(Product products[], int cart[], int cartSize);
void checkout(User *user, Product products[], int cart[], int cartSize);

int main() {
    Product products[MAX_PRODUCTS];
    products[0] = (Product){"Laptop", 999.99};
    products[1] = (Product){"Smartphone", 699.99};
    products[2] = (Product){"Headphones", 149.99};
    int productCount = 3;

    User user = {"user123", 1000.0};

    int cart[MAX_PRODUCTS];
    int cartSize = 0;

    char choice;
    while (1) {
        printf("\nAmazon-like Store Menu:\n");
        printf("1. Browse Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                browseProducts(products, productCount);
                break;
            case '2':
                addToCart(products, productCount, cart, &cartSize);
                break;
            case '3':
                viewCart(products, cart, cartSize);
                break;
            case '4':
                checkout(&user, products, cart, cartSize);
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

// Function to browse products
void browseProducts(Product products[], int count) {
    printf("Available Products:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, products[i].name, products[i].price);
    }
}

// Function to add a product to the cart
void addToCart(Product products[], int count, int *cart, int *cartSize) {
    int choice;
    browseProducts(products, count);
    printf("Enter the product number to add to cart: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Invalid product number.\n");
        return;
    }

    cart[*cartSize] = choice - 1;
    (*cartSize)++;
    printf("Product added to cart.\n");
}

// Function to view the cart
void viewCart(Product products[], int cart[], int cartSize) {
    printf("Your Cart:\n");
    for (int i = 0; i < cartSize; i++) {
        int index = cart[i];
        printf("%d. %s - $%.2f\n", i + 1, products[index].name, products[index].price);
    }
}

// Function to checkout and process the order
void checkout(User *user, Product products[], int cart[], int cartSize) {
    float total = 0;
    printf("Order Summary:\n");
    for (int i = 0; i < cartSize; i++) {
        int index = cart[i];
        printf("%d. %s - $%.2f\n", i + 1, products[index].name, products[index].price);
        total += products[index].price;
    }

    printf("Total: $%.2f\n", total);

    if (total > user->balance) {
        printf("Insufficient balance. Please remove some items from your cart or add funds.\n");
        return;
    }

    user->balance -= total;
    printf("Order placed successfully. Remaining balance: $%.2f\n", user->balance);
    // Code to process the order (e.g., update inventory, send confirmation email, etc.) goes here
}

