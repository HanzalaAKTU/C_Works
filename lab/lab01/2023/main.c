#include<stdio.h>

int main()
{
    /**/
    int num;
    printf("Please Enter a number for 1-100:\n");
    scanf("%d",&num);
    
    if(num%3==0)    // control the mode of the number with 3
    {
        if(num<50 && num>5) // check if it is between 5 and 50 Dec and 3 times
        {
            printf("FizzBuzz\n\n");
        }
        else
            printf("Fizz\n\n");
    }

    else if(num<50 && num>5)  // just check if it is between 5 and 50 Dec
    {
        printf("Buzz\n\n");
    }
   
    printf("\n>------------------------------<\n");     

    float x,y,z,max;        // the code of the given function is

    printf("Enter number of X:");
    scanf("%f",&x);
    printf("Enter number of Y:");
    scanf("%f",&y);

    if(x>y)
    {
        max=x;
    }
    else
    {
        max=y;
    }
    
    z=(x/y)+(max/(x+y));

    printf("Z: %.3f\n\n",z);


    printf("\n>------------------------------<\n");   
    
    int age,years;

    printf("Enter your Age: ");     // taking the age from the user
    scanf("%d",&age);

    printf("Enter your Years of Experience: ");    // taking the Years of Experience from the user
    scanf("%d",&years);

    // ensuring that the values in the collection are provided

    if(age<20 && years<10)
    {
        printf("Your Salary is 10000 \n\n");
    }

    if(age<=20 && years>10)
    {
        printf(" Error!!! \n\n");
    }

    if(age>20 && age<=50 && years<10)
    {
        printf("Your Salary is 15000 \n\n");
    }

    if(age>20 && age<=50 && years>10)
    {
        printf("Your Salary is 20000 \n\n");
    }
    
    if(age>50 && years<10)
    {
        printf("Your Salary is 20000 \n\n");
    }
    
    if(age>50 && years>10)
    {
        printf("Your Salary is 25000 \n\n");
    }

return 0;
}