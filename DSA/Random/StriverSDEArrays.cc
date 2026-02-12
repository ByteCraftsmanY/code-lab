#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> const& arr) {
    for (auto const& x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> const& mat) {
    for (auto const& row : mat) {
        for (auto const& ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

// https://leetcode.com/problems/set-matrix-zeroes/submissions/1506466615/
void setZeros(vector<vector<int>>& mat) {
    int i = 0, j = 0, n = mat.size(), m = mat[0].size();
    unordered_set<int> zeroRows, zeroCols;
    while (i < n) {
        while (j < m) {
            if (mat[i][j] == 0) {
                zeroRows.insert(i);
                zeroCols.insert(j);
            }
            j++;
        }
        j = 0, i++;
    }
    for (auto& r : zeroRows) {
        // cout << "zeroRow: " << r << endl;
        for (auto& ele : mat[r]) {
            ele = 0;
        }
    }
    for (auto& c : zeroCols) {
        // cout << "zeroCol: " << c << endl;
        for (auto& row : mat) {
            row[c] = 0;
        }
    }
}

void setZerosInput() {
    freopen("/home/yogesh/Projects/code-lab/bin/#input.txt", "r+", stdin);
    freopen("/home/yogesh/Projects/code-lab/bin/#output.txt", "w+", stdout);

    int m, n;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (auto& row : arr) {
        for (auto& ele : row) {
            cin >> ele;
        }
    }
    setZeros(arr);
    printMatrix(arr);
    /*
        3 3
        1 1 1
        1 0 1
        1 1 1
    */
}

// https://leetcode.com/problems/pascals-triangle/
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows);
    for (int i = 0; i < numRows; i++) {
        result[i] = vector<int>(i + 1, 0);
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                result[i][j] = 1;
                continue;
            }
            result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
        }
    }
    return result;
}

void paskalTriangleInput() {
    vector<vector<int>> result = generate(5);
    printMatrix(result);
}

void generateAllPermutation(string s, string result, vector<int>& isSelected) {
    if (result.size() == s.size()) {
        cout << result << endl;
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (isSelected[i]) continue;
        isSelected[i] = 1;
        generateAllPermutation(s, result + s[i], isSelected);
        isSelected[i] = 0;
    }
}

void nextPermutation(vector<int>& arr) {
    int n = arr.size(), idx = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }
    for (int i = n - 1; i >= idx; i--) {
        if (arr[i] > arr[idx]) {
            swap(arr[i], arr[idx]);
            break;
        }
    }
    reverse(arr.begin() + idx + 1, arr.end());
}

void nextPermutationInput() {
    // string s = "123";
    // vector<int> vc = vector<int>(s.size(), 0);
    // generateAllPermutation(s, "", vc);

    vector<int> arr = {1, 2, 3};
    nextPermutation(arr);
    printArray(arr);

    // do {
    //     cout << s << endl;
    // } while (next_permutation(s.begin(), s.end()));
}

// https://leetcode.com/problems/maximum-subarray/description/
int maxSubArray(vector<int>& nums) {
    int sum = 0, maxSum = 0;
    for (int num : nums) {
        if (sum < 0) sum = 0;
        sum += num;
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

void kadaneAlgoInput() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(arr) << endl;
    return;
}

// https://leetcode.com/problems/sort-colors/description/
void sortColors(vector<int>& nums) {
    int i = 0, j = 0, k = nums.size() - 1;
    while (j <= k) {
        if (nums[j] == 2) {
            swap(nums[k], nums[j]);
            k--;
            continue;
        }
        if (nums[j] == 0) {
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }
}

void sortColorsInput() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sortColors(arr);
    printArray(arr);
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
int maxProfit(vector<int>& prices) {
    int buyPrice = INT_MAX;
    int maxProfit = 0;
    for (auto x : prices) {
        if (buyPrice > x) buyPrice = x;
        maxProfit = max(maxProfit, x - buyPrice);
    }
    return maxProfit;
}

void stockBuyAndSellInput() {
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    arr = {7, 6, 4, 3, 1};
    cout << "profit is " << maxProfit(arr);
}

int main() {
    // setZerosInput();
    // paskalTriangleInput();
    // nextPermutationInput();
    // kadaneAlgoInput();
    // sortColorsInput();
    stockBuyAndSellInput();
    return 0;
}