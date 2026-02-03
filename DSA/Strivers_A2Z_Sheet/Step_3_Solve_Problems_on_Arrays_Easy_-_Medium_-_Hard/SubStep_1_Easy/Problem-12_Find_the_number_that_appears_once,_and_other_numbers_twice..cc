// Find the number that appears once, and other numbers twice.
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/arrays/find-the-number-that-appears-once-and-the-other-numbers-twice/
// LeetCode Link: https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

int findEle(vector<int>& nums) {
    int ele = 0;
    for (int num : nums) ele ^= num;
    return ele;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << findEle(nums);
    return 0;
}
