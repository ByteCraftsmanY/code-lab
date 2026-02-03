#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

string removeOuterParentheses(string s) {
    // stack<int> st;
    // int n = s.size();
    // for (int i = 0; i < n; i++) {
    //     if (s[i] == '(') {
    //         st.push(i);
    //     } else if (st.size() == 1) {
    //         s[st.top()] = s[i] = ' ';
    //         st.pop();
    //     } else {
    //         st.pop();
    //     }
    // }
    // string ans;
    // for (auto c : s) {
    //     if (c == ' ') {
    //         continue;
    //     }
    //     ans += c;
    // }
    // return ans;
    string result = "";
    int start = 0, count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            result += (s.substr(start + 1, i - start - 1));
            start = i + 1;
        }
    }
    return result;
}

string reverseWordString(string& s) {
    string result = "";
    int end = -1, i = s.size() - 1;
    auto addSub = [&result](string subStr) {
        if (result.size() > 0) {
            result += ' ';
        }
        result += subStr;
    };
    while (i >= 0) {
        if (s[i] == ' ' && end == -1) {
        } else if (end == -1) {
            end = i;
        } else if (s[i] == ' ') {
            addSub(s.substr(i + 1, end - i));
            end = -1;
        }
        i--;
    }
    if (end != -1) {
        addSub(s.substr(0, end + 1));
    }
    return result;
    /*

    4
    a good   example
    this is an amazing program
    This is decent
    hello world


    example good a
    program amazing an is this
    decent is This
    world hello

    */
}

string largestOddNumber(string num) {
    int n = num.size() - 1;
    while (n >= 0) {
        int digit = num[n] - '0';
        if (digit % 2 != 0) {
            return num.substr(0, n + 1);
        }
        n--;
    }
    return "";
}

string longestCommonPrefix(vector<string>& strs) {
    // string result = "";
    // int minLenString = INT_MAX;
    // for (string s : strs) {
    //     int strLen = s.size();
    //     minLenString = min(minLenString, strLen);
    // };
    // for (int i = 0; i < minLenString; i++) {
    //     bool isCommonChar = true;
    //     for (int itr = 1; itr < strs.size(); itr++) {
    //         char a = strs[itr - 1][i], b = strs[itr][i];
    //         if (a != b) {
    //             isCommonChar = false;
    //             break;
    //         }
    //     }
    //     if (!isCommonChar) {
    //         return result;
    //     }
    //     result += strs[0][i];
    // }
    // return result;

    sort(strs.begin(), strs.end());
    int n = strs.size(), itr = 0,
        maxLen = min(strs[0].size(), strs[n - 1].size());
    while (itr < maxLen && strs[0][itr] == strs[n - 1][itr]) {
        itr++;
    }
    return strs[0].substr(0, itr);
}

bool isIsomorphic(string s, string t) {
    int n1 = s.size(), n2 = t.size();
    if (n1 != n2) {
        return false;
    }
    const int totalAsciiChar = 128;
    vector<int> mappings1(totalAsciiChar, -1), mappings2(totalAsciiChar, -1);
    for (int i = 0; i < n1; i++) {
        int idx1 = s[i];
        int idx2 = t[i];
        if (mappings1[idx1] == -1 && mappings2[idx2] == -1) {
            mappings1[idx1] = idx2, mappings2[idx2] = idx1;
        } else if (mappings1[idx1] != idx2 && mappings2[idx2] != idx1) {
            return false;
        }
    }
    return true;
}

// kmp algorithm
bool rotateString(string s, string goal) {
    int n1 = s.size(), n2 = goal.size();
    if (n1 != n2) {
        return false;
    }
    // time: O(nm)
    // for (int i = 0; i < n1; i++) {
    //     string substr = s.substr(i + 1, n1) + s.substr(0, i + 1);
    //     if (substr == goal) {
    //         return true;
    //     }
    // }
    // return false;

    // time: O(n + m)
    auto buildLPSArray = [](string s) -> vector<int> {
        int n = s.size();
        int j = 0, i = 1;
        vector<int> lps(n, 0);
        while (i < n) {
            if (s[i] == s[j]) {  // increment both find more
                lps[i] = j + 1;
                i++, j++;
            } else if (j == 0) {  // no metching
                i++;
            } else {  // go to last matching
                j = lps[j - 1];
            }
        }
        return lps;
    };
    goal += goal;
    vi lps = buildLPSArray(s);

    int i = 0, j = 0, n = goal.size();
    while (i < n) {
        if (goal[i] == s[j]) {
            i++, j++;
        } else if (j == 0) {
            i++;
        } else {
            j = lps[j - 1];
        }
        if (j >= s.size()) {
            return true;
        }
    }
    return false;
}

bool isAnagram(string s, string t) {
    int n1 = s.size(), n2 = t.size();
    if (n1 != n2) {
        return false;
    }
    vi counter(26, 0);
    for (const char c : s) {
        counter[c - 'A']++;
    }
    for (const char c : t) {
        counter[c - 'A']++;
    }
    for (const int x : counter) {
        if (x != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // cout << rotateString("bbbacddceeb", "ceebbbbacdd") << endl;
    // return 0;
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        // cout << removeOuterParentheses(s) << endl;
        // cout << reverseWordString(s) << endl;
        // cout << largestOddNumber(s) << endl;
    }
    // vector<string> arr = {"flower", "flow", "flight"};
    // cout << longestCommonPrefix(arr) << endl;
    return 0;
}