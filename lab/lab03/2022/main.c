#include <stdio.h>

void x_star_display(int height);
void diamond_star_display(int height);
void multiplication_table_display(int size);
void is_polindrome_integer(int n);

int main()
{
    int option=0;
    int height;
    int size;
    int n;

    do
    {
        printf("?-----------?***********?-----------?\n");
        printf("\tSelect option\n");
        printf("Enter option 1 to x_star_display\n");
        printf("Enter option 2 to diamond_star_display\n");
        printf("Enter option 3 to multiplication_table_display\n");
        printf("Enter option 4 palindrome check number\n");
        printf("Enter option -1 to exit\n");
        printf("?-----------?***********?-----------?\n");

        printf("Selected option:\n");
        scanf("%d",&option);

        if (option==1)
        {
            printf("Enter an odd number integer as the height:");
            scanf("%d",&height);            

            x_star_display(height);
        }

        if(option==2)
        {
            printf("Enter an odd number integer as the height:");
            scanf("%d",&height);           

            diamond_star_display(height);
        }
    
        if (option==3)
        {
            printf("Enter an integer as the size:");
            scanf("%d",&size);
           
            multiplication_table_display(size); 
        }
    
        if (option==4)
        {
            printf("Enter an integer as the palindrome: ");
            scanf("%d", &n);
            
            is_polindrome_integer(n);          
        }

    }
    while (option!=-1);
}

void x_star_display(int height)
{
    for (int i=1;i<=height;i++)
    {
        for(int j=1;j<=height;j++)
        {
            if(i==j || j==(height-i+1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }   
}

void diamond_star_display(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1;  j <= height-i; j++)
        {
            printf(" ");
        }
    
        for (int j = 1; j <= i*2-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }    
    for (int i = height-1; i > 0; i--)
    {
        for(int j = 1;j <= height-i; j++)
        {
            printf(" ");
        }

        for(int j=1; j<= i*2-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void multiplication_table_display(int size)
{
    for (int i=1;i<=size;i++)
    {
        for(int j=1;j<=size;j++)
        {
            printf("%d\t",i*j);    
        }
        printf("\n");  
    }     
}

void is_polindrome_integer(int n)
{
    int reversed = 0, remainder, original;

    original = n;
            
    while (n != 0) 
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
       n /= 10;
    }        
        if (original == reversed)
            printf("%d is a palindrome.\n", original);
        else
        printf("%d is not a palindrome.\n", original);

}