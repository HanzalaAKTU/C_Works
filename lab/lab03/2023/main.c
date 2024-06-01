#include<stdio.h>

int median(int a, int b, int c);
int scores(int x, int y, int z);
int calc( char m, int k,int l, int r);

int main()
{
    char m;
    int a,b,c;
    int x,y,z;
    int k,l,r;
    

    printf("***----- PART1 -------***\n");
    printf("Enter 3 integer:\n");
    scanf("%d %d %d",&a,&b,&c);

    median(a,b,c);


    printf("\n\n***----- PART2 -------***\n");
    printf("Enter your scores:\n");
    scanf("%d %d %d",&x,&y,&z);

    scores(x,y,z);


    printf("\n\n***----- PART3 -------***\n");
    printf("Enter an arithmetic operation (+, -, *, /):");
    scanf("%c",&m);

    printf("\nEnter two numbers:\n");
    scanf("%d %d",&k,&l);

    printf("\nResult:");
    scanf("%d",&r); 

    calc(m,k,l,r);

}

int median(int a, int b, int c)
{
    int middle;

    if ((a-b)*(a-c) < 0)
        middle = a;

    if ((b-a)*(b-c) < 0)
        middle = b;
        
    if ((c-a)*(c-b) < 0)
        middle = c;

    printf("\nMedian number is %d\n",middle);
}

int scores(int x, int y, int z)
{
    int grade;
    int arr[]={x,y,z}; 

    printf("You letter grades are ");
    
    for (int i = 0; i < 3; i++)
    {
        grade = arr[i];
        int h= grade/10;
        switch (h)
        {
            case 10:
                printf(" A+ ");
                break;

            case 9:
                printf(" A+ ");
                break;

            case 8:
                printf(" A ");
                break; 

            case 7:
                printf(" B+ ");
                break; 

            case 6:
                printf(" B ");
                break; 

            case 5:
                printf(" C ");
                break; 
                
            case 4:
                printf(" D ");
                break;

            default:
                printf(" F ");
                break;
        }
    }

    float avarage=(x+y+z)/3;
    printf(" and A with an %.3f avarage",avarage);
}

int calc( char m, int k,int l, int r)
{
   
}