// Greedy algorithm to find minimum number of coins
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Easy Problems
// Post Link: https://takeuforward.org/data-structure/find-minimum-number-of-coins/
// LeetCode Link: https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findResult(vector<int>& coins, int idx, int target, int current, int result) {
        // cout<<target<<" "<<current<<" "<<idx<<" "<<result<<"\n";
        if (target == current) {
            return result;
        } else if (idx >= coins.size()) {
            return -1;
        }

        if ((target - current) >= coins[idx]) {
            return findResult(coins, idx, target, current + coins[idx], result + 1);
        }
        return findResult(coins, idx + 1, target, current, result);
    }

   public:
    int findMin(int n) {
        // code here
        vector<int> coins = {10, 5, 2, 1};
        return this->findResult(coins, 0, n, 0, 0);
    }

    int findMin2(int n) {
        int result = 0;
        vector<int> coins = {1, 2, 5, 10};
        for (int i = coins.size() - 1; i >= 0; i--) {
            while (coins[i] >= n) {
                n -= coins[i];
                result++;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
