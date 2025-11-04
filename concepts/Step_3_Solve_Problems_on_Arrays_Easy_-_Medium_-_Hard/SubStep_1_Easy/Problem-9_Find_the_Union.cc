// Find the Union
// Step: Solve Problems on Arrays [Easy -> Medium -> Hard]
// Sub Step: Easy
// Post Link: https://takeuforward.org/data-structure/union-of-two-sorted-arrays/
// LeetCode Link: N/A

#include <bits/stdc++.h>
using namespace std;

vector<int> makeUnion(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums = {};
    int i = 0, j = 0, n = nums1.size(), m = nums2.size();

    auto addElement = [&nums](int ele) {
        if (!nums.empty() && nums.back() == ele) return;
        nums.push_back(ele);
    };

    while (i < n && j < m) {
        if (nums1[i] < nums2[j])
            addElement(nums1[i++]);
        else
            addElement(nums2[j++]);
    }
    while (i < n) addElement(nums1[i++]);
    while (j < m) addElement(nums2[j++]);
    return nums;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5}, arr2 = {2, 3, 4, 4, 5}, result = makeUnion(arr1, arr2);
    arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, arr2 = {2, 3, 4, 4, 5, 11, 12}, result = makeUnion(arr1, arr2);
    for (auto x : result) cout << x << " ";
    return 0;
}
