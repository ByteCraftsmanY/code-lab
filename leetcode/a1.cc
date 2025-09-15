#include <bits/stdc++.h>
using namespace std;

string merge(string a, string b) {
    string r = "";
    int i = 0, j = 0;
    bool flipToB = false;
    while (i < a.size() && j < b.size()) {
        if (!flipToB)
            r += (a.at(i++)), flipToB = true;
        else
            r += (b.at(j++)), flipToB = false;
    }
    while (i < a.size())
        r += a.at(i++);
    while (j < b.size())
        r += b.at(j++);
    return r;
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << merge(a, b) << endl;
    return 0;
}