// Kadane's Algorithm, maximum subarray sum
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Medium
// Post Link: https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
// LeetCode Link: https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int>& arr) {
    int maxSum = INT_MIN, curSoFar = 0;
    for (auto const& x : arr) {
        curSoFar = max(curSoFar + x, x);
        maxSum = max(maxSum, curSoFar);
        if (curSoFar < 0) curSoFar = 0;
    }
    return maxSum;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << findMaxSum(arr);
    return 0;
}
