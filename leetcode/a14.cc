

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n) return 0;
    int i = 0;
    double sum = 0, maxAvg = 0, prevIdx = 0;
    while (i < k) {
        sum += (double)nums[i++] / (double)k;
    }
    maxAvg = sum;
    while (i < n) {
        sum -= ((double)nums[prevIdx++] / (double)k);
        sum += ((double)nums[i++] / (double)k);
        maxAvg = max(sum, maxAvg);
    }
    return maxAvg;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto& x : arr) {
        cin >> x;
    }
    double x = findMaxAverage(arr, m);
    cout << x << " ";
    return 0;
}