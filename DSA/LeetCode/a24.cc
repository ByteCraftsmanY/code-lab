#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

string removeStars(string s) {
    string result = "";
    int i = 0;
    while (i < s.size()) {
        if (s[i] == '*') {
            if (!result.empty()) result.pop_back();
        } else
            result += s[i];
        i++;
    }
    return result;
}

int main() {
    string s;
    getline(cin, s);
    // cout << s;˜
    cout << removeStars(s);
    return 0;
}