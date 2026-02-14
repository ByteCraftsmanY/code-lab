// https://www.hellointerview.com/community/questions/weighted-random-pick/cm5eguhab02f2838ox5omc14t
// https://leetcode.com/problems/random-pick-with-weight/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> weights;
    long long int sum = 0;
    vector<long long int> prefixSum;

   public:
    Solution(vector<int>& arr) : weights(arr) {
        srand(time(0));
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            prefixSum.push_back(sum);
        }
    }

    int pickIndex() {
        int target = (rand() % sum) + 1;
        int left = 0, right = prefixSum.size();
        while (left < right) {
            int mid = left + ((right - left) / 2);
            if (prefixSum[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    return 0;
}