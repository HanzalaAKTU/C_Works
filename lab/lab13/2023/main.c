#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct BST {
    struct Node* root;
};

struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct Node** node, int value) 
{
    if (*node == NULL) 
    {
        *node = createNode(value);
        return;
    }

    if (value < (*node)->value) 
        insertNode(&((*node)->left), value);
    
    else 
        insertNode(&((*node)->right), value);
}

struct BST* generateBST(const char* filename) 
{
    struct BST* bst = (struct BST*)malloc(sizeof(struct BST));
    bst->root = NULL;

    FILE* file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Error opening the file.\n");
        return bst;
    }

    int value;
    while (fscanf(file, "%d", &value) != EOF) 
    {
        insertNode(&(bst->root), value);
    }

    fclose(file);
    return bst;
}

void addNode(struct Node** node, int value) 
{
    if (*node == NULL) 
    {
        *node = createNode(value);
        return;
    }

    if (value < (*node)->value) 
        addNode(&((*node)->left), value);
    else 
        addNode(&((*node)->right), value);
}

struct Node* removeNode(struct Node* node, int value) 
{
    if (node == NULL)
        return node;

    if (value < node->value) 
        node->left = removeNode(node->left, value);
    
    else if (value > node->value) 
        node->right = removeNode(node->right, value);
    
    else 
    {
        if (node->left == NULL && node->right == NULL) 
        {
            free(node);
            node = NULL;
        } 
        
        else if (node->left == NULL) 
        {
            struct Node* temp = node;
            node = node->right;
            free(temp);
        } 
        
        else if (node->right == NULL) 
        {
            struct Node* temp = node;
            node = node->left;
            free(temp);
        } 
       
        else 
        {
            struct Node* minValueNode = node->right;
            while (minValueNode->left != NULL) 
            {
                minValueNode = minValueNode->left;
            }
            node->value = minValueNode->value;
            node->right = removeNode(node->right, minValueNode->value);
        }
    }

    return node;
}

void removeNodeFromBST(struct BST* bst, int value) 
{
    bst->root = removeNode(bst->root, value);
}

struct Node* searchNode(struct Node* node, int value) 
{
    if (node == NULL || node->value == value)
        return node;

    if (value < node->value) 
        return searchNode(node->left, value);
    else 
        return searchNode(node->right, value);
}

int countNodes(struct Node* node) 
{
    if (node == NULL)
        return 0;
    
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int getTotalNodeCount(struct BST* bst) 
{
    return countNodes(bst->root);
}

int getMaxDepth(struct Node* node) 
{
    if (node == NULL)
        return 0;

    int leftDepth = getMaxDepth(node->left);
    int rightDepth = getMaxDepth(node->right);
    
    return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
}

int getMaximumDepth(struct BST* bst) 
{
    return getMaxDepth(bst->root);
}

int countLeafNodes(struct Node* node) 
{
    if (node == NULL)
        return 0;
   
    if (node->left == NULL && node->right == NULL)
        return 1;
   
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int getLeafNodeCount(struct BST* bst) 
{
    return countLeafNodes(bst->root);
}

void printInOrder(struct Node* node) 
{
    if (node == NULL)
        return;

    printInOrder(node->left);
    printf("%d ", node->value);
    printInOrder(node->right);
}

void printPreOrder(struct Node* node) 
{
    if (node == NULL)
        return;

    printf("%d ", node->value);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printPostOrder(struct Node* node) 
{
    if (node == NULL)
        return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->value);
}

void printLevelOrder(struct BST* bst) 
{
    if (bst->root == NULL)
        return;

    int front = 0;
    int rear = 0;
    struct Node* queue[100];
    queue[rear] = bst->root;
    rear++;

    while (front < rear) 
    {
        struct Node* node = queue[front];
        front++;

        printf("%d ", node->value);

        if (node->left != NULL) 
        {
            queue[rear] = node->left;
            rear++;
        }

        if (node->right != NULL) 
        {
            queue[rear] = node->right;
            rear++;
        }
    }
}

void printTree(struct BST* bst, int printChoice) 
{
    switch (printChoice) 
    {
        case 1:
            printf("In-Order Traversal: ");
            printInOrder(bst->root);
            printf("\n");
            break;
        case 2:
            printf("Pre-Order Traversal: ");
            printPreOrder(bst->root);
            printf("\n");
            break;
        case 3:
            printf("Post-Order Traversal: ");
            printPostOrder(bst->root);
            printf("\n");
            break;
        case 4:
            printf("Level-Order Traversal: ");
            printLevelOrder(bst);
            printf("\n");
            break;
        default:
            printf("Invalid print choice.\n");
    }
}

int main() 
{
    struct BST* bst = generateBST("input.txt");
    int choice;
    int value;

    while (1) 
    {
        printf("\nBinary Search Tree Operations\n");
        printf("----------------------------\n");
        printf("1. Add Node\n");
        printf("2. Remove Node\n");
        printf("3. Search Node\n");
        printf("4. Total Node Count\n");
        printf("5. Maximum Depth\n");
        printf("6. Leaf Node Count\n");
        printf("7. Print Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                addNode(&(bst->root), value);
                break;
            case 2:
                printf("Enter the value to remove: ");
                scanf("%d", &value);
                removeNodeFromBST(bst, value);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (searchNode(bst->root, value) != NULL)
                    printf("Node with value %d found in the BST.\n", value);
                else
                    printf("Node with value %d not found in the BST.\n", value);
                break;
            case 4:
                printf("Total Node Count: %d\n", getTotalNodeCount(bst));
                break;
            case 5:
                printf("Maximum Depth: %d\n", getMaximumDepth(bst));
                break;
            case 6:
                printf("Leaf Node Count: %d\n", getLeafNodeCount(bst));
                break;
            case 7:
                printf("\n");
                printf("Select the print type:\n");
                printf("1. In-Order Traversal\n");
                printf("2. Pre-Order Traversal\n");
                printf("3. Post-Order Traversal\n");
                printf("4. Level-Order Traversal\n");
                printf("Enter your choice: ");
                scanf("%d", &value);
                printf("\n");
                printTree(bst, value);
                printf("\n");
                break;

            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
