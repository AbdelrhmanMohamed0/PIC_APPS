// Include standard input/output library and the game header file
#include <stdio.h>
#include <stdlib.h>
#include "x_o_game.h"

// Main function where the game loop runs
int main(void)
{
    // Game loop runs until there are two draws
    while (draw < 2)
    {
        init(Game);       // Initialize the game board
        printf("********************************************\n");
        Start_Game(Game); // Start a new game
    }
    return 0; // End of the program
}

// Function to initialize the game board with numbers 1-9
void init(char Game[ROWS][COLS])
{
    // Nested loops to assign numbers to each cell of the game board
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            Game[i][j] = '1' + i * COLS + j;
        }
    }
    // Initialize the flag array to track played positions
    for (int i = 0; i < 10; i++)
    {
        array_flag[i] = 0;
    }
}

// Function to start the game and handle the game loop
void Start_Game(char Game[ROWS][COLS])
{
    // Initialize game variables
    char symbol = 'X'; // Starting player symbol
    int index;         // Index for player's move
    char winner = 255; // ASCII value of -1, used to indicate no winner yet
    int moves = 0;     // Counter for the number of moves played
    char flag = 0;     // Flag to indicate invalid move

    // Game loop runs until there's a winner or the board is full
    while (winner == (char)255 && moves < 9)
    {
        display(Game); // Display the game board
        printf("Player %c, enter the index where you want to play: \n", symbol);
        scanf("%d", &index); // Get player's move
        // Check for valid index
        if (index < 1 || index > 9)
        {
            printf("Invalid index. Try again.\n");
            flag = 1;
            continue; // Skip the rest of the loop and ask for input again
        }
        flag = 0;                              // Reset flag for next iteration
        play(Game, symbol, index);             // Play the move
        winner = check_board_for_winner(Game); // Check for a winner
        if (winner != (char)255)
            break; // Exit loop if there's a winner
        // Switch player symbol if the move was valid
        if (flag == 0)
            symbol = (symbol == 'X') ? 'O' : 'X';
        moves++; // Increment move counter
    }
    // Check for a winner or draw after the game loop ends
    winner = check_board_for_winner(Game);
    display(Game); // Display the final game board
    // Announce the winner or declare a draw
    if (winner != (char)255)
    {
        printf("Player %c won!\n", winner);
    }
    else
    {
        draw++; // Increment draw counter
        winner = check_draw_won(); // Check if the game is a draw
        printf("It's a draw!\n");
        printf("Player %c won!\n", winner);
    }
}

// Function to display the game board
void display(char Game[ROWS][COLS])
{
    // Loop through each row and column to print the game board
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c\t", Game[i][j]); // Print each cell with a tab space
        }
        printf("\n"); // New line after each row
    }
}

// Function to play a move on the game board
void play(char Game[ROWS][COLS], char symbol, int index)
{
    // Calculate row and column from the index
    int row = (index - 1) / COLS;
    int col = (index - 1) % COLS;
    // Check if the chosen spot is available
    if (array_flag[index] == 0 && Game[row][col] >= '1' && Game[row][col] <= '9')
    {
        Game[row][col] = symbol; // Place the player's symbol on the board
        array_flag[index] = 1;   // Mark the spot as played
    }
    else
    {
        printf("This spot is already taken or invalid. Try another place.\n");
    }
}

// Function to check the game board for a winner
char check_board_for_winner(char Game[ROWS][COLS])
{
    // Check each row and column for matching symbols
    for (int i = 0; i < ROWS; i++)
    {
        if (Game[i][0] == Game[i][1] && Game[i][1] == Game[i][2])
            return Game[i][0]; // Return the winning symbol
        if (Game[0][i] == Game[1][i] && Game[1][i] == Game[2][i])
            return Game[0][i];
    }
    // Check diagonals for matching symbols
    if (Game[0][0] == Game[1][1] && Game[1][1] == Game[2][2])
        return Game[0][0];
    if (Game[0][2] == Game[1][1] && Game[1][1] == Game[2][0])
        return Game[0][2];
    return 255; // Return 255 if there's no winner
}

// Function to check for a draw
char check_draw_won(void)
{
    // Return the symbol of the player who won by draw or 'D' for a draw
    if (draw == 1)
    {
        return 'o';
    }
    else if (draw == 2)
    {
        return 'x';
    }
    else
    {
        return 'D'; // Return 'D' for draw
    }
}
