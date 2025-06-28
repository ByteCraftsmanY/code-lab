#include <bits/stdc++.h>
using namespace std;

// Broute force
bool wordBreak2(string s, vector<string>& wordDict, int idx = 0) {
    if (idx == s.size()) {
        return true;
    }
    string prefix = "";
    for (int i = idx; i < s.size(); i++) {
        prefix.push_back(s[i]);
        bool containsPrefix = false;
        for (auto const& word : wordDict) {
            if (word == prefix) {
                containsPrefix = true;
                break;
            }
        }
        if (containsPrefix && wordBreak2(s, wordDict, i + 1)) {
            return true;
        }
    }
    return false;
}

bool wordBreakRec(
    string s, vector<string>& wordDict, vector<int>& dp, int idx = 0) {
    if (idx >= s.size()) {
        return true;
    }
    if (dp[idx] != -1) {
        return dp[idx];
    }
    bool isPossible = false;
    for (auto const& word : wordDict) {
        if (word.size() > s.size() - idx) {
            continue;
        }
        int itr = idx;
        bool successMatch = true;
        for (auto const& c : word) {
            if (c == s[itr]) {
                itr++;
            } else {
                successMatch = false;
                break;
            }
        }
        if (successMatch) {
            isPossible |= wordBreakRec(s, wordDict, dp, idx + word.size());
        }
    }
    dp[idx] = isPossible;
    return dp[idx];
}

// top down DP
bool wordBreak3(string s, vector<string>& wordDict) {
    vector<int> dp(s.size() + 1, -1);
    return wordBreakRec(s, wordDict, dp, 0);
}

// bottom up dp
bool wordBreak4(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[n] = true;
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    for (int i = n - 1; i >= 0; i--) {
        for (int len = 1; len <= n - i; len++) {
            string substring = s.substr(i, len);
            if (wordSet.find(substring) != wordSet.end() && dp[i + len]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[0];
}

bool helper5(string s, unordered_set<string>& wordDict, vector<int>& dp, int start) {
    if (start == s.size()) {
        return true;
    }
    if (dp[start] != -1) {
        return dp[start];
    }
    for (int end = start + 1; end <= s.size(); end++) {
        string substring = s.substr(start, end - start);
        if (wordDict.find(substring) != wordDict.end()) {
            dp[end] = helper5(s, wordDict, dp, end);
            if (dp[end]) {
                return true;
            }
        }
    }
    return false;
}

bool wordBreak5(string s, vector<string>& wordDict) {
    vector<int> dp(s.size() + 1, -1);
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    return helper5(s, st, dp, 0);
}

int main() {
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    vector<string> wordDict(n, "");
    for (auto& word : wordDict) {
        cin >> word;
    }
    cout << wordBreak4(s, wordDict);
    return 0;
}
