// Minimum number of platforms required for a railway
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Medium/Hard
// Post Link: https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/
// LeetCode Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

int minPlatform(vector<int>& arr, vector<int>& dep) {
    // int maxPlatforms = 0;
    // for (int i = 0; i < arr.size(); i++) {
    //     int count = 1;
    //     for (int j = i + 1; j < dep.size(); j++) {
    //         // bool a = arr[i] >= arr[j] && dep[j] >= dep[i],
    //         //      b = arr[i] <= arr[j] && dep[j] >= dep[i];
    //         //  c = arr[i] >= arr[j] && dep[j] <= dep[i],
    //         //  d = arr[i] <= arr[j] && dep[j] <= dep[i];
    //         bool a = arr[i] >= arr[j] && arr[i] <= dep[j],
    //              b = arr[j] >= arr[i] && arr[j] <= dep[i];
    //         if (a || b) {
    //             count++;
    //         }
    //         maxPlatforms = max(maxPlatforms, count);
    //     }
    // }

    int i = 0, j = 0, count = 0, maxPlatforms = 0;
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    while (i < arr.size()) {
        if (arr[i] <= dep[j]) {
            count++, i++;
        } else {
            count--, j++;
        }
        maxPlatforms = max(maxPlatforms, count);
    }
    return maxPlatforms;
}

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800}, dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minPlatform(arr, dep) << endl;
    return 0;
}
