#include <stdio.h>
#include <math.h>

struct third_order_polynomial 
{
    double a3, a2, a1, a0;
};

struct polynomial 
{
    double a3, a2, a1, a0;
    double value;
    char constant;
};

double calculate_third_order_polynomial(struct third_order_polynomial p, double x) 
{
    return p.a3 * pow(x, 3) + p.a2 * pow(x, 2) + p.a1 * x + p.a0;
}

double calculate_polynomial(struct polynomial p, double x) 
{
    return p.a3 * pow(x, 3) + p.a2 * pow(x, 2) + p.a1 * x + p.a0;
}

struct polynomial get_integral(struct third_order_polynomial p1, struct third_order_polynomial p2, int a, int b) 
{
    struct polynomial result;

    result.a3 = (p1.a3 * p2.a3) / 4;
    result.a2 = (p1.a3 * p2.a2 + p1.a2 * p2.a3) / 3;
    result.a1 = (p1.a3 * p2.a1 + p1.a2 * p2.a2 + p1.a1 * p2.a3) / 2;
    result.a0 = (p1.a3 * p2.a0 + p1.a2 * p2.a1 + p1.a1 * p2.a2 + p1.a0 * p2.a3) / 1;
    result.constant = 'C';

    double integral_a = (result.a3 * pow(a, 4) / 4) + (result.a2 * pow(a, 3) / 3) + (result.a1 * pow(a, 2) / 2) + (result.a0 * a);
    double integral_b = (result.a3 * pow(b, 4) / 4) + (result.a2 * pow(b, 3) / 3) + (result.a1 * pow(b, 2) / 2) + (result.a0 * b);
    result.value = integral_b - integral_a;

    return result;
}

int main() 
{
    struct third_order_polynomial p1, p2;
    int a, b;

    printf("Enter coefficients for the first polynomial (a3 a2 a1 a0): ");
    scanf("%lf %lf %lf %lf", &p1.a3, &p1.a2, &p1.a1, &p1.a0);

    printf("Enter coefficients for the second polynomial (a3 a2 a1 a0): ");
    scanf("%lf %lf %lf %lf", &p2.a3, &p2.a2, &p2.a1, &p2.a0);

    printf("Enter interval values (a b): ");
    scanf("%d %d", &a, &b);

    struct polynomial result = get_integral(p1, p2, a, b);

    printf("Integrated polynomial coefficients: %.2lfx^3 + %.2lfx^2 + %.2lfx + %.2lf%c\n", result.a3, result.a2, result.a1, result.a0, result.constant);
    printf("Integrated polynomial value between [%d, %d]: %.2lf\n", a, b, result.value);

    return 0;
}
