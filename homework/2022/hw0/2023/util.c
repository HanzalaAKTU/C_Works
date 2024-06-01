#include <stdio.h>
#include "util.h"

int find_ebob(int num1, int num2);

void fraction_print(int numerator, int denominator) 
{
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) 
{
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) 
{
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) 
{
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) 
{
    *n3 = n1*d2;
    *d3 = n2*d1;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) 
{
   if(*n < 0 && *d<0)
    {
        *n = -(*n);
        *d = -(*d);
    }
    int ebob = find_ebob(*n,*d);  

    *n = (*n) / ebob;
    *d = (*d) / ebob;

} /* end fraction_div */

 /* i have defined the ebob function for the simplification process */
int find_ebob(int num1, int num2)
{
    int end_for_here=0;
    int result=1;

    if(num2<0) num2 = num2*(-1); 

    if(num1<0) num1 = num1*(-1);  

    if(num2<num1)
        end_for_here = num2;
    else 
        end_for_here = num1;

    for(int i=2; i<=end_for_here; ++i)
    {
        if(num1 % i ==0 && num2 % i ==0 )
            result = i;
    }
    return result;
}