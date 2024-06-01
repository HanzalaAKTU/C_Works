#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main() 
{
    int select; 
    double pl,pw,sl,sw; 
    double x1,x2,x3;  
    int x4,x5; 
    double y1,y2; 
    int y3,y4,y5;

    printf("Which problem do you want to solve ? :");
    scanf("%d",&select);

    if(select==1)
    { 
        printf("Enter the pl and pw inputs :\n");
        scanf("%lf %lf %lf %lf",&pl,&pw,&sl,&sw);

        if(dt1a(pl,pw)=='b' && dt1b(pl,pw)=='b') printf("Result is Setosa");

        if(dt1a(pl,pw)=='o' && dt1b(pl,pw)=='o') printf("Result is Virginica");

        if(dt1a(pl,pw)=='g' && dt1b(pl,pw)=='g') printf("Result is Versicolor");

        if(dt1a(pl,pw)=='b' && dt1b(pl,pw)=='o') printf("Result is Setosa and Virginica");

        if(dt1a(pl,pw)=='b' && dt1b(pl,pw)=='g') printf("Result is Setosa and Versicolor");

        if(dt1a(pl,pw)=='o' && dt1b(pl,pw)=='b') printf("Result is Virginica and Setosa");

        if(dt1a(pl,pw)=='o' && dt1b(pl,pw)=='g') printf("Result is Virginica and Versicolor");

        if(dt1a(pl,pw)=='g' && dt1b(pl,pw)=='b') printf("Result is Versicolor and Setosa");

        if(dt1a(pl,pw)=='g' && dt1b(pl,pw)=='o') printf("Result is Versicolor and Virginica");
    
        printf("\n");
    }

    else if(select==2)
    {
        printf("Enter input values:\n");
        scanf("%lf %lf %lf %d %d",&x1,&x2,&x3,&x4,&x5);

        if(dt2a(x1,x2,x3,x4,x5)==dt2b(x1,x2,x3,x4,x5)) 
            printf("Result is = %.2lf",(dt2a(x1,x2,x3,x4,x5)+dt2b(x1,x2,x3,x4,x5))/2);

        else if((dt2a(x1,x2,x3,x4,x5)-dt2b(x1,x2,x3,x4,x5))<CLOSE_ENOUGH && (dt2a(x1,x2,x3,x4,x5)-dt2b(x1,x2,x3,x4,x5))>-(CLOSE_ENOUGH)) 
            printf("Result is = %.2lf",(dt2a(x1,x2,x3,x4,x5)+dt2b(x1,x2,x3,x4,x5))/2);

        else    
            printf("Results are = %.2lf and %.2lf",dt2a(x1,x2,x3,x4,x5),dt2b(x1,x2,x3,x4,x5));            
    
        printf("\n");    
    }
		
    else if(select==3)
    {
        printf("x1:age\nx2:loan amouth\nx3:student(if yes 1 else 0)\nx4:income(low:1,2-normal:3,4-high:5,6)\nx5:month(1-12)");
        printf("\nEnter input values:");
        scanf("%lf %lf %d %d %d",&y1,&y2,&y3,&y4,&y5);

        if(dt3a(y1,y2,y3,y4,y5)==dt3b(y1,y2,y3,y4,y5))  
            printf("Result is = %.2lf",(dt3a(y1,y2,y3,y4,y5)+dt3b(y1,y2,y3,y4,y5))/2);

        else if((dt3a(y1,y2,y3,y4,y5)-dt3b(y1,y2,y3,y4,y5))<CLOSE_ENOUGH && (dt3a(y1,y2,y3,y4,y5)-dt3b(y1,y2,y3,y4,y5))>-(CLOSE_ENOUGH)) 
            printf("Result is %.2lf",(dt3a(y1,y2,y3,y4,y5)+dt3b(y1,y2,y3,y4,y5))/2);

        else  		
            printf("Results are = %.2lf and %.2lf",dt3a(y1,y2,y3,y4,y5),dt3b(y1,y2,y3,y4,y5)); 
    
        printf("\n");
    }

    else 
        printf("Invalid selection");	
    
    printf("\n");
    
    return 0;
}