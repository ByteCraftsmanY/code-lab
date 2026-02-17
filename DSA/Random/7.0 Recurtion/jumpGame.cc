#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums, int idx = 0) {
    int n = nums.size();
    if (idx >= (n - 1)) {
        return 0;
    }

    int mn = INT_MAX;
    for (int i = idx + 1; i < nums.size() && i <= idx + nums[i]; i++) {
        int rs = (jump(nums, i + idx));
        // printf("from [%d] = %d with jump: %d got %d\n", idx, nums[idx], i, rs);
        if (rs != INT_MAX)
            mn = min(mn, rs + 1);
    }
    return mn;
}

int main() {
    vector<int> arr = {3, 1, 1, 4};
    arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << jump(arr);
    return 0;
}