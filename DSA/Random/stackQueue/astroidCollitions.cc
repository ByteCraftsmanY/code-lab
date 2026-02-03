#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Asteroid Collision Problem
 *
 * Problem: Given an array asteroids of integers representing asteroids in a
 * row. For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 *
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Leetcode: https://leetcode.com/problems/asteroid-collision/
 */
vector<int> asteroidCollision(vector<int> &asteroids) {
  stack<int> st;

  for (int asteroid : asteroids) {
    // If asteroid is moving right, push to stack
    if (asteroid > 0) {
      st.push(asteroid);
    } else {
      // Asteroid is moving left (negative)
      bool isDestroyed = false;

      // Check collisions with asteroids moving right
      while (!st.empty() && st.top() > 0) {
        if (abs(asteroid) == st.top()) {
          // Both asteroids destroy each other
          st.pop();
          isDestroyed = true;
          break;
        } else if (abs(asteroid) > st.top()) {
          // Current asteroid destroys the one in stack
          st.pop();
        } else {
          // Stack asteroid destroys current asteroid
          isDestroyed = true;
          break;
        }
      }

      // If current asteroid wasn't destroyed, add it to stack
      if (!isDestroyed) {
        st.push(asteroid);
      }
    }
  }

  // Optimized stack to vector conversion
  vector<int> result(st.size());
  for (int i = st.size() - 1; i >= 0; i--) {
    result[i] = st.top();
    st.pop();
  }

  return result;
}

/**
 * Utility function to print a vector
 */
void printVector(const vector<int> &arr) {
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << "]" << endl;
}

int main() {
  // Test cases
  vector<int> test1 = {-2, -1, 1, 2};
  vector<int> test2 = {10, 2, -5};
  vector<int> test3 = {8, -8};
  vector<int> test4 = {5, 10, -5};

  cout << "Asteroid Collision Test Cases" << endl;
  cout << "=============================" << endl << endl;

  // Test Case 1: [-2,-1,1,2] -> [-2,-1,1,2] (no collisions)
  cout << "Test Case 1: [ ";
  printVector(test1);
  vector<int> result1 = asteroidCollision(test1);
  cout << "Result: [ ";
  printVector(result1);
  cout << endl;

  // Test Case 2: [10,2,-5] -> [10]
  cout << "Test Case 2: [ ";
  printVector(test2);
  vector<int> result2 = asteroidCollision(test2);
  cout << "Result: [ ";
  printVector(result2);
  cout << endl;

  // Test Case 3: [8,-8] -> []
  cout << "Test Case 3: [ ";
  printVector(test3);
  vector<int> result3 = asteroidCollision(test3);
  cout << "Result: [ ";
  printVector(result3);
  cout << endl;

  // Test Case 4: [5,10,-5] -> [5,10]
  cout << "Test Case 4: [ ";
  printVector(test4);
  vector<int> result4 = asteroidCollision(test4);
  cout << "Result: [ ";
  printVector(result4);
  cout << endl;

  return 0;
}