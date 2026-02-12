// https://www.geeksforgeeks.org/problems/top-k-numbers3425/1

#include <bits/stdc++.h>
using namespace std;

class ValueFreqCount {
   public:
    int value;
    int freq;
    ValueFreqCount(int v, int f) : value(v), freq(f) {}
};

class Compare {
   public:
    bool operator()(ValueFreqCount* a, ValueFreqCount* b) {
        if (a->freq == b->freq) {
            return a->value >= b->value;
        }
        return a->freq < b->freq;
    }
};

vector<vector<int>> solve(vector<int>& arr, int k) {
    vector<vector<int>> result;
    priority_queue<ValueFreqCount*, vector<ValueFreqCount*>, Compare> pq1, pq2;
    unordered_map<int, ValueFreqCount*> mp;
    for (auto const& x : arr) {
        vector<int> temp;
        ValueFreqCount* vfc;
        if (mp.find(x) != mp.end()) {
            vfc = mp[x];
            vfc->freq++;
        } else {
            vfc = new ValueFreqCount(x, 1);
            mp[x] = vfc;
            pq1.push(vfc);
        }
        while (!pq1.empty()) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        while (!pq2.empty()) {
            vfc = pq2.top();
            pq1.push(vfc);
            pq2.pop();
            if (temp.size() < k) {
                temp.push_back(vfc->value);
            }
            // cout << vfc->value << ":" << vfc->freq << "\t";
        }
        // cout << endl;
        result.push_back(temp);
    }
    return result;
}

vector<vector<int>> kTop(vector<int>& arr, int K) {
    unordered_map<int, int> freqCounter;
    vector<int> top(K + 1, 0);
    vector<vector<int>> result;

    for (auto const& x : arr) {
        freqCounter[x]++;
        top[K] = x;

        // search existing value index
        int index = K - 1;
        for (int i = 0; i < K; i++) {
            if (top[i] == x) {
                index = i;
                break;
            }
        }

        // arrange value
        for (int i = index; i >= 0; i--) {
            if (freqCounter[top[i]] < freqCounter[top[i + 1]]) {
                swap(top[i], top[i + 1]);
            } else if (
                freqCounter[top[i]] == freqCounter[top[i + 1]] &&
                top[i] > top[i + 1]) {
                swap(top[i], top[i + 1]);
            }
        }

        // print/add sorted value in result
        vector<int> temp;
        for (int i = 0; i < K; i++)
            if (top[i] != 0) temp.push_back(top[i]);
        result.push_back(temp);
    }
    return result;
}

int main() {
    vector<int> arr = {5, 2, 1, 3, 2};
    arr = {9, 1, 9, 1, 4};
    auto result = kTop(arr, 2);

    // result = solve(arr, 2);
    for (auto row : result) {
        for (auto c : row) cout << c << " ";
        cout << endl;
    }
    return 0;

    /*
        5 2
        9 1 9 1 4
    */
}