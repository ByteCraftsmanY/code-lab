// Merge Overlapping Subintervals
// Step: Arrays Part-II
// Difficulty: Medium
// Post Link: https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
// LeetCode Link: https://leetcode.com/problems/merge-intervals/
// GFG Link: https://bit.ly/3zRz904

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) -> bool {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    int i = 0, n = intervals.size(), j = 0, sec;
    while (i < n) {
        vector<int> temp = {intervals[i][0]};
        sec = intervals[i][1];
        j = i + 1;
        while (j < n && sec >= intervals[j][0]) {
            sec = max(sec, intervals[j][1]);
            j++;
        }
        temp.push_back(intervals[j - 1][1]);
        i = j;
        result.push_back(temp);
    }
    return result;
}

int main() {
    vector<vector<int>> mat = {{1, 3}, {0, 2}, {2, 3}, {4, 6}, {4, 5}, {5, 5}, {0, 2}, {3, 3}}, res = merge(mat);
    for (auto x : res) {
        for (auto c : x) cout << c << " ";
        cout << endl;
    }
    return 0;
}
