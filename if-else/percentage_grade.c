/* C program to enter marks of five subjects and find percentage and grade */

#include <stdio.h>


int main()
{

    int math, phy, che, bio, com;
    float per;

    printf("Enter 5 subjects marks: \n ");
    scanf(" %d%d%d%d%d",&math,&phy, &che, &bio, &com);

    per = (math+phy+che+bio+com)/5;

    printf("5 subjects Percentage: %.2f \n",per);

    if (per>=90)
        printf("Grade = A\n");
    
    else if (per>=80)
        printf("Grade = B\n");

    else if (per>=70)
        printf("Grade = C\n");    

    else if (per>=60)
        printf("Grade = D\n");

    else if (per>=40)
        printf("Grade = E\n");  

    else    
        printf("Grade = F\n");           
    
    return 0;
}        