#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    cout << s << endl;
    int maxLen = 0, n = s.size();
    for (int i = 0; i < n; i++) {
        vector<int> charSet(256, 0);
        for (int j = i; j < n; j++) {
            if (charSet[s[j]]) break;
            charSet[s[j]]++;
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

int lengthOfLongestSubstring2(string s) {
    int i = 0, j = 0, n = s.size(), maxLen = 0;
    vector<int> charSet(256, 0);
    while (j < n) {
        while (charSet[s[j]] > 0) charSet[s[i++]]--;
        maxLen = max(maxLen, j - i + 1);
        charSet[s[j++]]++;
    }
    return maxLen;
}

int lengthOfLongestSubstring3(string s) {
    int i = 0, j = 0, n = s.size(), maxLen = 0;
    vector<int> charSet(256, 0);
    while (j < n) {
        if (charSet[s[j]] > 0) i = j;
        maxLen = max(maxLen, j - i + 1);
        charSet[s[j++]]++f;
    }
    return maxLen;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << lengthOfLongestSubstring3(s) << endl;
    }
    return 0;
}