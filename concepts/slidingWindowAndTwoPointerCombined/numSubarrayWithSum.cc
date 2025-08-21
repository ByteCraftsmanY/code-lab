#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int count = 0, n = nums.size();
    // for (int i = 0; i < n; i++) {
    //     int sum = 0;
    //     for (int j = i; j < n; j++) {
    //         sum += nums[j];
    //         if (sum == goal) {
    //             count++;
    //         } else if (sum > goal) {
    //             break;
    //         }
    //     }
    // }

    int i = 0, j = 0, sum = 0;
    while (j < n) {
        sum += nums[j];
        if (sum == goal) {
            count++;
        }
        while (i < j && sum > goal) {
            sum -= nums[i++];
        }
        j++;
    }
    while (i < j && sum >= goal) {
        if (sum == goal) count++;
        sum -= nums[i++];
    }

    return count;
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    nums = {0, 0, 0, 0, 0}, goal = 0;
    cout << numSubarraysWithSum(nums, goal) << endl;
    return 0;
}