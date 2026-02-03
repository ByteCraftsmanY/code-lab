#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/max-consecutive-ones-iii/description/
int lengthOfLongestSubstring(string s) {
    int result = 0, i = 0, j = 0, n = s.size();
    unordered_map<int, int> charIndexMap;
    while (j < n) {
        if (charIndexMap.contains(s[j]) && charIndexMap[s[j]] >= i) {
            i = charIndexMap[s[j]] + 1;
        }
        charIndexMap[s[j]] = j;
        result = max(result, j - i + 1);
        j++;
    }
    return result;
}
// https://leetcode.com/problems/max-consecutive-ones-iii/
int longestOnes(vector<int>& nums, int k) {
    int i = 0, j = 0, result = 0, zeroCount = 0;
    while (j < nums.size()) {
        if (nums[j] == 0) {
            zeroCount++;
        }
        if (zeroCount > k) {
            if (nums[i] == 0) zeroCount--;
            i++;
        }
        if (zeroCount <= k) {
            result = max(result, j - i + 1);
        }
        j++;
    }
    return result;
}
int main() {
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}