#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int i = 0, j = 0, c = 0, maxLen = 0;
    // while (i < nums.size()) {
    //     while (c > k && j <= i) {
    //         if (nums[j] == 0) c--;
    //         j++;
    //     }
    //     maxLen = max(maxLen, i - j);
    //     if (nums[i] == 0) c++;
    //     i++;
    // }
    // if (c <= k)
    //     maxLen = max(maxLen, i - j);
    while (i < nums.size()) {
        if (nums[i] == 0) c++;
        if (c > k) {
            if (nums[j] == 0) c--;
            j++;
        }
        if (c <= k) maxLen = max(maxLen, i - j + 1);
        i++;
    }
    return maxLen;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, m = 2;
    // arr = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, m = 3;
    // arr = {0, 0, 0, 1}, m = 4;
    double x = longestOnes(arr, m);
    cout << x << " ";
    return 0;
}