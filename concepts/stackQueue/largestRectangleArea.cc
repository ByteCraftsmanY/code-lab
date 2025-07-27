#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Method 1: Brute Force Approach
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 *
 * For each bar, find the leftmost and rightmost smaller elements
 * and calculate the area that can be formed with current bar as height.
 */
int largestRectangleArea(vector<int> &histogramHeights) {
  int totalBars = histogramHeights.size();
  int maximumRectangleArea = 0;

  for (int currentBarIndex = 0; currentBarIndex < totalBars;
       currentBarIndex++) {
    int leftBoundaryIndex = currentBarIndex;
    int rightBoundaryIndex = currentBarIndex;
    int currentBarArea;

    // Find the leftmost smaller element (left boundary)
    while (leftBoundaryIndex >= 0 && histogramHeights[leftBoundaryIndex] >=
                                         histogramHeights[currentBarIndex]) {
      leftBoundaryIndex--;
    }

    // Find the rightmost smaller element (right boundary)
    while (rightBoundaryIndex < totalBars &&
           histogramHeights[rightBoundaryIndex] >=
               histogramHeights[currentBarIndex]) {
      rightBoundaryIndex++;
    }

    // Calculate area for current bar
    currentBarArea = (rightBoundaryIndex - leftBoundaryIndex - 1) *
                     histogramHeights[currentBarIndex];
    maximumRectangleArea = max(currentBarArea, maximumRectangleArea);
  }

  return maximumRectangleArea;
}

/**
 * Method 2: Using Stack with Pre-computed Next Smaller Elements
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * First pass: Find next smaller element for each position
 * Second pass: Find previous smaller element and calculate area
 */
int largestRectangleArea2(vector<int> &histogramHeights) {
  int totalBars = histogramHeights.size();
  int maximumRectangleArea = 0;
  int currentBarIndex = totalBars - 1;

  stack<int> monotonicStack;
  vector<int> nextSmallerElementIndex(histogramHeights.size(),
                                      histogramHeights.size());

  // Find next smaller element for each position
  while (currentBarIndex >= 0) {
    while (!monotonicStack.empty() && histogramHeights[monotonicStack.top()] >=
                                          histogramHeights[currentBarIndex]) {
      monotonicStack.pop();
    }

    if (!monotonicStack.empty()) {
      nextSmallerElementIndex[currentBarIndex] = monotonicStack.top();
    }

    monotonicStack.push(currentBarIndex);
    currentBarIndex--;
  }

  // Find previous smaller element and calculate area
  currentBarIndex = 0;
  while (!monotonicStack.empty()) {
    monotonicStack.pop();
  }

  while (currentBarIndex < totalBars) {
    while (!monotonicStack.empty() && histogramHeights[monotonicStack.top()] >=
                                          histogramHeights[currentBarIndex]) {
      monotonicStack.pop();
    }

    int previousSmallerElementIndex =
        !monotonicStack.empty() ? monotonicStack.top() : -1;
    int currentBarArea = (nextSmallerElementIndex[currentBarIndex] -
                          previousSmallerElementIndex - 1) *
                         histogramHeights[currentBarIndex];
    maximumRectangleArea = max(currentBarArea, maximumRectangleArea);
    monotonicStack.push(currentBarIndex);
    currentBarIndex++;
  }

  return maximumRectangleArea;
}

/**
 * Method 3: Single Pass Stack Solution (Most Efficient)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Use a monotonic stack to maintain bars in increasing order.
 * When we encounter a smaller bar, we calculate areas for all
 * larger bars in the stack.
 */
int largestRectangleArea3(vector<int> &histogramHeights) {
  int totalBars = histogramHeights.size();
  int maximumRectangleArea = 0;
  int currentBarIndex = 0;
  int currentBarArea = 0;
  int leftBoundaryIndex;

  stack<int> monotonicStack;

  while (currentBarIndex < totalBars) {
    // Pop all bars larger than current bar and calculate their areas
    while (!monotonicStack.empty() && histogramHeights[monotonicStack.top()] >=
                                          histogramHeights[currentBarIndex]) {
      int poppedBarIndex = monotonicStack.top();
      monotonicStack.pop();

      leftBoundaryIndex = !monotonicStack.empty() ? monotonicStack.top() : -1;
      currentBarArea = (currentBarIndex - leftBoundaryIndex - 1) *
                       histogramHeights[poppedBarIndex];
      maximumRectangleArea = max(maximumRectangleArea, currentBarArea);
    }

    monotonicStack.push(currentBarIndex);
    currentBarIndex++;
  }

  // Process remaining bars in the stack
  while (!monotonicStack.empty()) {
    int poppedBarIndex = monotonicStack.top();
    monotonicStack.pop();

    int leftBoundaryIndex = !monotonicStack.empty() ? monotonicStack.top() : -1;
    int rightBoundaryIndex = totalBars;

    currentBarArea = (rightBoundaryIndex - leftBoundaryIndex - 1) *
                     histogramHeights[poppedBarIndex];
    maximumRectangleArea = max(maximumRectangleArea, currentBarArea);
  }

  return maximumRectangleArea;
}

int main() {
  // Test case 1: [2, 1, 5, 6, 2, 3] -> Expected: 10
  vector<int> histogramHeights = {2, 1, 5, 6, 2, 3};
  cout << "Test Case 1: [2, 1, 5, 6, 2, 3]" << endl;
  cout << "Largest Rectangle Area: " << largestRectangleArea3(histogramHeights)
       << endl;

  // Test case 2: [2, 4] -> Expected: 4
  histogramHeights = {2, 4};
  cout << "\nTest Case 2: [2, 4]" << endl;
  cout << "Largest Rectangle Area: " << largestRectangleArea3(histogramHeights)
       << endl;

  return 0;
}