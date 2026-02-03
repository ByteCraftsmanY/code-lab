#include <iostream>
#include <vector>
using namespace std;

/**
 * Trapping Rain Water - Method 1: Prefix and Suffix Arrays
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * This approach uses two arrays to store the maximum height from left and right
 * for each position. The water trapped at each position is the minimum of the
 * left and right maximum heights minus the current height.
 *
 * Leetcode: https://leetcode.com/problems/trapping-rain-water/description/
 */
int trap(vector<int> &height) {
  int n = height.size();
  int result = 0;

  // Arrays to store maximum heights from left and right
  vector<int> prefixMax(n), suffixMax(n);

  // Fill prefixMax array (maximum height from left)
  prefixMax[0] = height[0];
  for (int i = 1; i < n; i++) {
    prefixMax[i] = max(prefixMax[i - 1], height[i]);
  }

  // Fill suffixMax array (maximum height from right)
  suffixMax[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffixMax[i] = max(suffixMax[i + 1], height[i]);
  }

  // Calculate trapped water at each position
  for (int i = 0; i < n; i++) {
    result += (min(prefixMax[i], suffixMax[i]) - height[i]);
  }

  return result;
}

/**
 * Trapping Rain Water - Method 2: Optimized Space
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) - but only one extra array
 *
 * This approach uses only one suffix array and maintains the left maximum
 * as a variable, reducing space complexity compared to method 1.
 */
int trap2(vector<int> &height) {
  int n = height.size();
  int result = 0;
  int leftMax = height[0];

  // Array to store maximum heights from right
  vector<int> suffixMax(n);
  suffixMax[n - 1] = height[n - 1];

  // Fill suffixMax array
  for (int i = n - 2; i >= 0; i--) {
    suffixMax[i] = max(suffixMax[i + 1], height[i]);
  }

  // Calculate trapped water using leftMax variable and suffixMax array
  for (int i = 1; i < n; i++) {
    leftMax = max(leftMax, height[i]);
    result += (min(leftMax, suffixMax[i]) - height[i]);
  }

  return result;
}

/**
 * Trapping Rain Water - Method 3: Two Pointers (Optimal)
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * This is the most efficient approach using two pointers. We maintain
 * leftMax and rightMax as we move the pointers inward, calculating
 * trapped water based on the smaller of the two maximums.
 */
int trap3(vector<int> &height) {
  int left = 0;
  int right = height.size() - 1;
  int leftMax = 0;
  int rightMax = 0;
  int total = 0;

  while (left < right) {
    if (height[left] <= height[right]) {
      // Process from left side
      leftMax = max(leftMax, height[left]);
      total += (leftMax - height[left]);
      left++;
    } else {
      // Process from right side
      rightMax = max(rightMax, height[right]);
      total += (rightMax - height[right]);
      right--;
    }
  }

  return total;
}

/**
 * Main function to test the trapping rain water algorithms
 */
int main() {
  // Test cases
  vector<int> test1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> test2 = {4, 2, 0, 3, 2, 5};

  cout << "=== Trapping Rain Water - Test Cases ===" << endl << endl;

  // Test Case 1
  cout << "Test Case 1:" << endl;
  cout << "Input: ";
  for (int i = 0; i < test1.size(); i++) {
    cout << test1[i];
    if (i < test1.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
  cout << "Output: " << trap3(test1) << endl;
  cout << "Expected: 6" << endl;
  cout << "Result: " << (trap3(test1) == 6 ? "✓ PASS" : "✗ FAIL") << endl;
  cout << endl;

  // Test Case 2
  cout << "Test Case 2:" << endl;
  cout << "Input: ";
  for (int i = 0; i < test2.size(); i++) {
    cout << test2[i];
    if (i < test2.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
  cout << "Output: " << trap3(test2) << endl;
  cout << "Expected: 9" << endl;
  cout << "Result: " << (trap3(test2) == 9 ? "✓ PASS" : "✗ FAIL") << endl;
  cout << endl;

  return 0;
}