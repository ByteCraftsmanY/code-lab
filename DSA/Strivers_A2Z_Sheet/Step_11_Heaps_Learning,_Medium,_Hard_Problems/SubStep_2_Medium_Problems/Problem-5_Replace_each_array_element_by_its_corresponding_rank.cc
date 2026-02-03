// Replace each array element by its corresponding rank
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Medium Problems
// Post Link: https://takeuforward.org/data-structure/replace-elements-by-its-rank-in-the-array/
// LeetCode Link: N/A

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> solve(vector<int>& arr) {
        // unordered_set<int> st(arr.begin(), arr.end());
        // vector<int> temp(st.begin(), st.end()), result(arr.size(), 0);
        // sort(temp.begin(), temp.end());
        // // for (int i = 0; i < temp.size(); i++) cout << i + 1 << ": " << temp[i] << "\n";
        // // cout << endl;
        // for (int j = 0; j < arr.size(); j++) {
        //     for (int i = 0; i < temp.size(); i++) {
        //         if (arr[j] != temp[i]) continue;
        //         result[j] = i + 1;
        //         break;
        //     }
        // }
        // return result;

        // int count = 1;
        // vector<int> result;
        // set<int> st(arr.begin(), arr.end());
        // unordered_map<int, int> mp;
        // for (auto x : st) {
        //     mp[x] = count++;
        // }
        // for (auto x : arr) {
        //     result.push_back(mp[x]);
        // }
        // return result;

        vector<int> temp(arr.begin(), arr.end()), result;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        int count = 1;
        for (int i = 0; i < temp.size(); i++) {
            if (!mp.contains(temp[i])) {
                mp[temp[i]] = count++;
            }
        }
        for (auto x : arr)
            result.push_back(mp[x]);
        return result;
    }
};

int main() {
    Solution* s = new Solution();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (auto& x : arr) {
            cin >> x;
        }
        arr = s->solve(arr);
        for (auto x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
