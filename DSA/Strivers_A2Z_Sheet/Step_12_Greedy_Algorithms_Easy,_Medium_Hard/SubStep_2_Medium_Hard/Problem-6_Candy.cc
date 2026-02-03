// Candy
// Step: Greedy Algorithms [Easy, Medium/Hard]
// Sub Step: Medium/Hard
// Post Link: https://takeuforward.org/data-structure/candy
// LeetCode Link: https://leetcode.com/problems/candy/

#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size(), sum = 0;
    /*
    vector<int> left(n, 1);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }

        // vector<int> right(n, 1);
        // for (int i = n - 2; i >= 0; i--) {
        //     if (ratings[i] > ratings[i + 1])
        //         right[i] = right[i + 1] + 1;
        //     else
        //         right[i] = 1;
        // }

        // for (int i = 0; i < n; i++) {
        //     sum += max(left[i], right[i]);
        // }

    int prev = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n && ratings[i] > ratings[i + 1])
            prev++;
        else
            prev = 1;
        sum += max(prev, left[i]);
    }

    */

    int i = 1, peak = 0, down = 0;
    sum = 1;  // initial element
    while (i < n) {
        while (i < n && ratings[i] == ratings[i - 1]) {
            sum += 1, i++;
        }

        peak = 1;
        while (i < n && ratings[i] > ratings[i - 1]) {
            i++, peak++, sum += peak;
        }

        down = 1;
        while (i < n && ratings[i] < ratings[i - 1]) {
            i++, sum += down, down++;
        }

        if (down > peak)
            sum += (down - peak);
    }
    return sum;
}

int main() {
    int t, n;
    vector<int> arr;
    cin >> t;
    while (t--) {
        cin >> n;
        arr.clear();
        arr.resize(n);
        for (auto& x : arr) {
            cin >> x;
        }
        for (auto x : arr) cout << x << " ";
        cout << ": " << candy(arr) << endl;
    }
    return 0;
}

/*

2
3
1 0 2
3
1 2 2


1 0 2 : 5
1 2 2 : 4


*/