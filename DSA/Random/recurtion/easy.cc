#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/string-to-integer-atoi/description/
int myAtoI(string s) {
    int i = 0, n = s.size();
    while (i < n && s[i] == ' ') i++;
    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') sign = -1;
        i++;
    }
    while (s[i] == '0') i++;
    int result = 0;
    while (i < n) {
        if (!isdigit(s[i])) return result;
        int val = s[i++] - '0';
        if ((INT_MAX / 10) < result || (result == (INT_MAX / 10) && val > 7)) {
            if (sign == -1) {
                return INT_MIN;
            }
            return INT_MAX;
        }
        result *= 10;
        result += val;
    }
    return sign == -1 ? -result : result;
}

int myAtoIHelper(string s, int idx, int sign, int result) {
    if (idx == s.size() || !isdigit(s[idx])) {
        return sign == -1 ? -result : result;
    }
    int val = s[idx] - '0';
    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && val > 7)) {
        return sign == -1 ? INT_MIN : INT_MAX;
    }
    return myAtoIHelper(s, idx + 1, sign, (result * 10) + val);
}

int myAtoIRecursive(string s) {
    int i = 0, n = s.size();
    while (i < n && s[i] == ' ') i++;
    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') sign = -1;
        i++;
    }
    while (s[i] == '0') i++;
    return myAtoIHelper(s, i, sign, 0);
}

// https://leetcode.com/problems/powx-n/description/
double myPow(double x, long long n) {
    if (n < 0) return 1 / myPow(x, -n);
    if (n == 0) return 1;
    return n & 1 ? x * myPow(x, n - 1) : myPow(x * x, n / 2);
}

int countGoodNumbersHelper(long long n, int idx, int len, long long &result) {
    if (n == 0) return 0;
    const vector<char> evenNums = {'0', '2', '4', '6', '8'};
    const vector<char> oddNums = {'2', '3', '5', '7'};
    long long modulo = (10e9) + 7;
    if (len == n) {
        result++;
        return result % modulo;
    }
    if (idx & 1) {
        for (auto const &x : oddNums) {
            countGoodNumbersHelper(n, idx + 1, len + 1, result);
        }
    } else {
        for (auto const &x : evenNums) {
            countGoodNumbersHelper(n, idx + 1, len + 1, result);
        }
    }
    return result;
}

// https://leetcode.com/problems/count-good-numbers/description/
int countGoodNumbers(int n, int idx = 0, int result = 1) {
    // O(5^n) -> exponential
    // long long res = 0;
    // return countGoodNumbersHelper(n, 0, 0, res);

    // O(n)
    // if (n == 0) {
    //     return result;
    // }
    // return (idx & 1) ? 4 * countGoodNumbers(n - 1, idx + 1, result) : 5 * countGoodNumbers(n - 1, idx + 1, result);

    // O(2log(n))
    int MOD = 1e9 + 7;
    auto powerHelper = [&MOD](long long x, long long n) -> long long int {
        long long int result = 1;
        while (n) {
            if (n & 1) {
                result = (result * x) % MOD;
                n--;
            } else {
                x = (x * x) % MOD;
                n /= 2;
            }
        }
        return result;
    };
    long long evens = powerHelper(5, (n + 1) / 2);
    long long odds = powerHelper(4, n / 2);
    return (evens * odds) % MOD;
}

void sortedInsert(stack<int> &st, int n) {
    if (st.empty() || st.top() < n) {
        st.push(n);
        return;
    }
    int temp = st.top();
    st.pop();
    sortedInsert(st, n);
    st.push(temp);
}

void sortStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }
    int x = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, x);
}

void insertAtLast(stack<int> &st, int n) {
    if (st.empty()) {
        st.push(n);
        return;
    }
    int x = st.top();
    st.pop();
    insertAtLast(st, n);
    st.push(x);
}

// https://www.geeksforgeeks.org/problems/reverse-a-stack/1
void reverseStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }
    int x = st.top();
    st.pop();
    reverseStack(st);
    insertAtLast(st, x);
}

void binaryStringsGenerator(vector<string> &ans, int num, string s = "", int idx = 0) {
    if (idx == num) {
        ans.push_back(s);
        return;
    }
    binaryStringsGenerator(ans, num, s + '0', idx + 1);
    if (!s.empty() && s.back() == '1') {
        return;
    }
    binaryStringsGenerator(ans, num, s + '1', idx + 1);
}

// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1
vector<string> generateBinaryStrings(int num) {
    vector<string> ans;
    binaryStringsGenerator(ans, num);
    return ans;
}

void parenthesisGenerator(vector<string> &ans, int n, string s, int open, int close) {
    if (open == close && close == n) {
        ans.push_back(s);
        return;
    }
    if (open < n)
        parenthesisGenerator(ans, n, s + '(', open + 1, close);
    if (close < n && open > close) {
        parenthesisGenerator(ans, n, s + ')', open, close + 1);
    }
}

// https://leetcode.com/problems/generate-parentheses/
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    parenthesisGenerator(ans, n, "", 0, 0);
    return ans;
}

// Time Complexity: O(2^n * n)
// Space Complexity: O(n) for recursion stack
// For each element, we have 2 choices: include or exclude
// This creates a binary tree with 2^n leaf nodes
// Each leaf node requires O(n) time to copy the result vector
void subsetsGenerator(vector<vector<int>> &ans, vector<int> &result, vector<int> &nums, int idx) {
    if (idx == nums.size()) {
        ans.push_back(result);
        return;
    }
    result.push_back(nums.at(idx));
    subsetsGenerator(ans, result, nums, idx + 1);
    result.pop_back();
    subsetsGenerator(ans, result, nums, idx + 1);
}

// https://leetcode.com/problems/subsets/
vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> result;
    subsetsGenerator(ans, result, nums, 0);
    return ans;
}

// Time Complexity: O(2^n)
// Space Complexity: O(n) for recursion stack
//
// Analysis:
// - For each element, we have 2 choices: include or exclude
// - This creates a binary tree with 2^n leaf nodes
// - Each recursive call takes O(1) time
// - Total recursive calls: 2^(n+1) - 1 ≈ 2^n
// - Maximum recursion depth: n (when we reach the end of array)
int wayFinder(vector<int> &arr, int k, int idx, int sum) {
    int MOD = 1e9 + 7;
    if (sum > k) {
        return 0;
    }
    if (idx == arr.size()) {
        if (sum == k) {
            return 1;
        }
        return 0;
    }
    int include = wayFinder(arr, k, idx + 1, sum + arr.at(idx));
    int exclude = wayFinder(arr, k, idx + 1, sum);
    return (include + exclude) % MOD;
}

// Time Complexity: O(n * k)
// Space Complexity: O(n * k) for DP table + O(n) for recursion stack
//
// Analysis:
// - DP table size: n rows (indices) × k+1 columns (sums from 0 to k)
// - Each state (idx, sum) is computed only once due to memoization
// - Total unique states: n * k
// - Each state computation takes O(1) time
// - Therefore, total time complexity: O(n * k)
int wayFinderWithDP(vector<int> &arr, int k, vector<vector<int>> &dp, int idx, int sum) {
    int MOD = 1e9 + 7;
    if (sum > k) {
        return 0;
    }
    if (idx == arr.size()) {
        if (sum == k) {
            return 1;
        }
        return 0;
    }
    if (dp[idx][sum] != -1) {
        return dp[idx][sum];
    }
    int include = wayFinderWithDP(arr, k, dp, idx + 1, sum + arr.at(idx));
    int exclude = wayFinderWithDP(arr, k, dp, idx + 1, sum);
    dp[idx][sum] = (include + exclude) % MOD;
    return dp[idx][sum];
}

// Prerequesit
// - https://youtu.be/fWX9xDmIzRI?si=dlt--3Tn168SsE2Z
// - https://youtu.be/eQCS_v3bw0Q?si=4EwRFs0vrefNIBld
// - https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532
int findWays(vector<int> &arr, int k) {
    // return wayFinder(arr, k, 0, 0);

    vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
    return wayFinderWithDP(arr, k, dp, 0, 0);
}

bool checkSubsequenceSumHelper(vector<int> &arr, int k, vector<vector<int>> &dp, int idx, int sum) {
    if (idx == arr.size()) {
        return k == sum;
    }
    if (sum > k) return false;
    if (dp[idx][sum] != -1) return dp[idx][sum];
    dp[idx][sum] = checkSubsequenceSumHelper(arr, k, dp, idx + 1, sum + arr.at(idx)) || checkSubsequenceSumHelper(arr, k, dp, idx + 1, sum);
    return dp[idx][sum];
}

// https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1
bool checkSubsequenceSum(int n, vector<int> &arr, int k) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return checkSubsequenceSumHelper(arr, k, dp, 0, 0);
}

void combinationSumHelper(vector<vector<int>> &ans, vector<int> &result, vector<int> &candidates, int target, int sum, int idx = 0) {
    if (sum > target) {
        return;
    }
    if (sum == target) {
        ans.push_back(result);
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        int candidate = candidates.at(i);
        result.push_back(candidate);
        combinationSumHelper(ans, result, candidates, target, sum + candidate, i);
        result.pop_back();
    }
}

// https://leetcode.com/problems/combination-sum/
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> result;
    combinationSumHelper(ans, result, candidates, target, 0);
    return ans;
}

void combinationSum2Helper(vector<vector<int>> &ans, vector<int> &result, vector<int> &candidates, int target, int sum, int idx = 0) {
    if (sum > target) {
        return;
    }
    if (sum == target) {
        ans.push_back(result);
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        if (i > 0 && candidates[i] == candidates[i - 1]) continue;
        int candidate = candidates.at(i);
        result.push_back(candidate);
        combinationSum2Helper(ans, result, candidates, target, sum + candidate, i + 1);
        result.pop_back();
    }
}

// https://leetcode.com/problems/combination-sum-ii/
vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> result;
    sort(candidates.begin(), candidates.end());
    combinationSum2Helper(ans, result, candidates, target, 0);
    return ans;
}

void subsetSumsGenerator(vector<int> &arr, vector<int> &result, int idx, int sum) {
    if (idx == arr.size()) {
        result.push_back(sum);
        return;
    }
    subsetSumsGenerator(arr, result, idx + 1, sum + arr[idx]);
    subsetSumsGenerator(arr, result, idx + 1, sum);
}

// https://www.geeksforgeeks.org/problems/subset-sums2234/1&selectedLang=python3
vector<int> subsetSums(vector<int> &arr) {
    vector<int> result;
    subsetSumsGenerator(arr, result, 0, 0);
    sort(result.begin(), result.end());
    return result;
}

void subsetsWithDupGenerator(vector<vector<int>> &ans, vector<int> &result, vector<int> &nums, int idx) {
    ans.push_back(result);
    for (int i = idx; i < nums.size(); i++) {
        if (i != idx && nums[i] == nums[i - 1]) continue;
        result.push_back(nums.at(idx));
        subsetsWithDupGenerator(ans, result, nums, i + 1);
        result.pop_back();
    }
}

// https://leetcode.com/problems/subsets-ii/
vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> result;
    sort(nums.begin(), nums.end());
    subsetsWithDupGenerator(ans, result, nums, 0);
    return ans;
}

void combinationSum3Generator(vector<vector<int>> &ans, vector<int> &result, int k, int n, int idx = 1, int sum = 0) {
    if (result.size() == k) {
        if (sum == n)
            ans.push_back(result);
        return;
    }
    for (int i = idx; i <= 9; i++) {
        if ((sum + i) > n) {
            break;
        }
        result.push_back(i);
        combinationSum3Generator(ans, result, k, n, i + 1, sum + i);
        result.pop_back();
    }
}

// https://leetcode.com/problems/combination-sum-iii/
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> result;
    combinationSum3Generator(ans, result, k, n);
    return ans;
}

unordered_map<char, string> lattersMap = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

void letterCombinationsGenerator(vector<string> &ans, string res, string digits, int idx) {
    if (idx == digits.size()) {
        ans.push_back(res);
        return;
    }
    for (char const &c : lattersMap[digits[idx]]) {
        letterCombinationsGenerator(ans, res + c, digits, idx + 1);
    }
}

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans;
    letterCombinationsGenerator(ans, "", digits, 0);
    return ans;
}

int main() {
    int t = 1;
    // cin >> t;
    // cin.ignore();
    while (t--) {
        // string s;
        // getline(cin, s);
        // cout << myAtoI(s) << endl;
        // cout << myAtoIRecursive(s) << endl;

        // int n;
        // long long res = 0;
        // cin >> n;
        // cout << countGoodNumbers(n, 0, 0, res) << endl;
        // cout << countGoodNumbers(n) << endl;
        // vector<int> arr = {11, 2, 32, 3, 41};
        // stack<int> st;
        // for (auto const &x : arr) st.push(x);
        // // sortStack(st);
        // // reverseStack(st);
        // while (!st.empty()) {
        //     cout << st.top() << "\t";
        //     st.pop();
        // }

        // int n;
        // cin >> n;
        // vector<string> results = generateBinaryStrings(n);
        // vector<string> results = generateParenthesis(n);
        // for (auto const &s : results) {
        //     cout << s << endl;
        // }
        // cout << endl;

        // vector<int> nums = {1, 2, 3};
        // auto ans = subsets(nums);
        // for (auto const &row : ans) {
        //     for (auto const &ele : row)
        //         cout << ele << " ";
        //     cout << endl;
        // }

        // vector<int> nums = {1, 1, 4, 5};
        // int result = findWays(nums, 5);
        // cout << result << endl;

        // vector<int> arr = {2, 3, 5, 7, 9};  //{10, 1, 2, 7, 6, 1, 5};
        // int k = 100;                        // 8;
        // cout << checkSubsequenceSum(arr.size(), arr, k) << endl;

        // vector<int> arr = {2, 3, 5};  //{2, 3, 6, 7};
        // int k = 8;                    // 7;
        // auto result = combinationSum2(arr, k);
        // for (auto row : result) {
        //     for (auto ele : row) {
        //         cout << ele << " ";
        //     }
        //     cout << endl;
        // }

        // vector<int> arr = {1, 2, 1};
        // vector<int> res = subsetSums(arr);
        // for (auto x : res) cout << x << " ";

        // vector<int> arr = {1, 1, 2, 2};
        // auto result = subsetsWithDup(arr);
        // for (auto row : result) {
        //     for (auto ele : row) {
        //         cout << ele << " ";
        //     }
        //     cout << endl;
        // }

        // auto result = combinationSum3(3, 9);
        // for (auto row : result) {
        //     for (auto ele : row) {
        //         cout << ele << " ";
        //     }
        //     cout << endl;
        // }

        auto result = letterCombinations("");
        for (auto const &s : result) cout << s << endl;
    }
    return 0;
}
