#include <stdio.h>
#include <math.h>

#define PI 3.14

int main()
{
    int a;
    float Surface,Volume;

    printf("Enter the edge lenght for cube: ");
    scanf("%d",&a);

    Surface = 6*a*a;
    Volume = a*a;

    printf("\nSurface Area = %.2f", Surface);
    printf("\tVolume = %.2f \n", Volume);

    int l,w,h;
    float Surface2,Volume2;

    printf("Enter side length for rectangular prism: ");
    scanf("%d",&l);
    printf("Enter side width: ");
    scanf("%d",&w);
    printf("Enter side height: ");
    scanf("%d",&h);
    
    Surface2 = 2*(w*l)+2*(l*h)+2*(w*h);
    Volume2 = w*h*l;
    
    printf("\nSurface Area = %.2f", Surface2);
    printf("\tVolume = %.2f \n", Volume2);

    int r;
    float Surface3,Volume3;

    printf("Enter the radius of sphere: ");
    scanf("%d",&r);

    Surface3 = 4*PI*r*r;
    Volume3 =  (4*PI*r*r*r)/3;

    printf("\nSurface Area = %.2f", Surface3);
    printf("\tVolume = %.2f \n", Volume3);


    int x,y;
    float Surface4,Volume4;

    printf("Enter the radius for cone: ");
    scanf("%d",&x);
    printf("Enter the height: ");
    scanf("%d",&y);

    float s=sqrt((x*x)+(y*y)); 
    Surface4 = PI*x*(x*s);
    Volume4 = PI*x*x*y;

    printf("\nSurface Area = %.2f", Surface4);
    printf("\tVolume = %.2f \n",Volume4);

}