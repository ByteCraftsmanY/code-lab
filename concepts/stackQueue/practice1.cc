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
    vi arr = {4, 2, 0, 3, 2, 5};
    cout << trap(arr) << endl;
}