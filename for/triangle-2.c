/*
 *****
 ****
 ***
 **
 *
*/

#include <stdio.h> 

int main()
{
    int t,i,j;

    printf("Enter trinagle: ");
    scanf("%d",&t);
    
    for (i = t; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf("*");
        }
        
        printf("\n");    

    }

}