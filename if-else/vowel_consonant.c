/* C program to check whether a character is vowel or consonant */

#include <stdio.h>


int main()
{

    char ch;

    printf("Enter a character: ");
    scanf("%c",&ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        printf("Your character is an vowel\n");
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("Your character is consonant\n ");
    else
        printf("Your character is not alpahbet\n ");

    return 0;
}        