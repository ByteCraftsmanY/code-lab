// Climbing Stars
// Step: Dynamic Programming [Patterns and Problems]
// Sub Step: 1D DP
// Post Link: https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/
// LeetCode Link: https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    // if (n <= 1) return 1;
    // return climbStairs(n - 1) + climbStairs(n - 2);

    int prev1 = 1, prev2 = 1, cur = 0;
    for (int i = 1; i <= n; i++) {
        cur = prev1 + prev2;
        prev1 = prev2;
        prev2 = cur;
    }
    return prev1;
}

int main() {
    for (int i = 1; i <= 10; i++) {
        cout << i << " : " << climbStairs(i) << endl;
    }
    return 0;
}
