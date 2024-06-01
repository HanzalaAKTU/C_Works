#include<stdio.h>

int input(int a);
int gcd(int b, int c);
int collect(int d, int e);
int multiplication(int f, int h);

int main()
{   
    int a,b,c,d,e,f,h;

    printf("\n***--------- GCD --------------***\n");
    printf("\nEnter First number: ");
    scanf("%d",&b);
   
    printf("\nEnter Second number: ");
    scanf("%d",&c);

    gcd(b,c);
    
    
    printf("\n***-------- INPUT ---------------***\n");
    printf("\nEnter an integer between 1 and 10: ");
    scanf("%d",&a);

    input(a);


    printf("\n***--------- COLLECT --------------***\n");

    printf("\nEnter First number: ");
    scanf("%d",&d);

    printf("\nEnter Second number: ");
    scanf("%d",&e);

    collect(d,e);


    printf("\n***----------- MULTİPLİCATİON------------***\n");

    printf("\nEnter First number: ");
    scanf("%d",&f);
   
    printf("\nEnter Second number: ");
    scanf("%d",&h);

    multiplication(f,h);


return 0;
}

int input(int a)
{
    if(1<=a && a <= 10)
    {
        if(a <= 5)
            printf("\nThe integer you entered is less than or equal to 5. \n");
        
        else 
            printf("\nThe integer you entered is greater than 5. \n");
    }

    else
        printf("\ninvalid input. \n");
       
}

int gcd(int b, int c)
{
    int result = 1;
    while (result > 0)
    {
        result = b % c;
        b = c;
        c = result;

    }

    printf("\n GCD:%d \n",b);
}

int collect(int d, int e)
{
    printf("\n");
    printf("First number:  %d\n",d);
    printf("Second number: %d\n",e);
    printf("Result: \n");

    if(d < e)
    {
        int backup = d;
        d = e;
        e = backup;
    }
    
    printf("%25d\n",d);
    printf("%25d\n",e);
    printf("%20c\n",'+');
    printf("%20c-------\n",'-');
    printf("%25d",(d+e));
    printf("\n");
}

int multiplication(int f, int h)
{
    printf("First number:  %d\n",f);
    printf("Second number: %d\n",h);
    printf("Result: \n");

    printf("%25d\n",f);
    printf("%25d\n",h);
    printf("%20c\n",'*');
    printf("%20c-------\n",'-');

    int current = h;
    int bosluk = 22;

    while(current > 0)
    {
        int e =  current % 10;      
        current = (current - e) / 10;
        int multiplied = e * f;
    
        for(int i=0; i<bosluk; i++)
            printf(" ");

        printf("%d\n",multiplied);
        bosluk--;
    }

    printf("%20c\n",'+');
    printf("%20c-------\n",'-');
    printf("%25d",(f*h));
    printf("\n");

}