// Task Scheduler
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Medium Problems
// Post Link: https://takeuforward.org/data-structure/task-scheduler
// LeetCode Link: https://leetcode.com/problems/task-scheduler/

#include <bits/stdc++.h>
using namespace std;

int minTimeToCompleteTasks(vector<char>& tasks, int n) {
    int timeUnit = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    unordered_map<char, int> mp;
    for (auto task : tasks) {
        mp[task]++;
    }
    for (auto [k, v] : mp) {
        pq.push(v);
    }
    while (!pq.empty() || !q.empty()) {
        timeUnit++;
        if (!pq.empty()) {
            int ele = pq.top();
            pq.pop();
            ele--;
            if (ele > 0) {
                q.push(make_pair(ele, timeUnit + n));
            }
        }
        if (!q.empty() && timeUnit == q.front().second) {
            pq.push(q.front().first);
            q.pop();
        }
    }
    return timeUnit;
}

int main() {
    vector<char> arr = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << minTimeToCompleteTasks(arr, 2) << endl;
    return 0;
}
