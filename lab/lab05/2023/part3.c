#include <stdio.h>
#include <math.h>

// Function to convert a number to binary
int convert_to_binary(int num) 
{
    int binary = 0, digit, place = 1;
    while (num != 0) 
    {
        digit = num % 2;
        binary += digit * place;
        num /= 2;
        place *= 10;
    }
    return binary;
}

// Function to convert a number to octal
int convert_to_octal(int num) 
{
    int octal = 0, digit, place = 1;
    while (num != 0) 
    {
        digit = num % 8;
        octal += digit * place;
        num /= 8;
        place *= 10;
    }
    return octal;
}

// Function to convert a number to hexadecimal


int main() 
{
    int choice, num;

    do 
    {
        printf("\nMenu:\n");
        printf("1. Convert a number to decimal, binary, octal, and hexadecimal\n");
        printf("2. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                printf("Decimal equivalent: %d\n", num);
                printf("Binary equivalent: %d\n", convert_to_binary(num));
                printf("Octal equivalent: %d\n", convert_to_octal(num));
                printf("Hexadecimal equivalent: %x\n",num);
                break;
            case 2:
                printf("Goodbye!\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}
