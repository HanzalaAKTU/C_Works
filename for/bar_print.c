/*
    Bar-Chart Printing Program)
*/

#include <stdio.h>

int main() 
{
    int number;

    for (int i = 1; i <= 5; i++) 
    {
        printf("Enter number %d (between 1 and 30): ", i);
        scanf("%d", &number);

        for (; number < 1 || number > 30; ) 
        {
            printf("Invalid input. Please enter a number between 1 and 30: ");
            scanf("%d", &number);
        }

        for (int j = 1; j <= number; j++) 
        {
            printf("*");
        }
        printf("\n"); 
    }

    return 0;
}
