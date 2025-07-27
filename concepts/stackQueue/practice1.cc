#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void printVector(vi &arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> findNextGreaterElement(vi &nums1, vi &nums2) {
    stack<int> st;
    unordered_map<int, int> mp;
    for (auto x : nums1) {
        mp[x] = -1;
    }
    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        if (!st.empty() && mp.find(nums2[i]) != mp.end()) {
            mp[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    vi nextGreater(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); i++) {
        nextGreater[i] = mp[nums1[i]];
    }
    return nextGreater;
}

vector<int> findNextGreaterElement2(vi &nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> nextGreater(n, -1);
    for (int i = 0; i < n; i++) {
        nums.push_back(nums[i]);
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty() && i < n) {
            nextGreater[i] = st.top();
        }
        st.push(nums[i]);
    }
    return nextGreater;
}

vector<int> findNextSmallerElement(vi &nums) {
    stack<int> st;
    vi nextSmaller(nums.size(), -1);
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nextSmaller[i] = st.top();
        }
        st.push(nums[i]);
    }
    return nextSmaller;
}

// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
    auto finder = [&arr, &n](int ele, int idx) -> int {
        int count = 0;
        for (int i = idx + 1; i < n; i++) {
            if (arr[i] > ele) {
                count++;
            }
        }
        return count;
    };

    vector<int> result = vector<int>(queries, 0);
    for (int i = 0; i < queries; i++) {
        result[i] = finder(arr[indices[i]], indices[i]);
    }
    return result;
}

int trap(vector<int> &height) {
    int n = height.size(), result = 0;
    // vector<int> rightMax(n, n);
    // rightMax[n - 1] = height[n - 1];
    // for (int i = n - 2; i >= 0; i--) {
    //     rightMax[i] = max(rightMax[i + 1], height[i]);
    // }
    // int leftMaxEle = height[0];
    // for (int i = 1; i < n - 1; i++) {
    //     leftMaxEle = max(leftMaxEle, height[i]);
    //     result += (min(leftMaxEle, rightMax[i]) - height[i]);
    // }

    int leftMax = height[0], rightMax = height[n - 1];
    int left = 1, right = n - 2;
    while (left < right) {
        if (height[left] <= height[right]) {
            leftMax = max(leftMax, height[left]);
            result += (leftMax - height[left]);
            left++;
        } else {
            rightMax = max(rightMax, height[right]);
            result += (rightMax - height[right]);
            right--;
        }
    }

    return result;
}

vector<int> findPreviousSmallerOrEqualElements(vector<int> const &nums) {
    vector<int> result(nums.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(i);
    }
    return result;
}

vector<int> findNextSmallerElements(vector<int> const &nums) {
    vector<int> result(nums.size(), nums.size());
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(i);
    }
    return result;
}

long long int sumSubarrayMins(vector<int> &arr) {
    const int MOD = 1e9 + 7;
    vector<int> previousSmallerElements = findPreviousSmallerOrEqualElements(arr),
                nextSmallerElements = findNextSmallerElements(arr);
    long long int result = 0;
    for (int i = 0; i < arr.size(); i++) {
        long long int count = 1LL * ((i - previousSmallerElements[i]) * (nextSmallerElements[i] - i));
        // cout << format("{} - {}\n", arr[i], count);
        result = (result + (1LL * arr[i] * count));  // % MOD;
    }
    return result;
}

vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> st;
    for (auto const &asteroid : asteroids) {
        if (asteroid > 0) {  // moving right
            st.push(asteroid);
            continue;
        }
        bool isDestroyed = false;
        while (!st.empty() && st.top() > 0) {
            if (st.top() == abs(asteroid)) {
                st.pop();
                isDestroyed = true;
                break;
            } else if (st.top() > abs(asteroid)) {
                isDestroyed = true;
                break;
            } else {
                st.pop();
            }
        }
        if (!isDestroyed) {
            st.push(asteroid);
        }
    }
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> findPreviousGreaterEqualElements(vector<int> const &arr) {
    vector<int> result(arr.size(), -1);
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(i);
    }
    return result;
}

vector<int> findNextGreaterElements(vector<int> const &arr) {
    vector<int> result(arr.size(), arr.size());
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(i);
    }
    return result;
}

long long int sumSubarrayMaxs(vector<int> &arr) {
    vector<int> previousGreaterEqualElements = findPreviousGreaterEqualElements(arr),
                nextGreaterElements = findNextGreaterElements(arr);
    long long int result = 0;
    for (int i = 0; i < arr.size(); i++) {
        long long int count = ((i - previousGreaterEqualElements[i]) * (nextGreaterElements[i] - i));
        result = result + (arr[i] * count * 1LL);
    }
    return result;
}

long long subArrayRanges(vector<int> &nums) {
    long long int largest = sumSubarrayMaxs(nums), smallest = sumSubarrayMins(nums);
    // cout << format("{} - {}\n", largest, smallest);
    return largest - smallest;
}

string removeKdigits(string num, int k) {
    if (k == num.size()) return "0";
    stack<char> st;
    for (int i = 0; i < num.size(); i++) {
        while (!st.empty() && k > 0 && st.top() > num[i]) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    string result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    while (!result.empty() && result.back() == '0') result.pop_back();
    if (result.empty()) return "0";
    reverse(result.begin(), result.end());
    return result;
}

int largestRectangleArea(vector<int> &heights) {
    int result = 0, n = heights.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            int curr = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            result = max(result, ((i - left - 1) * heights[curr]));
        }
        st.push(i);
    }
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        result = max(result, ((n - left - 1) * heights[curr]));
    }
    return result;
}

int maximalRectangle(vector<vector<char>> &matrix) {
    int result = 0, n = matrix.size();
    vector<vector<int>> prefixSumMatrix;
    int r = 0;
    while (r < n) {
        int m = matrix[r].size();
        vector<int> row(m, 0);
        for (int c = 0; c < m; c++) {
            if (r == 0) {
                row[c] = matrix[r][c] - '0';
            } else if (matrix[r][c] > '0') {
                row[c] = (prefixSumMatrix[r - 1][c]) + (matrix[r][c] - '0');
            }
        }
        prefixSumMatrix.push_back(row);
        r++;
    }
    // for (auto rw : prefixSumMatrix) {
    //     for (auto cw : rw) {
    //         cout << cw << " ";
    //     }
    //     cout << endl;
    // }
    for (auto rw : prefixSumMatrix) {
        result = max(result, largestRectangleArea(rw));
    }
    return result;
}

int main() {
    // vi nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    // vi ans = findNextGreaterElement(nums1, nums2);
    // vi nums = {1, 2, 3, 4, 3};
    // vi ans = findNextGreaterElement2(nums);
    // vi nums = {2, 1, 4, 3};
    // vi ans = findNextSmallerElement(nums);
    // printVector(ans);
    // vi arr = {3, 4, 2, 7, 5, 8, 10, 6}, indices = {0, 5}, ans = count_NGE(arr.size(), arr, indices.size(), indices);
    // printVector(ans);
    // vi arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vi arr = {4, 2, 0, 3, 2, 5};
    // cout << trap(arr) << endl;
    // vi arr = {3, 1, 2, 4};
    // cout << sumSubarrayMins(arr) << endl;
    // vi asteroids = {5, 10, -5};
    // asteroids = {8, -8};
    // asteroids = {10, 2, -5};
    // asteroids = {-2, -2, 1, -2};
    // asteroids = {-2, 2, 1, -2};
    // vi result = asteroidCollision(asteroids);
    // printVector(result);
    // vi arr = {1, 2, 3};
    // arr = {1, 3, 3};
    // arr = {4, -2, -3, 4, 1};
    // cout << subArrayRanges(arr) << endl;
    // cout << removeKdigits("33526221184202197273", 19) << endl;
    // vi arr = {2, 1, 5, 6, 2, 3};
    // vi arr = {2, 1, 2};
    // cout << largestRectangleArea(arr) << endl;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(matrix) << endl;
    return 0;
}