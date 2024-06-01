/* C program to calculate gross salary of an employee */

#include <stdio.h>


int main()
{

    float gross, basic, hra, da;

    printf(" Enter basic salary of an employee:\n");
    scanf("%f",&basic);
            
    if (basic <= 10000)
    {
        hra = basic * 0.2;
        da = basic * 0.8; 
    }

    else if (basic <= 20000)
    {
        hra = basic * 0.25;
        da = basic * 0.9;
    }

    else
    {
        hra = basic * 0.30;
        da = basic * 0.95;
    }

    gross = hra + da + basic;
    
    printf(" Gross Salary of Employee : %.2f\n",gross);


    return 0;
}        