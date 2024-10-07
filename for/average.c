#include <stdio.h>

int main()
{
    int a;
    int sum = 0;
    int count = 0;

    printf("Enter the number of integer: \n");
    
    for ( ; ; )
    {
        scanf("%d",&a);
        if (a == -1)
            break;
        
        sum += a;
        count++;

    }
    
    if (count > 0)
    {
        double average = (double)sum / count;
        printf("Average of integer: %.2f\n", average);
    }

    else
        printf("No numbers entered.\n");
    

    return 0;
}