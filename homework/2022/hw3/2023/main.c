#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ROOM_SIZE 5
#define MAX_ROOM_SIZE 10

// Function prototypes
void draw_room(int room_size, int pos_x, int pos_y, int door_x, int door_y);
void clear_screen();
int get_new_position(int current_pos, int room_size);
int is_gameover(int character_x, int character_y, int door_x, int door_y);

int main() 
{
    srand(time(NULL)); // Seed random number generator

    int room_size,character_pos,door_pos,moves;
    int character_x, character_y, door_x, door_y;
    int c_pos_x, c_pos_y, d_pos_x, d_pos_y;

    while (1) 
    {
        // Show menu and get user choice
        printf("== Puzzle Game ==\n");
        printf("1. New Game\n");
        printf("2. Help\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: // New game
                // Get room size from user
                printf("Enter room size (between %d and %d): ", MIN_ROOM_SIZE, MAX_ROOM_SIZE);
                scanf("%d", &room_size);
                
                if (room_size < MIN_ROOM_SIZE || room_size > MAX_ROOM_SIZE) 
                {
                    printf("Invalid room size!\n");
                    break;
                }

                // Randomly assign character and door positions
                character_pos = rand() % (room_size * room_size);
                do 
                {
                    door_pos = rand() % (room_size * room_size);
                } 
                while (door_pos == character_pos);

                moves = 0;

                while (1) 
                {
                    // Draw current state of room
                    clear_screen();
                    draw_room(room_size, c_pos_x, c_pos_y, d_pos_x, d_pos_y);

                    // Get user move
                    printf("Enter move (w=up, s=down, a=left, d=right): ");
                    
                    char move;
                    scanf(" %c", &move);

                    // Move character
                    int new_pos = get_new_position(character_pos, room_size);

                    if (new_pos < 0 || new_pos >= room_size * room_size) 
                        printf("Cannot move through walls!\n");
                    
                    else 
                    {
                        character_pos = new_pos;
                        moves++;
                    }

                    // Check if game is over
                    if (is_gameover(character_x, character_y, door_x, door_y)) 
                    {
                        clear_screen();
                        draw_room(room_size, c_pos_x, c_pos_y, d_pos_x, d_pos_y);
                        
                        printf("Congratulations, you have reached the door!\n");
                        printf("You completed the game in %d moves.\n", moves);
                        break;
                    }
                }
                break;
            
            case 2: // Help
                printf("Instructions:\n");
                printf("The objective of the game is to free the character by leading them to the door.\n");
                printf("The character is able to move one space in any of the four cardinal directions: up, down, left, and right.\n");
                printf("Use the following keys to move: 'a' for left, 'd' for right, 'w' for up, and 's' for down.\n");
                printf("The game is over when the character reaches the door.\n");
                break;
            
            case 3: // Exit
                printf("Goodbye!\n");
                return 0;
            
            default: // Invalid choice
                printf("Invalid choice!\n");
                break;
        }
    }
}

void draw_room(int room_size, int pos_x, int pos_y, int door_x, int door_y) 
{    
    int i,j;

    // Draw the room
    
    for (i = 0; i < room_size; i++) 
    {
        printf("-");
    }
    printf("\n");
    
    for (i = 0; i < room_size; i++) 
    {
        printf("|");
        for (j = 0; j < room_size; j++) 
        {
            if (i == pos_y && j == pos_x) 
                printf("C");
            
            else if (i == door_y && j == door_x) 
                printf("D");
            
            else 
                printf(" ");
            
        }
        printf("|\n");
    }
    
    
    for (i = 0; i < room_size; i++) 
    {
        printf("-");
    }
    printf("\n");
}

void clear_screen()
{
    printf("\033[2J\033[1;1H");
}

int get_new_position(int current_pos, int room_size) 
{
    int row = current_pos / room_size;
    int col = current_pos % room_size;
    int new_row = row;
    int new_col = col;
    char direction;

    switch(direction) 
    {
        case 'a': // move left
            new_col = col - 1;
            break;
        case 'd': // move right
            new_col = col + 1;
            break;
        case 'w': // move up
            new_row = row - 1;
            break;
        case 's': // move down
            new_row = row + 1;
            break;
        default: // invalid input
            return current_pos;
    }

    // check if the new position is out of bounds
    if (new_row < 0 || new_row >= room_size || new_col < 0 || new_col >= room_size) 
    {
        return current_pos;
    }

    // calculate the new position based on the new row and column
    int new_pos = new_row * room_size + new_col;
    return new_pos;
}

int is_gameover(int character_x, int character_y, int door_x, int door_y) 
{
    if (character_x == door_x && character_y == door_y) 
        return 1;
    
    return 0;
}