#include <stdio.h>
#include <math.h>

float convert_celsius_to_fahrenheit(float celsius) 
{
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

float convert_fahrenheit_to_celsius(float fahrenheit) 
{
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

void display_menu() 
{
    printf("Please choose an option:\n");
    printf("a) Convert Celsius to Fahrenheit\n");
    printf("b) Convert Fahrenheit to Celsius\n");
    printf("c) Quit\n");
}

char get_menu_choice() 
{
    char choice;
    printf("\nEnter your choice: ");
    scanf(" %c", &choice);
    while (choice != 'a' && choice != 'b' && choice != 'c') 
    {
        printf("\nInvalid choice. \nPlease enter a, b, or c: ");
        scanf(" %c", &choice);
    }
    return choice;
}

int main() 
{
    char choice;
    float temperature, converted_temp;
    while (1) 
    {
        display_menu();
        choice = get_menu_choice();
        switch (choice) 
        {
            case 'a':
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &temperature);
                converted_temp = convert_celsius_to_fahrenheit(temperature);
                printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n\n", temperature, converted_temp);
                break;
            case 'b':
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                converted_temp = convert_fahrenheit_to_celsius(temperature);
                printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", temperature, converted_temp);
                break;
            case 'c':
                printf("\nExiting program...\n");
                return 0;
            default:
                break;
        }
    }
}