// Pascal's Triangle
// Step: Arrays
// Difficulty: Medium
// Post Link: https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/
// LeetCode Link: https://leetcode.com/problems/pascals-triangle/
// GFG Link: https://bit.ly/3C95qlR

#include <bits/stdc++.h>
using namespace std;

/*
    //    0 1  2  3  4  5 6 7
    // 7: 1 7 21 35 35 21 7 1

    nCr = !n / !r * !(n-r)

    for 7,3

    = 7/1 * 6/2 * 5/3
    = 210/6
    = 35


*/
int getElementByIndex(int n, int k) {
    int res = 1;
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

vector<int> generateRow(int n) {
    vector<int> res;
    // for (int i = 0; i <= n; i++) {
    //     res.push_back(get(n, i));
    // }

    // C(N,0) = 1
    int prev = 1;
    res.push_back(prev);

    double curr = 0;
    for (int i = 1; i <= n; i++) {
        curr = (double)(prev * ((n - i) + 1)) / i;
        res.push_back(curr);
        prev = curr;
    }

    /*

        0   1       2               3
        1  7/1  7/1 * 6/2   7/1 * 6/2 * 5/3

        nCr intuation


    */

    return res;
}

vector<vector<int>> generateTriangle(int n) {
    vector<vector<int>> res;
    for (int i = 0; i <= n; i++) {
        vector<int> temp;
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                temp.push_back(1);
                continue;
            }
            int sum = res[i - 1][j - 1] + res[i - 1][j];
            temp.push_back(sum);
        }
        res.push_back(temp);
    }
    return res;
}

int main() {
    auto res = generateTriangle(7);
    return 0;
}