/* C program to check whether a character is uppercase or lowercase  */

#include <stdio.h>


int main()
{

    char ch;

    printf("Enter a character: ");
    scanf("%c",&ch);

    if (ch >= 'a' && ch <= 'z')  
        printf("Your character is lowercase alphabet\n "); 
    else if (ch >= 'A' && ch <= 'Z')
        printf("Your character is uppercase alphabet\n ");
    else
        printf("Your character is not alphabet\n ");
        
    return 0;
}        