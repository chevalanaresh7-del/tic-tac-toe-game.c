#include <stdio.h>

char board[3][3];

// Function to initialize board
void initBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

// Function to display board
void displayBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Function to check winner
int checkWin() {
    // Rows & Columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

// Function to check draw
int checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

// Function to place mark
void makeMove(int choice, char mark) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = mark;
    } else {
        printf("Invalid move! Try again.\n");
        makeMove(choice, mark);
    }
}

int main() {
    int choice;
    char player = 'X';

    initBoard();

    while(1) {
        displayBoard();
        printf("Player %c, enter your choice (1-9): ", player);
        scanf("%d", &choice);

        if(choice < 1 || choice > 9) {
            printf("Invalid input! Try again.\n");
            continue;
        }

        makeMove(choice, player);

        if(checkWin()) {
            displayBoard();
            printf("🎉 Player %c wins!\n", player);
            break;
        }

        if(checkDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
