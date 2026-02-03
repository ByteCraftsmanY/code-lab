#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size()) {
            swap(nums[i], nums[j]);
            if (nums[j] != 0) j++;
            i++;
        }
    }
};