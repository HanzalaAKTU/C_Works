#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for exam paper information
typedef struct ExamPaper {
    char studentName[50];
    long int studentNumber;
    int score;
    struct ExamPaper* next;
} ExamPaper;

// Function to add a new exam paper to the stack
ExamPaper* push(ExamPaper* stack, const char* studentName, long int studentNumber, int score) 
{
    // Create a new exam paper
    ExamPaper* newPaper = (ExamPaper*)malloc(sizeof(ExamPaper));
    strcpy(newPaper->studentName, studentName);
    newPaper->studentNumber = studentNumber;
    newPaper->score = score;

    // Set the next pointer to the current top of the stack
    newPaper->next = stack;

    // Update the stack to point to the new exam paper
    stack = newPaper;

    printf("Exam Paper Added: Student Name: %s, Student Number: %ld, Score: %d\n", studentName, studentNumber, score);

    return stack;
}

// Function to remove the most recently added exam paper from the stack
ExamPaper* pop(ExamPaper* stack) 
{
    if (stack == NULL) 
    {
        printf("Stack is empty.\n");
        return NULL;
    }

    ExamPaper* top = stack;
    stack = stack->next;

    printf("Last Added Exam Paper:\n");
    printf("- Student Name: %s, Student Number: %ld, Score: %d\n", top->studentName, top->studentNumber, top->score);

    free(top);

    return stack;
}

// Function to check if the stack is empty or not
int isEmpty(ExamPaper* stack) 
{
    return stack == NULL;
}

// Function to display the exam papers in the stack
void display(ExamPaper* stack) 
{
    if (stack == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Exam Papers in the Stack:\n");
    ExamPaper* current = stack;
    while (current != NULL) 
    {
        printf("- %s, Student Number: %ld, Score: %d\n", current->studentName, current->studentNumber, current->score);
        current = current->next;
    }
}

int main() 
{
    ExamPaper* stack = NULL;

    stack = push(stack, "Zehra Bilici", 20220000001, 90);
    // After all push operations, call display() to see the exam papers in the stack.

    stack = push(stack, "Barış Özcan", 20190000002, 85);
    stack = push(stack, "Mehmet Burak Koca", 20180000010, 95);

    stack = pop(stack);
    // After all pop operations, call display() to see the updated exam papers in the stack.

    if (!isEmpty(stack)) 
    {
        printf("Stack is not empty.\n");
    }

    display(stack);

    return 0;
}
