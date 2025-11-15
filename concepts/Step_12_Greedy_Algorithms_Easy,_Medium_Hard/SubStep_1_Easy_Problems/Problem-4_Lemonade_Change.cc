// Lemonade Change
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Easy Problems
// Post Link: https://takeuforward.org/Greedy/lemonade-change
// LeetCode Link: https://leetcode.com/problems/lemonade-change/

#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    vector<int> mp = {0, 0};  // [0] = 5, [1] = 10
    for (auto const& bill : bills) {
        switch (bill) {
            case 5:
                mp[0]++;
                break;
            case 10:
                if (mp[0] <= 0) return false;
                mp[1]++, mp[0]--;
                break;
            case 20:
                if (mp[1] > 0 && mp[0] > 0) {
                    mp[1]--, mp[0]--;
                } else if (mp[0] >= 3) {
                    mp[0] -= 3;
                } else {
                    return false;
                }
                break;
        }
    }
    return true;
}

int main() {
    return 0;
}
