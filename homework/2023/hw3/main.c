#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_LINE_LENGTH 1001
#define MAX_VALUES 100

double evaluatePolynomial(char polynomial[], double x) 
{
    double result = 0.0;
    char *term = strtok(polynomial, "+");

    while (term != NULL) 
    {
        double term_coefficient = 0.0;
        double term_power = 1.0;

        if (strstr(term, "x") != NULL) 
        {
            char *exponent_ptr = strstr(term, "^");
            if (exponent_ptr != NULL) 
            {
                sscanf(term, "%lfx^%lf", &term_coefficient, &term_power);
            } 
            else 
            {
                sscanf(term, "%lfx", &term_coefficient);
                term_power = 1.0; // If no exponent, set power to 1.0
            }
        } 
        else 
        {
            sscanf(term, "%lf", &term_coefficient);
            term_power = 0.0; // If no 'x', set power to 0.0 (constant term)
        }

        result += term_coefficient * pow(x, term_power);
        term = strtok(NULL, "+");
    }

    return result;
}

int main() 
{
    FILE *valuesFile = fopen("values.txt", "r");
    FILE *polynomialsFile = fopen("polynomials.txt", "r");
    FILE *evaluationsFile = fopen("evaluations.txt", "w");

    if (valuesFile == NULL || polynomialsFile == NULL || evaluationsFile == NULL) 
    {
        printf("Error opening files.\n");
        return 1;
    }

    double values[MAX_VALUES];
    int num_values = 0;
    double value;
    char polynomial[MAX_LINE_LENGTH];

    while (fscanf(valuesFile, "%lf", &value) == 1 && num_values < MAX_VALUES) 
    {
        values[num_values++] = value;
    }

    while (fgets(polynomial, MAX_LINE_LENGTH, polynomialsFile) != NULL) 
    {
        for (int i = 0; i < num_values; ++i) 
        {
            double result = evaluatePolynomial(polynomial, values[i]);
            fprintf(evaluationsFile, "%.2lf ", result);
        }
        fprintf(evaluationsFile, "\n");
    }

    fclose(valuesFile);
    fclose(polynomialsFile);
    fclose(evaluationsFile);

    return 0;
}
