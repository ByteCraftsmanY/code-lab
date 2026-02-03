#include <bits/stdc++.h>
using namespace std;

/**
 * Backtracking function to find all possible expressions that evaluate to target
 * @param result Vector to store valid expressions
 * @param num Input number string
 * @param target Target sum to achieve
 * @param exp Current expression being built
 * @param idx Current index in num string
 * @param sum Current sum of the expression
 * @param lastNum Last number in the expression (needed for multiplication)
 */
void backtrack(vector<string>& result, string num, int target, string exp,
               int idx, long long sum, long long lastNum) {
    // Base case: if we've used all digits
    if (idx == num.size()) {
        if (sum == target) {
            result.push_back(exp);
        }
        return;
    }

    // Try all possible numbers starting from current index
    for (int i = idx; i < num.size(); i++) {
        string subnum = num.substr(idx, i - idx + 1);

        // Skip numbers with leading zeros
        if (subnum.size() > 1 && subnum[0] == '0') {
            continue;
        }

        long long digit = stoll(subnum);

        // For first number, just add it without operator
        if (idx == 0) {
            backtrack(result, num, target, exp + subnum, i + 1, sum + digit, digit);
            continue;
        }

        // Try addition
        backtrack(result, num, target, exp + '+' + subnum, i + 1, sum + digit, digit);

        // Try subtraction
        backtrack(result, num, target, exp + '-' + subnum, i + 1, sum - digit, -digit);

        // Try multiplication
        // For multiplication, we need to:
        // 1. Subtract the last number from current sum
        // 2. Multiply last number with current digit
        // 3. Add the result back to sum
        backtrack(result, num, target, exp + '*' + subnum, i + 1,
                  (sum - lastNum) + (lastNum * digit), lastNum * digit);
    }
}

/**
 * Main function to find all expressions that evaluate to target
 * @param num Input number string
 * @param target Target sum to achieve
 * @return Vector of valid expressions
 */
vector<string> addOperators(string num, int target) {
    vector<string> result;
    if (num.empty()) {
        return result;
    }
    backtrack(result, num, target, "", 0, 0, 0);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string num;
        int target;
        getline(cin, num);
        cin >> target;
        cin.ignore();

        auto result = addOperators(num, target);
        for (const auto& expr : result) {
            cout << expr << endl;
        }
        cout << endl;
    }
    return 0;
}
