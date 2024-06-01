#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define WALL_SIZE_1 3
#define WALL_SIZE_2 5
#define COURSE_1_COUNT 4
#define COURSE_2_COUNT 3
#define TOTAL_COURSES (COURSE_1_COUNT + COURSE_2_COUNT)
#define FIRST_YEAR_ECTS_REQUIRED 32
#define SECOND_YEAR_ECTS_REQUIRED 24

char board[BOARD_SIZE * BOARD_SIZE];
int player_position;
int ects_collected = 0;
int movements = 0;
int courses_remaining = TOTAL_COURSES;

void initialize_game() {
    // Fill the board with empty spaces
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        board[i] = '.';
    }

    // Place walls
    int wall_start_1 = (BOARD_SIZE / 2 - WALL_SIZE_1 / 2) * BOARD_SIZE + BOARD_SIZE / 2 - WALL_SIZE_1 / 2;
    int wall_start_2 = (BOARD_SIZE / 2 - WALL_SIZE_2 / 2) * BOARD_SIZE + BOARD_SIZE / 2 - WALL_SIZE_2 / 2;

    for (int i = 0; i < WALL_SIZE_1; i++) {
        for (int j = 0; j < WALL_SIZE_1; j++) {
            board[(wall_start_1 + i) * BOARD_SIZE + (wall_start_1 + j)] = '#';
        }
    }

    for (int i = 0; i < WALL_SIZE_2; i++) {
        for (int j = 0; j < WALL_SIZE_2; j++) {
            board[(wall_start_2 + i) * BOARD_SIZE + (wall_start_2 + j)] = '#';
        }
    }

    // Place player at center
    player_position = BOARD_SIZE * (BOARD_SIZE / 2) + (BOARD_SIZE / 2);
    board[player_position] = 'P';

    // Place courses randomly
    srand(time(NULL));

    for (int i = 0; i < COURSE_1_COUNT; i++) {
        int pos;
        do {
            pos = rand() % (wall_start_1 - 1);
        } while (board[pos] != '.');
        board[pos] = '1';
    }

    for (int i = 0; i < COURSE_2_COUNT; i++) {
        int pos;
        do {
            pos = rand() % (wall_start_2 - wall_start_1 - 1) + wall_start_1 + WALL_SIZE_1 + 1;
        } while (board[pos] != '.');
        board[pos] = '2';
    }
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char current_cell = board[i * BOARD_SIZE + j];
            if (current_cell == 'P') {
                printf("P ");
            } else if (current_cell == '#') {
                printf("# ");
            } else {
                printf("%c ", current_cell);
            }
        }
        printf("\n");
    }
}


void move_player(char direction) {
    int new_position = player_position;
    switch (direction) {
        case 'w':
            new_position -= BOARD_SIZE;
            break;
        case 's':
            new_position += BOARD_SIZE;
            break;
        case 'a':
            new_position -= 1;
            break;
        case 'd':
            new_position += 1;
            break;
        default:
            printf("Invalid move! Use w (up), s (down), a (left), or d (right).\n");
            return;
    }

    if (new_position < 0 || new_position >= BOARD_SIZE * BOARD_SIZE) {
        printf("Invalid move! You hit the edge of the board.\n");
        return;
    }

    char current_cell = board[new_position];
    if (current_cell == '#') {
        printf("You climbed over the wall!\n");
    } else if (current_cell == '1') {
        ects_collected += 8;
        courses_remaining--;
    } else if (current_cell == '2') {
        if (ects_collected >= FIRST_YEAR_ECTS_REQUIRED) {
            ects_collected += 8;
            courses_remaining--;
        } else {
            printf("You need to collect %d more ECTS to pass through this wall!\n", FIRST_YEAR_ECTS_REQUIRED - ects_collected);
            return;
        }
    }

    board[player_position] = '.';
    board[new_position] = 'P';
    player_position = new_position;
    movements++;

    printf("Current ECTS: %d\n", ects_collected);

    if (courses_remaining == 0) {
        printf("Congratulations! You've collected all courses.\n");
        if (ects_collected >= SECOND_YEAR_ECTS_REQUIRED) {
            printf("You have enough ECTS to pass through the second wall and reach the exit.\n");
            printf("Total ECTS: %d\n", ects_collected);
            printf("Total movements: %d\n", movements);
            exit(0);
        } else {
            printf("You need to collect %d more ECTS to pass through the second wall and reach the exit.\n", SECOND_YEAR_ECTS_REQUIRED - ects_collected);
        }
    }
}

int main() {
    initialize_game();
    printf("Welcome to the ECTS Collection Game!\n");
    printf("Collect 1s and 2s to accumulate ECTS and pass through walls.\n");
    printf("Avoid hitting the walls and make sure to collect enough ECTS.\n");
    printf("Good luck!\n");

    while (1) {
        print_board();
        char direction;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &direction);
        move_player(direction);
    }

    return 0;
}
