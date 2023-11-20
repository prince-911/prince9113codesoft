#include <iostream>
using namespace std;

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

bool Win(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char players[] = {'X', 'O'};
    int current = 0;
    bool gameOver = false;
    
    while (!gameOver) {
        printBoard(board);
        char player = players[current];
        cout << "Player with " << player << "'s turn." << endl;
        
        int row, col;
        do {
            cout << "Enter Row (0-2): ";
            cin >> row;
            cout << "Enter Column (0-2): ";
            cin >> col;
        } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ');
        
        board[row][col] = player;
        
        if (Win(board, player)) {
            printBoard(board);
            cout << "Player " << player << " wins!" << endl;
            gameOver = true;
        } else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        }
        
        current = 1 - current;
        
        char playAgain;
        cout << "U want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }
    
    return 0;
}