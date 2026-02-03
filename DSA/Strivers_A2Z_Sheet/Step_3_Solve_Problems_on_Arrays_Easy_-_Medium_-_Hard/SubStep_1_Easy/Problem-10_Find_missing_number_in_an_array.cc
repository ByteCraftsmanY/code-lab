// Find missing number in an array
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/arrays/find-the-missing-number-in-an-array/
// LeetCode Link: https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
using namespace std;

int findMissingNum(vector<int>& nums) {
    int n = *max_element(nums.begin(), nums.end()), sum = accumulate(nums.begin(), nums.end(), 0), actualSum = (n * (n + 1)) / 2;
    return actualSum - sum;
}

int main() {
    vector<int> nums = {0, 2, 3, 1, 4};
    cout << findMissingNum(nums) << " ";
    return 0;
}
