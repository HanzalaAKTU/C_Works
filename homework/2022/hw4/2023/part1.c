#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void printMenu(char *menuFile);
float getPrice(int choice);
float applyDiscount(float price, char isStudent);
float calculateVAT(float price);
void printReceipt(int orderNumber, struct tm *current_time, float totalPrice, float priceAfterDiscount, char isStudent, int *choices, int *quantities);
int getMenuChoice();
int getQuantity();
char getStudentFlag();
void writeToFile(int orderNumber, struct tm *current_time, float totalPrice, float priceAfterDiscount, char isStudent, int *choices, int *quantities);


void printMenu(char *menuFile)
{
    FILE *fp = fopen(menuFile, "r");
    if(fp == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }
    char line[100];
    int count = 1;
    printf("Yemek Listesi:\n");
    printf("---------------\n");
    printf("Product\tPrice (TL)\n");
    printf("---------------\n");
    while(fgets(line, sizeof(line), fp) != NULL) 
    {
        printf("%d. %s", count, line);
        count++;
    }
    printf("\n");
    fclose(fp);
}

float getPrice(int choice)
{
    float price;

    switch (choice) 
    {
        case 1:
            price = 75.99;
            break;
        case 2:
            price = 21.50;
            break;
        case 3:
            price = 40.00;
            break;
        case 4:
            price = 55.60;
            break;
        case 5:
            price = 15.00;
            break;
        case 6:
            price = 5.00;
            break;
        case 7:
            price = 60.00;
            break;
        case 8:
            price = 32.50;
            break;
        default:
            price = -1.0; // invalid choice
            break;
    }

    return price;
}

float applyDiscount(float price, char isStudent)
{
    float discountRate = 0.0;
    if (isStudent == 'Y') 
        discountRate += 0.125;
    
    if (price >= 150) 
        discountRate += 0.1;
    
    float discountAmount = price * discountRate;
    float discountedPrice = price - discountAmount;
    return discountedPrice;
}

float calculateVAT(float price)
{
    float vat = price * 0.18; // calculate VAT amount
    return vat;
}

void printReceipt(int orderNumber, struct tm *current_time, float totalPrice, float priceAfterDiscount, char isStudent, int *choices, int *quantities) 
{
    float MAX_CHOICES,STUDENT_DISCOUNT,DISCOUNT_THRESHOLD,ADDITIONAL_DISCOUNT;

    printf("%d %02d.%02d.%d/%02d:%02d\n", orderNumber, current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900, current_time->tm_hour, current_time->tm_min);
    printf("------------------------------------\n");
    printf("Product Price (TL)\n");
    printf("------------------------------------\n");
    float total = 0.0;

    for (int i = 0; i < MAX_CHOICES; i++) 
    {
        if (choices[i] != 0 && quantities[i] != 0) 
        {
            float price = getPrice(choices[i]) * quantities[i];
            total += price;
            printf("%d* %-10d %.2f\n", quantities[i], getMenuChoice(choices[i]), price);
        }
    }
    printf("Total: %.2f\n", total);

    if (isStudent == 'Y') 
    {
        float discount = total * STUDENT_DISCOUNT;
        printf("Student discount: -%.2f\n", discount);
        total -= discount;
    }

    if (total >= DISCOUNT_THRESHOLD) 
    {
        float discount = total * ADDITIONAL_DISCOUNT;
        printf("Additional discount: -%.2f\n", discount);
        total -= discount;
    }
    printf("------------------------------------\n");
    printf("Price: %.2f\n", priceAfterDiscount);
    float vat = calculateVAT(total);
    printf("Price + VAT: %.2f\n", priceAfterDiscount + vat);
}

int getMenuChoice()
{
    int choice;
    printf("\nPlease choose a product (1-8): ");
    scanf("%d", &choice);
    
    while (choice < 1 || choice > 8) 
    {
        printf("Invalid choice. Please choose a product (1-8): ");
        scanf("%d", &choice);
    }
    
    return choice;
}

int getQuantity()
{
    int quantity;
    printf("How many servings do you want? ");
    while (scanf("%d", &quantity) != 1 || quantity < 0) 
    {
        printf("Please enter a valid quantity (0 or greater): ");
        while (getchar() != '\n'); // Clear input buffer
    }
    return quantity;
}

char getStudentFlag()
{
    char isStudent;
    do {
        printf("Are you a student? (Y/N): ");
        scanf(" %c", &isStudent);
        isStudent = toupper(isStudent); // Convert to uppercase
        if (isStudent != 'Y' && isStudent != 'N') 
            printf("Please enter a valid answer!\n");
        
    } while (isStudent != 'Y' && isStudent != 'N');

    return isStudent;
}

void writeToFile(int orderNumber, struct tm *current_time, float totalPrice, float priceAfterDiscount, char isStudent, int *choices, int *quantities) 
{
    char *NUM_ITEMS, *MENU_ITEMS;
    FILE *filePtr;
    char fileName[20];

    // Construct the file name using the order number
    sprintf(fileName, "order%d.txt", orderNumber);

    // Open the file for writing
    filePtr = fopen(fileName, "w");

    // Write the order details to the file
    fprintf(filePtr, "Order Number: %d\n", orderNumber);
    fprintf(filePtr, "Date: %02d/%02d/%04d %02d:%02d:%02d\n", current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900, current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
    fprintf(filePtr, "Student: %c\n", isStudent);
    fprintf(filePtr, "Total Price: %.2f\n", totalPrice);
    fprintf(filePtr, "Price After Discount: %.2f\n", priceAfterDiscount);

    // Write the menu items and quantities to the file
    fprintf(filePtr, "Menu Items:\n");
    for (int i=0; i<NUM_ITEMS; i++) 
    {
        if (quantities[i] > 0) 
            fprintf(filePtr, "%d: %d\n", MENU_ITEMS[i], quantities[i]);
    }

    // Close the file
    fclose(filePtr);
}

int main() 
{
    char menuFile[] = "menu.txt";
    int numMenuItems = countMenuItems(menuFile);
    char isStudent;
    int choices[numMenuItems];
    int quantities[numMenuItems];
    float totalPrice, priceAfterDiscount;
    int orderNumber = generateOrderNumber();
    struct tm *current_time = getCurrentTime();
    
    // Display menu to user and get their choices and quantities
    displayMenu(menuFile);
    for (int i = 0; i < numMenuItems; i++) 
    {
        choices[i] = getMenuChoice();
        quantities[i] = getQuantity();
    }
    
    // Calculate total price
    totalPrice = calculateTotalPrice(choices, quantities, numMenuItems);
    
    // Ask if user is a student and apply discount if necessary
    isStudent = getStudentFlag();
    priceAfterDiscount = applyDiscount(totalPrice, isStudent);
    
    // Calculate VAT and display receipt
    float vat = calculateVAT(priceAfterDiscount);
    printReceipt(orderNumber, current_time, totalPrice, priceAfterDiscount, isStudent, choices, quantities);
    
    // Write receipt to file
    writeToFile(orderNumber, current_time, totalPrice, priceAfterDiscount, isStudent, choices, quantities);
    
    return 0;
}