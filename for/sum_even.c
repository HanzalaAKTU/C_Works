#include <stdio.h>

int main()
{
    int a,sum;

    for (a = 2; a <= 30; a+= 2)
    {
        
        printf("%d\n",a);
        sum += a;
        
    }
    
    printf("Sum of the integer: %d\n",sum);

    return 0;
}