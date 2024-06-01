#include <stdio.h>

int main() 
{
    FILE *fp;
    int n, i, count = 0;
    char team;
    int age[100];
    char occupation[100];
    float salary[100], total_salary = 0, avg_salary;

    // Open the file for reading
    fp = fopen("table.txt", "r");
    if (fp == NULL) 
    {
        printf("Error: File not found!\n");
        return 0;
    }

    // Read the number of rows in the table
    fscanf(fp, "%d", &n);

    // Read each row into the arrays
    for (i = 0; i < n; i++) 
    {
        fscanf(fp, "%d %c %f %*c", &age[i], &occupation[i], &salary[i]);
        if (occupation[i] == ' ') 
            fscanf(fp, "%c", &occupation[i]); // handle the space between salary and favorite team
        
        fscanf(fp, "%c", &occupation[i]); // read the favorite team character
    }

    // Close the file
    fclose(fp);

    // Ask the user to select a team
    printf("Please select a team: ");
    scanf("%c", &team);

    // Calculate the average salary of fans of the selected team
    for (i = 0; i < n; i++) 
    {
        if (occupation[i] == team) 
        {
            total_salary += salary[i];
            count++;
        }
    }

    // Display the result
    if (count == 0) 
        printf("There are no fans of %c in the database!\n", team);
    else {
        avg_salary = total_salary / count;
        printf("Average salaries of fans of %c: %.1f\n", team, avg_salary);
    }

    return 0;
}
