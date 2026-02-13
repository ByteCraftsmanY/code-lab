// https://leetcode.com/problems/longest-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    int maxLen = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
            continue;
        }
        st.pop();
        if (st.empty()) {  // if unmatched closing parentheses
            st.push(i);
            continue;
        }
        maxLen = max(maxLen, i - st.top());
    }
    return maxLen;
}

int solve2(string s) {
    int open = 0, close = 0, maxLen = 0;
    // handles extra closing brackets
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            open++;
        } else {
            close++;
        }

        if (close > open) {
            open = close = 0;
        } else if (close == open) {
            maxLen = max(maxLen, close * 2);
        }
    }

    open = close = 0;
    // handles extra opening brackets
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            open++;
        } else {
            close++;
        }

        if (open > close) {
            open = close = 0;
        } else if (open == close) {
            maxLen = max(maxLen, open * 2);
        }
    }
    return maxLen;
}

int main() {
    cout << solve2("()(())");
    return 0;
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << solve(s) << endl;
    }
    return 0;
}

/*
)((((()()((()()))

*/

// )((((()()((()()))