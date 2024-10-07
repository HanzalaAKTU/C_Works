/*
    Bar-Chart Printing Program)
*/

#include <stdio.h>

int main() 
{
    int number;

    // Loop to process 5 numbers
    for (int i = 1; i <= 5; i++) 
    {
        // Ask for input and validate it using only 'for' loop
        printf("Enter number %d (between 1 and 30): ", i);
        scanf("%d", &number);

        // Validate input within the loop
        for (; number < 1 || number > 30; ) 
        {
            printf("Invalid input. Please enter a number between 1 and 30: ");
            scanf("%d", &number);
        }

        // Print the corresponding number of asterisks for the valid input
        for (int j = 1; j <= number; j++) 
        {
            printf("*");
        }
        printf("\n"); // New line after each set of asterisks
    }

    return 0;
}
