#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board
char currentPlayer = 'X'; // Start with player X

// Function to initialize the board with numbers 1-9
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to make a move
bool makeMove(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if (pos < 1 || pos > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false; // Invalid move
    }

    board[row][col] = currentPlayer;
    return true;
}

// Function to check for a win
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Main game loop
int main() {
    int position;
    initializeBoard();

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter a position (1-9): ";
        cin >> position;

        if (!makeMove(position)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        switchPlayer();
    }

    return 0;
}
