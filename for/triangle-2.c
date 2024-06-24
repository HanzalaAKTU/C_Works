#include <stdio.h> 

int main()
{
    int t,i,y;

    printf("Enter trinagle: ");
    scanf("%d",&t);
    
    for (i = 1; i <= t; i++)
    {
        for (y = t; y < i; y--)
        {
            printf("*");
        }
        
    printf("\n");    

    }
    

}