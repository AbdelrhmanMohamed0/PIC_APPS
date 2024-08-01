#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "english_words.h" // Assumes a header file 'english_words.h' that contains an array of words
#include <time.h>

// Function declarations
int check_index_of_character(char character, int index);
int searchWord(char *statement, char *word);

// Main function
int main(void)
{
    int trials = 10; // Number of allowed guesses
    int flag = 0; // Flag to check if the word is guessed correctly
    char array[20]; // Array to store the guessed characters
    char character; // Variable to store the user's guess
    srand(time(NULL)); // Seed for random number generation

    // Initialize the array with dashes
    for (int i = 0; i < 20; i++)
    {
        array[i] = '-';
    }

    // Generate a random number to select a word from the englishWords array
    int random_number = rand() % 100;
    int len = strlen(englishWords[random_number]); // Length of the chosen word
    printf("your trials is %d \n", trials); // Inform the user of the number of trials

    // Print dashes for each letter in the word
    for (int i = 0; i < len; i++)
    {
        printf("- ");
    }

    // Game loop
    while (trials != 0)
    {
        printf("\n please enter character \n");
        fflush(stdin); // Clear the input buffer
        fflush(stdout); // Clear the output buffer
        scanf("%c", &character); // Read a character from the user
        fflush(stdin); // Clear the input buffer again
        fflush(stdout); // Clear the output buffer again

        // Check if the guessed character is in the word
        int num = check_index_of_character(character, random_number);
        if (num != -1) // If the character is found
        {
            array[num] = character; // Update the array with the guessed character
            for (int i = 0; i < len; i++) // Print the current state of the array
            {
                printf("%c", array[i]);
            }
            if (searchWord(array, (char *)englishWords[random_number])) // Check if the word is fully guessed
            {
                flag = 1; // Set the flag to indicate a win
                break; // Exit the loop
            }
        }
        else // If the character is not found
        {
            printf("your trials is %d \n", --trials); // Decrement trials and inform the user
        }
    }

    // Check the result of the game
    if (flag)
    {
        printf("\n WIIIIIN\n"); // Inform the user of a win
    }
    else
    {
        printf("\n Man is Executed \n"); // Inform the user of a loss
    }
    return 0; // End of the program
}

// Function to check the index of a character in the chosen word
int check_index_of_character(char character, int index)
{
    static int count_character_repeat[26] = {0}; // Array to keep track of character occurrences
    int counter = 0; // Counter for the number of times a character appears
    for (int i = 0; i < strlen(englishWords[index]); i++) // Iterate through the word
    {
        if (englishWords[index][i] == character) // If the character matches
        {
            if (count_character_repeat[character - 'a'] == counter) // Check if it's the nth occurrence
            {
                count_character_repeat[character - 'a']++; // Increment the occurrence count
                return i; // Return the index of the character
            }
            counter++; // Increment the counter
        }
    }
    return -1; // Return -1 if the character is not found
}

// Function to search for a word in a given statement
int searchWord(char *statement, char *word)
{
    char *ptr = strstr(statement, word); // Search for the word in the statement

    if (ptr != NULL) // If the word is found
    {
        return 1; // Return 1
    }
    else // If the word is not found
    {
        return 0; // Return 0
    }
}
