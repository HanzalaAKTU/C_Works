#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int target, guess, guessCount = 0;
    srand(time(0)); 
    target = rand() % 1000 + 1; 

    printf("target: %d\n",target);

    printf("Welcome to the guessing game!\n");
    printf("Guess the number between 1 and 1000.\n");

    while (1) 
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guessCount++;

        if (guess<1 || guess>1000)
            printf("Please enter a number between 1 and 1000.\n");
        
        else if (guess < target) 
            printf("Too low! Try again.\n");
       
        else if (guess > target) 
            printf("Too high! Try again.\n");
        
        else 
        {
            printf("Congratulations! You guessed the correct number %d in %d guesses!\n", target, guessCount);
            break; 
        }
    }

    return 0;
}