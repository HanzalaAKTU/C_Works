/*
     *
    **
   ***
  ****
 *****
 */

#include <stdio.h> 

int main()
{
    int t,i,j,k;

    printf("Enter trinagle: ");
    scanf("%d",&t);
    
    for (i = 1; i <=t; i++)
    {
        for ( k = 0; k < t-i; k++)
        {
            printf(" ");
        }
        
        for (j = 0; j < i; j++)
        {
            printf("*");
        }
        
        printf("\n");    

    }
    
}