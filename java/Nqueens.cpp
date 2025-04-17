#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check left side of the current row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q') return false;
    }

    // Check upper diagonal (left side)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check lower diagonal (left side)
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

void solveNQueens(vector<vector<string>>& res, vector<string>& board, int col, int n) {
    if (col == n) {
        res.push_back(board);  // All queens placed successfully
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';  // Place queen
            solveNQueens(res, board, col + 1, n);  // Recur for next column
            board[row][col] = '.';  // Backtrack (remove queen)
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));  // Initialize empty board
    solveNQueens(res, board, 0, n);
    return res;
}

int main() {
    int n = 4;  // Change n for different board sizes
    vector<vector<string>> solutions = solveNQueens(n);

    // Print all solutions
    for (const auto& board : solutions) {
        for (const string& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
