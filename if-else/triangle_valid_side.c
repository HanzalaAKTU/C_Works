/* C program to check whether a triangle is valid or not if its sides are */

#include <stdio.h>


int main()
{

    int a, b, c;

    printf(" Enter tree side of triangle: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a+b > c)
    {
        if (b+c >a)
        {
            if (a+c > b)
                printf(" Your triangle is a valid \n");
            
            else
                printf(" Your triangle is a not valid \n");
        }
        else
            printf(" Your triangle is a not valid \n");
    }

    else
        printf(" Your triangle is a not valid \n");

    return 0;    
}        