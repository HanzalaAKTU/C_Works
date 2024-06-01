#include <stdio.h>
#include <math.h>

int select_shape();     /*Function for user*/
int select_calc();
int calculate(int (*a)(),int (*b)());

int calc_triangle(int);
int calc_quadrilateral(int);
int calc_circle(int);
int calc_pyramid(int);
int calc_cylinder(int);

enum  Shapes{Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder}; /*enum types for function */
enum Calculator{Area=1,Perimeter,Volume};

int main()  
{   /*main function*/
    int x;
    do
    {   
        x=calculate(select_shape,select_calc);
    } 
    while (x!=0);
}

int calculate(int a(), int b())
{   /*calculate function*/
    int m,n,k;
    
    m=a();
        
    if(m!=0)
    {
        n=b();

        switch (m)
        {
            case Triangle:
                calc_triangle(n);
                
            break;

            case Quadrilateral:
                calc_quadrilateral(n);
                
            break;

            case Circle:
                calc_circle(n);
            
            break;
            
            case Pyramid:
                calc_pyramid(n);
            
            break;

            case Cylinder:
                calc_cylinder(n);

            break;   
        }
    }   
}

int select_shape()
{   /*user shape selection*/
    int select_shape;
          
        printf("\n\n -----------**********---------- \n\n");
        printf(" Welcome to the geometric calculator! \n\n");
        printf("\n Select a shape to calculate:\n");
        printf(" --------------------------------- \n");
        printf(" 1. Triangle\n");
        printf(" 2. Quadrilateral\n");
        printf(" 3. Circle\n");
        printf(" 4. Pyramid\n");
        printf(" 5. Cylinder\n");
        printf(" 0. Exit\n");
        printf(" --------------------------------- \n\n");
        
        printf(" Select:\n");
        scanf(" %d",&select_shape);

    return select_shape;
}

int select_calc()
{   /*user select calculator*/
    int select_calc;
    
            printf("\n Select Calculator:\n");
            printf(" ---------------------------------\n"); 
            printf(" 1. Area\n");           
            printf(" 2. Perimeter\n");
            printf(" 3. volume\n");
            printf(" 0. Exit\n\n");
            printf(" Choice:\n");
            scanf(" %d",&select_calc);

    return select_calc;
}

int calc_triangle(int h)
{   /*calculation for triangle*/
    float a,b,c,s,area,perimeter;
    
    switch (h)
    {
        case Area: 
        do
        {
            printf("\n Please enter tree sides of Triangle:\n");
            scanf(" %f %f %f",&a,&b,&c);
    
            s = (a+b+c)/2 ;
            area = sqrt(s*(s-a)*(s-b)*(s-c));

            if (s<=a || s<=b || s<=c)
                printf("ERROR ! Please enter a valid entry. \n");
                    
            else if(s>a || s>b || s>c)
                printf(" Area of TRIANGLE : %.3f ",area);
        } 
        while (s<=a || s<=b || s<=c);

        break;

        case Perimeter:
        do
        {
            printf("\n Please enter tree sides of Triangle:\n");
            scanf(" %f %f %f",&a,&b,&c);

            perimeter = (a+b+c);

            if (a>=b+c || b>=a+c || c>=a+b)
                printf("ERROR ! Please enter a valid entry. \n");
            else     
                printf(" Perimeter of TRIANGLE : %.3f",perimeter);
        }
        while(a>=b+c || b>=a+c || c>=a+b);  

        break;

        case Volume:

            printf("\nERROR! You cannot calculate the volume of a triangle. Please try again.\n");

        break;
    }
}

int calc_quadrilateral(int k)
{   /*calculation for quadrilateral*/
    float a,b,c,d,s,area,perimeter;

    switch (k)
    {
        case Area: 
        
        do
        {
            printf("\n Please enter four sides of Quadrilateral:\n");
            scanf("%f %f %f %f",&a,&b,&c,&d);
    
            s = (a+b+c+d)/2 ;
            area = sqrt( (s-a)*(s-b)*(s-c)*(s-d));
        
            if (a>=b+c+d || b>=a+c+d || c>=a+b+d || d>=a+b+c)
                printf("ERROR ! Please enter a valid entry. \n"); 
            else  
                printf(" Area of QUADRİLATERAL : %.3f ",area);
        }
        while (a>=b+c+d || b>=a+c+d || c>=a+b+d || d>=a+b+c);

        break;

        case Perimeter:

            printf("\n Please enter tree sides of Triangle:\n");
            scanf("%f %f %f %f",&a,&b,&c,&d);

            perimeter = (a+b+c+d);

            if (a>b+c+d || b>a+c+d || c>a+b+d || d>a+b+c)
                printf("ERROR ! Please enter a valid entry. \n");
            else     
                printf(" Perimeter of TRIANGLE : %.3f",perimeter);

        break;

        case Volume:

            printf("\nERROR! You cannot calculate the volume of a triangle. Please try again.\n");

        break;
    }
} 

int calc_circle(int t)
{   /*calculator for circle*/
    float r,pi,area,perimeter;
    pi = 3.14;
    
    switch (t)
    {
        case Area: 
        
            printf("\n Please enter radius of Circle:\n");
            scanf("%f",&r);
    
            area = pi * r * r ;
        
            printf(" Area of QUADRİLATERAL : %.3f ",area);
      

        break;

        case Perimeter:
            
            printf("\n Please enter radius of Circle:\n");
            scanf("%f",&r);

            perimeter = 2 * pi * r;

            printf(" Perimeter of QUADRİLATERAL : %.3f",perimeter);
        
        break;

        case Volume:

          printf("\nERROR! You cannot calculate the volume of a triangle. Please try again.\n");

        break;
    }
}

int calc_pyramid(int p)
{   /*calculator for pyramid*/
    float a,h,B,L,S,volume;

    switch (p)
    {
        case Area:

            printf(" Please enter the base side and slant height of a Prymid:\n");
            scanf("%f %f",&a,&h);

            B= a*a;
            L= 2*a*h;
            S= B+L;

            printf("\nBase Surface Area of a PYRAMID: %.3f\n",B);
            printf("\nLateral Surface Area of a PYRAMID: %.3f\n",L);
            printf("\nSurface Area of a PYRAMID: %.3f\n",S);
        
        break;

        case Perimeter:

            printf(" Please enter the base side of a Prymid:\n");
            scanf("%f",&a);

            B= a*a;

            printf("\nBase Surface Area of a PYRAMID: %.3f\n",B);

        break;

        case Volume:

            printf("Please enter the base side and height of a Pyramid:\n");
            scanf("%f %f",&a,&h);
        
            volume = (a*a*h)/3;

            printf("\nVolume of a PYRAMİD: %.3f\n",volume);

        break;
    }
}

int calc_cylinder(int s)
{   /*calculator for cylinder*/
    float r,h,pi,B,L,S,volume;
    pi=3.14;

    switch (s)
    {
        case Area:

            printf(" Please enter the radius and  height of a Cylinder:\n");
            scanf("%f %f",&r,&h);

            B= pi*r*r;
            L= 2*pi*r*h;
            S= 2*pi*r*(r+h);

            printf("\nBase Surface Area of a CYLİNDER: %.3f\n",B);
            printf("\nLateral Surface Area of a CYLİNDER: %.3f\n",L);
            printf("\nSurface Area of a CYLİNDER: %.3f\n",S);
        
        break;

            case Perimeter:

            printf(" Please enter the base side of a Prymid:\n");
            scanf("%f",&r);

            B= r*r;

            printf("\nBase Surface Area of a PYRAMID: %.3f\n",B);

        break;

        case Volume:

            printf("Please enter the radius and  height of a Cylinder::\n");
            scanf("%f %f",&r,&h);
        
            volume = pi*r*r*h;

            printf("\nVolume of a PYRAMİD: %.3f\n",volume);

        break;
    }
}