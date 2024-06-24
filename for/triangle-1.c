#include <stdio.h> 

int main()
{
    int t;

    printf("Enter trinagle: ");
    scanf("%d",&t);
    
    for (int i = 1; i <= t; i++)
    {
        for (int y = 0; y < i; y++)
        {
            printf("*");
        }
        
    printf("\n");    

    }
    
}