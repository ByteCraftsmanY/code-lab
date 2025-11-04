// Maximum Consecutive Ones
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/count-maximum-consecutive-ones-in-the-array/
// LeetCode Link: https://leetcode.com/problems/max-consecutive-ones/

#include <bits/stdc++.h>
using namespace std;

int maxOccuranceOnce(vector<int>& nums) {
    int maxOneFinal = 0, maxOneTemp = 0;
    for (int num : nums) {
        if (num != 1) {
            maxOneTemp = 0;
            continue;
        }
        maxOneTemp++;
        maxOneFinal = max(maxOneFinal, maxOneTemp);
    }
    return maxOneFinal;
}

int main() {
    vector<int> nums = {1, 0, 1, 1, 0, 1};
    nums = {1, 1, 0, 1, 1, 1};
    cout << maxOccuranceOnce(nums);
    return 0;
}
