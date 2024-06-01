#include <stdio.h>

int main() 
{
    char operator;
    int num1, num2, result;

    printf("Please enter an arithmetic operation (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Please enter two integers: ");
    scanf("%d %d", &num1, &num2);

    switch (operator) 
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator. Please try again.\n");
            return 0;
    }

    printf("The result is %d.\n", result);

    if (result == (num1 + num2) && operator == '+') 
       printf("Bravo, correct answer!\n");
     
    else if (result == (num1 - num2) && operator == '-') 
        printf("Bravo, correct answer!\n");
    
    else if (result == (num1 * num2) && operator == '*') 
        printf("Bravo, correct answer!\n");
    
    else if (result == (num1 / num2) && operator == '/') 
        printf("Bravo, correct answer!\n");
    
    else 
        printf("Wrong answer, try again.\n");
    

    return 0;
}