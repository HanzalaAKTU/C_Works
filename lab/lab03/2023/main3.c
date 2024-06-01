#include <stdio.h>

int calc(char m, int k, int l) 
{
    int r;

    switch (m) 
    {
        case '+':
            r = k + l;
            break;
        case '-':
            r = k - l;
            break;
        case '*':
            r = k * l;
            break;
        case '/':
            r = k / l;
            break;
        default:
            printf("Invalid operator. Please try again.\n");
            return -1;
    }

    return r;
}

int main() 
{
    char m;
    int k, l, r;

    printf("Please enter an arithmetic operation (+, -, *, /): ");
    scanf("%c", &m);

    printf("Please enter two integers: ");
    scanf("%d %d", &k, &l);

    r = calc(m, k, l);

    if (r != -1) 
    {
        printf("The result is %d.\n", r);

        if (r == (k + l) && m == '+') 
            printf("Bravo, correct answer!\n");
         
        else if (r == (k - l) && m == '-')       
            printf("Bravo, correct answer!\n");
         
        else if (r == (k * l) && m == '*') 
            printf("Bravo, correct answer!\n");
         
        else if (r == (k / l) && m == '/') 
            printf("Bravo, correct answer!\n");
         
        else 
            printf("Wrong answer, try again.\n");
    }

    return 0;
}
