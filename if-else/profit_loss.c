/* C program to calculate profit or loss */

#include <stdio.h>


int main()
{

    int sell,cost,difference;

    printf("Enter your Cost prince: \n");
    scanf("%d", &cost);
        
    printf("Enter your Sell prince: \n");
    scanf("%d", &sell);


    if (sell>cost)
    {
        difference = sell - cost;
        printf("Your Profit = %d \n",difference);
    }
    
    else if (cost>sell)
    {
        difference = cost - sell;
        printf("Your Loss = %d \n",difference);
    }
    
    else
        printf("No profit No loss \n");
    
          
    
    return 0;
}        