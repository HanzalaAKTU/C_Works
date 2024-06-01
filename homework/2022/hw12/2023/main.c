#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    char type[20];
    int ivals[1];
    double svals[1];
} Asset1;

typedef struct {
    char type[20];
    double svals[2];
    int ivals[2];
} Asset2;

typedef struct {
    char type[20];
    char string1[50];
    char string2[50];
} Asset3;

typedef struct {
    char type[20];
    double value1;
    float value2;
    double value3;
} Asset4;

// Function to create a new Node
Node* createNode(void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a Node at the beginning of the linked list
void insertNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

// Part 1: Generate and Fill the Linked List
void fillLinkedList(Node** head) {
    srand(time(NULL));
    int numAssets = rand() % 11 + 10;  // Generate a random number between 10 and 20

    for (int i = 0; i < numAssets; i++) {
        int assetType = rand() % 4;

        if (assetType == 0) {
            Asset1* asset = (Asset1*)malloc(sizeof(Asset1));
            strcpy(asset->type, "Asset1");
            asset->ivals[0] = rand();
            asset->svals[0] = (double)rand() / RAND_MAX;
            insertNode(head, createNode(asset));
        } else if (assetType == 1) {
            Asset2* asset = (Asset2*)malloc(sizeof(Asset2));
            strcpy(asset->type, "Asset2");
            asset->svals[0] = (double)rand() / RAND_MAX;
            asset->svals[1] = (double)rand() / RAND_MAX;
            asset->ivals[0] = rand();
            asset->ivals[1] = rand();
            insertNode(head, createNode(asset));
        } else if (assetType == 2) {
            Asset3* asset = (Asset3*)malloc(sizeof(Asset3));
            strcpy(asset->type, "Asset3");
            strcpy(asset->string1, "Hello");
            strcpy(asset->string2, "World");
            insertNode(head, createNode(asset));
        } else if (assetType == 3) {
            Asset4* asset = (Asset4*)malloc(sizeof(Asset4));
            strcpy(asset->type, "Asset4");
            asset->value1 = (double)rand() / RAND_MAX;
            asset->value2 = (float)rand() / RAND_MAX;
            asset->value3 = (double)rand() / RAND_MAX;
            insertNode(head, createNode(asset));
        }
    }
}

// Part 2: Serialize and Write the Linked List
void serializeLinkedList(Node* head) {
    FILE* file = fopen("linkedlist.bin", "wb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Node* current = head;

    while (current != NULL) {
        void* data = current->data;
        char type[20];

        if (strcmp(((Asset1*)data)->type, "Asset1") == 0) {
            strcpy(type, "Asset1");
            fwrite(type, sizeof(char), 20, file);
            fwrite(data, sizeof(Asset1), 1, file);
        } else if (strcmp(((Asset2*)data)->type, "Asset2") == 0) {
            strcpy(type, "Asset2");
            fwrite(type, sizeof(char), 20, file);
            fwrite(data, sizeof(Asset2), 1, file);
        } else if (strcmp(((Asset3*)data)->type, "Asset3") == 0) {
            strcpy(type, "Asset3");
            fwrite(type, sizeof(char), 20, file);
            fwrite(data, sizeof(Asset3), 1, file);
        } else if (strcmp(((Asset4*)data)->type, "Asset4") == 0) {
            strcpy(type, "Asset4");
            fwrite(type, sizeof(char), 20, file);
            fwrite(data, sizeof(Asset4), 1, file);
        }

        current = current->next;
    }

    fclose(file);
}

// Part 3: Read and Reconstruct the Linked List
void deserializeLinkedList(Node** head) {
    FILE* file = fopen("linkedlist.bin", "rb");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (!feof(file)) {
        char type[20];
        fread(type, sizeof(char), 20, file);

        if (strcmp(type, "Asset1") == 0) {
            Asset1* asset = (Asset1*)malloc(sizeof(Asset1));
            fread(asset, sizeof(Asset1), 1, file);
            insertNode(head, createNode(asset));
        } else if (strcmp(type, "Asset2") == 0) {
            Asset2* asset = (Asset2*)malloc(sizeof(Asset2));
            fread(asset, sizeof(Asset2), 1, file);
            insertNode(head, createNode(asset));
        } else if (strcmp(type, "Asset3") == 0) {
            Asset3* asset = (Asset3*)malloc(sizeof(Asset3));
            fread(asset, sizeof(Asset3), 1, file);
            insertNode(head, createNode(asset));
        } else if (strcmp(type, "Asset4") == 0) {
            Asset4* asset = (Asset4*)malloc(sizeof(Asset4));
            fread(asset, sizeof(Asset4), 1, file);
            insertNode(head, createNode(asset));
        }
    }

    fclose(file);
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        void* data = current->data;
        if (strcmp(((Asset1*)data)->type, "Asset1") == 0) {
            Asset1* asset = (Asset1*)data;
            printf("Asset1: ivals[0] = %d, svals[0] = %.2lf\n", asset->ivals[0], asset->svals[0]);
        } else if (strcmp(((Asset2*)data)->type, "Asset2") == 0) {
            Asset2* asset = (Asset2*)data;
            printf("Asset2: svals[0] = %.2lf, svals[1] = %.2lf, ivals[0] = %d, ivals[1] = %d\n",
                   asset->svals[0], asset->svals[1], asset->ivals[0], asset->ivals[1]);
        } else if (strcmp(((Asset3*)data)->type, "Asset3") == 0) {
            Asset3* asset = (Asset3*)data;
            printf("Asset3: string1 = %s, string2 = %s\n", asset->string1, asset->string2);
        } else if (strcmp(((Asset4*)data)->type, "Asset4") == 0) {
            Asset4* asset = (Asset4*)data;
            printf("Asset4: value1 = %.2lf, value2 = %.2f, value3 = %.2lf\n",
                   asset->value1, asset->value2, asset->value3);
        }

        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    // Part 1: Generate and Fill the Linked List
    fillLinkedList(&head);

    // Part 2: Serialize and Write the Linked List
    serializeLinkedList(head);

    // Part 3: Read and Reconstruct the Linked List
    Node* reconstructedList = NULL;
    deserializeLinkedList(&reconstructedList);

    // Print the reconstructed linked list
    printf("Reconstructed Linked List:\n");
    printLinkedList(reconstructedList);

    return 0;
}
