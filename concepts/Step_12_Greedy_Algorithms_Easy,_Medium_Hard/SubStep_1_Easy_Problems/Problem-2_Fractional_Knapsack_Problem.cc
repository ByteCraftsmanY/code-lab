// Fractional Knapsack Problem
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Easy Problems
// Post Link: https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/
// LeetCode Link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    double result = 0;
    vector<pair<int, int>> temp;
    for (int i = 0; i < val.size(); i++) {
        temp.push_back({val[i], wt[i]});
    }
    sort(temp.begin(), temp.end(), [](pair<int, int>& p1, pair<int, int>& p2) -> bool {
        double a = static_cast<double>(p1.first) / static_cast<double>(p1.second);
        double b = static_cast<double>(p2.first) / static_cast<double>(p2.second);
        return a > b;
    });
    for (auto const& x : temp) {
        if (x.second <= capacity) {
            result += x.first;
            capacity -= x.second;
            continue;
        }
        result += (static_cast<double>(capacity) * (static_cast<double>(x.first) / static_cast<double>(x.second)));
        break;
    }
    return round(result * 1e6) / 1e6;
}

int main() {
    vector<int> val = {60, 100, 120}, wt = {10, 20, 30};
    cout << fractionalKnapsack(val, wt, 50);
    return 0;
}
