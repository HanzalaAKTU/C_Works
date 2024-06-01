#include <stdio.h>
#include <math.h>

// Enumeration of colors
enum Color {RED,GREEN,BLUE,YELLOW,ORANGE};

// Length-3 vector for each color
double colors[5][3] = 
{
    {1, 0, 0},    // RED
    {0, 1, 0},    // GREEN
    {0, 0, 1},    // BLUE
    {0.5, 0.5, 0}, // YELLOW
    {0.5, 0.4, 0.2} // ORANGE
};

// Function to calculate Euclidean distance between two colors
double distance(double color1[3], double color2[3]) 
{
    double sum = 0;
    for (int i = 0; i < 3; i++) 
    {
        sum += pow(color1[i] - color2[i], 2);
    }
    return sqrt(sum);
}

// Function to mix two colors
enum Color mixColors(enum Color c1, enum Color c2) 
{
    double mixedColor[3] = 
    {
        (colors[c1][0] + colors[c2][0]) / 2,
        (colors[c1][1] + colors[c2][1]) / 2,
        (colors[c1][2] + colors[c2][2]) / 2
    };
    
    // Find the closest color to the mixed color
    double closestDistance = distance(mixedColor, colors[0]);
    int closestColor = 0;
    for (int i = 1; i < 5; i++) 
    {
        double d = distance(mixedColor, colors[i]);
        if (d < closestDistance) 
        {
            closestDistance = d;
            closestColor = i;
        }
    }
    
    return closestColor;
}

int main() 
{
    // Test mixing colors
    enum Color c1 = RED;
    enum Color c2 = BLUE;
    enum Color mixed = mixColors(c1, c2);
    
    // Print results
    printf("Mixing %d and %d results in %d (", c1, c2, mixed);
    switch (mixed) 
    {
        case RED:
            printf("RED)\n");
            break;
        case GREEN:
            printf("GREEN)\n");
            break;
        case BLUE:
            printf("BLUE)\n");
            break;
        case YELLOW:
            printf("YELLOW)\n");
            break;
        case ORANGE:
            printf("ORANGE)\n");
            break;
        default:
            printf("UNKNOWN COLOR)\n");
            break;
    }
    
    return 0;
}