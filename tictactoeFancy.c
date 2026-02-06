#include <stdio.h>
#include <string.h>
int checkWinner(char board[3][3]);

// Viser pladen
void printBoard(char board[3][3]) {
    printf("\n   1   2   3\n");
    printf("A  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("B  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("C  %c | %c | %c\n\n", board[2][0], board[2][1], board[2][2]);
}

// Tjekker om feltet allerede er optaget
int spaceTaken(char board[3][3], int row, int col) {
    return board[row][col] != '_';
}

// Oversætter input ("A1") til rækker og kolonner
int getPosition(char move[], int *row, int *col) {
    if (strlen(move) != 2) return 0; // ugyldigt input
    if (move[0] == 'A') *row = 0;
    else if (move[0] == 'B') *row = 1;
    else if (move[0] == 'C') *row = 2;
    else return 0; // ugyldig række

    if (move[1] >= '1' && move[1] <= '3')
        *col = move[1] - '1';
    else
        return 0; // ugyldig kolonne

    return 1; // gyldigt
}

int main() {
    char board[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };

    char move[3];
    int row, col;
    char currentPlayer = 'X'; // starter med spiller 1

    printf("Velkommen til Tic Tac Toe!\n");
    printf("Spiller 1 = X   |   Spiller 2 = O\n");

    // simpelt loop (fx 9 ture maks)
    for (int turn = 0; turn < 9; turn++) {
        printBoard(board);
        printf("Spiller %c, vælg felt (fx A1, B3): ", currentPlayer);
        scanf("%2s", move);

        if (board ==  ){

        }

        // valider input
        if (!getPosition(move, &row, &col)) {
            printf("Ugyldigt felt! Brug fx A1 eller C3.\n");
            turn--; // prøv igen uden at tælle turen
            continue;
        }

        // tjek om feltet er taget
        if (spaceTaken(board, row, col)) {
            printf("Feltet er allerede taget! Prøv igen.\n");
            turn--;
            continue;
        }

        // placer X eller O
        board[row][col] = currentPlayer;

        // skift spiller
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);
    printf("Spillet er slut!\n");
    return 0;
}
