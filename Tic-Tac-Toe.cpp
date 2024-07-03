#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void displayBoard() {
        cout << "\n   0   1   2\n";
        for (int i = 0; i < 3; i++) {
            cout << i << " ";
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "  -----------\n";
        }
    }

    bool isMoveValid(int row, int col) {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }

    void makeMove(int row, int col) {
        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;
            if (checkWin()) {
                displayBoard();
                cout << "\nPlayer " << currentPlayer << " wins!" << endl;
                resetGame();
            } else if (checkDraw()) {
                displayBoard();
                cout << "\nThe game is a draw!" << endl;
                resetGame();
            } else {
                switchPlayer();
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') return false;
            }
        }
        return true;
    }

    void resetGame() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void playGame() {
        int row, col;
        while (true) {
            displayBoard();
            cout << "\nPlayer " << currentPlayer << ", please enter your move (row and column): ";
            cin >> row >> col;
            makeMove(row, col);
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
