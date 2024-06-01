/* C program to count minimum number of notes in an amount */

#include <stdio.h>


int main()
{

    int amount;
    int note200, note100, note50, note20, note10, note5, note1;

    note200 = note100 = note50 = note20 = note10 = note5 = note1 = 0;

    printf("Enter amount: ");
    scanf("%d",&amount);


    if (amount >= 200)
    {
        note200 = amount / 200;
        amount -= note200*200;  
    }
    
    if (amount >= 100)
    {
        note100 = amount / 100;
        amount -= note100*100;  
    }

    if (amount >= 50)
    {
        note50 = amount / 50;
        amount -= note50*50;  
    }    
    
    if (amount >= 20)
    {
        note20 = amount / 20;
        amount -= note20*20;  
    }

    if (amount >= 10)
    {
        note10 = amount / 10;
        amount -= note10*10;  
    }

    if (amount >= 5)
    {
        note5 = amount / 5;
        amount -= note5*5;  
    }

    if (amount >= 1)
    {
        note1= amount / 1;
        amount -= note1*1;  
    }

    printf("Total number of notes = \n");
    printf("200 = %d\n", note200);
    printf("100 = %d\n", note100);
    printf("50 = %d\n", note50);
    printf("20 = %d\n", note20);
    printf("10 = %d\n", note10);
    printf("5 = %d\n", note5);
    printf("1 = %d\n", note1);

    return 0;

}        
