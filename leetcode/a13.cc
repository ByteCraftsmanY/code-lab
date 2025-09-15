#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1, ops = 0, sum = 0;
    while (i < j) {
        sum = nums[i] + nums[j];
        if (sum > k)
            j--;
        else if (sum < k)
            i++;
        else
            i++, j--, ops++;
    }
    return ops;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto& x : arr) {
        cin >> x;
    }
    int x = maxOperations(arr, m);
    cout << x << " ";
    return 0;
}