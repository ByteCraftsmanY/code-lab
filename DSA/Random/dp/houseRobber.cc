// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int>& arr, int idx, vector<int>& dp) {
    if (idx >= arr.size()) {
        return 0;
    }
    if (dp[idx] != -1) return dp[idx];
    int include = arr[idx] + findMax(arr, idx + 2, dp);
    int notInclude = findMax(arr, idx + 1, dp);
    dp[idx] = max(include, notInclude);
    return dp[idx];
}

int houseRobber(vector<int>& arr) {
    vector<int> dp(arr.size(), -1);
    return findMax(arr, 0, dp);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
    }
    return dp[n];
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 1},
        {2, 7, 9, 3, 1},
    };
    for (auto& row : mat) {
        cout << rob(row) << endl;
    }
    return 0;
}