#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
string reverseVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    vector<char> stringVowels;
    for (char c : s) {
        if (vowels.contains(tolower(c))) {
            stringVowels.push_back(c);
        }
    }
    int k = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (vowels.contains(tolower(s.at(i)))) {
            s[i] = stringVowels[k++];
        }
    }
    return s;
}
int main() {
    string s;
    getline(cin, s);
    cout << reverseVowels(s);
    return 0;
}