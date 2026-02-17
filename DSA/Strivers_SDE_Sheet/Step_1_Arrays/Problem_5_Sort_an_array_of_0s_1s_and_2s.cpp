// Sort an array of 0's, 1's and 2's
// Step: Arrays
// Difficulty: Medium
// Post Link: https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
// LeetCode Link: https://leetcode.com/problems/sort-colors/
// GFG Link: None

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int i = 0, j = 0, k = nums.size() - 1;
    while (j < k) {
        if (nums[j] == 2) {
            swap(nums[k--], nums[j]);
            continue;
        } else if (nums[j] == 0) {
            swap(nums[j], nums[i++]);
        }
        j++;
    }
}

int main() {
    return 0;
}
