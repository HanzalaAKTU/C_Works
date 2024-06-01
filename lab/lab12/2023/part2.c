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
typedef struct Customer {
    char name[MAX_NAME_LENGTH];
    int age;
    char groupName[MAX_GROUP_NAME_LENGTH];
    PriorityLevel priorityLevel;
    struct Customer* next;
    struct Customer* prev;
} Customer;

Customer* front = NULL;
Customer* rear = NULL;

// Function to insert a new customer into the priority queue
void insertCustomer(Customer newCustomer) 
{
    FILE* file = fopen(CUSTOMER_DATA_FILE, "a"); // Open the file in append mode

    if (file == NULL) 
    {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(file, "%s %d %s %d\n", newCustomer.name, newCustomer.age, newCustomer.groupName, newCustomer.priorityLevel);
    fclose(file);

    Customer* newCustomerNode = (Customer*)malloc(sizeof(Customer));
    strcpy(newCustomerNode->name, newCustomer.name);
    newCustomerNode->age = newCustomer.age;
    strcpy(newCustomerNode->groupName, newCustomer.groupName);
    newCustomerNode->priorityLevel = newCustomer.priorityLevel;
    newCustomerNode->next = NULL;

    if (front == NULL) 
    {
        front = rear = newCustomerNode;
        newCustomerNode->prev = NULL;
    } 
    
    else 
    {
        Customer* temp = front;

        while (temp != NULL && temp->priorityLevel >= newCustomer.priorityLevel) 
        {
            temp = temp->next;
        }

        if (temp == NULL) 
        {
            rear->next = newCustomerNode;
            newCustomerNode->prev = rear;
            rear = newCustomerNode;
        } 
        
        else 
        {
            if (temp->prev == NULL) 
            {
                newCustomerNode->prev = NULL;
                newCustomerNode->next = temp;
                temp->prev = newCustomerNode;
                front = newCustomerNode;
            } 
           
            else 
            {
                newCustomerNode->prev = temp->prev;
                newCustomerNode->next = temp;
                temp->prev->next = newCustomerNode;
                temp->prev = newCustomerNode;
            }
        }
    }
}

// Function to remove a customer from the priority queue
void removeCustomer(char* customerName) 
{
    FILE* file = fopen(CUSTOMER_DATA_FILE, "r");
    FILE* tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) 
    {
        printf("Failed to open the file(s).\n");
        return;
    }

    char buffer[1024];
    char name[MAX_NAME_LENGTH];
    int age;
    char groupName[MAX_GROUP_NAME_LENGTH];
    int priorityLevel;

    while (fgets(buffer, sizeof(buffer), file) != NULL) 
    {
        sscanf(buffer, "%s %d %s %d", name, &age, groupName, &priorityLevel);

        if (strcmp(name, customerName) != 0) 
        {
            fprintf(tempFile, "%s %d %s %d\n", name, age, groupName, priorityLevel);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(CUSTOMER_DATA_FILE);
    rename("temp.txt", CUSTOMER_DATA_FILE);

    Customer* temp = front;

    while (temp != NULL) 
    {
        if (strcmp(temp-> (name, customerName) == 0))
        {
            if (temp->prev == NULL) 
            {
                front = temp->next;
                if (front != NULL) 
                {
                    front->prev = NULL;
                }
            } 
            
            else 
            {
                temp->prev->next = temp->next;
                if (temp->next != NULL) 
                {
                    temp->next->prev = temp->prev;
                }
            }        
            Customer* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        } 
        else 
        {
            temp = temp->next;
        }
    }
}

// Function to display customers in order of their priorities
void displayCustomers() 
{
    FILE* file = fopen(CUSTOMER_DATA_FILE, "r");
    
    if (file == NULL) 
    {
        printf("Failed to open the file.\n");
        return;
    }

    char buffer[1024];
    char name[MAX_NAME_LENGTH];
    int age;
    char groupName[MAX_GROUP_NAME_LENGTH];
    int priorityLevel;

    printf("Customers in order of priority:\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL) 
    {
        sscanf(buffer, "%s %d %s %d", name, &age, groupName, &priorityLevel);

        printf("Name: %s, Age: %d, Group: %s, Priority: %d\n", name, age, groupName, priorityLevel);
    }

    fclose(file);
}

// Recursive function to search for a customer by name
void searchCustomerHelper(Customer* node, char* customerName) 
{
    if (node == NULL) 
    {
        printf("Customer not found.\n");
        return;
    }
    
    if (strcmp(node->name, customerName) == 0) 
    {
        printf("Customer Found:\n");
        printf("Name: %s, Age: %d, Group: %s, Priority: %d\n", node->name, node->age, node->groupName, node->priorityLevel);
        return;
    }

    searchCustomerHelper(node->next, customerName);
}

void searchCustomer(char* customerName) 
{
    searchCustomerHelper(front, customerName);
}

// Function to change the priority level of a customer
void changePriority(char* customerName, PriorityLevel newPriority) 
{
    Customer* temp = front;while (temp != NULL) 
    {
        if (strcmp(temp->name, customerName) == 0) 
        {
            temp->priorityLevel = newPriority;
            break;
        }

        temp = temp->next;
    }

    FILE* file = fopen(CUSTOMER_DATA_FILE, "w");

    if (file == NULL) 
    {
        printf("Failed to open the file.\n");
        return;
    }

    temp = front;

    while (temp != NULL) 
    {
        fprintf(file, "%s %d %s %d\n", temp->name, temp->age, temp->groupName, temp->priorityLevel);
        temp = temp->next;
    }

    fclose(file);
}

int main() 
{
    // Example usage
    Customer customer1 = {"John Doe", 25, "NORMAL", NORMAL};
    Customer customer2 = {"Jane Smith", 40, "VETERAN", VETERAN};
    Customer customer3 = {"David Johnson", 60, "OD", OD};
    Customer customer4 = {"Sarah Adams", 35, "VIP", VIP};insertCustomer(customer1);
    insertCustomer(customer2);
    insertCustomer(customer3);
    insertCustomer(customer4);

    displayCustomers();

    printf("\nSearching for customer 'Jane Smith':\n");
    searchCustomer("Jane Smith");

    printf("\nChanging priority of customer 'Jane Smith' to VIP:\n");
    changePriority("Jane Smith", VIP);

    displayCustomers();

    return 0;
}