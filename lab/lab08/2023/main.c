#include <stdio.h>

typedef struct 
{
    double matrix[3][3];
    double determinant;
} matrix;

void print_matrix(matrix initial_matrix) 
{
    printf("\nMatrix:\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%8.4lf ", initial_matrix.matrix[i][j]);
        }
        printf("\n");
    }
}

void determinant_of_matrix(matrix* initial_matrix) 
{
    double a = initial_matrix->matrix[0][0];
    double b = initial_matrix->matrix[0][1];
    double c = initial_matrix->matrix[0][2];
    double d = initial_matrix->matrix[1][0];
    double e = initial_matrix->matrix[1][1];
    double f = initial_matrix->matrix[1][2];
    double g = initial_matrix->matrix[2][0];
    double h = initial_matrix->matrix[2][1];
    double i = initial_matrix->matrix[2][2];
    
    double det = a * (e*i - f*h) - b * (d*i - f*g) + c * (d*h - e*g);
    initial_matrix->determinant = det;
}

void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix) 
{
    determinant_of_matrix(initial_matrix);
    double det = initial_matrix->determinant;
    
    if (det == 0) 
    {
        printf("\nError: Matrix is not invertible!\n");
        return;
    }
    
    double a = initial_matrix->matrix[0][0];
    double b = initial_matrix->matrix[0][1];
    double c = initial_matrix->matrix[0][2];
    double d = initial_matrix->matrix[1][0];
    double e = initial_matrix->matrix[1][1];
    double f = initial_matrix->matrix[1][2];
    double g = initial_matrix->matrix[2][0];
    double h = initial_matrix->matrix[2][1];
    double i = initial_matrix->matrix[2][2];
    
    inverted_matrix->matrix[0][0] = (e*i - f*h) / det;
    inverted_matrix->matrix[0][1] = -(b*i - c*h) / det;
    inverted_matrix->matrix[0][2] = (b*f - c*e) / det;
    inverted_matrix->matrix[1][0] = -(d*i - f*g) / det;
    inverted_matrix->matrix[1][1] = (a*i - c*g) / det;
    inverted_matrix->matrix[1][2] = -(a*f - c*d) / det;
    inverted_matrix->matrix[2][0] = (d*h - e*g) / det;
    inverted_matrix->matrix[2][1] = -(a*h - b*g) / det;
    inverted_matrix->matrix[2][2] = (a*e - b*d) / det;
    inverted_matrix->determinant = det;
}

int main() 
{
    matrix m = { {{1.0000, 0.9134, 0.2785}, {0.9058, 0.6324, 0.5469}, {0.1270, 0.0975, 0.9575}}, 0 };
    matrix inv_m = { {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0 };
    
    print_matrix(m);

    inverse_matrix(&m, &inv_m);

    printf("\nInverse Matrix:\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%8.4lf ", inv_m.matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nDeterminant of the initial matrix: %lf\n", m.determinant);
    printf("Determinant of the inverted matrix: %lf\n", inv_m.determinant);

    return 0;
}