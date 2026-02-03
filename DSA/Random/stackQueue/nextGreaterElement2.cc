#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Next Greater Element II - Circular Array
 *
 * Problem: Given a circular integer array nums, return the next greater number
 * for every element in nums. The next greater number of a number x is the first
 * greater number to its traversing order next in the array, which means you
 * could search circularly to find its next greater number.
 *
 * LeetCode: https://leetcode.com/problems/next-greater-element-ii/
 */

// Method 1: Brute Force Approach
// Time Complexity: O(n²)
// Space Complexity: O(1)
vector<int> nextGreaterElements(vector<int> &nums) {
  vector<int> result(nums.size(), -1);

  for (int i = 0; i < nums.size(); i++) {
    bool found = false;

    // Search from current position to end
    for (int j = i + 1; !found && j < nums.size(); j++) {
      if (nums[j] > nums[i]) {
        result[i] = nums[j];
        found = true;
      }
    }

    // Search from start to current position (circular)
    for (int j = 0; !found && j < i; j++) {
      if (nums[j] > nums[i]) {
        result[i] = nums[j];
        found = true;
      }
    }
  }

  return result;
}

// Method 2: Optimized Brute Force with Modulo
// Time Complexity: O(n²)
// Space Complexity: O(1)
vector<int> nextGreaterElements2(vector<int> &nums) {
  int n = nums.size();
  vector<int> result(n, -1);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < i + n; j++) {
      if (nums[j % n] > nums[i]) {
        result[i] = nums[j % n];
        break;
      }
    }
  }

  return result;
}

// Method 3: Stack-based Approach (Most Efficient)
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> nextGreaterElements3(vector<int> &nums) {
  int n = nums.size();
  stack<int> st;
  vector<int> result(n, -1);

  // Process the array twice to handle circular nature
  for (int i = 2 * n - 1; i >= 0; i--) {
    int currentNum = nums[i % n];

    // Remove elements from stack that are smaller than current
    while (!st.empty() && st.top() <= currentNum) {
      st.pop();
    }

    // If we're in the first n elements and stack is not empty
    if (i < n && !st.empty()) {
      result[i] = st.top();
    }

    st.push(currentNum);
  }

  return result;
}

int main() {
  vector<int> nums = {5, 4, 3, 2, 1};

  cout << "Input array: ";
  for (auto ele : nums) {
    cout << ele << " ";
  }
  cout << endl;

  auto result = nextGreaterElements3(nums);

  cout << "Next greater elements: ";
  for (auto ele : result) {
    cout << ele << " ";
  }
  cout << endl;

  return 0;
}