// Linear Search
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/linear-search-in-c/
// LeetCode Link: N/A

#include <bits/stdc++.h>
using namespace std;

int findElementIndex(vector<int>& nums, int k) {
    for (int i = 0; i < nums.size(); i++) {
        if (k == nums.at(i)) return i;
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 0, 2, 3, 0, 4, 0, 1};
    cout << findElementIndex(nums, 5);
    return 0;
}
