#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

bool uniqueOccurrences(vector<int>& nums) {
    unordered_map<int, int> freqCount;
    unordered_set<int> counterSet;
    for (auto x : nums) {
        freqCount[x]++;
    }
    for (auto [k, count] : freqCount) {
        if (counterSet.contains(count)) return false;
        counterSet.insert(count);
    }
    return true;
}

int main() {
    vector<int> nums = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    nums = {1, 2};
    auto res = uniqueOccurrences(nums);
    cout << res;
    return 0;
}