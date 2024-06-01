#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Order structure
typedef struct Order {
    char* customerName;
    int orderID;
    char* items;
    time_t orderTime;
    struct Order* next;
} Order;

// LIFO (Stack) data structure
typedef struct LIFO {
    Order* top;
} LIFO;

// FIFO (Queue) data structure
typedef struct FIFO {
    Order* front;
    Order* rear;
} FIFO;

// Function to create a new order
Order* createOrder(char* customerName, int orderID, char* items, time_t orderTime) 
{
    Order* newOrder = (Order*)malloc(sizeof(Order));
    newOrder->customerName = strdup(customerName);
    newOrder->orderID = orderID;
    newOrder->items = strdup(items);
    newOrder->orderTime = orderTime;
    newOrder->next = NULL;
    return newOrder;
}

// Enqueue function for FIFO (Queue)
void enqueue(FIFO* queue, char* customerName, int orderID, char* items, time_t orderTime) 
{
    Order* newOrder = createOrder(customerName, orderID, items, orderTime);
    if (queue->rear == NULL) 
    {
        queue->front = newOrder;
        queue->rear = newOrder;
    } 
    
    else 
    {
        queue->rear->next = newOrder;
        queue->rear = newOrder;
    }
}

// Dequeue function for FIFO (Queue)
Order* dequeue(FIFO* queue, time_t thresholdTime) 
{
    Order* current = queue->front;
    Order* previous = NULL;
    Order* removedOrders = NULL;

    while (current != NULL) 
    {
        if (current->orderTime < thresholdTime) 
        {
            if (previous == NULL) 
                queue->front = current->next;
            else 
                previous->next = current->next;
            
            if (current == queue->rear) 
                queue->rear = previous;

            current->next = removedOrders;
            removedOrders = current;

            current = previous != NULL ? previous->next : queue->front;
        } 
        
        else 
        {
            previous = current;
            current = current->next;
        }
    }

    return removedOrders;
}

// Push function for LIFO (Stack)
void push(LIFO* stack, char* customerName, int orderID, char* items, time_t orderTime) 
{
    Order* newOrder = createOrder(customerName, orderID, items, orderTime);
    newOrder->next = stack->top;
    stack->top = newOrder;
}

// Pop function for LIFO (Stack)
Order* pop(LIFO* stack) 
{
    if (stack->top == NULL) 
    {
        return NULL;  // Stack is empty
    }

    Order* removedOrder = stack->top;
    stack->top = stack->top->next;
    removedOrder->next = NULL;

    return removedOrder;
}

// Serialization functions

void serializeLIFO(LIFO* stack, const char* filename) 
{
    FILE* file = fopen(filename, "wb");
    if (file == NULL) 
    {
        printf("Error opening file for serialization.\n");
        return;
    }

    Order* current = stack->top;
    while (current != NULL) 
    {
        fwrite(current, sizeof(Order), 1, file);
        current = current->next;
    }

    fclose(file);
    printf("LIFO data structure serialized to a binary file.\n");
}

LIFO* deserializeLIFO(const char* filename) 
{
    FILE* file = fopen(filename, "rb");
    if (file == NULL) 
    {
        printf("Error opening file for deserialization.\n");
        return NULL;
    }

    LIFO* stack = (LIFO*)malloc(sizeof(LIFO));
    stack->top = NULL;

    Order tempOrder;
    while (fread(&tempOrder, sizeof(Order), 1, file) == 1) 
    {
        Order* newOrder = createOrder(tempOrder.customerName, tempOrder.orderID, tempOrder.items, tempOrder.orderTime);
        newOrder->next = stack->top;
        stack->top = newOrder;
    }

    fclose(file);
    printf("LIFO data structure deserialized from a binary file.\n");
    return stack;
}

void serializeFIFO(FIFO* queue, const char* filename) 
{
    FILE* file = fopen(filename, "wb");
    if (file == NULL) 
    {
        printf("Error opening file for serialization.\n");
        return;
    }

    Order* current = queue->front;
    while (current != NULL) 
    {
        fwrite(current, sizeof(Order), 1, file);
        current = current->next;
    }

    fclose(file);
    printf("FIFO data structure serialized to a binary file.\n");
}

FIFO* deserializeFIFO(const char* filename) 
{
    FILE* file = fopen(filename, "rb");
    if (file == NULL) 
    {
        printf("Error opening file for deserialization.\n");
        return NULL;
    }

    FIFO* queue = (FIFO*)malloc(sizeof(FIFO));
    queue->front = NULL;
    queue->rear = NULL;

    Order tempOrder;
    while (fread(&tempOrder, sizeof(Order), 1, file) == 1) 
    {
        Order* newOrder = createOrder(tempOrder.customerName, tempOrder.orderID, tempOrder.items, tempOrder.orderTime);
        if (queue->rear == NULL) 
        {
            queue->front = newOrder;
            queue->rear = newOrder;
        } 
        
        else 
        {
            queue->rear->next = newOrder;
            queue->rear = newOrder;
        }
    }

    fclose(file);
    printf("FIFO data structure deserialized from a binary file.\n");
    return queue;
}

int main() 
{
    LIFO stack;
    stack.top = NULL;

    FIFO queue;
    queue.front = NULL;
    queue.rear = NULL;

    // Enqueue orders to the FIFO (Queue)
    enqueue(&queue, "Ali Yılmaz", 101, "Pizza, Salad, Ice Cream", time(NULL));
    enqueue(&queue, "Ayşe Demir", 102, "Steak, Mashed Potatoes, Salad", time(NULL));

    // Print the orders in the FIFO (Queue)
    Order* current = queue.front;
    while (current != NULL) 
    {
        printf("Customer Name: %s\n", current->customerName);
        printf("Order ID: %d\n", current->orderID);
        printf("Items: %s\n", current->items);
        printf("Order Time: %s", ctime(&current->orderTime));
        printf("--------------------\n");

        current = current->next;
    }

    // Dequeue orders older than the threshold time from the FIFO (Queue)
    time_t thresholdTime = time(NULL);  // Example threshold time
    Order* removedOrders = dequeue(&queue, thresholdTime);

    // Print the removed orders
    printf("Order Removed from Queue:\n");
    current = removedOrders;
    while (current != NULL) 
    {
        printf("Customer Name: %s\n", current->customerName);
        printf("Order ID: %d\n", current->orderID);
        printf("Items: %s\n", current->items);
        printf("Order Time: %s", ctime(&current->orderTime));
        printf("--------------------\n");

        Order* temp = current;
        current = current->next;
        free(temp);
    }

    // Serialize and deserialize the LIFO (Stack)
    serializeLIFO(&stack, "lifo_data.bin");
    deserializeLIFO("lifo_data.bin");

    // Serialize and deserialize the FIFO (Queue)
    serializeFIFO(&queue, "fifo_data.bin");
    deserializeFIFO("fifo_data.bin");

    return 0;
}