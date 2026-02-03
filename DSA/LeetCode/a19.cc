#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> resSt1, resSt2;
    unordered_set<int> st1(all(nums1)), st2(all(nums2));
    for (auto x : nums1)
        if (!st2.contains(x)) resSt1.insert(x);
    for (auto x : nums2)
        if (!st1.contains(x)) resSt2.insert(x);
    return {vector<int>(all(resSt1)), vector<int>(all(resSt2))};
}

int main() {
    vector<int> nums1 = {1, 2, 3, 3}, nums2 = {1, 1, 2, 2};
    auto res = findDifference(nums1, nums2);
    for (auto x : res) {
        for (auto e : x)
            cout << e << " ";
        cout << endl;
    }
}