#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STUDENTS 10000

// Student structure definition
struct Student {
    int ID;
    int age;
    float gpa;
};

// Function to generate an array of Student structures
struct Student* generateStudentArray() 
{
    struct Student* students = (struct Student*)malloc(NUM_STUDENTS * sizeof(struct Student));

    // Generate random values for each student
    for (int i = 0; i < NUM_STUDENTS; i++) 
    {
        students[i].ID = i + 1;
        students[i].age = rand() % 30 + 18;      // Random age between 18 and 47
        students[i].gpa = (float)(rand() % 41) / 10.0;  // Random GPA between 0.0 and 4.0
    }

    return students;
}

// Function to calculate the average GPA
float calculateAverageGPA(struct Student* students) 
{
    float sum = 0.0;

    for (int i = 0; i < NUM_STUDENTS; i++) 
    {
        sum += students[i].gpa;
    }

    return sum / NUM_STUDENTS;
}

int main() 
{
    srand(time(NULL));  // Seed the random number generator

    float totalAverageGPA = 0.0;

    for (int i = 0; i < NUM_STUDENTS; i++) 
    {
        struct Student* students = generateStudentArray();
        float averageGPA = calculateAverageGPA(students);
        totalAverageGPA += averageGPA;

        free(students);  // Deallocate memory for the student array
    }

    float finalAverageGPA = totalAverageGPA / NUM_STUDENTS;

    printf("Average GPA of 10,000 x 10,000 students: %.8f\n", finalAverageGPA);

    return 0;
}
