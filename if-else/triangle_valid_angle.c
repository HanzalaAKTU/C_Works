/* C program to check whether a triangle is valid or not if angles are given */

#include <stdio.h>


int main()
{

    int a, b, c, sum;

    printf(" Enter tree angles of triangle: ");
    scanf("%d%d%d", &a, &b, &c);

    sum = a + b + c;

    if (sum == 180)
        if (a > 0 && b > 0 && c > 0)
            printf(" Your triangle is valid \n");
        else
            printf(" Your triangle is not valid. \n");
    else
        printf(" Your triangle is not valid. \n");

    return 0;
}        
