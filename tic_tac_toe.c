#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], char player);

int main() {
    char board[SIZE][SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    char player = 'X';
    int result = -1;

    while (result == -1) {
        printBoard(board);
        makeMove(board, player);
        result = checkWin(board);
        player = (player == 'X') ? 'O' : 'X';
    }

    printBoard(board);

    if (result == 1) {
        printf("Player %c wins!\n", (player == 'X') ? 'O' : 'X');
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void printBoard(char board[SIZE][SIZE]) {
    printf("Current board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

void makeMove(char board[SIZE][SIZE], char player) {
    int move;
    printf("Player %c, enter your move: ", player);
    scanf("%d", &move);

    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;

    if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move! Try again.\n");
        makeMove(board, player);
    } else {
        board[row][col] = player;
    }
}

int checkWin(char board[SIZE][SIZE]) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    // Check for draw
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return -1; // Game is still ongoing
            }
        }
    }
    return 0; // It's a draw
}


