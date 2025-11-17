// Jump Game
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Medium/Hard
// Post Link: https://takeuforward.org/Greedy/jump-game-i
// LeetCode Link: https://leetcode.com/problems/jump-game/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool helper(vector<int>& arr, vector<int>& dp, int idx) {
        if (idx == arr.size() - 1) {
            return true;
        } else if (idx >= arr.size()) {
            return false;
        } else if (dp[idx] != -1) {
            return dp[idx];
        }
        for (int i = idx + arr[idx]; i > idx; i--) {
            if (i >= arr.size()) continue;
            dp[i] = helper(arr, dp, i);
            if (dp[i]) {
                return true;
            }
        }
        return false;
    }

   public:
    bool canJump(vector<int>& arr) {
        vector<int> dp(arr.size(), -1);
        return this->helper(arr, dp, 0);
    }
};

/*
    only have to check if array has 0
    and if we are able to cross 0
    then we can reach at the end of the array
*/
bool canJump(vector<int>& nums) {
    int maxDistance = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxDistance)
            return false;
        else if (maxDistance >= nums.size())
            return true;
        maxDistance = max(maxDistance, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> arr = {2, 3, 1, 0, 4};
    arr = {3, 2, 1, 0, 4};
    cout << canJump(arr);
    return 0;
}
