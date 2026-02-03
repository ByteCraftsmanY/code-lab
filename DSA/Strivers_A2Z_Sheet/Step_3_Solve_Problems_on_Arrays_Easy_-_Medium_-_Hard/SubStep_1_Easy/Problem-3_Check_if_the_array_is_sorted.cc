// Check if the array is sorted
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/check-if-an-array-is-sorted/
// LeetCode Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/#:~:text=Input%3A%20nums%20%3D%20%5B2%2C,no%20rotation)%20to%20make%20nums.

#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] > nums[i]) return false;
    }
    return true;
}

int main() {
    vector<int> nums = {2, 1, 23, 13, 21};
    nums = {1, 2, 3, 4, 5};
    cout << isSorted(nums) << endl;
    return 0;
}
