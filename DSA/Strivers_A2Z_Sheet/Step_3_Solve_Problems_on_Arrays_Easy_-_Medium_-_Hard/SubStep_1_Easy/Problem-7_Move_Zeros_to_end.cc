// Move Zeros to end
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/move-all-zeros-to-the-end-of-the-array/
// LeetCode Link: https://leetcode.com/problems/move-zeroes/

#include <bits/stdc++.h>
using namespace std;

int moveK(vector<int>& nums, int k = 0) {
    int i = 0, j = 0, n = nums.size();
    while (i < n) {
        swap(nums[i], nums[j]);
        i++;
        if (nums[j] != k) {
            j++;
        }
    }
    return j;
}

int main() {
    vector<int> nums = {1, 0, 2, 3, 0, 4, 0, 1};
    int k = moveK(nums);
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
