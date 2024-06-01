#include <stdio.h>

int main()
{

    float weight,size,vki;
    printf("Enter your weight: ");
    scanf("%f",&weight);
    printf("\nEnter your size m: ");
    scanf("%f",&size);

    vki = weight/(size*size);

    printf("Your Body Mass İndex: %f",vki);

    if(vki<18.5)
    {
        printf("\nunderweight\n");
    }

    else if(vki<24.9)    
    {
        printf("\navarage weight\n");
    }
    else if(vki<29.9)    
    {
        printf("\noverweight\n");
    }
    
    else if(vki>30)    
    {
        printf("\nobese\n");
    }

}