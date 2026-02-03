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
 * Brute force approach to find sum of minimums of all subarrays
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * @param arr - Input array
 * @return Sum of minimums of all subarrays modulo 10^9 + 7
 *
 * Leetcode: https://leetcode.com/problems/sum-of-subarray-minimums/description/
 */
int sumSubarrayMins(vector<int> &arr) {
  const int MOD = 1e9 + 7;
  int sum = 0;
  int n = arr.size();

  // Generate all subarrays and find their minimums
  for (int i = 0; i < n; i++) {
    int minEle = arr[i]; // Initialize minimum for current subarray
    for (int j = i; j < n; j++) {
      minEle = min(minEle, arr[j]); // Update minimum for current subarray
      sum = (sum + minEle) % MOD;   // Add to sum and take modulo
    }
  }
  return sum;
}

/**
 * Find the previous smaller or equal element for each position using monotonic
 * stack Time Complexity: O(n) Space Complexity: O(n)
 * @param arr - Input array
 * @return Vector where result[i] = index of previous smaller/equal element, -1
 * if none
 * if we have array of 1,1
 * prev small element will be -1, -1
 * next small element will be 2, 2
 * contibution of 0 ele idx = (0-(-1)) * (2 - 0) = 2
 * contibution of 1 ele idx = (1-(-1)) * (2 - 1) = 2 * 1 = 2
 * which is wrong (2 * 2 * 1 = 4)
 * to handle this we need to ignore equal element from one side either
 * for that reason ignore element for 1 side let's say from left side then
 * prev smaller equal elements will be -1 0
 * contibution of 0 ele idx = (0-(-1)) * (2 - 0) = 2
 * contibution of 1 ele idx = (1-0) * (2 - 1) = 1
 * ans = 2 * 1 = 2
 */
vector<int> findPreviousSmallerEqualElements(vector<int> &arr) {
  vector<int> result(arr.size(),
                     -1); // Initialize with -1 (no previous smaller element)
  stack<int> st;          // Monotonic stack to maintain indices
  int i = 0;

  while (i < arr.size()) {
    // Pop elements from stack until we find a smaller or equal element
    while (!st.empty() && arr[st.top()] > arr[i]) {
      st.pop();
    }
    // If stack is not empty, top element is the previous smaller/equal element
    if (!st.empty()) {
      result[i] = st.top();
    }
    st.push(i); // Push current index
    i++;
  }
  return result;
}

/**
 * Find the next smaller element for each position using monotonic stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @param arr - Input array
 * @return Vector where result[i] = index of next smaller element, n if none
 */
vector<int> findNextSmallerElements(vector<int> &arr) {
  vector<int> result(arr.size(),
                     arr.size()); // Initialize with n (no next smaller element)
  stack<int> st;                  // Monotonic stack to maintain indices
  int i = arr.size() - 1;         // Start from the end

  while (i >= 0) {
    // Pop elements from stack until we find a smaller element
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }
    // If stack is not empty, top element is the next smaller element
    if (!st.empty()) {
      result[i] = st.top();
    }
    st.push(i); // Push current index
    i--;
  }
  return result;
}

/**
 * Optimized approach using monotonic stack to find sum of minimums of all
 * subarrays Time Complexity: O(n) Space Complexity: O(n)
 *
 * Algorithm:
 * 1. For each element arr[i], find how many subarrays have arr[i] as their
 * minimum
 * 2. This is calculated as: (i - left[i]) * (right[i] - i) * arr[i]
 * 3. Where left[i] is the previous smaller/equal element and right[i] is the
 * next smaller element
 *
 * @param arr - Input array
 * @return Sum of minimums of all subarrays modulo 10^9 + 7
 */
int sumSubarrayMins2(vector<int> &arr) {
  const int MOD = 1e9 + 7;
  int sum = 0;
  int n = arr.size();

  // Find previous smaller/equal elements and next smaller elements
  vector<int> previousSmallerEqualElements =
      findPreviousSmallerEqualElements(arr);
  vector<int> nextSmallerElements = findNextSmallerElements(arr);

  // Calculate contribution of each element to the final sum
  for (int i = 0; i < n; i++) {
    // Number of elements to the left that are >= arr[i]
    int previousElementsCount = i - previousSmallerEqualElements[i];
    // Number of elements to the right that are > arr[i]
    int nextElementsCount = nextSmallerElements[i] - i;

    // Total subarrays where arr[i] is the minimum
    // Use 1LL to avoid integer overflow
    sum = (sum +
           ((1LL * previousElementsCount * nextElementsCount) * 1LL * arr[i])) %
          MOD;
  }
  return sum;
}

/**
 * Main function to test the sum of subarray minimums
 */
int main() {
  vector<int> arr = {3, 1, 2, 4};
  cout << "Sum of minimums of all subarrays: " << sumSubarrayMins2(arr) << endl;
  return 0;
}