#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1, mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        bool isPrevEleSmaller = mid - 1 >= 0 ? nums[mid - 1] < nums[mid] : true;
        bool isNextEleSmaller = mid + 1 < n ? nums[mid + 1] < nums[mid] : true;
        if (isPrevEleSmaller && isNextEleSmaller)
            return mid;
        else if (mid + 1 < n && nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main() {
    vi arr = {1, 2, 1, 3, 5, 6, 4};
    arr = {1, 2, 3, 1};
    cout << findPeakElement(arr);
    return 0;
}