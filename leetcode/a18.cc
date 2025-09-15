#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), prefixSum = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) {
            if (prefixSum == sum - prefixSum - nums[i]) {
                return i;
            }
            prefixSum += nums[i];
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> arr = {
        {1, 7, 3, 6, 5, 6},
        {1, 2, 3},
        {2, 1, -1},
        {1, -1, 2},
    };
    Solution* s = new Solution();
    for (auto x : arr)
        cout << s->pivotIndex(x) << endl;
    return 0;
}