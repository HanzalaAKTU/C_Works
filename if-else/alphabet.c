/* C program to check whether a character is alphabet or not */

#include <stdio.h>

int main()
{

    char ch;

    printf("Enter a character: ");
    scanf("%c",&ch);

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("Your character is an alpahbet\n ");
    else
        printf("Your character is not alpahbet\n ");

    return 0;
}        
