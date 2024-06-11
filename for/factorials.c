#include <stdio.h>

int main()
{
    int max;
    printf("Enter the maximum integer for factorial calculation: ");
    scanf("%d", &max);

    long long factorial = 1;
    for (int i = 1; i <= max; i++) 
    {
        factorial *= i;
    }
    printf("\n Factorials %d is : %llu\n",max, factorial);
    

    return 0;
}