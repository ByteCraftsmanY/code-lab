#include <bits/stdc++.h>
using namespace std;

string predictPartyVictory(string senate) {
    queue<int> dq, rq;
    int n = senate.size();
    for (int i = 0; i < n; i++) {
        if (senate.at(i) == 'D')
            dq.push(i);
        else
            rq.push(i);
    }
    while (!dq.empty() && !rq.empty()) {
        int d = dq.front(), r = rq.front();
        dq.pop(), rq.pop();
        if (d < r)
            dq.push(d + n);
        else
            rq.push(r + n);
    }
    if (!rq.empty()) return "Radiant";
    return "Dire";
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << predictPartyVictory(s) << endl;
    }
    return 0;
}