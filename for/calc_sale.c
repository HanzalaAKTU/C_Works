/*
    Calculating Sales
*/

#include <stdio.h>

int main()
{
    int product_number, quantity_sold;
    float total_value = 0.0, price;

    for (;;)
    {
        printf("Enter product number (1-5) or -1 to stop: ");
        scanf("%d", &product_number);

        if (product_number == -1)
            break;

        for (; product_number < 1 || product_number > 5;) 
        {
            printf("Invalid product number. Please enter a valid product number (1-5): ");
            scanf("%d", &product_number);

            if (product_number == -1) 
                break;
        }    
        
        if (product_number == -1) 
            break;

        printf("Enter quantity sold:");
        scanf("%d", &quantity_sold);  

        switch (product_number)
        {
        case 1:
            price = 2.98;
            break;
        case 2:
            price = 4.50;
            break;
        case 3:
            price = 9.98;
            break;
        case 4:
            price = 4.49;
            break;
        case 5:
            price = 6.87;
            break;
        
        default:
            printf("Invalid product number.\n");
            continue;
        }  
        total_value += price * quantity_sold; 
    }
    
    printf("\nTotal retail value of all products sold: $%.2f\n", total_value);

return 0;
}