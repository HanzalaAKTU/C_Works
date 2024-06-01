/* C program to print number of days in a month */

#include <stdio.h>


int main()
{

    int month;

    printf(" Enter a month number (1-12): ");
    scanf("%d",&month);

    if (month == 1)
        printf("Your month day January and this month is 31 day \n");
    else if (month == 2)
        printf("Your month day February and this month is 28 or 29 day \n");
    else if (month == 3)
        printf("Your month day March and this month is 31 day \n");
    else if (month == 4)
        printf("Your month day April and this month is 30 day \n");
    else if (month == 5)
        printf("Your month day May and this month is 31 day \n");
    else if (month == 6)
        printf("Your month day June and this month is 30 day \n");
    else if (month == 7)
        printf("Your month day July and this month is 31 day \n");
    else if (month == 8)
        printf("Your month day August and this month is 31 day \n");
    else if (month == 9)
        printf("Your month day September and this month is 30 day \n");
    else if (month == 10)
        printf("Your month day October and this month is 30 day \n");
    else if (month == 11)
        printf("Your month day November and this month is 31 day \n");
    else if (month ==12)
        printf("Your month day December and this month is 30 day \n");
    else
        printf("Invalid input! Please enter month number between (1-12).\n");

    return 0;
}        