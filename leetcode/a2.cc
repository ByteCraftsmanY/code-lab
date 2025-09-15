#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

string findResult(string a, string b) {
    int n = a.size(), m = b.size();
    if (m > n) return findResult(b, a);
    auto isFactor = [&m, &n](int k) -> bool {
        return m % k == 0 && n % k == 0;
    };
    auto getConcatStr = [](string substr, int n) -> string {
        string result = "";
        for (int i = 0; i < n; i++) {
            result.append(substr);
        }
        return result;
    };
    for (int i = m; i >= 1; i--) {
        if (!isFactor(i)) {
            continue;
        }
        string subStr = b.substr(0, i), p = getConcatStr(subStr, n / i), q = getConcatStr(subStr, m / i);
        if (p == a && b == q) {
            return subStr;
        }
    }
    return "";
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << findResult(a, b);
    return 0;
}