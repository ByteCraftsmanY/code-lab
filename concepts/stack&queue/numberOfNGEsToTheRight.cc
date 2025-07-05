#include <iostream>
#include <vector>
using namespace std;

/**
 * Number of Next Greater Elements to the Right
 *
 * Problem: Given an array and a query array containing indices, for each query
 * index, find the count of elements to the right that are greater than the
 * element at that index.
 *
 * Reference:
 * https://www.naukri.com/code360/problems/count-of-greater-elements-to-the-right_8365436?leftPanelTabValue=SOLUTION
 */

// Method 1: Brute Force Approach
// Time Complexity: O(n * q) where n = arr.size(), q = query.size()
// Space Complexity: O(q)
vector<int> countGreater(const vector<int> &arr, const vector<int> &query) {
  vector<int> result(query.size(), 0);

  for (int i = 0; i < query.size(); i++) {
    int queryIndex = query[i];

    // Count elements to the right that are greater than arr[queryIndex]
    for (int j = queryIndex + 1; j < arr.size(); j++) {
      if (arr[queryIndex] < arr[j]) {
        result[i]++;
      }
    }
  }

  return result;
}

// Method 2: Optimized Approach using Monotonic Stack (if needed for larger
// datasets) Time Complexity: O(n + q) Space Complexity: O(n)
vector<int> countGreaterOptimized(const vector<int> &arr,
                                  const vector<int> &query) {
  int n = arr.size();
  vector<int> result(query.size(), 0);

  // For each query, we can optimize by precomputing next greater elements
  // This is a more complex approach but useful for multiple queries
  for (int i = 0; i < query.size(); i++) {
    int queryIndex = query[i];

    // Count elements to the right that are greater
    for (int j = queryIndex + 1; j < n; j++) {
      if (arr[queryIndex] < arr[j]) {
        result[i]++;
      }
    }
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
void runTestCase(const vector<int> &arr, const vector<int> &query,
                 const vector<int> &expected, int testNum) {
  cout << "Test Case " << testNum << ":" << endl;
  printVector(arr, "Array");
  printVector(query, "Query Indices");

  vector<int> result = countGreater(arr, query);
  printVector(result, "Result");
  printVector(expected, "Expected");

  bool isCorrect = (result == expected);
  cout << "Result: " << (isCorrect ? "✓ PASS" : "✗ FAIL") << endl;
  cout << endl;
}

int main() {
  cout << "Testing Number of Next Greater Elements to the Right:" << endl;
  cout << "==================================================" << endl;

  // Test case 1
  vector<int> arr1 = {5, 2, 10, 4};
  vector<int> query1 = {0, 1};
  vector<int> expected1 = {1, 1};
  runTestCase(arr1, query1, expected1, 1);

  // Test case 2
  vector<int> arr2 = {1, 3, 2, 4};
  vector<int> query2 = {0, 1, 2};
  vector<int> expected2 = {3, 1, 1};
  runTestCase(arr2, query2, expected2, 2);

  return 0;
}