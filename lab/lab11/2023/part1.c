#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order {
    int orderID;
    char customerName[100];
    char items[100];
    char orderTime[100];
    struct Order* next;
};

struct Order* enqueue(struct Order* queue, char* customerName, int orderID, char* items, char* orderTime) 
{
    struct Order* newOrder = (struct Order*)malloc(sizeof(struct Order));
    newOrder->orderID = orderID;
    strcpy(newOrder->customerName, customerName);
    strcpy(newOrder->items, items);
    strcpy(newOrder->orderTime, orderTime);
    newOrder->next = NULL;

    if (queue == NULL) 
    {
        return newOrder;
    }

    struct Order* currOrder = queue;
    while (currOrder->next != NULL) 
    {
        currOrder = currOrder->next;
    }

    currOrder->next = newOrder;
    return queue;
}

struct Order* dequeue(struct Order* queue) 
{
    if (queue == NULL) 
    {
        printf("Queue is empty.\n");
        return NULL;
    }

    struct Order* removedOrder = queue;
    queue = queue->next;
    free(removedOrder);

    return queue;
}

void display(struct Order* queue) 
{
    if (queue == NULL) 
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Order* currOrder = queue;
    while (currOrder != NULL) 
    {
        printf("Order ID: %d, Customer Name: %s, Items: %s, Order Time: %s\n",
               currOrder->orderID, currOrder->customerName, currOrder->items, currOrder->orderTime);
        currOrder = currOrder->next;
    }
}

void updateOrder(struct Order* queue, int orderID, char* newItems) 
{
    struct Order* currOrder = queue;
    while (currOrder != NULL) 
    {
        if (currOrder->orderID == orderID) 
        {
            strcpy(currOrder->items, newItems);
            break;
        }
        currOrder = currOrder->next;
    }
}

int main() 
{
    struct Order* queue = NULL;

    // Enqueue operation
    queue = enqueue(queue, "Barış Ozcan", 101, "Burger, Fries, Coke", "10:00 AM");

    // Display orders by order time
    printf("Display Orders by Order Time:\n");
    display(queue);

    // Enqueue operation
    queue = enqueue(queue, "Zehra Bilici", 102, "Pizza, Salad, Ice Cream", "11:30 AM");

    // Display orders by order time
    printf("Display Orders by Order Time:\n");
    display(queue);

    // Enqueue operation
    queue = enqueue(queue, "Mehmet Burak Koca", 103, "Steak, Mashed Potatoes, Salad", "12:15 PM");

    // Display orders by order time
    printf("Display Orders by Order Time:\n");
    display(queue);

    // Dequeue operation
    printf("Dequeue Operation:\n");
    queue = dequeue(queue);

    // Display orders by order time
    printf("Display Orders by Order Time:\n");
    display(queue);

    // Update order
    printf("Update Order:\n");
    updateOrder(queue, 102, "Pizza, Salad, Coke");

    // Display orders by order time
    printf("Display Orders by Order Time:\n");
    display(queue);

    // Delete order
    printf("Delete Order:\n");
    queue = dequeue(queue);

    // Display orders by order time
    printf("Display Orders by Order Time:\n");
    display(queue);

    return 0;
}
