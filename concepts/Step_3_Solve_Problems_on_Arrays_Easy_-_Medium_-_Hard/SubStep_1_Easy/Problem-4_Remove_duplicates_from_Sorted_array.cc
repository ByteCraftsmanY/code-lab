// Remove duplicates from Sorted array
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/
// LeetCode Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/#:~:text=Input%3A%20nums%20%3D%20%5B0%2C,%2C%203%2C%20and%204%20respectively.

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 0, n = nums.size();
    while (i < n) {
        swap(nums[i], nums[j]);
        i++;
        if (j == 0 || nums[j] != nums[j - 1]) {
            j++;
        }
    }
    return j;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5, 5, 5};
    int n = removeDuplicates(nums);
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    return 0;
}
