#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26




void countLetters(char *filename, int *letter_counts) 
{
    FILE *file_ptr;
    char c;

    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) 
    {
        printf("Unable to open file.\n");
        return;
    }

    while ((c = fgetc(file_ptr)) != EOF) 
    {
        if (isalpha(c)) 
        {
            c = tolower(c);
            letter_counts[c - 'a']++;
        }
    }

    fclose(file_ptr);
}

void printTable(int *letter_counts) 
{
    printf("Letter frequency table:\n");
    printf("------------------------\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {
        printf("%c: %d\n", 'a' + i, letter_counts[i]);
    }
}


// Part 1: Letter Frequency Problem
void part1() 
{
    int letter_counts[ALPHABET_SIZE] = {0};
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    countLetters(filename, letter_counts);
    printTable(letter_counts);
}



















// Part 2: Mixing Colors
// Enumeration of colors
enum Color {RED,GREEN,BLUE,YELLOW,ORANGE};

// Length-3 vector for each color
double colors[5][3] = 
{
    {1, 0, 0},    // RED
    {0, 1, 0},    // GREEN
    {0, 0, 1},    // BLUE
    {0.5, 0.5, 0}, // YELLOW
    {0.5, 0.4, 0.2} // ORANGE
};

// Function to calculate Euclidean distance between two colors
double distance(double color1[3], double color2[3]) 
{
    double sum = 0;
    for (int i = 0; i < 3; i++) 
    {
        sum += pow(color1[i] - color2[i], 2);
    }
    return sqrt(sum);
}

// Function to mix two colors
enum Color colorMixer(enum Color c1, enum Color c2) 

{
    double mixedColor[3] = 
    {
        (colors[c1][0] + colors[c2][0]) / 2,
        (colors[c1][1] + colors[c2][1]) / 2,
        (colors[c1][2] + colors[c2][2]) / 2
    };
    
    // Find the closest color to the mixed color
    double closestDistance = distance(mixedColor, colors[0]);
    int closestColor = 0;
    for (int i = 1; i < 5; i++) 
    {
        double d = distance(mixedColor, colors[i]);
        if (d < closestDistance) 
        {
            closestDistance = d;
            closestColor = i;
        }
    }
    
    return closestColor;
}




// Part 3: Tic-Tac-Toe

char board[3][3];

void init_board()
{
    int i, j;
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            board[i][j] = '-';
        }
    }
}

void display_board()
{
    int i, j;
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool check_winner(char player)
{
    int i, j;
    bool win;

    // Check rows
    for (i = 0; i < 3; i++) 
    {
        win = true;
        for (j = 0; j < 3; j++) 
        {
            if (board[i][j] != player) 
            {
                win = false;
                break;
            }
        }
        if (win) 
            return true;
    }

    // Check columns
    for (j = 0; j < 3; j++) 
    {
        win = true;
        for (i = 0; i < 3; i++) 
        {
            if (board[i][j] != player) 
            {
                win = false;
                break;
            }
        }
        if (win) 
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
    {
        return true;
    }

    return false;
}

bool make_move(char player)
{
    int row, col;

    printf("Player %c, enter your move (row [1-3] column [1-3]): ", player);
    scanf("%d %d", &row, &col);

    row--;
    col--;

    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') 
    {
        printf("Invalid move. Please try again.\n");
        return false;
    }

    board[row][col] = player;

    return true;
}

bool game_over()
{
    int i, j;

    // Check if board is full
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            if (board[i][j] == '-') 
                return false;
        }
    }

    return true;
}









void part3() 
{
 char player = 'X';
    bool playing = true;
    char choice;

    while (playing) 
    {
        printf("Welcome to Tic-Tac-Toe!\n");
        init_board();
        while (!game_over()) 
        {
            display_board();
            if (make_move(player)) 
            {
                if (check_winner(player)) 
                {
                    display_board();
                    printf("Player %c wins!\n", player);
                    break;
                }
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        if (!check_winner('X') && !check_winner('O')) 
            printf("It's a draw!\n");

        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &choice);
        
        if (choice == 'n') 
            playing = false;
    }
    printf("Thanks for playing!\n");
 
}

int main() 
{
  part1();
  enum Color c1 = RED, c2 = BLUE;
  enum Color mixedColor = colorMixer(c1, c2);
  printf("Mixed color: %d\n", mixedColor);
  part3();
  return 0;
}
