#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    // int steps = 0;
    // for (int i = 0; i < 31; i++) {
    //     int bitChecker = (1 << i);
    //     if ((start & bitChecker) ^ (goal & bitChecker)) {
    //         start = start ^ bitChecker;
    //         steps++;
    //     }
    // }
    // return steps;

    int count = 0;
    int res = start ^ goal;
    while (res) {
        if (res & 1) {
            count++;
        }
        res = res >> 1;
    }
    return count;
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    int n = nums.size(), subsets = (1 << (n)) - 1;
    for (int i = 0; i <= subsets; i++) {
        vector<int> temp;
        for (int j = 0; j < nums.size(); j++) {
            if (i & (1 << (j))) {
                temp.push_back(nums[j]);
            }
        }
        result.push_back(temp);
    }
    return result;
}

int findXorFrom1toN(int N) {
    int mod = N % 4;
    switch (mod) {
        case 0:
            return N;
        case 1:
            return 1;
        case 2:
            return N + 1;
    }
    return 0;
}

int findXOR(int L, int R) {
    // int result = 0;
    // for (int i = L; i <= R; i++) {
    //     result ^= i;
    // }
    // return result;
    return findXorFrom1toN(L - 1) ^ findXorFrom1toN(R);
}

vector<int> twoOddNum(vector<int> arr) {
    int xorVal = 0;
    for (auto const &num : arr) {
        xorVal ^= num;
    }
    int firstSetBitVal = (xorVal ^ (xorVal - 1)) & xorVal;
    int bucket0 = 0, bucket1 = 0;
    for (auto const &num : arr) {
        if (num & firstSetBitVal) {
            bucket1 ^= num;
        } else {
            bucket0 ^= num;
        }
    }
    if (bucket0 > bucket1) {
        return {bucket0, bucket1};
    }
    return {bucket1, bucket0};
}

int main() {
    cout << minBitFlips(10, 7) << endl;
    return 0;
}
