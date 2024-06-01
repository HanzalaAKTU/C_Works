#include<stdio.h>
#include<math.h>

int main()
{
    int a;

    printf("Enter an integer between 1 and 10: ");
    scanf("%d",&a);
    printf("\n");

    if(1<=a && a <= 10)
    {
        if(a <= 5)
            printf("The integer you entered is less than or equal to 5. \n");
        
        else 
            printf("The integer you entered is greater than 5. \n");
    }

    else
        printf("invalid input. \n");
}