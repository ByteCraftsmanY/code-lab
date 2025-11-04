// Left Rotate an array by one place
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/left-rotate-the-array-by-one/
// LeetCode Link: https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums) {
    int n = nums.size();
    int ele = nums[0];
    for (int i = 1; i < n; i++) {
        nums[i - 1] = nums[i];
    }
    nums[n - 1] = ele;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    rotate(nums);
    for (auto num : nums) cout << num << endl;
    return 0;
}
