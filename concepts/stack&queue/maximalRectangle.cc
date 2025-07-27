#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Calculate the largest rectangle area in a histogram
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Uses a monotonic stack to find the largest rectangle
 * that can be formed with each bar as height.
 */
int largestRectangleArea(vector<int> histogramHeights) {
  stack<int> monotonicStack;
  int totalBars = histogramHeights.size();
  int maximumRectangleArea = 0;
  int currentBarArea = 0;

  // Process each bar in the histogram
  for (int currentBarIndex = 0; currentBarIndex < totalBars;
       currentBarIndex++) {
    // Pop all bars larger than current bar and calculate their areas
    while (!monotonicStack.empty() && histogramHeights[monotonicStack.top()] >=
                                          histogramHeights[currentBarIndex]) {
      int poppedBarIndex = monotonicStack.top();
      monotonicStack.pop();

      int leftBoundaryIndex =
          !monotonicStack.empty() ? monotonicStack.top() : -1;
      currentBarArea = (currentBarIndex - leftBoundaryIndex - 1) *
                       histogramHeights[poppedBarIndex];
      maximumRectangleArea = max(currentBarArea, maximumRectangleArea);
    }
    monotonicStack.push(currentBarIndex);
  }

  // Process remaining bars in the stack
  while (!monotonicStack.empty()) {
    int nextSmallerElementIndex = totalBars;
    int currentBarIndex = monotonicStack.top();
    monotonicStack.pop();

    int previousBarIndex = !monotonicStack.empty() ? monotonicStack.top() : -1;
    currentBarArea = (nextSmallerElementIndex - previousBarIndex - 1) *
                     histogramHeights[currentBarIndex];
    maximumRectangleArea = max(currentBarArea, maximumRectangleArea);
  }

  return maximumRectangleArea;
}

/**
 * Find the maximal rectangle containing only 1's in a binary matrix
 * Time Complexity: O(n * m)
 * Space Complexity: O(m)
 *
 * Algorithm:
 * 1. Convert the matrix to histogram heights for each row
 * 2. For each row, calculate the largest rectangle area
 * 3. Return the maximum area found
 */
int maximalRectangle(vector<vector<char>> &binaryMatrix) {
  int totalRows = binaryMatrix.size();
  int totalColumns = binaryMatrix[0].size();
  int maximumRectangleArea = 0;

  // Create a matrix to store cumulative heights for each column
  vector<vector<int>> histogramHeightsMatrix(totalRows,
                                             vector<int>(totalColumns, 0));

  // Calculate histogram heights for each column
  for (int columnIndex = 0; columnIndex < totalColumns; columnIndex++) {
    int cumulativeHeight = 0;

    for (int rowIndex = 0; rowIndex < totalRows; rowIndex++) {
      if (binaryMatrix[rowIndex][columnIndex] == '0') {
        cumulativeHeight = 0; // Reset height if we encounter a 0
      } else {
        cumulativeHeight += (binaryMatrix[rowIndex][columnIndex] - '0');
      }
      histogramHeightsMatrix[rowIndex][columnIndex] = cumulativeHeight;
    }
  }

  // Find the largest rectangle area for each row
  for (const auto &histogramRow : histogramHeightsMatrix) {
    maximumRectangleArea =
        max(maximumRectangleArea, largestRectangleArea(histogramRow));
  }

  return maximumRectangleArea;
}

int main() {
  // Example test cases
  vector<vector<char>> testMatrix1 = {{'1', '0', '1', '0', '0'},
                                      {'1', '0', '1', '1', '1'},
                                      {'1', '1', '1', '1', '1'},
                                      {'1', '0', '0', '1', '0'}};

  cout << "Test Matrix 1:" << endl;
  for (const auto &row : testMatrix1) {
    for (char cell : row) {
      cout << cell << " ";
    }
    cout << endl;
  }
  cout << "Maximal Rectangle Area: " << maximalRectangle(testMatrix1) << endl;

  vector<vector<char>> testMatrix2 = {{'0'}};

  cout << "\nTest Matrix 2:" << endl;
  for (const auto &row : testMatrix2) {
    for (char cell : row) {
      cout << cell << " ";
    }
    cout << endl;
  }
  cout << "Maximal Rectangle Area: " << maximalRectangle(testMatrix2) << endl;

  return 0;
}