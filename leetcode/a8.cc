#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// bool increasingTriplet(vector<int>& nums) {
//     int n = nums.size();
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (nums[j] <= nums[i]) continue;
//             for (int k = j + 1; k < n; k++) {
//                 if (nums[k] <= nums[j]) continue;
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// https://www.youtube.com/watch?v=i340M1N4i8Y
bool increasingTriplet(vector<int>& nums) {
    int firstMin = INT_MAX, secondMin = INT_MAX;
    for (auto num : nums) {
        if (num < firstMin) {
            firstMin = num;
        } else if (num < secondMin) {
            secondMin = num;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (auto& x : arr) {
        cin >> x;
    }
    cout << increasingTriplet(arr);
    return 0;
}