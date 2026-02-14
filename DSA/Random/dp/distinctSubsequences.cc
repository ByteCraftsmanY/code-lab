// https://leetcode.com/problems/distinct-subsequences/description/
// https://www.geeksforgeeks.org/problems/distinct-occurrences/1

#include <bits/stdc++.h>
using namespace std;

void helper(string s, int idx = 0, string r = "") {
    int n = s.size();
    if (idx >= n) {
        cout << r << endl;
        return;
    }
    helper(s, idx + 1, r);
    helper(s, idx + 1, r + s[idx]);
}

void subsequence(string s) {
    helper(s, 0, "");
}

int numDistinct(string s, string t) {
    int count = 0;
    string temp = "";
    int n = s.size();
    long long int imx = 1 << n;
    for (int i = 0; i < imx; i++) {
        temp.clear();
        for (int idx = n - 1; idx >= 0; idx--) {
            int v = (1 << idx);
            if (v & i)
                temp = s[idx] + temp;
        }
        // cout << temp << endl;
        if (temp == t) count++;
    }
    return count;
}

int helper2(string s, string t, int i, int j, vector<vector<int>>& dp) {
    if (j < 0)
        return 1;
    else if (i < 0)
        return 0;
    else if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] != t[j]) {
        dp[i][j] = helper2(s, t, i - 1, j, dp);
    } else
        dp[i][j] = helper2(s, t, i - 1, j - 1, dp) + helper2(s, t, i - 1, j, dp);
    return dp[i][j];
}

int numDistinct2(string s, string t) {
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return helper2(s, t, s.size() - 1, t.size() - 1, dp);
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    // cout << numDistinct(s, t);
    // subsequence(s);
    cout << numDistinct2(s, t);
    return 0;
}

/*
rabbbit
rabbit

3

*/