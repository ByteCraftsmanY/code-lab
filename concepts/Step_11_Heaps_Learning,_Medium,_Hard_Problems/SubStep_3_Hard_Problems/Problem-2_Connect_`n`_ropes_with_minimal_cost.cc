// Connect `n` ropes with minimal cost
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Hard Problems
// Post Link: https://takeuforward.org/data-structure/minimum-cost-to-connect-sticks
// LeetCode Link: N/A
// GFG Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int>& arr) {
    // code here
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    int result = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + b;
        result += c;
        pq.push(c);
    }
    return result;
}

int main() {
    return 0;
}
