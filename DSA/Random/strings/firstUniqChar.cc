// https://leetcode.com/problems/first-unique-character-in-a-string/description/
#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    vector<int> freqCounter(26, 0);
    for (auto c : s) freqCounter[c - 'a']++;
    for (int i = 0; i < s.size(); i++) {
        if (freqCounter[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

int main() {
    return 0;
}