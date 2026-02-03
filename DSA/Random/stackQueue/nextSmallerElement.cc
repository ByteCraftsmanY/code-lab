#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Next Smaller Element
 *
 * Problem: Given an array, find the next smaller element for each element.
 * The next smaller element is the first smaller element that appears after
 * the current element. If no such element exists, return -1.
 *
 * Reference:
 * https://www.naukri.com/code360/problems/next-greater-element_1112581
 */

// Method 1: Brute Force Approach
// Time Complexity: O(n²)
// Space Complexity: O(1)
vector<int> nextSmallerElement(const vector<int> &arr, int n) {
  vector<int> result(n, -1);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i]) {
        result[i] = arr[j];
        break;
      }
    }
  }

  return result;
}

// Method 2: Stack-based Approach (Most Efficient) | (monotonic stack)
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> nextSmallerElement2(const vector<int> &arr, int n) {
  stack<int> st;
  vector<int> result(n, -1);

  // Process array from right to left
  for (int i = n - 1; i >= 0; i--) {
    // Remove elements from stack that are greater than or equal to current
    while (!st.empty() && st.top() >= arr[i]) {
      st.pop();
    }

    // If stack is not empty, top element is the next smaller
    if (!st.empty()) {
      result[i] = st.top();
    }

    st.push(arr[i]);
  }

  return result;
}

// Helper function to print vector elements
void printVector(const vector<int> &vec, const string &label) {
  cout << label << ": ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
    if (i < vec.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

// Helper function to run test case
void runTestCase(const vector<int> &input, const vector<int> &expected,
                 int testNum) {
  cout << "Test Case " << testNum << ":" << endl;
  printVector(input, "Input");

  vector<int> result =
      nextSmallerElement2(input, static_cast<int>(input.size()));
  printVector(result, "Output");
  printVector(expected, "Expected");

  bool isCorrect = (result == expected);
  cout << "Result: " << (isCorrect ? "✓ PASS" : "✗ FAIL") << endl;
  cout << endl;
}

int main() {
  cout << "Testing Next Smaller Element:" << endl;
  cout << "============================" << endl;

  // Test case 1
  vector<int> test1 = {2, 1, 4, 3};
  vector<int> expected1 = {1, -1, 3, -1};
  runTestCase(test1, expected1, 1);

  // Test case 2
  vector<int> test2 = {1, 3, 2};
  vector<int> expected2 = {-1, 2, -1};
  runTestCase(test2, expected2, 2);

  return 0;
}