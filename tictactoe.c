#include <stdio.h>
#include <string.h>

void printBoard(char board[3][3]);
void gameboard(char playInput[], char A1[], char A2[], char A3[], char B1[], char B2[], char B3[], char C1[], char C2[], char C3[]);
void spaceTaken(char spaceCheck[], char x[], char o[], char space[]);

int main(){

    char playerInput[3];
    
    char board[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };

    printf("Player 1 is x, and player 2 is o\n");
    gameboard("x", "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3");

    printf("Player 1 start, where placing your x \n");
    scanf(" %2c", &playerInput);

    if(strcmp(playerInput, "A1") == 0){
        gameboard("x", "x", "_", "_", "_", "_", "_", "_", "_", "_");

    }

    //gameboard("x", "_", "_", "_", "_", "_", "_", "_", "_", "_");


}
void printBoard(char board[3][3]) {
    printf("   1   2   3\n");
    printf("A  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("B  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("C  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}
void gameboard(char playerInput[], char A1[], char A2[], char A3[], char B1[], char B2[], char B3[], char C1[], char C2[], char C3[]){
    printf("bla bla %s \n", playerInput);

    printf(" _%s_|_%s_|_%s_\n", A1, B1, C1);
    printf(" _%s_|_%s_|_%s_\n", A2, B2, C2);    
    printf(" _%s_|_%s_|_%s_\n", A3, B3, C3);



}

//regn ud om der er en streg eller ej, fordi så kan der spilles videre. Gørdet evt så bogstav er char og tal integar
void spaceTaken(char spaceCheck[], char x[], char o[], char space[]){
    if (strcmp(spaceCheck, "_") == 0) {
    }
}
