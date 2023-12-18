#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char player, int position);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);

int main() {
    do {
        vector<vector<char>> board(3, vector<char>(3, ' ')); 
        char currentPlayer = 'X';
        bool gameInProgress = true;

        cout << "Welcome to Tic-Tac-Toe!\n";

        do {
            displayBoard(board);

            int position;
            do {
                cout << "Player " << currentPlayer << ", enter your move (1-9): ";
                cin >> position;
            } while (!makeMove(board, currentPlayer, position));

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameInProgress = false;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                gameInProgress = false;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; 
            }

        } while (gameInProgress);

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing!\n";
            break;
        }

    } while (true);

    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------\n";
    for (const auto& row : board) {
        cout << "| ";
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool makeMove(vector<vector<char>>& board, char player, int position) {
    
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    
    if (position < 1 || position > 9 || board[row][col] != ' ') {
        cout << "Invalid move. Try again.\n";
        return false;
    }

    board[row][col] = player;
    return true;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; 
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; 
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; 
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; 
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    // Check if the board is full
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; 
            }
        }
    }
    return true; 
}
