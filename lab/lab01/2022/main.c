#include <stdio.h>

double x,y; /* Variables for calculating the midpoint of coordinates */
double m; /* Variable for calculating the slope of the coordinates */
double area,temp; /* Variables for calculating the area of the coordinates */

int midpoint_calculation(int a,int b,int c,int d)
{
    x=(double) (a+c)/2; /* Formulas of the finding midpoint*/
    y=(double) (b+d)/2;

    return x,y;
}
int slope_calculation(int a,int b,int c,int d)
{
    m= (double) (d-b)/(c-a); /* Formulas of the finding slope*/
    
    return m;
}
int area_calculation(int a,int b,int c,int d)
{
    temp=(double) (c-a)*(c-a)+(d-b)*(d-b);
    area=(3.14*temp)/4; /* Formulas of the area of circle*/
    
    return area;
}
int main()
{
    int x1,y1,x2,y2; /* Variables for coordinates */

    printf("enter the coordinates : "); /* User Part */
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

    printf("x1: %d\n",x1);
    printf("y1: %d\n",y1);
    printf("x2: %d\n",x2);
    printf("y2: %d\n",y2);
    printf("\n");

    midpoint_calculation(x1,y1,x2,y2);
    printf("Midpoint : M(X,Y) =(%.1lf , %.1lf)\n",x,y);
    printf("\n");
    
    slope_calculation(x1,y1,x2,y2);
    printf("Slope m = (%.1lf)\n",m);
    printf("\n");

    area_calculation(x1,y1,x2,y2);
    printf("Area: A = %.1lf",area);
}