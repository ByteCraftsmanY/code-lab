// Left rotate an array by D places
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/rotate-array-by-k-elements/
// LeetCode Link: https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start++], nums[end--]);
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) return;
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
    reverse(nums, 0, n - 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    rotate(nums, 2);
    for (auto num : nums) cout << num << endl;
    return 0;
}
