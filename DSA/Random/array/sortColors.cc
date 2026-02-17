// https://leetcode.com/problems/sort-colors/

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