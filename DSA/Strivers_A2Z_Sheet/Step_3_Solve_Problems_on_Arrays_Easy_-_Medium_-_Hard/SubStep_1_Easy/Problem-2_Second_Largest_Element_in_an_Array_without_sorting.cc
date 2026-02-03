// Second Largest Element in an Array without sorting
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/find-second-smallest-and-second-largest-element-in-an-array/
// LeetCode Link: N/A
// CodeStudio Link: https://www.naukri.com/code360/problems/second-largest-element-in-the-array_873375?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

int findSecondLargestElement(vector<int>& nums) {
    int ele1, ele2;
    ele1 = nums[0], ele2 = INT_MIN;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > ele1) {
            ele2 = ele1;
            ele1 = nums[i];
        }
        if (nums[i] > ele2 && nums[i] < ele1) {
            ele2 = nums[i];
        }
    }
    if (ele2 == INT_MIN) return -1;
    return ele2;
}

int main() {
    vector<int> nums = {2, 1, 23, 13, 21};
    int ele = findSecondLargestElement(nums);
    cout << ele;
    return 0;
}
