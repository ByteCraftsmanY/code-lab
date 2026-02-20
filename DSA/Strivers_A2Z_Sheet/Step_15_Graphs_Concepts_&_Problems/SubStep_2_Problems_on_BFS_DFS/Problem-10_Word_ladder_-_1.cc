// Word ladder - 1
// Step: Graphs [Concepts & Problems]
// Sub Step: Problems on BFS/DFS
// Post Link: https://takeuforward.org/graph/word-ladder-i-g-29/
// LeetCode Link: https://leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
using namespace std;

// bfs way
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push(make_pair(beginWord, 1));
    st.erase(beginWord);
    while (!q.empty()) {
        auto data = q.front();
        q.pop();
        string s = data.first;
        int steps = data.second;
        if (s == endWord) return steps;
        for (int i = 0; i < s.size(); i++) {
            char orignalChar = s[i];
            for (int c = 'a'; c <= 'z'; c++) {
                s[i] = c;
                if (st.find(s) != st.end()) {
                    q.push({s, steps + 1});
                    st.erase(s);
                }
            }
            s[i] = orignalChar;
        }
    }
    return 0;
}

int helper(string beginWord, string endWord, unordered_set<string>& wordList, int steps) {
    // cout << "called for " << beginWord << " with step " << steps << endl;
    if (beginWord == endWord) {
        return steps;
    }
    int r = INT_MAX;
    for (int i = 0; i < beginWord.size(); i++) {
        char oc = beginWord[i];
        for (char c = 'a'; c <= 'z'; c++) {
            beginWord[i] = c;
            if (wordList.find(beginWord) != wordList.end()) {
                wordList.erase(beginWord);
                r = min(r, helper(beginWord, endWord, wordList, steps + 1));
                // wordList.insert(beginWord);
            }
        }
        beginWord[i] = oc;
    }
    return r;
}

// dfs way ladderLength2
int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    int r = helper(beginWord, endWord, st, 0);
    if (r == INT_MAX) return 0;
    return r;
}

int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << ladderLength2(beginWord, endWord, wordList);
    return 0;
}
