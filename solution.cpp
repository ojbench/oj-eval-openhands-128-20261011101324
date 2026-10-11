#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkWin(const vector<string>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

bool isValidGame(const vector<string>& board) {
    int xCount = 0, oCount = 0;
    
    // Count pieces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') xCount++;
            else if (board[i][j] == 'o') oCount++;
        }
    }
    
    // x goes first, so xCount should be equal to oCount or oCount + 1
    if (xCount != oCount && xCount != oCount + 1) {
        return false;
    }
    
    bool xWins = checkWin(board, 'x');
    bool oWins = checkWin(board, 'o');
    
    // Both players can't win simultaneously
    if (xWins && oWins) {
        return false;
    }
    
    // If x wins, x must have one more piece than o
    if (xWins && xCount != oCount + 1) {
        return false;
    }
    
    // If o wins, counts must be equal
    if (oWins && xCount != oCount) {
        return false;
    }
    
    return true;
}

int main() {
    vector<string> board(3);
    for (int i = 0; i < 3; i++) {
        cin >> board[i];
    }
    
    // First check if the game state is valid
    if (!isValidGame(board)) {
        cout << "invalid" << endl;
        return 0;
    }
    
    bool xWins = checkWin(board, 'x');
    bool oWins = checkWin(board, 'o');
    
    if (xWins) {
        cout << "win" << endl;
    } else if (oWins) {
        cout << "lose" << endl;
    } else {
        // Check if board is full
        bool isFull = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    isFull = false;
                    break;
                }
            }
            if (!isFull) break;
        }
        
        if (isFull) {
            cout << "tie" << endl;
        } else {
            cout << "ongoing" << endl;
        }
    }
    
    return 0;
}