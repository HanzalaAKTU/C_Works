#include <stdio.h>
#include<math.h>

int main()
{
    int c,d;

    printf("\n\nEnter First number: ");
    scanf("%d",&c);
   
    printf("Enter Second number: ");
    scanf("%d",&d);

    printf("\n");
    printf("First number:  %d\n",c);
    printf("Second number: %d\n",d);
    printf("Result: \n");

    printf("%25d\n",c);
    printf("%25d\n",d);
    printf("%20c\n",'*');
    printf("%20c-------\n",'-');

    int current = d;
    int bosluk = 22;

    while(current > 0)
    {
        int e =  current % 10;      
        current = (current - e) / 10;
        int multiplied = e * c;
    
        for(int i=0; i<bosluk; i++)
            printf(" ");

        printf("%d\n",multiplied);
        bosluk--;
    }

    printf("%20c\n",'+');
    printf("%20c-------\n",'-');
    printf("%25d",(c*d));

return 0;    
}