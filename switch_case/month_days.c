/* C program to print number of days in a month using switch case */

#include <stdio.h>

int main()
{
    int month;

    printf("Enter month number(1-12): ");
    scanf("%d", &month);


    switch(month)
    {
        case 1: 
            printf("Its January and this month have 31 days");
            break;
        case 2: 
            printf("Its February and this month have 28/29 days");
            break;
        case 3: 
            printf("Its March and this month have 31 days");
            break;
        case 4: 
            printf("Its April and this month have 30 days");
            break;
        case 5: 
            printf("Its May and this month have 31 days");
            break;
        case 6: 
            printf("Its June and this month have 30 days");
            break;
        case 7: 
            printf("Its July and this month have 31 days");
            break;
        case 8: 
            printf("Its August and this month have 31 days");
            break;
        case 9: 
            printf("Its September and this month have 30 days");
            break;
        case 10: 
            printf("Its October and this month have 31 days");
            break;
        case 11: 
            printf("Its November and this month have 30 days");
            break;
        case 12: 
            printf("Its December and this month have 31 days");
            break;
        default: 
            printf("Invalid input! Please enter month number between 1-12");

    }

    return 0;
}