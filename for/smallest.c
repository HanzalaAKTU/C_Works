#include <stdio.h>

int main()
{
    int a,num,smallest;
    

    printf("Enter the number of integer: \n");
    scanf("%d",&a);
    
   
    printf("Enter %d integers: \n", a);
    scanf("%d",&num);
    smallest = num;
    
    for (int i = 1; i < a; i++)
    {
        
        scanf("%d",&num);
        if (num < smallest) 
            smallest = num;
        
    }
    
    printf("The smallest integer is: %d\n", smallest);

    return 0;
}