#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length())
        return false;
    unordered_map<int, int> mp1, mp2, mp3;
    for (auto c : word1)
        mp1[c]++;
    for (auto c : word2)
        mp2[c]++;
    if (mp1.size() != mp2.size())
        return false;
    for (auto [k, c] : mp1) {
        if (!mp2.contains(k))
            return false;
        mp3[c]++;
    }
    for (auto [k, c] : mp2) {
        if (!mp1.contains(k))
            return false;
        if (mp3[c] == 0) {
            return false;
        }
        mp3[c]--;
    }
    return true;
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << closeStrings(a, b) << endl;
    return 0;
}