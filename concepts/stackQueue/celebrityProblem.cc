#include <iostream>
#include <vector>
using namespace std;

// https://www.naukri.com/code360/problems/the-celebrity-problem_10728328?leftPanelTabValue=PROBLEM

/**
 * Celebrity Problem - Find the celebrity in a party
 *
 * A celebrity is someone who is known by everyone but doesn't know anyone.
 * Given a matrix where matrix[i][j] = 1 means person i knows person j,
 * find the celebrity if it exists, otherwise return -1.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

// Sample matrix representing who knows whom
// matrix[i][j] = 1 means person i knows person j
vector<vector<int>> matrix = {
    {0, 1, 0, 1}, // Person 0 knows person 1 and 3
    {0, 0, 0, 0}, // Person 1 doesn't know anyone (potential celebrity)
    {1, 1, 0, 0}, // Person 2 knows person 0 and 1
    {1, 1, 1, 0}, // Person 3 knows person 0, 1, and 2
};

/**
 * Check if person 'a' knows person 'b'
 *
 * @param a The person who might know 'b'
 * @param b The person who might be known by 'a'
 * @return true if 'a' knows 'b', false otherwise
 */
bool knows(int a, int b) { return matrix[a][b]; }

/**
 * Find the celebrity using the counting method
 *
 * Algorithm:
 * 1. Count how many people each person knows
 * 2. Count how many people know each person
 * 3. Celebrity should be known by everyone (n-1 people) and know no one (0
 * people)
 *
 * @param n Number of people in the party
 * @return Index of the celebrity, or -1 if no celebrity exists
 */
int findCelebrityCounting(int n) {
  if (n <= 0) {
    return -1;
  }

  vector<int> knownBy(n, 0);    // How many people know person i
  vector<int> knowsCount(n, 0); // How many people person i knows

  // Count relationships
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) { // Skip self-knowledge
        if (knows(i, j)) {
          knowsCount[i]++; // Person i knows person j
        }
        if (knows(j, i)) {
          knownBy[i]++; // Person j knows person i
        }
      }
    }
  }

  // Find celebrity: known by everyone (n-1) but knows no one (0)
  for (int i = 0; i < n; i++) {
    if (knownBy[i] == n - 1 && knowsCount[i] == 0) {
      return i;
    }
  }

  return -1;
}

/**
 * Find the celebrity using the elimination method
 *
 * Algorithm:
 * 1. Start with two pointers at the ends
 * 2. If person at 'top' knows person at 'bottom', eliminate 'top'
 * 3. If person at 'bottom' knows person at 'top', eliminate 'bottom'
 * 4. If neither knows the other, eliminate both
 * 5. Continue until only one person remains
 * 6. Verify if the remaining person is actually a celebrity
 *
 * @param n Number of people in the party
 * @return Index of the celebrity, or -1 if no celebrity exists
 */
int findCelebrity(int n) {
  if (n <= 0) {
    return -1;
  }

  int top = 0, bottom = n - 1;

  // Eliminate people until only one candidate remains
  while (top < bottom) {
    if (knows(top, bottom)) {
      // 'top' knows 'bottom', so 'top' cannot be celebrity
      top++;
    } else if (knows(bottom, top)) {
      // 'bottom' knows 'top', so 'bottom' cannot be celebrity
      bottom--;
    } else {
      // Neither knows the other, eliminate both
      top++;
      bottom--;
    }
  }

  // Verify if the remaining person is actually a celebrity
  int candidate = top;
  for (int i = 0; i < n; i++) {
    if (i == candidate) {
      continue; // Skip checking with self
    }

    // Celebrity should not know anyone
    if (knows(candidate, i)) {
      return -1;
    }

    // Everyone should know the celebrity
    if (!knows(i, candidate)) {
      return -1;
    }
  }

  return candidate;
}

/**
 * Alternative implementation using stack approach
 *
 * @param n Number of people in the party
 * @return Index of the celebrity, or -1 if no celebrity exists
 */
int findCelebrityStack(int n) {
  if (n <= 0) {
    return -1;
  }

  // Push all people onto stack
  vector<int> stack;
  for (int i = 0; i < n; i++) {
    stack.push_back(i);
  }

  // Eliminate people until only one remains
  while (stack.size() > 1) {
    int a = stack.back();
    stack.pop_back();
    int b = stack.back();
    stack.pop_back();

    if (knows(a, b)) {
      // 'a' knows 'b', so 'a' cannot be celebrity
      stack.push_back(b);
    } else {
      // 'a' doesn't know 'b', so 'b' cannot be celebrity
      stack.push_back(a);
    }
  }

  if (stack.empty()) {
    return -1;
  }

  // Verify if the remaining person is actually a celebrity
  int candidate = stack[0];
  for (int i = 0; i < n; i++) {
    if (i == candidate) {
      continue;
    }

    if (knows(candidate, i) || !knows(i, candidate)) {
      return -1;
    }
  }

  return candidate;
}

/**
 * Brute force approach for comparison
 *
 * @param n Number of people in the party
 * @return Index of the celebrity, or -1 if no celebrity exists
 */
int findCelebrityBruteForce(int n) {
  for (int i = 0; i < n; i++) {
    bool isCelebrity = true;

    // Check if person i knows anyone
    for (int j = 0; j < n; j++) {
      if (i != j && knows(i, j)) {
        isCelebrity = false;
        break;
      }
    }

    if (!isCelebrity) {
      continue;
    }

    // Check if everyone knows person i
    for (int j = 0; j < n; j++) {
      if (i != j && !knows(j, i)) {
        isCelebrity = false;
        break;
      }
    }

    if (isCelebrity) {
      return i;
    }
  }

  return -1;
}

int main() {
  cout << "=== Celebrity Problem Tests ===\n\n";

  int n = 4;
  cout << "Matrix representing who knows whom:\n";
  for (int i = 0; i < n; i++) {
    cout << "Person " << i << ": ";
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  // Test different approaches
  cout << "Results:\n";
  cout << "Counting Method: " << findCelebrityCounting(n) << "\n";
  cout << "Elimination Method: " << findCelebrity(n) << "\n";
  cout << "Stack Method: " << findCelebrityStack(n) << "\n";
  cout << "Brute Force: " << findCelebrityBruteForce(n) << "\n";

  return 0;
}