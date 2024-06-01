#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VALUES 100
#define MAX_POLY_LENGTH 1001 // 1000 characters + 1 for null terminator
#define MAX_POLY_DEGREE 10

double evaluatePolynomial(double coefficients[], int degree, double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * pow(x, i); // Degree starts from 0
    }
    return result;
}

int main() {
    FILE *valuesFile, *polynomialsFile, *evaluationsFile;
    valuesFile = fopen("values.txt", "r");
    polynomialsFile = fopen("polynomials.txt", "r");
    evaluationsFile = fopen("evaluations.txt", "w");

    if (valuesFile == NULL || polynomialsFile == NULL || evaluationsFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    double values[MAX_VALUES];
    double coefficients[MAX_POLY_DEGREE + 1]; // coefficients for the polynomial

    char polynomial[MAX_POLY_LENGTH];
    int degree;

    // Read values from values.txt
    int numValues = 0;
    while (numValues < MAX_VALUES && fscanf(valuesFile, "%lf", &values[numValues]) == 1) {
        numValues++;
    }

    if (numValues == 0) {
        printf("No valid values found in values.txt\n");
        return 1;
    }

    fseek(valuesFile, 0, SEEK_SET); // Reset values file pointer to the beginning

    while (fgets(polynomial, MAX_POLY_LENGTH, polynomialsFile) != NULL) {
        // Remove the newline character if it exists
        size_t len = strlen(polynomial);
        if (polynomial[len - 1] == '\n') {
            polynomial[len - 1] = '\0';
        }

        // Extract coefficients and degree from the polynomial string
        memset(coefficients, 0, sizeof(coefficients)); // Reset coefficients
        degree = -1;

        char *token = strtok(polynomial, "+");
        while (token != NULL) {
            int coeff = 1; // Default coefficient is 1 if not specified
            int power = 0;
            if (strstr(token, "x") != NULL) {
                if (token[0] != 'x') {
                    sscanf(token, "%dx^%d", &coeff, &power);
                } else {
                    sscanf(token, "x^%d", &power);
                }
            }
            coefficients[power] = coeff;
            if (power > degree) {
                degree = power;
            }
            token = strtok(NULL, "+");
        }

        // Evaluate polynomials for each value and write results to evaluations.txt
        for (int i = 0; i < numValues; ++i) {
            double result = evaluatePolynomial(coefficients, degree, values[i]);
            fprintf(evaluationsFile, "%.2f ", result);
        }
        fprintf(evaluationsFile, "\n");
    }

    fclose(valuesFile);
    fclose(polynomialsFile);
    fclose(evaluationsFile);

    return 0;
}
