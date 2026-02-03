#include <bits/stdc++.h>
using namespace std;

/**
 * Checks if a queen can be placed at position (r,c) on the board
 * @param mat Current board state
 * @param row Array tracking occupied rows
 * @param col Array tracking occupied columns
 * @param r Row to check
 * @param c Column to check
 * @param n Size of the board
 * @return true if position is safe for queen placement
 */
bool isEligible(vector<string>& mat, vector<bool>& row, vector<bool>& col,
                int r, int c, int n) {
    // Check if row or column is already occupied
    if (row[r] || col[c]) {
        return false;
    }

    // Check all four diagonal directions for existing queens
    // Upper-left diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (mat[i][j] == 'Q') return false;
    }

    // Upper-right diagonal
    for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
        if (mat[i][j] == 'Q') return false;
    }

    // Lower-left diagonal
    for (int i = r, j = c; i < n && j >= 0; i++, j--) {
        if (mat[i][j] == 'Q') return false;
    }

    // Lower-right diagonal
    for (int i = r, j = c; i < n && j < n; i++, j++) {
        if (mat[i][j] == 'Q') return false;
    }

    return true;
}

/**
 * Recursive helper function to solve N-Queens problem
 * @param ans Vector to store all valid solutions
 * @param resultMatrix Current board state
 * @param row Array tracking occupied rows
 * @param col Array tracking occupied columns
 * @param n Size of the board
 * @param r Current row
 * @param c Current column
 * @param q Number of queens remaining to place
 */
void helper(vector<vector<string>>& ans, vector<string>& resultMatrix,
            vector<bool>& row, vector<bool>& col,
            int n, int r, int c, int q) {
    // Base case: all queens placed successfully
    if (q <= 0) {
        ans.push_back(resultMatrix);
        return;
    }

    // Try placing queen in each valid position
    for (int ritr = r; ritr < n; ritr++) {
        for (int citr = c; citr < n; citr++) {
            if (!isEligible(resultMatrix, row, col, ritr, citr, n)) {
                continue;
            }

            // Place queen and mark row/column as occupied
            resultMatrix[ritr][citr] = 'Q';
            row[ritr] = true;
            col[citr] = true;

            // Recursively try placing remaining queens
            helper(ans, resultMatrix, row, col, n, ritr + 1, 0, q - 1);

            // Backtrack: remove queen and unmark row/column
            resultMatrix[ritr][citr] = '.';
            row[ritr] = false;
            col[citr] = false;
        }
    }
}

/**
 * Solves the N-Queens problem
 * @param n Size of the board and number of queens
 * @return Vector of all valid solutions
 */
vector<vector<string>> solveNQueens(int n) {
    // Initialize empty board
    string emptyRow(n, '.');
    vector<string> resultMatrix(n, emptyRow);
    vector<vector<string>> solutions;
    vector<bool> row(n, false), col(n, false);

    // Start solving from top-left corner
    helper(solutions, resultMatrix, row, col, n, 0, 0, n);
    return solutions;
}

/*
    since we are moving from left to right we dont need to check right part
    + we are placing 1 queen at a time we dont need to check current column for queen
    we only require to check those queen which are placed on the left
 */
bool isEligible2(vector<string> resultMatrix, int r, int c, int n) {
    int i, j;

    // check left top
    i = r, j = c;
    while (i >= 0 && j >= 0) {
        if (resultMatrix[i][j] == 'Q') {
            return false;
        }
        i--, j--;
    }

    // check left
    i = r, j = c;
    while (j >= 0) {
        if (resultMatrix[i][j] == 'Q') {
            return false;
        }
        j--;
    }

    // check left bottom
    i = r, j = c;
    while (i < n && j >= 0) {
        if (resultMatrix[i][j] == 'Q') {
            return false;
        }
        i++, j--;
    }
    return true;
}

void helper2(vector<vector<string>>& solutions, vector<string> board, int col, int n) {
    if (col >= n) {
        solutions.push_back(board);
        return;
    }
    for (int r = 0; r < n; r++) {
        if (!isEligible2(board, r, col, n)) {
            continue;
        }
        board[r][col] = 'Q';
        helper2(solutions, board, col + 1, n);
        board[r][col] = '.';
    }
}

vector<vector<string>> solveNQueens2(int n) {
    // Initialize empty board
    string emptyRow(n, '.');
    vector<string> board(n, emptyRow);
    vector<vector<string>> solutions;

    // Start solving from top-left corner
    helper2(solutions, board, 0, n);
    return solutions;
}

void helper3(
    vector<vector<string>>& solutions, vector<string> board, int col, int n,
    vector<bool>& left, vector<bool>& bottomLeft, vector<bool>& topLeft) {
    if (col >= n) {
        solutions.push_back(board);
        return;
    }
    auto getBottomLeftIdx = [n](int r, int c) -> int {
        return r + c;
    };
    auto getTopLeftIdx = [n](int r, int c) -> int {
        return (n - 1) + (c - r);
    };

    for (int r = 0; r < n; r++) {
        int bottomLeftIdx = getBottomLeftIdx(r, col), topLeftIdx = getTopLeftIdx(r, col);
        if (left[r] || bottomLeft[bottomLeftIdx] || topLeft[topLeftIdx]) {
            continue;
        }
        board[r][col] = 'Q';
        left[r] = true, bottomLeft[bottomLeftIdx] = true, topLeft[topLeftIdx] = true;
        helper3(solutions, board, col + 1, n, left, bottomLeft, topLeft);
        board[r][col] = '.';
        left[r] = false, bottomLeft[bottomLeftIdx] = false, topLeft[topLeftIdx] = false;
    }
}

vector<vector<string>> solveNQueens3(int n) {
    // Initialize empty board
    string emptyRow(n, '.');
    vector<string> board(n, emptyRow);
    vector<vector<string>> solutions;
    vector<bool> left(n, false);
    vector<bool> bottomLeft((n * 2) - 1, false);
    vector<bool> topLeft((n * 2) - 1, false);

    // Start solving from top-left corner
    helper3(solutions, board, 0, n, left, bottomLeft, topLeft);
    return solutions;
}

int main() {
    int n = 4;
    vector<vector<string>> solutions = solveNQueens3(n);

    // Print all solutions
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << "-----" << endl;
    }
    return 0;
}

/*
    https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/
    https://leetcode.com/problems/n-queens/submissions/1661524817/
*/
