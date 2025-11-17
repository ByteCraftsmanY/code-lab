// Jump Game 2
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Medium/Hard
// Post Link: https://takeuforward.org/data-structure/jump-game-2
// LeetCode Link: https://leetcode.com/problems/jump-game-ii/

#include <bits/stdc++.h>
using namespace std;

/*
    TC: WithDp: O(n^2), without dp: O(n^n)
    SC: WithDp: O(n^2), without dp: O(n)
*/
int helper(vector<int>& nums, int idx, int jumps, vector<vector<int>>& dp) {
    if (idx >= nums.size() - 1)
        return jumps;
    else if (dp[idx][jumps] != -1)
        return dp[idx][jumps];

    int minJumps = INT_MAX;
    for (int i = idx + 1; i < nums.size() && i <= idx + nums[idx]; i++) {
        minJumps = min(minJumps, helper(nums, i, jumps + 1, dp));
    }

    dp[idx][jumps] = minJumps;
    return minJumps;
}

int jump(vector<int>& nums) {
    // vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    // return helper(nums, 0, 0, dp);

    int jumps = 0, curr = 0, maxRight = 0;
    for (int idx = 0; idx < nums.size() - 1; idx++) {
        maxRight = max(maxRight, idx + nums[idx]);
        if (idx == curr) {
            jumps++;
            curr = maxRight;
        }
    }
    return jumps;
}

int main() {
    vector<int> nums = {2, 0, 2, 0, 1};
    // nums = {2, 0, 2, 0, 1};
    // nums = {4, 1, 1, 3, 1, 1, 1};
    cout << jump(nums) << endl;
    return 0;
}
