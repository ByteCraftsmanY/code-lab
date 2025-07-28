#include <deque>
#include <iostream>
#include <vector>
using namespace std;

/**
 * Find the maximum element in each sliding window of size k
 *
 * Time Complexity: O(n) - Each element is pushed and popped at most once
 * Space Complexity: O(k) - Deque stores at most k elements
 *
 * @param nums Input array
 * @param k Window size
 * @return Vector containing maximum of each sliding window
 */
vector<int> maxSlidingWindow(const vector<int> &nums, int k) {
  if (nums.empty() || k <= 0 || k > nums.size()) {
    return {};
  }

  deque<int> maxIndices; // Stores indices of potential maximum elements
  vector<int> result;

  // Process first k elements (first window)
  for (int i = 0; i < k; ++i) {
    // Remove smaller elements from back (they can't be maximum)
    while (!maxIndices.empty() && nums[maxIndices.back()] <= nums[i]) {
      maxIndices.pop_back();
    }
    maxIndices.push_back(i);
  }

  // Add maximum of first window
  result.push_back(nums[maxIndices.front()]);

  // Process remaining elements
  for (int i = k; i < nums.size(); ++i) {
    // Remove elements outside current window from front
    while (!maxIndices.empty() && maxIndices.front() <= i - k) {
      maxIndices.pop_front();
    }

    // Remove smaller elements from back
    while (!maxIndices.empty() && nums[maxIndices.back()] <= nums[i]) {
      maxIndices.pop_back();
  }

    maxIndices.push_back(i);
    result.push_back(nums[maxIndices.front()]);
  }

  return result;
}

/**
 * Alternative implementation using a more concise approach
 */
vector<int> maxSlidingWindowOptimized(const vector<int> &nums, int k) {
  if (nums.empty() || k <= 0 || k > nums.size()) {
    return {};
  }

  deque<int> dq;
  vector<int> result;

  for (int i = 0; i < nums.size(); ++i) {
    // Remove elements outside current window
    while (!dq.empty() && dq.front() <= i - k) {
      dq.pop_front();
    }

    // Remove smaller elements from back
    while (!dq.empty() && nums[dq.back()] <= nums[i]) {
      dq.pop_back();
    }

    dq.push_back(i);

    // Add maximum to result starting from k-1 index
    if (i >= k - 1) {
    result.push_back(nums[dq.front()]);
    }
  }

  return result;
}

int main() {
  // Test cases
  vector<vector<int>> testArrays = {
      {1, 3, -1, -3, 5, 3, 6, 7}, // Original test case
      {4, 0, -1, 3, 5, 3, 6, 8},  // Another test case
      {20, 25},                   // Small array
      {1},                        // Single element
      {1, 2, 3, 4, 5},            // Increasing sequence
      {5, 4, 3, 2, 1}             // Decreasing sequence
  };

  vector<int> windowSizes = {3, 2, 1, 1, 3, 2};

  cout << "=== Sliding Window Maximum Tests ===\n\n";

  for (size_t i = 0; i < testArrays.size(); ++i) {
    cout << "Test Case " << (i + 1) << ":\n";
    cout << "Array: ";
    for (int num : testArrays[i]) {
      cout << num << " ";
    }
    cout << "\nWindow Size: " << windowSizes[i] << "\n";

    vector<int> result = maxSlidingWindow(testArrays[i], windowSizes[i]);
    cout << "Result: ";
    for (int num : result) {
      cout << num << " ";
  }
    cout << "\n\n";
  }

  return 0;
}