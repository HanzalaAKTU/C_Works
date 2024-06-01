/* C program to check divisibility of any number */

#include <stdio.h>


int main()
{

    int num;

    printf("enter a number: ");
    scanf("%d", &num);
 
    if ( num % 5 == 0 && num % 11 == 0  )
        printf("Your number is divisible\n");

    else
        printf("Your number is undivisible\n");
        
    return 0;

}        