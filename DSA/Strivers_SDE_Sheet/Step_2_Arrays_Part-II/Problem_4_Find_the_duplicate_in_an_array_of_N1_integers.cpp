// Find the duplicate in an array of N+1 integers
// Step: Arrays Part-II
// Difficulty: Medium
// Post Link: https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/
// LeetCode Link: https://leetcode.com/problems/find-the-duplicate-number/
// GFG Link: None

#include <bits/stdc++.h>
using namespace std;

/**
 * similar to detect cycle in linked list problem
 */

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 2};
    arr = {3, 1, 3, 4, 2};
    // arr = {3, 3, 3, 3, 3};
    cout << findDuplicate(arr);
    return 0;
}
