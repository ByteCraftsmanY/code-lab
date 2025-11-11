// Kth smallest element in an array [use priority queue]
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Medium Problems
// Post Link: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/
// LeetCode Link: N/A

#include <bits/stdc++.h>
using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    for (int i = 0; i < k; i++) {
        res = pq.top();
        pq.pop();
    }
    return res;
}

int main() {
    vector<int> elements = {3, 2, 1, 5, 6, 4};
    int k = 1, res = findKthSmallest(elements, k);
    cout << format("\n {} \n", res);
    return 0;
}
