#include <climits>
#include <cstddef>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <utility>
using namespace std;

/**
 * Optimized MinStack implementation using std::stack with pairs
 * This eliminates dynamic memory allocation and provides better performance
 * Time Complexity: O(1) for all operations
 * Space Complexity: O(n) where n is the number of elements
 */
class MinStack {
private:
  stack<pair<int, int>> dataStack; // pair<value, minSoFar>

public:
  /**
   * Constructor - no initialization needed
   */
  MinStack() = default;

  /**
   * Destructor - std::stack handles cleanup automatically
   */
  ~MinStack() = default;

  /**
   * Push a value onto the stack
   * @param value The value to push
   */
  void push(int value) {
    if (dataStack.empty()) {
      // First element is both value and minimum
      dataStack.push({value, value});
    } else {
      // Store value and current minimum
      int currentMin = dataStack.top().second;
      dataStack.push({value, min(value, currentMin)});
    }
  }

  /**
   * Remove the top element from the stack
   * @throws runtime_error if stack is empty
   */
  void pop() {
    if (dataStack.empty()) {
      throw runtime_error("Cannot pop from empty stack");
    }
    dataStack.pop();
  }

  /**
   * Get the top element of the stack
   * @return The top element
   * @throws runtime_error if stack is empty
   */
  int top() {
    if (dataStack.empty()) {
      throw runtime_error("Cannot get top from empty stack");
    }
    return dataStack.top().first;
  }

  /**
   * Get the minimum value in the stack
   * @return The minimum value
   * @throws runtime_error if stack is empty
   */
  int getMin() {
    if (dataStack.empty()) {
      throw runtime_error("Cannot get minimum from empty stack");
    }
    return dataStack.top().second;
  }

  /**
   * Check if the stack is empty
   * @return true if empty, false otherwise
   */
  bool isEmpty() const { return dataStack.empty(); }

  /**
   * Get the current size of the stack
   * @return Number of elements in the stack
   */
  size_t size() const { return dataStack.size(); }

  /**
   * Clear all elements from the stack
   */
  void clear() {
    while (!dataStack.empty()) {
      dataStack.pop();
    }
  }
};

/**
 * Alternative optimized implementation using two stacks
 * This approach can be more memory efficient for certain use cases
 */
class MinStackOptimized {
private:
  stack<int> valueStack;
  stack<int> minStack;

public:
  MinStackOptimized() = default;
  ~MinStackOptimized() = default;

  void push(int value) {
    valueStack.push(value);

    if (minStack.empty() || value <= minStack.top()) {
      minStack.push(value);
    }
  }

  void pop() {
    if (valueStack.empty()) {
      throw runtime_error("Cannot pop from empty stack");
    }

    if (valueStack.top() == minStack.top()) {
      minStack.pop();
    }
    valueStack.pop();
  }

  int top() {
    if (valueStack.empty()) {
      throw runtime_error("Cannot get top from empty stack");
    }
    return valueStack.top();
  }

  int getMin() {
    if (minStack.empty()) {
      throw runtime_error("Cannot get minimum from empty stack");
    }
    return minStack.top();
  }

  bool isEmpty() const { return valueStack.empty(); }

  size_t size() const { return valueStack.size(); }
};

/**
 * Space-optimized MinStack implementation using mathematical trick
 * Stores encoded values to maintain O(1) operations with minimal space overhead
 * Uses the formula: encoded_value = 2*value - previous_min
 * Time Complexity: O(1) for all operations
 * Space Complexity: O(n) but with better constant factors
 */
class MinStackSpaceOptimized {
private:
  int currentMinimum;
  stack<int> dataStack;

public:
  /**
   * Constructor initializes with maximum integer value
   */
  MinStackSpaceOptimized() : currentMinimum(INT_MAX) {}

  /**
   * Push a value onto the stack using encoding trick
   * @param value The value to push
   */
  void push(int value) {
    if (dataStack.empty()) {
      // First element - store as-is
      currentMinimum = value;
      dataStack.push(value);
      return;
    }

    if (currentMinimum > value) {
      // New minimum found - encode the value
      int encodedValue = (2 * value) - currentMinimum;
      currentMinimum = value;
      dataStack.push(encodedValue);
      return;
    }

    // Regular value - store as-is
    dataStack.push(value);
  }

  /**
   * Remove the top element from the stack
   * @throws runtime_error if stack is empty
   */
  void pop() {
    if (dataStack.empty()) {
      throw runtime_error("Cannot pop from empty stack");
    }

    if (currentMinimum > dataStack.top()) {
      // Decode the minimum value
      currentMinimum = (2 * currentMinimum) - dataStack.top();
    }
    dataStack.pop();
  }

  /**
   * Get the top element of the stack
   * @return The top element
   * @throws runtime_error if stack is empty
   */
  int top() {
    if (dataStack.empty()) {
      throw runtime_error("Cannot get top from empty stack");
    }

    if (currentMinimum > dataStack.top()) {
      // Return decoded minimum value
      return currentMinimum;
    }
    return dataStack.top();
  }

  /**
   * Get the minimum value in the stack
   * @return The minimum value
   * @throws runtime_error if stack is empty
   */
  int getMin() {
    if (dataStack.empty()) {
      throw runtime_error("Cannot get minimum from empty stack");
    }
    return currentMinimum;
  }

  /**
   * Get the current size of the stack
   * @return Number of elements in the stack
   */
  size_t size() const { return dataStack.size(); }

  /**
   * Clear all elements from the stack
   */
  void clear() {
    while (!dataStack.empty()) {
      dataStack.pop();
    }
    currentMinimum = INT_MAX;
  }

  /**
   * Check if the stack is empty
   * @return true if empty, false otherwise
   */
  bool isEmpty() const { return dataStack.empty(); }
};

/**
 * Performance comparison and demonstration
 */
int main() {
  cout << "=== Optimized MinStack Demonstration ===" << endl;

  MinStackSpaceOptimized minStack;

  // Performance test with larger dataset
  cout << "Testing with 100,000 elements..." << endl;

  // Push test
  for (int i = 100000; i >= 1; i--) {
    minStack.push(i);
  }

  cout << "After pushing 100,000 elements:" << endl;
  cout << "Size: " << minStack.size() << endl;
  cout << "Top: " << minStack.top() << endl;
  cout << "Min: " << minStack.getMin() << endl;

  // Pop test
  cout << "\nPopping first 10 elements:" << endl;
  for (int i = 0; i < 10; i++) {
    cout << "Pop " << (i + 1) << ": Top=" << minStack.top()
         << ", Min=" << minStack.getMin() << endl;
    minStack.pop();
  }

  cout << "\nFinal state:" << endl;
  cout << "Size: " << minStack.size() << endl;
  cout << "Top: " << minStack.top() << endl;
  cout << "Min: " << minStack.getMin() << endl;

  // Clear and test empty state
  minStack.clear();
  cout << "\nAfter clearing: Size=" << minStack.size()
       << ", Empty=" << (minStack.isEmpty() ? "true" : "false") << endl;

  minStack.push(12);
  cout << minStack.getMin() << endl;
  minStack.push(15);
  cout << minStack.getMin() << endl;
  minStack.push(10);
  cout << minStack.getMin() << endl;
  minStack.pop();
  cout << minStack.getMin() << endl;

  return 0;
}