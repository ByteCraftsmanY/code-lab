// Set Matrix Zeros
// Step: Arrays
// Difficulty: Medium
// Post Link: https://takeuforward.org/data-structure/set-matrix-zero/
// LeetCode Link: https://leetcode.com/problems/set-matrix-zeroes/
// GFG Link: https://bit.ly/3SVaSig

#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& mat) {
    bool isCol0 = false;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 0) {
                if (j > 0)
                    mat[0][j] = 0;  // set col
                mat[i][0] = 0;      // set row
                if (j == 0) isCol0 = true;
            }
        }
    }
    for (int i = mat.size() - 1; i >= 0; i--) {
        for (int j = mat[i].size() - 1; j >= 0; j--) {
            if (mat[i][0] == 0 || (mat[0][j] == 0 && j > 0) || (j == 0 && isCol0)) {
                mat[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> mat = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    mat = {
        {1, 2, 3, 4},
        {5, 0, 7, 8},
        {0, 10, 11, 12},
        {13, 14, 15, 0},
    };

    mat = {{-4, -2147483648, 6, -7, 0}, {-8, 6, -8, -6, 0}, {2147483647, 2, -9, -6, -10}};
    setZeroes(mat);
    return 0;
}

int main() {
    return 0;
}
