#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& arr, int k) {
    int l = 0, h = arr.size() - 1;
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (arr[m] == k) {
            return m;
        } else if (arr[m] < arr[h]) {
            if (k >= arr[m] && k <= arr[h]) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        } else {
            if (k >= arr[l] && k <= arr[m]) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {8, 9, 1, 2, 3, 4, 5, 6, 7};
    for (int i = 1; i <= 9; i++) {
        int res = find(arr, i);
        cout << "found: " << i << " at index: " << res << endl;
    }
    return 0;
}