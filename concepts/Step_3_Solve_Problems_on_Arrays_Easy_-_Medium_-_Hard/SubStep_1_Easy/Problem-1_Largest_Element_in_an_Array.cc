// Largest Element in an Array
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/find-the-largest-element-in-an-array/
// LeetCode Link: N/A

#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& nums) {
    if (nums.size() == 0) return -1;
    int ele = nums[0];
    for (auto num : nums) {
        ele = max(num, ele);
    }
    return ele;
}

int main() {
    vector<int> nums = {2, 1, 23, 13, 21};
    int ele = largestElement(nums);
    cout << ele;
    return 0;
}
