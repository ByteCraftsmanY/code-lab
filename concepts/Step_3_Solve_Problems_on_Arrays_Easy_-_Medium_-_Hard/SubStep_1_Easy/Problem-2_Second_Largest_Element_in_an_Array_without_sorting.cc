// Second Largest Element in an Array without sorting
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/find-second-smallest-and-second-largest-element-in-an-array/
// LeetCode Link: N/A

#include <bits/stdc++.h>
using namespace std;

int findSecondLargestElement(vector<int>& nums) {
    int ele1, ele2;
    ele1 = INT_MIN, ele2 = INT_MIN;
    for (auto num : nums) {
        if (num > ele1) {
            ele1 = num;
        }
        if (num > ele2 && num != ele1) {
            ele2 = num;
        }
    }
    return ele2;
}

int main() {
    vector<int> nums = {2, 1, 23, 13, 21};
    int ele = findSecondLargestElement(nums);
    cout << ele;
    return 0;
}
