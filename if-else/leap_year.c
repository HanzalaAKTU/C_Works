/* C program to check Leap Year */

#include <stdio.h>

int main()
{

    int year;
    
    printf("enter a year: ");
    scanf("%d", &year);

    if (year % 4 == 0)
        printf("Your year is a leap year\n");

    else   
        printf("Your year is not leap year\n"); 

    return 0;       
}        
