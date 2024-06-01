#include <stdio.h>

#define MAX_SIZE 100

int readInput(int numbers[]);
void labelNumbers(int numbers[], char labels[], int size);
void printNumbers(int numbers[], char labels[], int size);

void printNumbers(int numbers[], char labels[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d %c\n", numbers[i], labels[i]);
    }
}

int readInput(int numbers[]) 
{
    int count = 0;
    int num;
    while (scanf("%d", &num) == 1 && num != -100 && count < MAX_SIZE) 
    {
        numbers[count++] = num;
    }
    return count;
}

void labelNumbers(int numbers[], char labels[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        if (numbers[i] % 2 == 0) 
            labels[i] = 'e';
        else 
            labels[i] = 'o';
        
    }
}

int main() 
{
    int numbers[MAX_SIZE];
    char labels[MAX_SIZE];
    int size = readInput(numbers);
    labelNumbers(numbers, labels, size);
    printNumbers(numbers, labels, size);
    return 0;
}