#include <stdio.h>

float calculate_drug_A(int age) 
{
    if (age < 18)
        return 25.00;
    else if (age >= 18 && age < 65)
        return 45.00;
    else
        return 30.00;
}

float calculate_drug_B(int age, float A) 
{
    if (age < 18)
        return 2 * A;
    else if (age >= 18 && age < 65)
        return 5 * A;
    else
        return 3 * A;
}

float calculate_drug_C(int age, float B, float X) 
{
    if (age < 18)
        return 30 + B - 1.5 * X;
    else if (age >= 18 && age < 65)
        return 40 + 2 * B - 3 * X;
    else
        return 35 + B - 2.5 * X;
}

float determine_X(char gender, float A) 
{
    switch (gender) 
    {
        case 'M':
            return A / 2;
        case 'F':
            return A / 3;
        default:
            return 0;
    }
}

int main() 
{
    int age;
    char gender;
    float A, B, C, X;

    printf("Yaşınızı girin: ");
    scanf("%d", &age);
    printf("Cinsiyetinizi girin (M/F): ");
    scanf(" %c", &gender);

    A = calculate_drug_A(age);
    X = determine_X(gender, A);
    B = calculate_drug_B(age, A);
    C = calculate_drug_C(age, B, X);

    printf("İlaç A: %.2f\n", A);
    printf("İlaç B: %.2f\n", B);
    printf("İlaç C: %.2f\n", C);

    return 0;
}