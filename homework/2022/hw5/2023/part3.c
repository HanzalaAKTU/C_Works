#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

int main()
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

    return 0;
}