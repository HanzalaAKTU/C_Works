/* C program to check alphabet, digit or special character */

#include <stdio.h>

int main()
{

    char ch;

    printf("Enter a character: ");
    scanf("%c",&ch);

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("Your character is alphabet\n "); 
    else if (ch >= '0' && ch <= '9')
        printf("Your character is a digit\n ");
    else
        printf("Your character is a special character\n ");

    return 0;
}        
