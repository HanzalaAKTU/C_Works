#include <stdio.h>
#include <math.h>

long long factorial(int n)
{
    if(n == 0) 
        return 1;
    
    return n * factorial(n-1);
}

void performOperation(char operator, double operand1, double operand2, char format, int m, int n)
{
    double result;
    switch(operator)
    {
        case '+':
            result = operand1 + operand2;
            break;
        
        case '-':
            result = operand1 - operand2;
            break;
        
        case '*':
            result = operand1 * operand2;
            break;
        
        case '/':
            if(operand2 == 0)
            {
                printf("Error: Division by zero\n");
                return;
            }
            result = operand1 / operand2;
            break;
       
        case '!':
            if(operand1 < 0)
            {
                printf("Error: Factorial of a negative number is undefined\n");
                return;
            }
            
            if(operand1 > 20)
            {
                printf("Error: Factorial of %lf is too large to compute\n", operand1);
                return;
            }
            result = (double)factorial((int)operand1);
            break;
       
        case '^':
            result = pow(operand1, operand2);
            break;
       
        case '%':
            result = fmod(operand1, operand2);
            break;
       
        default:
            printf("Error: Invalid operator\n");
            return;
    }
    
    if(format == 'i')
        printf("%lld\n", (long long)result);
    
    else if(format == 's')
    {
        if(n > m)
            printf("Warning: n is greater than m\n");
        
        int intPart = (int)result;
        int decimalPlaces = m - n;
        int decimalPart = (int)(round((result - intPart) * pow(10, decimalPlaces)));
        int exponent = n - m;
        printf("%0*d.%0*dE%d\n", m, intPart, decimalPlaces, decimalPart, exponent);
    }
    
    else
        printf("Error: Invalid format\n");
    
}

int main()
{
    double operand1, operand2;
    char operator, format;
    int m, n;
    
    printf("\nEnter format of output(S or I): ");
    scanf("%c", &format);

    if(format == 's')
    {
        printf("Enter m and n: ");
        scanf("%d %d", &m, &n);
    }

    printf("\nEnter two operands and operator: ");
    scanf("%lf %lf %c", &operand1, &operand2, &operator);
    
   
    
    performOperation(operator, operand1, operand2, format, m, n);
    return 0;
}
