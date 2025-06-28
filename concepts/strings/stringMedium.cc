#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// https://leetcode.com/problems/sort-characters-by-frequency/description/
// https://www.naukri.com/code360/problems/sorting-characters-by-frequency_1263699
string frequencySort(string s) {
    const int charCount = 128;
    vector<int> freqCounter(charCount, 0);
    for (auto c : s) {
        freqCounter[c]++;
    }

    vector<vector<int>> bucket(s.size() + 1);
    for (int i = 0; i < charCount; i++) {
        bucket[freqCounter[i]].push_back(i);
    }

    string result = "";
    for (int i = bucket.size() - 1; i >= 0; i--) {
        for (auto c : bucket[i]) {
            int count = i;
            while (count > 0) {
                result += c;
                count--;
            }
        }
    }
    return result;
}

// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// https://www.naukri.com/code360/problems/maximum-nesting-depth-of-the-parentheses_8144741
int maxDepth(string s) {
    const char inChar = '(', outChar = ')';
    int counter = 0, maxDep = 0;
    for (const char &c : s) {
        switch (c) {
            case inChar:
                counter++;
                break;
            case outChar:
                counter--;
                break;
        }
        maxDep = max(maxDep, counter);
    }
    return maxDep;

    /*
    2
    (3*(4*(5*(6))))
    (((((5)))))

    4
    5
    */
}

// https://leetcode.com/problems/roman-to-integer/description/
int romanToInt(string s) {
    unordered_map<char, int> mp = {
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
        {'X', 10},   {'V', 5},   {'I', 1},
    };

    int i = 0, result = 0;
    int n = s.size();
    // const char M = 'M', D = 'D', C = 'C', L = 'L', X = 'X', V = 'V', I = 'I';
    // while (i < n) {
    //     char c = s[i];
    //     if (c == M) {
    //         result += mp[M];
    //     } else if (c == D) {
    //         result += mp[D];
    //     } else if (c == C) {
    //         if (i + 1 < n) {
    //             char nxtC = s[i + 1];
    //             if (nxtC == M) {
    //                 result += 900, i += 2;
    //                 continue;
    //             } else if (nxtC == D) {
    //                 result += 400, i += 2;
    //                 continue;
    //             }
    //         }
    //         result += 100;
    //     } else if (c == L) {
    //         result += mp[L];
    //     } else if (c == X) {
    //         if (i + 1 < n) {
    //             char nxtC = s[i + 1];
    //             if (nxtC == C) {
    //                 result += 90, i += 2;
    //                 continue;
    //             } else if (nxtC == L) {
    //                 result += 40, i += 2;
    //                 continue;
    //             }
    //         }
    //         result += 10;
    //     } else if (c == V) {
    //         result += mp[V];
    //     } else {
    //         if (i + 1 < n) {
    //             char nxtC = s[i + 1];
    //             if (nxtC == X) {
    //                 result += 9, i += 2;
    //                 continue;
    //             } else if (nxtC == V) {
    //                 result += 4, i += 2;
    //                 continue;
    //             }
    //         }
    //         result += 1;
    //     }
    //     i++;
    // }

    for (int i = 0; i < n; i++) {
        int curVal = mp[s[i]], nextVal = i + 1 < n ? mp[s[i + 1]] : 0;
        if (curVal < nextVal) {
            result += (nextVal - curVal), i++;
        } else {
            result += (curVal);
        }
    }

    return result;

    /*
    4
    III
    LVIII
    MCMXCIV
    DCXXI


    3
    58
    1994
    621
    */
}

// https://leetcode.com/problems/string-to-integer-atoi/
// https://www.geeksforgeeks.org/write-your-own-atoi/
int myAtoi(string s) {
    // int n = s.size();
    // long long int result = 0;
    // if (n == 0) return 0;

    // // remove whitespaces
    // {
    //     int i = 0;
    //     while (s[i] == ' ') i++;
    //     s = s.substr(i, n);
    //     n = s.size();
    //     if (n == 0) return 0;
    //     i = n - 1;
    //     while (s[i] == ' ') i--;
    //     s = s.substr(0, i + 1);
    //     n = s.size();
    //     if (n == 0) return 0;
    // }

    // // Handle optional sign
    // bool isNeg = false;
    // if (s[0] == '-') {
    //     isNeg = true;
    //     s = s.substr(1, n);
    // } else if (s[0] == '+') {
    //     s = s.substr(1, n);
    // }

    // for (int i = 0; i < n; i++) {
    //     if (!isdigit(s[i])) break;
    //     // if (!(s[i] >= '0' && s[i] <= '9')) break;
    //     result *= 10;
    //     result += (s[i] - '0');
    //     if (isNeg && (-result) < INT_MIN) {
    //         return INT_MIN;
    //     } else if (!isNeg && result > INT_MAX) {
    //         return INT_MAX;
    //     }
    // }

    // if (isNeg) return static_cast<int>(-1 * result);
    // return (int)result;

    int n = s.size(), i = 0, sign = 1, result = 0;
    while (s[i] == ' ') i++;
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') sign = -1;
        i++;
    }

    while (i < n) {
        if (!isdigit(s[i])) break;
        if ((result > INT_MAX / 10) ||
            (result == INT_MAX / 10 && s[i] - '0' > 7)) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        result *= 10;
        result += (s[i] - '0');
        i++;
    }
    return result * sign;

    /*
    5
    -042
    42
    1337c0d3
    0-1
    words and 987


    -42
    42
    1337
    0
    0
    */
}

class TrieNode {
    vector<TrieNode *> container;

   public:
    TrieNode() { container = vector<TrieNode *>(26, nullptr); }

    void Add(char c, TrieNode *node) { container[c - 'a'] = node; }

    TrieNode *Get(char c) { return container[c - 'a']; }

    bool Contains(char c) { return container[c - 'a'] != nullptr; }
};

// https://www.youtube.com/watch?v=RV0QeTyHZxo
// https://www.naukri.com/code360/problems/count-distinct-substrings_985292
// https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/
int countDistinctSubstrings(string &s) {
    int n = s.size();
    /*
        time: O(n^2)
        space: O(n^3)
            if all the substrings are distinct then
            there will be n^2 substrings will be generated on an avarage
            string size is ~n/2[1,2,3,.....n-1,n]
            so its ~O(n^3)
    */
    // unordered_set<string> st({"", s});
    // for (int start = 0; start < n; start++) {   // starting point
    //     for (int j = 1; j <= n - start; j++) {  // len
    //         st.insert(s.substr(start, j));
    //     }
    // }
    // return st.size();

    /*
        time: O(n^2)
        space: -
            veriable in case of tri data structure
    */
    int counter = 0;
    TrieNode *root = new TrieNode();
    for (int i = 0; i < n; i++) {
        TrieNode *node = root;
        for (int j = i; j < n; j++) {
            if (!node->Contains(s[j])) {
                counter++;
                node->Add(s[j], new TrieNode());
            }
            node = node->Get(s[j]);
        }
    }
    return counter + 1;
}

// https://leetcode.com/problems/longest-palindromic-substring/description/
// https://takeuforward.org/data-structure/longest-palindromic-subsequence-dp-28/
string longestPalindrome(string &s) {
    int n = s.size();
    string result = "";
    auto isPalindrom = [](string s) -> bool {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            if (s[low] != s[high]) {
                return false;
            }
            low++, high--;
        }
        return true;
    };

    // for (int i = 0; i < n; i++) {  // O(n^3)
    //     string temp = "";
    //     for (int j = i; j < n; j++) {
    //         temp += s[j];
    //         if (isPalindrom(temp) && temp.size() > result.size()) {
    //             result = temp;
    //         }
    //     }
    // }
    int maxLen = 0, l, r;
    auto checkPalindrom = [&maxLen, &result, &n, s](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            int len = (r - l + 1);
            if (len > maxLen) {
                maxLen = len;
                result = s.substr(l, r - l + 1);
            }
            l--, r++;
        }
    };
    for (int i = 0; i < n; i++) {  // O(n^2)
        // odd length
        l = i, r = i;
        checkPalindrom(l, r);

        // even length
        l = i, r = i + 1;
        checkPalindrom(l, r);
    }
    return result;
    /*
    2
    babad
    cbbd

    bab
    bb
    */
}

// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
int beautySum(string &s) {
    int sum = 0, n = s.size();
    int maxVal, minVal, idx;
    for (int i = 0; i < n; i++) {
        vector<int> counter(26, 0);
        for (int j = i; j < n; j++) {
            idx = s[j] - 'a', counter[idx]++;
            maxVal = INT_MIN, minVal = INT_MAX;
            for (const int cnt : counter) {
                if (cnt <= 0) continue;
                maxVal = max(maxVal, cnt), minVal = min(minVal, cnt);
            }
            sum = sum + (maxVal - minVal);
        }
    }
    return sum;
    /*

    3
    aabcb
    aabcbaa
    xzvfsppsjfbxdwkqe

    5
    17
    64
    */
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        // cout << frequencySort(s) << endl;
        // cout << maxDepth(s) << endl;
        // cout << romanToInt(s) << endl;
        // cout << myAtoi(s) << endl;
        // cout << countDistinctSubstrings(s) << endl;
        // cout << longestPalindrome(s) << endl;
        cout << beautySum(s) << endl;
    }
    return 0;
}