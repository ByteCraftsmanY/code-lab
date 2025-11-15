// Valid Paranthesis Checker
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Easy Problems
// Post Link: https://takeuforward.org/data-structure/valid-paranthesis-checker
// LeetCode Link: https://leetcode.com/problems/valid-parenthesis-string/

#include <bits/stdc++.h>
using namespace std;

bool helper(string& s, int idx, int count, vector<vector<int>>& dp) {
    if (count < 0) return false;
    if (idx == s.size()) return count == 0;
    if (dp[idx][count] != -1) return dp[idx][count];

    bool result = false;
    if (s[idx] == '(') {
        result = helper(s, idx + 1, count + 1, dp);
    } else if (s[idx] == ')') {
        result = helper(s, idx + 1, count - 1, dp);
    } else {
        result = helper(s, idx + 1, count, dp) ||      // * = ""
                 helper(s, idx + 1, count + 1, dp) ||  // * = "("
                 helper(s, idx + 1, count - 1, dp);    // * = ")"
    }
    dp[idx][count] = result;
    return result;
}

/*
    TimeComplexity & SpaceComplexity
        WithDP: O(n^2) & O(n^2)
        WithoutDP: O(3^n) & O(n)
        Range: O(n) & O(1)
*/
bool checkValidString(string s) {
    // vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
    // return helper(s, 0, 0, dp);

    if (!s.empty() && s.front() == ')')
        return false;

    int min = 0, max = 0, i = 0;
    while (i < s.size()) {
        if (s[i] == '(') {
            min++, max++;
        } else if (s[i] == ')') {
            min--, max--;
        } else {
            min -= 1, max += 1;
        }
        if (min < 0) min = 0;
        if (max < 0) return false;
        i++;
    }
    return (min == 0);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << s << " : " << checkValidString(s) << endl;
    }
    return 0;
}
