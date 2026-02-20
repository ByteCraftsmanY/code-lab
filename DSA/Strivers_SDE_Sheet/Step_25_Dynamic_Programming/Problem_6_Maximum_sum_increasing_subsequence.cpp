// Maximum sum increasing subsequence
// Step: Dynamic Programming
// Difficulty: Hard
// Post Link: None
// LeetCode Link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// GFG Link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

#include <bits/stdc++.h>
using namespace std;

int helper(int prev, int curr, vector<int>& nums, vector<vector<int>>& dp) {
    int n = nums.size();
    if (curr >= n) return 0;

    // return cache result
    if (dp[prev + 1][curr] != -1) return dp[prev + 1][curr];

    // non pick
    int maxLen = helper(prev, curr + 1, nums, dp);

    // pick
    if (prev == -1 || nums[prev] < nums[curr]) {
        maxLen = max(maxLen, helper(curr, curr + 1, nums, dp) + 1);
    }
    dp[prev + 1][curr] = maxLen;

    return maxLen;
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    return helper(-1, 0, nums, dp);
}

// space optimized
int lengthOfLIS2(vector<int>& nums) {
    int n = nums.size(), maxLen = 0;
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(dp[i], maxLen);
    }
    return maxLen;
}

// print sequence
int lengthOfLIS3(vector<int>& nums) {
    int n = nums.size(), maxLen = 0;
    if (n == 0) return 0;
    vector<int> dp(n, 1);

    int idx = -1;
    vector<int> path(n, 0);
    for (int i = 0; i < n; i++) path[i] = i;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                path[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            idx = i;
        }
    }

    auto printer = [](vector<int>& data) {
        for (auto d : data) {
            cout << d << " ";
        }
        cout << endl;
    };
    printer(nums);
    printer(dp);
    printer(path);

    int i = maxLen - 1;
    vector<int> sequence(maxLen, 0);
    while (i >= 0) {
        sequence[i--] = nums[idx];
        idx = path[idx];
    }
    printer(sequence);

    return maxLen;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    // nums = {0, 1, 0, 3, 2, 3};
    // nums = {7, 7, 7, 7, 7, 7, 7};
    cout << lengthOfLIS3(nums) << endl;
    return 0;
}
