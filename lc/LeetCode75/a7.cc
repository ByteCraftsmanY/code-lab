#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vi backword(n, 1), forword(n, 1), result(n);
    for (int i = n - 2; i >= 0; i--) {
        forword[i] = forword[i + 1] * nums[i + 1];
    }
    for (int i = 1; i < n; i++) {
        backword[i] = backword[i - 1] * nums[i - 1];
    }
    for (int i = 0; i < n; i++) {
        result[i] = forword[i] * backword[i];
    }
    return result;
}

vector<int> productExceptSelf2(vector<int>& nums) {
    int n = nums.size(), multiplier = 1;
    vector<int> result(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        multiplier *= nums[i + 1];
        result[i] *= multiplier;
    }
    multiplier = 1;
    for (int i = 1; i < n; i++) {
        multiplier *= nums[i - 1];
        result[i] *= multiplier;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (auto& x : arr) {
        cin >> x;
    }
    vi result = productExceptSelf2(arr);
    for (auto x : result) {
        cout << x << endl;
    }
    return 0;
}