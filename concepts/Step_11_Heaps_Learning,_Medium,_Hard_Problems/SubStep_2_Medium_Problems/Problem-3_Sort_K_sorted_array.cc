// Sort K sorted array
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Medium Problems
// Post Link: https://takeuforward.org/data-structure/sort-k-sorted-array
// LeetCode Link: N/A
// CodingNinja: https://www.naukri.com/code360/problems/nearly-sorted_982937

#include <bits/stdc++.h>
using namespace std;

void sortK(vector<int>& arr, int k) {
    // brute force
    // O(nlogn)
    // sort(arr.begin(), arr.end());

    // O(nk)
    // by insertion sort
    // for (int i = 1; i < arr.size(); i++) {
    //     int j = i, k = i;
    //     while (j >= 0) {
    //         if (arr[j] > arr[k]) {
    //             swap(arr[j], arr[k]);
    //             k = j;
    //         }
    //         j--;
    //     }
    // }

    // by min heap
    // O(n + (n-k)logk + (k+1)logk)
    vector<int> result;
    result.reserve(arr.size());
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k + 1);
    for (int i = k + 1; i < arr.size(); i++) {
        result.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    arr = result;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for (auto& x : arr) cin >> x;
        sortK(arr, k);
        for (const auto x : arr) cout << x << " ";
        cout << endl;
    }
    return 0;
}
