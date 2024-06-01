#include <stdio.h>

int sum(int i, int end) 
{
    if (i == end)  
        return 0;
    if (i % 3 == 0) 
    {
        return i + sum(i+1, end);
    }
    return sum(i+1, end);
}
    

int main() 
{
    int i,j;
    printf("Type two numbers: ");
    scanf("%d %d", &i, &j);
    
    printf("the sum of the function in the given value range: %d\n", sum(i, j));
}