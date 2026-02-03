// Assign Cookies
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Easy Problems
// Post Link: https://takeuforward.org/data-structure/assign-cookies
// LeetCode Link: https://leetcode.com/problems/assign-cookies/

#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0, result = 0;
    while (i < g.size()) {
        if (j >= s.size()) break;
        if (g[i] > s[j]) {
            j++;
            continue;
        }
        result++;
        i++, j++;
    }
    return result;
}

int main() {
    return 0;
}
