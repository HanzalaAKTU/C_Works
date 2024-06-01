#include <stdio.h>
#include <math.h>

int leap_year(int year);
int grade_calc(int exam1, int exam2, int exam3, int ass1, int ass2);
void enhanced(char operator, double operand1, double operand2, char format, int m, int n);

long long factorial(int n)
{
    if(n == 0) 
        return 1;
    
    return n * factorial(n-1);
}

int main()
{
    int year;

    double operand1, operand2;
    char operator, format;
    int m, n;

    int exam1,exam2,exam3;
    int ass1, ass2;
    
    printf("***------*** Part1 = Leap Year ***------***\n\n");

    printf("Please enter a year:  ");
    scanf("%d",&year);
    leap_year(year);


    printf("\n\n***------*** Part2 = Enhanced Calculator ***------***\n\n");
    
    printf("Enter the format of output (S or I):");
    scanf("%c",&format);

    if(format == 's')
    {
        printf("Enter m and n: ");
        scanf("%d %d", &m, &n);
    }
   
    printf("\nEnter two operands and operator: ");
    scanf("%lf %lf %c", &operand1, &operand2, &operator);

    enhanced(operator, operand1, operand2, format, m, n);


    printf("\n\n***------*** Part3 = Grade Calculator ***------***\n\n");

    printf("\nEnter 3 exam grades of student: ");
    scanf("%d %d %d",&exam1, &exam2, &exam3);
    
    printf("\nEnter 2 assigment grades of student: ");
    scanf("%d %d",&ass1, &ass2);

    grade_calc(exam1,exam2,exam3,ass1,ass2);
    
return 0;
}

int leap_year(int year)
{
    int leap_year = year%4;
    if (leap_year == 0)
        printf("\n %d is a leap year\n",year);
    
    else 
        printf("\n %d is not a leap year\n",year);
    
    return year;
}

void enhanced(char operator, double operand1, double operand2, char format, int m, int n)
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
                printf("Error: Division by zero\n");
                        
            result = operand1 / operand2;
            break;
       
        case '!':
            if(operand1 < 0)
                printf("Error: Factorial of a negative number is undefined\n");
            
            if(operand1 > 20)
                printf("Error: Factorial of %lf is too large to compute\n", operand1);
            
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

int grade_calc(int exam1, int exam2, int exam3, int ass1, int ass2)
{
    float final;
    final = (exam1+exam2+exam3)/3*0.6+(ass1+ass2)/2*0.4;

    if (final<60)
        printf("\nFinal Grade: %.2f Failed!\n",final);

    else
        printf("\nFinal Grade: %.2f Passed\n",final);   
    
return final;
}