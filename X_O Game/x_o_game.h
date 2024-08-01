// Header guards to prevent double inclusion of the header file
#ifndef X_O_GAME_H_
#define X_O_GAME_H_

// Define the number of columns and rows for the Tic Tac Toe game
#define COLS 3
#define ROWS 3

// Declare the game board array and a flag array to track played positions
char Game[ROWS][COLS];
char array_flag[10];
int draw = 0; // Variable to track the number of draws

// Function prototypes for initializing and starting the game, displaying the board, playing a move, and checking for a winner or draw
void init(char Game[ROWS][COLS]);
void Start_Game(char Game[ROWS][COLS]);
void display(char Game[ROWS][COLS]);
char check_board_for_winner(char Game[ROWS][COLS]);
void play(char Game[ROWS][COLS], char symbol, int index);
char check_draw_won(void);

// End of header guard
#endif