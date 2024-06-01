#include <stdio.h>
#include <math.h>

#define NUM_SAMPLES 10
#define EPSILON 0.001

// Function to read points for a class
void readPoints(double points[][2], int numPoints) 
{
    for (int i = 0; i < numPoints; i++) 
    {
        printf("Enter point %d coordinates: ", i + 1);
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }
}

// Function to calculate the average point for a class
void calculateAverage(double points[][2], int numPoints, double average[2]) 
{
    double sumX = 0, sumY = 0;
    for (int i = 0; i < numPoints; i++) 
    {
        sumX += points[i][0];
        sumY += points[i][1];
    }
    average[0] = sumX / numPoints;
    average[1] = sumY / numPoints;
}

// Function to classify and print the label and distance for a test point
void classifyAndPrint(double testPoint[2], double average1[2], double average2[2]) 
{
    double distance1 = 0, distance2 = 0;

    // Calculate the distance from the test point to both class averages
    distance1 = sqrt(pow(testPoint[0] - average1[0], 2) + pow(testPoint[1] - average1[1], 2));
    distance2 = sqrt(pow(testPoint[0] - average2[0], 2) + pow(testPoint[1] - average2[1], 2));

    // Compare distances and classify the point
    if (distance1 < distance2) 
        printf("class 1, distance = %lf\n", distance1);
    
    else 
        printf("class 2, distance = %lf\n", distance2);
}

int main() 
{
    double class1Points[NUM_SAMPLES][2];
    double class2Points[NUM_SAMPLES][2];
    double averageClass1[2], averageClass2[2];
    double connectingLine[2], midpoint[2];
    double separatingLineSlope;

    // Read points for class 1 and class 2
    printf("Enter points for class 1:\n");
    readPoints(class1Points, NUM_SAMPLES);

    printf("Enter points for class 2:\n");
    readPoints(class2Points, NUM_SAMPLES);

    // Calculate the average points for both classes
    calculateAverage(class1Points, NUM_SAMPLES, averageClass1);
    calculateAverage(class2Points, NUM_SAMPLES, averageClass2);

    // Calculate the connecting line and midpoint
    connectingLine[0] = averageClass2[0] - averageClass1[0];
    connectingLine[1] = averageClass2[1] - averageClass1[1];

    midpoint[0] = (averageClass1[0] + averageClass2[0]) / 2.0;
    midpoint[1] = (averageClass1[1] + averageClass2[1]) / 2.0;

    // Calculate the slope of the separating line
    if (connectingLine[0] != 0) 
        separatingLineSlope = -connectingLine[1] / connectingLine[0];
    
    else 
        separatingLineSlope = 0; // Avoid divide-by-zero
    
    printf("Midpoint = %lf %lf\n", midpoint[0], midpoint[1]);
    printf("Separating line slope = %lf\n", separatingLineSlope);

    // Now, implement the classification and testing logic for test points

    while (1) 
    {
        double testPoint[2];
        printf("Enter a test point (or 'q' to quit): ");

        // Check for unexpected input
        if (scanf("%lf %lf", &testPoint[0], &testPoint[1]) != 2) 
        {
            char input[3];
            scanf("%s", input);
            
            if (input[0] == 'q') 
                break; // Quit if 'q' is entered
            else 
            {
                printf("Unexpected input. Program quits.\n");
                break;
            }
        }

        classifyAndPrint(testPoint, averageClass1, averageClass2);
    }

    return 0;
}
