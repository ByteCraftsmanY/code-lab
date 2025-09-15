#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int j = 0, i = 0;
        while (i < t.size()) {
            if (j >= s.size()) break;
            if (s[j] == t[i])
                i++, j++;
            else
                i++;
        }
        return j == s.size();
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->isSubsequence("aza", "abzba");
    return 0;
}