#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/next-greater-element-i/description/
 * Basic implementation of Next Greater Element
 * Time Complexity: O(nums1.size() * nums2.size())
 * Space Complexity: O(nums1.size())
 */
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
  vector<int> result(nums1.size(), -1);
  unordered_map<int, int> numToIndexMap;

  // Initialize mapping for nums1 elements
  for (int const &num : nums1) {
    numToIndexMap[num] = -1;
  }

  // Find indices of nums1 elements in nums2
  for (int i = 0; i < nums2.size(); i++) {
    if (numToIndexMap.find(nums2[i]) != numToIndexMap.end()) {
      numToIndexMap[nums2[i]] = i;
    }
  }

  // Find next greater element for each element in nums1
  for (int i = 0; i < nums1.size(); i++) {
    int num = nums1[i];
    int idx = numToIndexMap[num];

    for (int j = idx + 1; j < nums2.size(); j++) {
      if (nums2[j] > num) {
        result[i] = nums2[j];
        break;
      }
    }
  }

  return result;
}

/**
 * Optimized implementation using monotonic stack
 * Time Complexity: O(nums1.size() + nums2.size())
 * Space Complexity: O(nums2.size())
 */
vector<int> nextGreaterElementOptimized(vector<int> &nums1,
                                        vector<int> &nums2) {
  vector<int> result(nums2.size(), -1);
  vector<int> finalResult(nums1.size(), -1);
  stack<int> st;
  unordered_map<int, int> valToIdxMap;

  // Process nums2 from right to left using monotonic stack
  int i = nums2.size() - 1;
  while (i >= 0) {
    valToIdxMap[nums2[i]] = i;

    // Maintain monotonic decreasing stack
    while (!st.empty() && st.top() <= nums2[i]) {
      st.pop();
    }

    if (!st.empty()) {
      result[i] = st.top();
    }

    st.push(nums2[i]);
    i--;
  }

  // Map results back to nums1
  for (int i = 0; i < nums1.size(); i++) {
    finalResult[i] = result[valToIdxMap[nums1[i]]];
  }

  return finalResult;
}



int main() {
  // Test case for next greater element
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};

  cout << "Testing Next Greater Element:" << endl;
  cout << "=============================" << endl;

  // Display input arrays
  cout << "nums1: [";
  for (int i = 0; i < nums1.size(); i++) {
    cout << nums1[i];
    if (i < nums1.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;

  cout << "nums2: [";
  for (int i = 0; i < nums2.size(); i++) {
    cout << nums2[i];
    if (i < nums2.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;

  // Test both implementations
  vector<int> result1 = nextGreaterElement(nums1, nums2);
  vector<int> result2 = nextGreaterElementOptimized(nums1, nums2);

  cout << "\nResults:" << endl;
  cout << "--------" << endl;

  cout << "Basic Implementation: [";
  for (int i = 0; i < result1.size(); i++) {
    cout << result1[i];
    if (i < result1.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;

  cout << "Optimized Implementation: [";
  for (int i = 0; i < result2.size(); i++) {
    cout << result2[i];
    if (i < result2.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;

  // Validate results
  vector<int> expected = {-1, 3, -1};
  bool isCorrect1 = (result1 == expected);
  bool isCorrect2 = (result2 == expected);

  cout << "\nValidation:" << endl;
  cout << "-----------" << endl;
  cout << "Expected Output: [-1, 3, -1]" << endl;
  cout << "Basic: " << (isCorrect1 ? "✓ PASS" : "✗ FAIL") << endl;
  cout << "Optimized: " << (isCorrect2 ? "✓ PASS" : "✗ FAIL") << endl;

  return 0;
}