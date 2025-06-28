#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void printMatrix(const vector<vector<int>> &matrix) {
    for (auto row : matrix) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

// https://www.naukri.com/code360/problems/row-with-maximum-1-s_1112656?leftPanelTabValue=PROBLEM
int getRowHavingMax1(const vector<vector<int>> &matrix) {
    /*
        TimeComplexity: O(nlogm)
        SpaceComplexity: O(1)
    */
    int maxCount = 0, rowIdx = -1;
    for (int i = 0; i < matrix.size(); i++) {
        auto row = matrix[i];
        int lb = lower_bound(row.begin(), row.end(), 1) - row.begin();
        int count = row.size() - lb;
        if (maxCount < count) {
            maxCount = count, rowIdx = i;
        }
    }
    return rowIdx;
}

bool searchMatrix(const vector<vector<int>> &matrix, const int target) {
    // https://www.naukri.com/code360/problems/search-in-a-2d-matrix_980531?leftPanelTabValue=PROBLEM
    // O(n*m)
    // for (int i = 0; i < matrix.size(); i++) {
    //     for (int j = 0; j < matrix[i].size(); j++) {
    //         if (matrix[i][j] == target) {
    //             return true;
    //         }
    //     }
    // }
    // return false;

    // O(n) + O(logn)
    // for (int i = 0; i < matrix.size(); i++) {
    //     if (target >= matrix[i][0] &&
    //         target <= matrix[i][matrix[i].size() - 1]) {
    //         return binary_search(matrix[i].begin(), matrix[i].end(), target);
    //     }
    // }
    // return false;

    // O(log(n+m))
    int rows = matrix.size(), cols = matrix[0].size();
    auto getRowColIdx = [cols](int idx) -> pair<int, int> {
        return {idx / cols, idx % cols};
    };
    int low = 0, high = rows * cols - 1, mid = 0;
    while (low <= high) {
        mid = low + ((high - low) >> 2);
        auto [row, col] = getRowColIdx(mid);
        int val = matrix[row][col];
        if (val == target) {
            return true;
        } else if (target > val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int binarySearch(const vector<int> &arr, const int target) {
    int low = 0, high = arr.size();
    while (low <= high) {
        int mid = low + ((high - low) >> 2);
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

pair<int, int> search(vector<vector<int>> matrix, int target) {
    // https://www.naukri.com/code360/problems/search-in-a-row-wise-and-column-wise-sorted-matrix_839811?leftPanelTabValue=PROBLEM
    // for (int i = 0; i < matrix.size(); i++) {
    //     if (target >= matrix[i][0] &&
    //         target <= matrix[i][matrix[i].size() - 1]) {
    //         int res = binarySearch(matrix[i], target);
    //         if (res != -1) {
    //             return {i, res};
    //         }
    //     }
    // }
    // return {-1, -1};

    // O(n + m)
    int n = matrix.size(), m = matrix[0].size(), low = 0, high = m - 1;
    while (low < n && high >= 0) {
        if (matrix[low][high] == target) {
            return {low, high};
        } else if (matrix[low][high] > target) {
            high--;
        } else {
            low++;
        }
    }
    return {-1, -1};
}

bool isElePeakInCol(const vector<vector<int>> &mat, int i, int j) {
    int top = -1, bottom = -1, ele = mat[i][j];
    if (i - 1 >= 0) top = mat[i - 1][j];
    if (i + 1 < mat.size()) bottom = mat[i + 1][j];
    return (ele > top) && (ele > bottom);
}

int findPeak(const vector<vector<int>> &mat, int i) {
    vi arr = mat[i];
    int n = arr.size();
    if ((n == 1 || arr[0] > arr[1]) && isElePeakInCol(mat, i, 0)) {
        return 0;
    }
    if (arr[n - 1] > arr[n - 2] && isElePeakInCol(mat, i, n - 1)) {
        return n - 1;
    }

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = low + ((high - low) >> 2);
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1] &&
            isElePeakInCol(mat, i, mid)) {
            return mid;
        } else if (arr[mid - 1] < arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

vector<int> findPeakGrid(vector<vector<int>> &mat) {
    // O(n*m)
    // auto isPeak = [mat](int i, int j) -> bool {
    //     int left = -1, right = -1, top = -1, bottom = -1, ele = mat[i][j];
    //     if (j - 1 >= 0) left = mat[i][j - 1];
    //     if (j + 1 < mat[i].size()) right = mat[i][j + 1];
    //     if (i - 1 >= 0) top = mat[i - 1][j];
    //     if (i + 1 < mat.size()) bottom = mat[i + 1][j];
    //     return ((ele > left) && (ele > right) && (ele > top) && (ele >
    //     bottom));
    // };

    // for (int i = 0; i < mat.size(); i++) {
    //     for (int j = 0; j < mat[i].size(); j++) {
    //         if (isPeak(i, j)) {
    //             return {i, j};
    //         }
    //     }
    // }

    // return {-1, -1};

    for (int i = 0; i < mat.size(); i++) {
        int j = findPeak(mat, i);  // rowPeak
        if (j != -1) {
            return {i, j};
        }
    }
    return {-1, -1};
}

int findMedianIn2DMatrix(const vector<vector<int>> &mat) {
    // TimeComplexity: O(nLogm) * O(log(10^9))
    int n = mat.size(), m = mat[0].size();
    int minReqEle = (n * m) / 2;
    auto getEleCount = [mat, n](int num) -> int {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int ub =
                upper_bound(mat[i].begin(), mat[i].end(), num) - mat[i].begin();
            count += ub;
        }
        return count;
    };
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++) {
        low = min(mat[i][0], low);
        high = max(mat[i][m - 1], high);
    }
    while (low <= high) {
        int mid = low + ((high - low) >> 2);
        int count = getEleCount(mid);
        if (count <= minReqEle) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
    /*
        0 1 2 3 4 5 6 7 8
        1 2 3 4 5 6 7 8 9
    */
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (auto &row : matrix) {
            for (auto &col : row) {
                cin >> col;
            }
        }
        // printMatrix(matrix);
        // cout << getRowHavingMax1(matrix) << endl;
        // int target = 0;
        // cin >> target;
        // cout << (searchMatrix(matrix, target) ? "true" : "false") << endl;

        // vi arr = findPeakGrid(matrix);
        // for (auto x : arr) cout << x << " ";
        // cout << endl;
        cout << findMedianIn2DMatrix(matrix) << endl;
    }
    return 0;
}