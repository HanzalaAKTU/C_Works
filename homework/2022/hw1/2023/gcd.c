#include<stdio.h>

int main()
{
    int result = 1, a,b,gcd;

    printf("\n\nEnter First number: ");
    scanf("%d",&a);
   
    printf("Enter Second number: ");
    scanf("%d",&b);

    while (result > 0)
    {
        result = a % b;
        a = b;
        b = result;

    }

    printf("\n GCD:%d",a);

    return 0;
}