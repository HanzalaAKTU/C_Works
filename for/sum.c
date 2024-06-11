#include <stdio.h>

int main()
{
    int a,i,num;
    

    printf("Enter the number of integer: \n");
    scanf("%d",&a);
    
    int sum = 0;
    printf("Enter %d integers: \n", a);

    for (i = 0; i < a; i++)
    {
        
        scanf("%d",&num);
        sum += num;
        
    }
    
    printf("Sum of the integer: %d\n",sum);

    return 0;
}