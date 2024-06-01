#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void draw_room(int size, int pos_x, int pos_y, int door_x, int door_y);
int is_game_over(int pos_x, int pos_y, int door_x, int door_y);
void game(int size);
void help();

void draw_room(int size, int pos_x, int pos_y, int door_x, int door_y) {
    // Draw the room with size and positions of character and door
    // Use loops and conditions to print each character at the correct location
    // Example:
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == pos_y && j == pos_x) {
                printf("C");
            } else if (i == door_y && j == door_x) {
                printf("D");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int is_game_over(int pos_x, int pos_y, int door_x, int door_y) {
    // Check if the game is over by comparing the positions of character and door
    if (pos_x == door_x && pos_y == door_y) {
        return 1;
    } else {
        return 0;
    }
}

void game(int size) {
    // Start a new game with specified size
    int pos_x = rand() % size;
    int pos_y = rand() % size;
    int door_x = rand() % size;
    int door_y = rand() % size;

    draw_room(size, pos_x, pos_y, door_x, door_y);
    int move_count = 0;
    while (!is_game_over(pos_x, pos_y, door_x, door_y)) {
        // Prompt user for move
        printf("Enter a move (w, a, s, d): ");
        char move;
        scanf(" %c", &move);

        // Update character position based on move
        switch (move) {
            case UP:
                if (pos_y > 0) {
                    pos_y--;
                } else {
                    printf("Cannot move up\n");
                }
                break;
            case DOWN:
                if (pos_y < size - 1) {
                    pos_y++;
                } else {
                    printf("Cannot move down\n");
                }
                break;
            case LEFT:
                if (pos_x > 0) {
                    pos_x--;
                } else {
                    printf("Cannot move left\n");
                }
                break;
            case RIGHT:
                if (pos_x < size - 1) {
                    pos_x++;
                } else {
                    printf("Cannot move right\n");
                }
                break;
            default:
                printf("Invalid move\n");
                break;
        }

        move_count++;
        draw_room(size, pos_x, pos_y, door_x, door_y);
    }

    printf("Congratulations! You have reached the door in %d moves.\n", move_count);
}

void help() {
    // Print the game's instructions and rules
    printf("Instructions:\n");
    printf("The objective of the game is to reach the door by moving the character using the following keys:\n");
    printf("w - move up\na - move left\ns - move down\nd - move right\n");
    printf("The game ends when the character reaches the door.\n");
    printf("Good luck!\n");
}

int main() {
    int room_size, character_x, character_y, door_x, door_y;
    char move;

    while (1) {
        int choice = menu();

        if (choice == 1) {
            printf("Enter room size (5-10): ");
            scanf("%d", &room_size);

            if (room_size < 5 || room_size > 10) {
                printf("Invalid room size! Please enter a number between 5 and 10.\n");
                continue;
            }

            init_room(room_size, &character_x, &character_y, &door_x, &door_y);
            draw_room(room_size, character_x, character_y, door_x, door_y);

            int moves = 0;
            while (1) {
                printf("Enter move (w/a/s/d): ");
                scanf(" %c", &move);

                if (move != 'w' && move != 'a' && move != 's' && move != 'd') {
                    printf("Invalid move! Please enter a valid move.\n");
                    continue;
                }

                int prev_character_x = character_x;
                int prev_character_y = character_y;

                if (move == 'w') {
                    character_x--;
                } else if (move == 'a') {
                    character_y--;
                } else if (move == 's') {
                    character_x++;
                } else if (move == 'd') {
                    character_y++;
                }

                if (is_valid_move(room_size, character_x, character_y)) {
                    moves++;
                    draw_room(room_size, character_x, character_y, door_x, door_y);
                    if (check_game_over(character_x, character_y, door_x, door_y)) {
                        printf("Congratulations! You have reached the door in %d moves.\n", moves);
                        break;
                    }
                } else {
                    printf("Invalid move! You cannot move through walls.\n");
                    character_x = prev_character_x;
                    character_y = prev_character_y;
                }
            }

        } else if (choice == 2) {
            help();
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}
