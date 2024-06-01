#include <stdio.h>
#include <math.h>

#define PI 3.14

float cube_surface(int a);
float cube_volume(int a);
float prism_surface(int l, int w, int h);
float prism_volume(int l, int w, int h);
float sphere_surface(int r);
float sphere_volume(int r);
float cone_surface(int r, int h);
float cone_volume(int r, int h);

int main()
{
    int a, l, w, h, r;

    printf("\nEnter the edge length for cube: ");
    scanf("%d", &a);
    printf("\nSurface Area = %.2f", cube_surface(a));
    printf("\tVolume = %.2f \n", cube_volume(a));

    printf("\nEnter side length for rectangular prism: ");
    scanf("%d", &l);
    printf("\nEnter side width: ");
    scanf("%d", &w);
    printf("\nEnter side height: ");
    scanf("%d", &h);
    printf("\nSurface Area = %.2f", prism_surface(l, w, h));
    printf("\tVolume = %.2f \n", prism_volume(l, w, h));

    printf("\nEnter the radius of sphere: ");
    scanf("%d", &r);
    printf("\nSurface Area = %.2f", sphere_surface(r));
    printf("\tVolume = %.2f \n", sphere_volume(r));

    printf("\nEnter the radius for cone: ");
    scanf("%d", &r);
    printf("\nEnter the height: ");
    scanf("%d", &h);
    printf("\nSurface Area = %.2f", cone_surface(r, h));
    printf("\tVolume = %.2f \n", cone_volume(r, h));

    return 0;
}

float cube_surface(int a)
{
    float Surface;
    Surface = 6 * a * a;
    return Surface;
}

float cube_volume(int a)
{
    float Volume;
    Volume = a * a * a;
    return Volume;
}

float prism_surface(int l, int w, int h)
{
    float Surface;
    Surface = 2 * (w * l) + 2 * (l * h) + 2 * (w * h);
    return Surface;
}

float prism_volume(int l, int w, int h)
{
    float Volume;
    Volume = w * h * l;
    return Volume;
}

float sphere_surface(int r)
{
    float Surface;
    Surface = 4 * PI * r * r;
    return Surface;
}

float sphere_volume(int r)
{
    float Volume;
    Volume = (4 * PI * r * r * r) / 3;
    return Volume;
}

float cone_surface(int r, int h)
{
    float s = sqrt((r * r) + (h * h));
    float Surface;
    Surface = PI * r * (r + s);
    return Surface;
}

float cone_volume(int r, int h)
{
    float Volume;
    Volume = (PI * r * r * h)/ 3;
    return Volume;
}