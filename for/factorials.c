#include <stdio.h>

int main()
{
    int max;
    printf("Enter the maximum integer for factorial calculation:\n ");
    scanf("%d", &max);

    int factorial = 1;
    for (int i = 1; i <= max; i++) 
    {
        factorial *= i;
    }
    printf("Factorials %d is : %d\n",max, factorial);
    

    return 0;
}