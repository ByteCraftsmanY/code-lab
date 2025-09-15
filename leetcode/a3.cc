#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> result(candies.size(), false);
    int maxCandy = *max_element(candies.begin(), candies.end());
    for (int i = 0; i < candies.size(); i++) {
        result[i] = (extraCandies + candies.at(i)) >= maxCandy;
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto& x : arr) {
        cin >> x;
    }
    vector<bool> result = kidsWithCandies(arr, m);
    for (auto x : result) {
        cout << x << " ";
    }
    return 0;
}