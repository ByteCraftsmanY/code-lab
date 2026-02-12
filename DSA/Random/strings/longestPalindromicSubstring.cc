#include <bits/stdc++.h>
using namespace std;

class result {
   public:
    int n;
    string s;

    result(int n, string s) : n(n), s(s) {
    }
};

result longestPalindromicSubstring(string& s) {
    string rs = "";
    int maxLen = 0, n = s.size();
    for (int i = 0; i < n; i++) {
        // odd case
        int start = i, end = i, len = 0;
        while (start >= 0 && end < n && s[start] == s[end]) {
            len = end - start + 1;
            if (len > maxLen) {
                maxLen = len;
                rs = s.substr(start, len);
            }
            start--, end++;
        }

        // even case
        start = i, end = i + 1, len = 0;
        while (start >= 0 && end < n && s[start] == s[end]) {
            len = end - start + 1;
            if (len > maxLen) {
                maxLen = len;
                rs = s.substr(start, len);
            }
            start--, end++;
        }
    }
    return result(maxLen, rs);
}
/**
 * a
 * bb
 *
 */

int main() {
    string s = "abcbabcb";
    result rs = longestPalindromicSubstring(s);
    cout << rs.n << " " << rs.s << endl;
    return 0;
}