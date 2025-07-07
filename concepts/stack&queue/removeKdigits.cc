#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/**
 * LeetCode Problem: Remove K Digits
 * Problem Link: https://leetcode.com/problems/remove-k-digits/description/
 *
 * Given string num representing a non-negative integer num, and an integer k,
 * return the smallest possible integer after removing k digits from num.
 *
 * Time Complexity Analysis:
 * - removeKdigits (Recursive): O(2^n) - exponential due to trying all
 * combinations
 * - removeKdigits2 (Stack): O(n) - linear time, single pass through the string
 *
 * Space Complexity:
 * - removeKdigits: O(n) - recursion stack depth
 * - removeKdigits2: O(n) - stack space
 */

/**
 * Removes a character from a string at the specified index
 * @param s Input string
 * @param idx Index to remove character from
 * @return String with character removed
 * Time Complexity: O(n)
 */
string removeCharFromIdx(string s, int idx) {
  string result = "";
  for (int i = 0; i < s.size(); i++) {
    if (i == idx) {
      continue;
    }
    result += s[i];
  }
  return result;
}

/**
 * Compares two strings numerically, ignoring leading zeros
 * @param one First string to compare
 * @param two Second string to compare
 * @return true if one > two, false otherwise
 * Time Complexity: O(n) where n is the length of the longer string
 */
bool isOneGreaterFromTwo(string one, string two) {
  int i = 0, j = 0;

  // Skip leading zeros in first string
  while (i < one.size() && one[i] == '0') {
    i++;
  }

  // Skip leading zeros in second string
  while (j < two.size() && two[j] == '0') {
    j++;
  }

  int oneLen = one.size() - i;
  int twoLen = two.size() - j;

  // Compare lengths first
  if (oneLen > twoLen) {
    return true;
  } else if (oneLen < twoLen) {
    return false;
  }

  // Compare digit by digit
  while (i < one.size()) {
    if (one[i] > two[i]) {
      return true;
    } else if (one[i] < two[i]) {
      return false;
    }
    i++;
  }
  return true;
}

/**
 * Recursive solution to remove k digits from a number
 * This is a brute force approach that tries all combinations
 * @param num Input number as string
 * @param k Number of digits to remove
 * @param idx Current index being considered
 * @return Smallest possible number after removing k digits
 * Time Complexity: O(2^n) - exponential due to recursion tree
 * Space Complexity: O(n) - recursion stack depth
 */
string removeKdigits(string num, int k, int idx = 0) {
  // Base cases
  if (idx > num.size()) {
    return num;
  } else if (k == 0) {
    return num;
  } else if (num.size() == k) {
    return "0";
  }

  // Try two options:
  // 1. Don't remove current digit
  string a = removeKdigits(num, k, idx + 1);

  // 2. Remove current digit
  string b = removeKdigits(removeCharFromIdx(num, idx), k - 1, idx);

  // Choose the smaller number
  string c = isOneGreaterFromTwo(b, a) ? a : b;

  // Remove leading zeros
  long long itr = 0;
  while (itr < c.size() - 1 && c[itr] == '0') {
    itr++;
  }

  return c.substr(itr, c.size() - itr);
}

/**
 * Optimal solution using stack to remove k digits
 * Uses greedy approach: remove larger digits when possible
 * @param num Input number as string
 * @param k Number of digits to remove
 * @return Smallest possible number after removing k digits
 * Time Complexity: O(n) - single pass through the string
 * Space Complexity: O(n) - stack space
 */
string removeKdigits2(string num, int k) {
  string result;
  stack<char> st;

  // Process each digit
  for (int i = 0; i < num.size(); i++) {
    // Remove larger digits from stack while we can
    while (!st.empty() && k > 0 && st.top() > num[i]) {
      st.pop();
      k--;
    }
    st.push(num[i]);
  }

  // Remove remaining digits if k > 0
  while (k > 0) {
    st.pop();
    k--;
  }

  // Build result from stack (in reverse order)
  while (!st.empty()) {
    result.push_back(st.top());
    st.pop();
  }

  // Remove trailing zeros
  while (!result.empty() && result.back() == '0') {
    result.pop_back();
  }

  // Handle empty result
  if (result.empty()) {
    return "0";
  }

  // Reverse to get correct order
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  int t, n;
  string s;

  cin >> t;

  while (t--) {
    cin.ignore();
    getline(cin, s);
    cin >> n;

    cout << removeKdigits2(s, n) << endl;
  }

  return 0;
}