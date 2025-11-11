// Hands of Straights
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Medium Problems
// Post Link: https://takeuforward.org/data-structure/hands-of-straights
// LeetCode Link: https://leetcode.com/problems/hand-of-straights/
// + https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    // priority_queue<int, vector<int>, greater<int>> pq(hand.begin(), hand.end());
    // while (!pq.empty()) {
    //     int minEle = pq.top();
    //     pq.pop();
    //     for (int i = minEle; i <= minEle + groupSize; i++) {
    //         if (pq.empty()) return false;

    //     }
    // }

    int n = hand.size();
    if (n % groupSize != 0) return false;

    /*
        multiset<int> st(hand.begin(), hand.end());
        vector<int> ele;
        for (int p = 0; p <= n / groupSize; p++) {
            cout << format("pass: {}", p);
            for (auto x : st) {
                for (int i = x; i < x + groupSize; i++) {
                    if (!st.contains(i)) return false;
                    ele.push_back(i);
                }
                break;
            }
            cout << " >> ";
            for (auto x : ele) cout << x << " ";
            cout << endl;
            for (auto x : ele) st.erase(st.find(x));
            ele.clear();
        }
        return st.empty();
    */

    unordered_map<int, int> mp;
    priority_queue<int, vector<int>, greater<int>> pq(hand.begin(), hand.end());
    for (auto x : hand) mp[x]++;

    int groupCountReq = hand.size() / groupSize, groupCount = 0;
    while (true) {
        int minValue = pq.top();
        for (int i = minValue; i < minValue + groupSize; i++) {
            if (!mp.contains(i) || mp[i] <= 0) return false;
            mp[i]--;
            cout << i << " ";
            while (mp[i] <= 0 && !pq.empty() && i == pq.top()) pq.pop();
        }
        groupCount++;
        cout << format(" :: G{}\n", groupCount);
        if (groupCount == groupCountReq)
            return true;
        else if (pq.empty())
            return false;
    }
    return true;
}

int main() {
    int k = 4;
    vector<int> arr = {1, 2, 3, 3, 4, 4, 5, 6};
    // arr = {3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11}, k = 3;
    // arr = {1, 2, 3, 4}, k = 3;
    cout << isNStraightHand(arr, k) << endl;
    return 0;
}
