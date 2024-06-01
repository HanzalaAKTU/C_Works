#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int user_choice, computer_choice; 
    char play_again;
    
    srand(time(NULL));  // Seed the random number generator with current time
    
    do {
        // Get user's choice
        printf("\nPlease make a choice!\n");
        printf("\n1: Stone, 2: Paper, 3: Scissors\n");
        scanf("%d", &user_choice);
        
        // Generate computer's choice
        computer_choice = rand() % 3 + 1;  // Random number between 1 and 3
        
        // Print both choices
        printf("You chose ");
        switch (user_choice) 
        {
            case 1:
                printf("Stone");
                break;
            case 2:
                printf("Paper");
                break;
            case 3:
                printf("Scissors");
                break;
            default:
                printf("invalid option");
                break;
        }
        printf(". I chose ");
        switch (computer_choice) 
        {
            case 1:
                printf("Stone");
                break;
            case 2:
                printf("Paper");
                break;
            case 3:
                printf("Scissors");
                break;
        }
        printf(". ");
        
        // Compare both choices and print the result
        if (user_choice == computer_choice) 
            printf("It's a tie!\n");
         
        else if ((user_choice == 1 && computer_choice == 3) || (user_choice == 2 && computer_choice == 1) || (user_choice == 3 && computer_choice == 2)) 
            printf("You won!\n");
        
        else 
            printf("You lost!\n");
        
        // Ask if user wants to play again
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &play_again);
    } while (play_again == 'Y' || play_again == 'y');
    
    printf("\nThanks for playing!\n");
    return 0;
}