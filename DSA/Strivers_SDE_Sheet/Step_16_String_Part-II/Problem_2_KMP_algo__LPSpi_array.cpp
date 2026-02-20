// KMP algo / LPS(pi) array
// Step: String Part-II
// Difficulty: Hard
// Post Link: None
// LeetCode Link: https://leetcode.com/problems/implement-strstr/
// GFG Link: https://practice.geeksforgeeks.org/problems/search-pattern0205/1
// GFG Resource: https://www.geeksforgeeks.org/dsa/kmp-algorithm-for-pattern-searching/
// YT Link: https://www.youtube.com/watch?v=ziteu2FpYsA

#include <bits/stdc++.h>
using namespace std;

// LPS = Longest Prefix which is also a suffix
vector<int> buildLPSArray(string& pattern) {
    vector<int> lps(pattern.size(), 0);
    lps[0] = 0;  // for first char longest prefix is 0
    int i = 0, j = 1;
    while (j < pattern.size()) {
        if (pattern[i] == pattern[j]) {
            lps[j] = i + 1;
            i++, j++;
        } else {
            if (i != 0) {
                i = lps[i - 1];
            } else {
                lps[j] = 0;
                j++;
            }
        }
    }
    return lps;
}

int findFirstIndex(string& text, string& pattern) {
    int res = -1;
    vector<int> result = {};
    vector<int> lps = buildLPSArray(pattern);

    int i = 0, j = 0, n = text.size(), m = pattern.size();
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;

            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1]; // move back to previous index 
            }

        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    // cout << "starting indexes: ";
    // for (auto x : result) {
    //     cout << x << " ";
    // }
    // cout << endl;

    if (!result.empty()) return result.front();
    return -1;
}

int main() {
    string text = "aaaaaaaab", pattern = "aaab";
    text = "sadbutsad", pattern = "sad";
    cout << findFirstIndex(text, pattern);
    return 0;
}
