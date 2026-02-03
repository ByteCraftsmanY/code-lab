#include <bits/stdc++.h>
using namespace std;

bool helper(
    vector<vector<char>>& board, vector<vector<bool>>& isVisited, string s,
    int curIdx, int row, int col) {
    if (curIdx >= s.size()) {
        return true;
    }
    if ((row < 0 || row >= board.size()) || (col < 0 || col >= board[row].size())) {
        return false;
    }
    if (isVisited[row][col] || s[curIdx] != board[row][col]) {
        return false;
    }
    isVisited[row][col] = true;
    bool result = helper(board, isVisited, s, curIdx + 1, row, col + 1) ||
                  helper(board, isVisited, s, curIdx + 1, row + 1, col) ||
                  helper(board, isVisited, s, curIdx + 1, row, col - 1) ||
                  helper(board, isVisited, s, curIdx + 1, row - 1, col);
    isVisited[row][col] = false;
    return result;
}

bool exists(vector<vector<char>>& board, string word) {
    if (board.empty() || word.empty()) {
        return false;
    }
    vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
            if (helper(board, isVisited, word, 0, row, col)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string s = "ABCCED";

    bool result = exists(board, s);
    cout << result;
    return 0;
}

/*
    https://www.youtube.com/watch?v=pfiQ_PS1g8E
    https://takeuforward.org/data-structure/word-search-leetcode/
*/
