#include <bits/stdc++.h>
using namespace std;

/**
 * Checks if a number can be placed at the given position in the Sudoku board
 * @param board The Sudoku board
 * @param rowUsed Numbers used in each row
 * @param colUsed Numbers used in each column
 * @param blockUsed Numbers used in each 3x3 block
 * @param row Current row position
 * @param col Current column position
 * @param num Number to check
 * @return true if the number can be placed, false otherwise
 */
bool isValid(vector<vector<char>>& board,
             vector<vector<bool>>& rowUsed,
             vector<vector<bool>>& colUsed,
             vector<vector<bool>>& blockUsed,
             int row, int col, int num) {
    return (!rowUsed[row][num] &&
            !colUsed[col][num] &&
            !blockUsed[(row / 3) * 3 + (col / 3)][num]);
}

/**
 * Recursive helper function to solve the Sudoku puzzle
 * @param board The Sudoku board
 * @param rowUsed Numbers used in each row
 * @param colUsed Numbers used in each column
 * @param blockUsed Numbers used in each 3x3 block
 * @param row Current row position
 * @param col Current column position
 * @return true if the puzzle is solved, false otherwise
 */
bool solveSudokuHelper(vector<vector<char>>& board,
                       vector<vector<bool>>& rowUsed,
                       vector<vector<bool>>& colUsed,
                       vector<vector<bool>>& blockUsed,
                       int row, int col) {
    int n = board.size();
    int m = board[0].size();

    // Base case: reached the end of the board
    if (row >= n) {
        return true;
    }

    // Move to next row if reached end of current row
    if (col >= m) {
        return solveSudokuHelper(board, rowUsed, colUsed, blockUsed, row + 1, 0);
    }

    // If cell is already filled, move to next cell
    if (board[row][col] != '.') {
        return solveSudokuHelper(board, rowUsed, colUsed, blockUsed, row, col + 1);
    }

    // Try placing numbers 1-9 in the current cell
    for (char num = '1'; num <= '9'; num++) {
        int value = num - '0';

        if (isValid(board, rowUsed, colUsed, blockUsed, row, col, value)) {
            // Place the number
            board[row][col] = num;
            rowUsed[row][value] = true;
            colUsed[col][value] = true;
            blockUsed[(row / 3) * 3 + (col / 3)][value] = true;

            // Recursively try to solve the rest of the board
            if (solveSudokuHelper(board, rowUsed, colUsed, blockUsed, row, col + 1)) {
                return true;
            }

            // Backtrack if solution not found
            board[row][col] = '.';
            rowUsed[row][value] = false;
            colUsed[col][value] = false;
            blockUsed[(row / 3) * 3 + (col / 3)][value] = false;
        }
    }
    return false;
}

/**
 * Solves a Sudoku puzzle
 * @param board The Sudoku board to solve
 */
void solveSudoku(vector<vector<char>>& board) {
    // Initialize tracking arrays for used numbers
    vector<vector<bool>> rowUsed(board.size(), vector<bool>(board[0].size() + 1, false));
    vector<vector<bool>> colUsed(board.size(), vector<bool>(board[0].size() + 1, false));
    vector<vector<bool>> blockUsed(board.size(), vector<bool>(board[0].size() + 1, false));

    // Mark initial numbers as used
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '.') continue;

            int value = board[i][j] - '0';
            rowUsed[i][value] = true;
            colUsed[j][value] = true;
            blockUsed[(i / 3) * 3 + (j / 3)][value] = true;
        }
    }

    // Start solving from the top-left corner
    solveSudokuHelper(board, rowUsed, colUsed, blockUsed, 0, 0);
}

int main() {
    // Initialize 9x9 Sudoku board
    vector<vector<char>> board(9, vector<char>(9));

    // Sample Sudoku puzzle
    board = {
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'},
    };

    // Solve the puzzle
    solveSudoku(board);

    // Print the solution
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
