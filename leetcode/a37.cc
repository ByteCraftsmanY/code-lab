#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int minEatingSpeed(vector<int>& piles, int h) {
    int high = *max_element(piles.begin(), piles.end());

    // int res = INT_MAX;
    // for (int i = 1; i <= high; i++) {
    //     int hours = 0;
    //     for (int& x : piles) {
    //         hours += ceil((double)x / i);
    //     }
    //     if (hours <= h)
    //         res = min(res, i);
    // }

    int low = 1;
    long long mid = 0, hours;
    while (low <= high) {
        hours = 0, mid = low + ((high - low) / 2);
        for (int& x : piles)
            hours += ceil((double)x / mid);
        if (hours > h)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main() {
    vi arr;
    int h;
    arr = {3, 6, 7, 11}, h = 8;
    arr = {30, 11, 23, 4, 20}, h = 5;
    arr = {30, 11, 23, 4, 20}, h = 6;
    cout << minEatingSpeed(arr, h);
    return 0;
}