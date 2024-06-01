/* C program to check whether a triangle is Equilateral, Isosceles or Scalene */

#include <stdio.h>


int main()
{

    int a, b, c;

    printf(" Enter tree side of triangle: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a==b && b==c)
        printf("Your triangle is equilateral\n");

    else if (a==b || a==c || b==c)
        printf("Your triangle is isosceles\n");
    
    else
        printf(" Your triangle is a scalene \n");

    return 0;    
}        