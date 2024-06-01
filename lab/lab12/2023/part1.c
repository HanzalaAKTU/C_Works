#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_GROUP_NAME_LENGTH 20
#define CUSTOMER_DATA_FILE "customers.txt"

// Priority levels
typedef enum {
    NORMAL = 1,
    VETERAN = 2,
    OD = 3,
    VIP = 4
} PriorityLevel;

// Customer structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char groupName[MAX_GROUP_NAME_LENGTH];
    PriorityLevel priorityLevel;
} Customer;

// Function to insert a new customer into the priority queue
void insertCustomer(Customer newCustomer) {
    FILE *file = fopen(CUSTOMER_DATA_FILE, "a"); // Open the file in append mode

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(file, "%s %d %s %d\n", newCustomer.name, newCustomer.age, newCustomer.groupName, newCustomer.priorityLevel);
    fclose(file);
}

// Function to remove a customer from the priority queue
void removeCustomer(char* customerName) {
    FILE *file = fopen(CUSTOMER_DATA_FILE, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Failed to open the file(s).\n");
        return;
    }

    char buffer[1024];
    char name[MAX_NAME_LENGTH];
    int age;
    char groupName[MAX_GROUP_NAME_LENGTH];
    int priorityLevel;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%s %d %s %d", name, &age, groupName, &priorityLevel);

        if (strcmp(name, customerName) != 0) {
            fprintf(tempFile, "%s %d %s %d\n", name, age, groupName, priorityLevel);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(CUSTOMER_DATA_FILE);
    rename("temp.txt", CUSTOMER_DATA_FILE);
}

// Function to display customers in order of their priorities
void displayCustomers() {
    FILE *file = fopen(CUSTOMER_DATA_FILE, "r");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char buffer[1024];
    char name[MAX_NAME_LENGTH];
    int age;
    char groupName[MAX_GROUP_NAME_LENGTH];
    int priorityLevel;

    printf("Customers in order of priority:\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%s %d %s %d", name, &age, groupName, &priorityLevel);

        printf("Name: %s, Age: %d, Group: %s, Priority: %d\n", name, age, groupName, priorityLevel);
    }

    fclose(file);
}

int main() 
{
    // Example usage
    Customer customer1 = {"John Doe", 25, "NORMAL", NORMAL};
    Customer customer2 = {"Jane Smith", 40, "VETERAN", VETERAN};
    Customer customer3 = {"David Johnson", 60, "OD", OD};
    Customer customer4 = {"Sarah Adams", 35, "VIP", VIP};

    insertCustomer(customer1);
    insertCustomer(customer2);
    insertCustomer(customer3);
    insertCustomer(customer4);

    displayCustomers();

    removeCustomer("Jane Smith");

    displayCustomers();

    return 0;
}
