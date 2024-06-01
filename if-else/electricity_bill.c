/* C program to calculate total electricity bill */

#include <stdio.h>


int main()
{

    int unit;
    float amt, basic, surcharge, total;

    printf(" Enter total units consumed: \n");
    scanf("%d", &unit);

    if (unit <= 50)
        amt = unit * 0.50;

    else if (unit <= 150)
        amt = (50 * 0.50) + (unit-50) * 0.75;
    
    else if (unit <= 250)
        amt = (50 * 0.50) + (100 * 0.75) + (unit-150) * 1.20;
    
    else
        amt = (50 * 0.50) + (100 * 0.75) + (100 * 1.20) + (unit-250) * 1.50;

    surcharge = amt * 0.20;
    total = amt + surcharge;

    printf(" Your Electricity Bill : %.2f\n",total);


    return 0;
}        