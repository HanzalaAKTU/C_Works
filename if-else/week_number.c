/*C program to print day name of week */

#include <stdio.h>


int main()
{

    int week;

    printf(" Enter a week number (1-7): ");
    scanf("%d",&week);

    if (week == 1)
        printf("Your week day Monday \n");
    else if (week == 2)
        printf("Your week day Tuesday \n");
    else if (week == 3)
        printf("Your week day Wednesday \n");
    else if (week == 4)
        printf("Your week day Thursday \n");
    else if (week == 5)
        printf("Your week day Friday \n");
    else if (week == 6)
        printf("Your week day Saturday \n");
    else if (week == 7)
        printf("Your week day Sunday \n");
    else
        printf("Invalid input! Please enter week number between (1-7).\n");
    
    return 0;
}        