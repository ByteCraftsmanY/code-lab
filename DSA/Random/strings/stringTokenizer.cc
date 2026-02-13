#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char delimiter) {
    if (s.empty()) return {};

    string token = "";
    vector<string> result;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == delimiter) {
            result.push_back(token);
            token = "";
        } else {
            token += s[i];
        }
    }
    if (!token.empty())
        result.push_back(token);
    return result;
}

int main() {
    // freopen("/home/yogesh/Projects/code-lab/bin/#input.txt", "r+", stdin);
    // int t;
    // cin >> t;
    // cin.ignore();
    // while (t--) {
    string s;
    char delimiter;
    // getline(cin, s);
    // cin >> delimiter;
    // cout << "for- " << s << "\n";
    s = "aman maneshwar", delimiter = ' ';
    // s = "geeks:for:geeks", delimiter = ':';
    vector<string> results = split(s, delimiter);
    for (auto x : results) {
        cout << x << endl;
    }
    // }
    return 0;
}