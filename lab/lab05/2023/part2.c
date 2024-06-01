#include <stdio.h>
#include <math.h>

int main() 
{
    int num, digits, reversed_num = 0;

    // Get user input and check number of digits
    printf("Enter a 3, 4, or 5 digit integer: ");
    scanf("%d", &num);
    if (num >= 100 && num <= 999) 
        digits = 3;
    
    else if (num >= 1000 && num <= 9999) 
        digits = 4;
    
    else if (num >= 10000 && num <= 99999) 
        digits = 5;
    
    else 
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Reverse the number
    while (num != 0) 
    {
        reversed_num = reversed_num * 10 + num % 10;
        num /= 10;
    }

    // Check for leading zeros and print the reversed number
    if (digits == 3 && reversed_num < 100) 
        printf("0");
    
    if (digits == 4 && reversed_num < 1000) 
        printf("0");
    
    if (digits == 5 && reversed_num < 10000) 
        printf("0");
    
    printf("%d\n", reversed_num);

    return 0;
}