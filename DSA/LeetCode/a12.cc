#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int maxArea(vector<int>& height) {
    int n = height.size(), maxVal = INT_MIN;
    auto getVal = [&height](int p1, int p2) -> int {
        int minHeight = min(height[p1], height[p2]);
        return minHeight * (p2 - p1);
    };
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         maxVal = max(maxVal, getVal(i, j));
    //     }
    // }

    int i = 0, j = n - 1;
    while (i < j) {
        maxVal = max(maxVal, getVal(i, j));
        if (height[i] < height[j])
            i++;
        else
            j--;
    }

    return maxVal;
}

int main() {
    vi arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // arr = {1, 1};
    cout << maxArea(arr);
    return 0;
}