// Kth largest element in a stream of running integers
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Hard Problems
// Post Link: https://takeuforward.org/data-structure/kth-largest-element-in-a-stream-of-running-integers
// LeetCode Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/#:~:text=Implement%20KthLargest%20class%3A,largest%20element%20in%20the%20stream.

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    int k = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        while (pq.size() > k) {
            this->pq.pop();
        }
    }

    int add(int val) {
        this->pq.push(val);
        if (this->pq.size() > this->k) {
            this->pq.pop();
        }
        return this->pq.top();
    }
};

int main() {
    return 0;
}
