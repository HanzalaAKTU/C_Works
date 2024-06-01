#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2);
void region(float x, float y);

int main() 
{
    float x1, y1, x2, y2;

    printf("Enter the coordinates of point 1 (x y): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter the coordinates of point 2 (x y): ");
    scanf("%f %f", &x2, &y2);

    printf("Distance between the points: %.2f\n", distance(x1, y1, x2, y2));

    printf("Region of point 1: ");
    region(x1, y1);
    printf("Region of point 2: ");
    region(x2, y2);

    return 0;
}

float distance(float x1, float y1, float x2, float y2) 
{
    return sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));
}

void region(float x, float y) 
{
    if (x > 0) 
    {
        if (y > 0)
            printf("Quadrant 1\n");
        else if (y < 0)
            printf("Quadrant 4\n");
        else
            printf("On X-axis\n");
    } 
    
    else if (x < 0) 
    {
        if (y > 0)
            printf("Quadrant 2\n");
        else if (y < 0)
            printf("Quadrant 3\n");
        else
            printf("On X-axis\n");
    } 
    
    else 
    {
        if (y != 0)
            printf("On Y-axis\n");
        else
            printf("Origin\n");
    }
}