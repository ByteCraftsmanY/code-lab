// Maximum Sum Combination
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Hard Problems
// Post Link: https://takeuforward.org/data-structure/maximum-sum-combination
// artical: https://www.geeksforgeeks.org/dsa/k-maximum-sum-combinations-two-arrays/
// LeetCode Link: https://www.interviewbit.com/problems/maximum-sum-combinations/
// GFG Link: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
// Code360: https://www.naukri.com/code360/problems/k-max-sum-combinations_975322?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    vector<int> result;
    set<pair<int, int>> pairs;
    priority_queue<tuple<int, int, int>> pq;
    pq.push(make_tuple(a.front() + b.front(), 0, 0));
    pairs.insert({0, 0});

    while (k-- && !pq.empty()) {
        auto [sum, i, j] = pq.top();
        pq.pop();
        result.push_back(sum);

        if (i + 1 < a.size() && pairs.find(make_tuple(i + 1, j)) == pairs.end()) {
            pq.push(make_tuple(a[i + 1] + b[j], i + 1, j));
            pairs.insert(make_pair(i + 1, j));
        }
        if (j + 1 < b.size() && pairs.find(make_tuple(i, j + 1)) == pairs.end()) {
            pq.push({a[i] + b[j + 1], i, j + 1});
            pairs.insert({i, j + 1});
        }
    }

    return result;
}

int main() {
    vector<int> a = {1, 4, 2, 3}, b = {2, 5, 1, 6}, result = topKSumPairs(a, b, 3);
    for (auto const x : result) cout << x << " ";
    return 0;
}
