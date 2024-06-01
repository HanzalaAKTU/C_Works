/* C program to find all roots of a quadratic equation */

#include <stdio.h>
#include <math.h>


int main()
{

    float a, b, c;
    float root1, root2;
    float discriminant;


    printf("Enter values of a, b, c of quadratic equation (aX^2 + bX + c): ");
    scanf("%f%f%f",&a ,&b, &c);

    discriminant= (b*b)-(4*a*c);

    if (discriminant > 0)
    {
        root1= (-b - sqrt(discriminant))/(2*a);
        root2= (-b + sqrt(discriminant))/(2*a);

        printf("Two distinct and real roots exists: %.2f and %.2f\n", root1, root2);
    }

    else if (discriminant == 0)
    {        
        root2 = root1 = (-b)/(2*a);

        printf("Two equal and real roots exists: %.2f and %.2f\n", root1, root2);
    }

    else
        printf(" There are two distinct complex roots\n");
      
    
    return 0;
}        