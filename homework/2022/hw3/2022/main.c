#include <stdio.h>
#include <math.h>

int sum (int n1, int n2, int flag);
int multi (int n1, int n2, int flag);
int isprime(int a);

int main()
{
    int selected;
    int sum_or_mult;
    int even_or_odd;
    int num1,num2,num3;
   
    printf(" ?-----------?***********?-----------? \n");
    printf(" \t Select Operation \n");
    printf("1. Calculate sum/multiplication between two numbers \n");
    printf("2. Calculate prime numbers \n");
    printf("3. Show number sequence in file \n");
    printf("4. Sort number sequence in file \n");
    printf(" ?-----------?***********?-----------? \n");

    printf("Selecet operation:\n");
    scanf("%d", &selected);

    if(selected==1)
    {
        printf("Please enter'0' for sum, '1' for multiplication\n");
        scanf("%d", &sum_or_mult);

        switch (sum_or_mult)
        {
            case 0:
            printf("Please enter '0' to work on even number, '1' to work on odd numbers.\n");
            scanf("%d",&even_or_odd);
            break;
    
            case 1:
            printf("Please enter '0' to work on even number, '1' to work on odd numbers.\n");
            scanf("%d",&even_or_odd);
            break;

            default:
            printf("incorrect number\n");
            break;
        }
            
        if (sum_or_mult==0)
        {
            printf("Please enter two different number:\n");
            scanf("%d %d", &num1,&num2);
            
            printf("Result \n");
            printf("Number1:%d\n Number2: %d\n " ,num1,num2 );
           
            sum(num1,num2,even_or_odd);
        }

        if (sum_or_mult==1)
        {
            printf("Please enter two different number:\n");
            scanf("%d %d", &num1,&num2);
           
            printf("Result \n");
            printf("Number1:%d \n Number2: %d\n " ,num1,num2 );
           
            multi(num1,num2,even_or_odd);
        }
    }

    if(selected==2)
    {
        printf("Please enter an integer number:");
        scanf("\n%d",&num3);
        for(int i=2; i<num3; i++)
        {
            int p = isprime(i);
                if(p != 0)
                    printf("%d is not a prime number, it is dividible by %d.\n",i,p);
                else
                    printf("%d is a prime number.\n",i);
        }
    }

    if (selected==3)
    {

    }

    if (selected==4)
    {

    }    
}
    
int sum(int n1, int n2, int flag)
{
    int i;
    int sum=0;

    if(flag==0)
    {
        for(i=n1+1;i<n2;i++)
        {
            if(i%2==0)
            {
                sum=sum+i;
                    if(i+1 == n2 || i+2 == n2)
                        printf("%d = %d",i,sum);
                    else
                        printf("%d+",i);
            }
        }
    }

    if (flag==1)
    {
        for(i=n1+1;i<n2;i++)
        {
            if(i%2==1)
            {
                sum=sum+i;                    
                    if(i+1 == n2 || i+2 == n2)
                        printf("%d = %d",i,sum);
                    else
                        printf("%d+",i);                        
            }
        }        
    }
}

int multi (int n1, int n2, int flag)
{
    int i;
    int multi=1;

    if (flag==0)
    {
        for(i=n1+1;i<n2;i++ )
        {    
            if(i%2==0)
            {
                multi=multi*i;                    
                if(i+1 == n2 || i+2 == n2)
                    printf("%d = %d",i,multi);
                else
                    printf("%d*",i);
            }    
        }
    }
        
    if (flag==1)
    {
        for(i=n1+1;i<n2;i++)
        {    
            if (i%2==1)
            {
                multi=multi*i;                        
                    if( i+1 == n2 || i+2 == n2 )
                        printf("%d = %d",i,multi);
                    else
                        printf("%d*",i);                    
            }
        }
    }
}

int isprime(int num3)
{
    for (int i=2;i<num3;i++)
    {
        if(num3%i==0)
            return i;
    }
        return 0;
}