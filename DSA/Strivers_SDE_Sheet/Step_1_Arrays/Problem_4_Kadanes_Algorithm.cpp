// Kadane's Algorithm
// Step: Arrays
// Difficulty: Easy
// Post Link: https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
// LeetCode Link: https://leetcode.com/problems/maximum-subarray/
// GFG Link: None

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currSum = 0, maxSum = INT_MIN;
    for (auto x : nums) {
        if (currSum < 0) currSum = 0;
        currSum += x;
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    return 0;
}
