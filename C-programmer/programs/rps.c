#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void) {


    char player1, player2; // variables to store choices from both players

    char bot;

    char gamemode[10];

    // seed random generator
    srand(time(NULL));

    printf("Welcome to Rock Paper Scissors! \n");
    printf("Choose a gamemode: \n");
    printf("1. PVP \n");
    printf("2. PVE \n");
    
    scanf(" %9s", gamemode);



    if (strcmp(gamemode, "PVP") == 0 || strcmp(gamemode, "1") == 0){

    // Loop until player 1 gives a valid input (r, p, or s)
     do {
        printf("Player 1 choose (r = rock, p = paper, s = scissor):\n");
        scanf(" %c", &player1);

        // If the input is not valid, show an error message
        if (player1 != 'r' && player1 != 'p' && player1 != 's') {
            printf("Wrong input! Try again.\n");
        }
    } while (player1 != 'r' && player1 != 'p' && player1 != 's');
    
    // Loop until player 2 gives a valid input (r, p, or s)
    do {
        printf("Player 2 choose (r = rock, p = paper, s = scissor):\n");
        scanf(" %c", &player2);

        // If the input is not valid, show an error message
        if (player2 != 'r' && player2 != 'p' && player2 != 's') {
            printf("Wrong input! Try again.\n");
        }
    } while (player2 != 'r' && player2 != 'p' && player2 != 's');

    // Show result
    printf("Result: \n");

    int tie = (player1 == player2); // checks if it is a tie, same input from both players

    if (tie) {
        printf("It's a tie! \n");

    // Check if player 2 wins (rock beats scissor, paper beats rock, scissor beats paper)
    } else if ((player1 == 'r' && player2 == 's') ||
               (player1 == 'p' && player2 == 'r') ||
               (player1 == 's' && player2 == 'p')) {
        printf("Player 1 won!\n");

    } else {
        printf("Player 2 won \n");
    }

} else if (strcmp(gamemode, "PVE") == 0 || strcmp(gamemode, "2") ==0 ){

    // Loop until player 1 gives a valid input (r, p, or s)
     do {
        printf("Player choose (r = rock, p = paper, s = scissor):\n");
        scanf(" %c", &player1);

        // If the input is not valid, show an error message
        if (player1 != 'r' && player1 != 'p' && player1 != 's') {
            printf("Wrong input! Try again.\n");
        }
    } while (player1 != 'r' && player1 != 'p' && player1 != 's');


    // Bot-input
    /*
    int random = (rand() % 3)+1;
    if (random == 1) bot = 'r';
    else if (random == 2) bot = 'p';
    else bot = 's';
    */
    char botChoices[3] = {'r', 'p', 's'};
    bot = botChoices[rand() % 3];

    printf("The Bot chose: \n %c \n", bot);

    // Result
    if (player1 == bot) {
        printf("It's a Tie! \n");
    } else if ((player1 == 'r' && bot == 's') ||
               (player1 == 'p' && bot == 'r') ||
               (player1 == 's' && bot == 'p')) {
                
        printf("You won! \n");
    } else {
        printf("The Bot won! \n");
    }
    
    
}

}