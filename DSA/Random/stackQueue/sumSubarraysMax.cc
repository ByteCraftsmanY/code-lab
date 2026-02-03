#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Utility function to print a vector
 * @param arr - The vector to print
 */
void printVector(const vector<int> &arr) {
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;
}

/**
 * Brute force approach to find sum of maximums of all subarrays
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * @param arr - Input array
 * @return Sum of maximums of all subarrays modulo 10^9 + 7
 *
 * Similar to Leetcode:
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/ but for
 * maximums instead of minimums
 */
int sumSubarrayMaxsBruteForce(vector<int> &arr) {
  const int MOD = 1e9 + 7;
  int sum = 0;
  int n = arr.size();

  // Generate all subarrays and find their maximums
  for (int i = 0; i < n; i++) {
    int maxEle = arr[i]; // Initialize maximum for current subarray
    for (int j = i; j < n; j++) {
      maxEle = max(maxEle, arr[j]); // Update maximum for current subarray
      sum = (sum + maxEle) % MOD;   // Add to sum and take modulo
    }
  }
  return sum;
}

/**
 * Find the previous greater or equal element for each position using monotonic
 * stack Time Complexity: O(n) Space Complexity: O(n)
 * @param arr - Input array
 * @return Vector where result[i] = index of previous greater/equal element, -1
 * if none
 */
vector<int> findPreviousGreaterEqualElements(vector<int> &arr) {
  vector<int> result(arr.size(),
                     -1); // Initialize with -1 (no previous greater element)
  stack<int> st;          // Monotonic stack to maintain indices
  int i = 0;

  while (i < arr.size()) {
    // Pop elements from stack until we find a greater or equal element
    while (!st.empty() && arr[st.top()] < arr[i]) {
      st.pop();
    }
    // If stack is not empty, top element is the previous greater/equal element
    if (!st.empty()) {
      result[i] = st.top();
    }
    st.push(i); // Push current index
    i++;
  }
  return result;
}

/**
 * Find the next greater element for each position using monotonic stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @param arr - Input array
 * @return Vector where result[i] = index of next greater element, n if none
 */
vector<int> findNextGreaterElements(vector<int> &arr) {
  vector<int> result(arr.size(),
                     arr.size()); // Initialize with n (no next greater element)
  stack<int> st;                  // Monotonic stack to maintain indices
  int i = arr.size() - 1;         // Start from the end

  while (i >= 0) {
    // Pop elements from stack until we find a greater element
    while (!st.empty() && arr[st.top()] <= arr[i]) {
      st.pop();
    }
    // If stack is not empty, top element is the next greater element
    if (!st.empty()) {
      result[i] = st.top();
    }
    st.push(i); // Push current index
    i--;
  }
  return result;
}

/**
 * Optimized approach using monotonic stack to find sum of maximums of all
 * subarrays Time Complexity: O(n) Space Complexity: O(n)
 *
 * Algorithm:
 * 1. For each element arr[i], find how many subarrays have arr[i] as their
 * maximum
 * 2. This is calculated as: (i - left[i]) * (right[i] - i) * arr[i]
 * 3. Where left[i] is the previous greater/equal element and right[i] is the
 * next greater element
 *
 * @param arr - Input array
 * @return Sum of maximums of all subarrays modulo 10^9 + 7
 */
int sumSubarrayMaxs(vector<int> &arr) {
  const int MOD = 1e9 + 7;
  int sum = 0;
  int n = arr.size();

  // Find previous greater/equal elements and next greater elements
  vector<int> previousGreaterEqualElements =
      findPreviousGreaterEqualElements(arr);
  vector<int> nextGreaterElements = findNextGreaterElements(arr);

  // Calculate contribution of each element to the final sum
  for (int i = 0; i < n; i++) {
    // Number of elements to the left that are >= arr[i]
    int previousElementsCount = i - previousGreaterEqualElements[i];
    // Number of elements to the right that are > arr[i]
    int nextElementsCount = nextGreaterElements[i] - i;

    // Total subarrays where arr[i] is the maximum
    // Use 1LL to avoid integer overflow
    sum = (sum +
           ((1LL * previousElementsCount * nextElementsCount) * 1LL * arr[i])) %
          MOD;
  }
  return sum;
}

/**
 * Main function to test the sum of subarray maximums
 */
int main() {
  cout << "=== Sum of Subarray Maximums Test ===" << endl;

  // Test case 1: Basic test
  vector<int> arr1 = {3, 1, 2, 4};
  cout << "Test case 1: ";
  printVector(arr1);
  cout << "Brute force result: " << sumSubarrayMaxsBruteForce(arr1) << endl;
  cout << "Optimized result: " << sumSubarrayMaxs(arr1) << endl;
  cout << endl;

  // Test case 2: All same elements
  vector<int> arr2 = {2, 2, 2, 2};
  cout << "Test case 2: ";
  printVector(arr2);
  cout << "Brute force result: " << sumSubarrayMaxsBruteForce(arr2) << endl;
  cout << "Optimized result: " << sumSubarrayMaxs(arr2) << endl;
  cout << endl;

  // Test case 3: Increasing sequence
  vector<int> arr3 = {1, 2, 3, 4};
  cout << "Test case 3: ";
  printVector(arr3);
  cout << "Brute force result: " << sumSubarrayMaxsBruteForce(arr3) << endl;
  cout << "Optimized result: " << sumSubarrayMaxs(arr3) << endl;
  cout << endl;

  // Test case 4: Decreasing sequence
  vector<int> arr4 = {4, 3, 2, 1};
  cout << "Test case 4: ";
  printVector(arr4);
  cout << "Brute force result: " << sumSubarrayMaxsBruteForce(arr4) << endl;
  cout << "Optimized result: " << sumSubarrayMaxs(arr4) << endl;

  return 0;
}