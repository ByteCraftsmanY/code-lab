// Print all subsequences/Power Set
// Step: Recursion [PatternWise]
// Sub Step: Subsequences Pattern
// Post Link: https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/
// LeetCode Link: https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size(), total = pow(2, n);
    for (int i = 0; i < total; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                temp.push_back(nums.at(j));
            }
        }
        result.push_back(temp);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (auto arr : res) {
        for (auto ele : arr)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}
