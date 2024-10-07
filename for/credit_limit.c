/*
   Calculating Credit Limits
 */

#include <stdio.h>

int main() 
{
    int account_number;
    float old_credit_limit, current_balance, new_credit_limit;

    // Loop for 3 customers
    for (int i = 1; i <= 3; i++) 
    {
        // Input data for the customer
        printf("Enter account number for customer %d: ", i);
        scanf("%d", &account_number);

        printf("Enter old credit limit for customer %d: ", i);
        scanf("%f", &old_credit_limit);

        printf("Enter current balance for customer %d: ", i);
        scanf("%f", &current_balance);

        // Calculate the new credit limit (half of the old limit)
        new_credit_limit = old_credit_limit / 2;

        // Print the customer's data
        printf("\nCustomer %d\n", account_number);
        printf("Old credit limit: $%.2f\n", old_credit_limit);
        printf("New credit limit: $%.2f\n", new_credit_limit);
        printf("Current balance: $%.2f\n", current_balance);

        // Check if the current balance exceeds the new credit limit
        if (current_balance > new_credit_limit) 
            printf("Warning: Balance exceeds new credit limit!\n");
        
        else 
            printf("Balance is within the new credit limit.\n");
        
        printf("\n");
    }

    return 0;
}
