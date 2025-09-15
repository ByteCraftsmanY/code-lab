#include <bits/stdc++.h>
using namespace std;

int maxVowels(string s, int k) {
    int n = s.size();
    if (k > n) {
        return 0;
    }
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int i = 0, j = 0, c = 0, mx = 0;
    while (i < k) {
        if (vowels.contains(s[i++])) c++;
    }
    mx = c;
    while (i < n) {
        if (vowels.contains(s[j++]))
            c--;
        if (vowels.contains(s[i++]))
            c++;
        mx = max(mx, c);
    }
    return mx;
}

int main() {
    string s;
    int k;
    getline(cin, s);
    cin >> k;
    cout << maxVowels(s, k);
    return 0;
}