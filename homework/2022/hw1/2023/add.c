#include<stdio.h>
#include<math.h>


int main()
{   
    int a,b;

    if (a<b)
    {
        int backout;

        backout =a;
        a = b;
        b = backout;
    }
    
    printf("Enter First number: ");
    scanf("%d",&a);

    printf("Enter Second number: ");
    scanf("%d",&b);

    printf("\n");
    printf("First number:  %d\n",a);
    printf("Second number: %d\n",b);
    printf("Result: \n");
    
    printf("%25d\n",a);
    printf("%25d\n",b);
    printf("%20c\n",'+');
    printf("%20c-------\n",'-');
    printf("%25d",(a+b));

return 0;    
}