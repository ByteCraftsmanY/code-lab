// https://leetcode.com/problems/maximum-subarray/description/

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