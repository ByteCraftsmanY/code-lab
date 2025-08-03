#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/**
 * Brute Force Approach - O(n²) time complexity
 *
 * For each starting position, find the longest substring without repeating
 * characters by checking each character and maintaining a set of seen
 * characters.
 *
 * @param s Input string
 * @return Length of longest substring without repeating characters
 */
int findLength(string s) {
  int maxLen = 0;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    unordered_set<char> uniqueChar;
    string substring = "";

    for (int j = i; j < n; j++) {
      // Check if character already exists in current substring
      if (uniqueChar.find(s[j]) != uniqueChar.end()) {
        int subStringSize = substring.size();
        maxLen = max(maxLen, subStringSize);
        break;
      }

      uniqueChar.insert(s[j]);
      substring += s[j];
      // cout << "Current substring: " << substring << endl;
    }

    // Update maxLen for case when we reach end of string
    maxLen = max(maxLen, (int)substring.size());
  }

  return maxLen;
}

/**
 * Optimized Sliding Window Approach - O(n) time complexity
 *
 * Uses two pointers (i and j) to maintain a sliding window.
 * When a repeating character is found, we slide the left pointer
 * to the position after the first occurrence of the repeating character.
 *
 * @param s Input string
 * @return Length of longest substring without repeating characters
 */
int findLengthOptimized(string s) {
  int i = 0, j = 0, maxLen = 0;
  unordered_map<char, int> mp; // Maps character to its last position

  while (j < s.size()) {
    // If character already exists in current window
    if (mp.find(s[j]) != mp.end()) {
      // Slide left pointer to position after first occurrence
      for (int k = i; k < mp[s[j]] + 1; k++) {
        mp.erase(s[i++]);
      }
    }

    // Add current character to map
    mp[s[j]] = j;

    // Update maximum length
    maxLen = max(maxLen, j - i + 1);
    j++;
  }

  return maxLen;
}

/**
 * Alternative Optimized Approach - More readable version
 *
 * Uses a cleaner sliding window approach with better readability
 *
 * @param s Input string
 * @return Length of longest substring without repeating characters
 */
int findLengthOptimizedClean(string s) {
  int left = 0, right = 0, maxLen = 0;
  unordered_map<char, int> charMap;

  while (right < s.size()) {
    char currentChar = s[right];

    // If character exists in current window, update left pointer
    if (charMap.find(currentChar) != charMap.end()) {
      left = max(left, charMap[currentChar] + 1);
    }

    // Update character position
    charMap[currentChar] = right;

    // Update maximum length
    maxLen = max(maxLen, right - left + 1);
    right++;
  }

  return maxLen;
}

/**
 * Most Efficient Approach - O(n) time complexity with constant space
 *
 * Uses a fixed-size vector (256 elements) to store character positions.
 * This approach is more memory efficient than using unordered_map for ASCII
 * characters. Each character's ASCII value serves as an index into the vector.
 *
 * @param s Input string
 * @return Length of longest substring without repeating characters
 */
int findLength2(string s) {
  int left = 0, right = 0, maxLen = 0;
  vector<int> charMap(256, -1); // Initialize all positions to -1

  while (right < s.size()) {
    char currentChar = s[right];

    // If character already exists in current window, update left pointer
    if (charMap[currentChar] != -1) {
      left = charMap[currentChar] + 1;
    }

    // Update character position
    charMap[currentChar] = right;

    // Update maximum length
    maxLen = max(maxLen, right - left + 1);
    right++;
  }

  return maxLen;
}

/**
 * Main function with comprehensive test cases
 */
int main() {
  cout << "=== Longest Substring Without Repeating Characters ===" << endl;

  // Test cases
  vector<string> testCases = {
      "abcabcbb", // Expected: 3 ("abc")
      "bbbbb",    // Expected: 1 ("b")
      "pwwkew",   // Expected: 3 ("wke")
      "",         // Expected: 0
      "a",        // Expected: 1
      "ab",       // Expected: 2
      "abc",      // Expected: 3
      "dvdf",     // Expected: 3 ("vdf")
      "anviaj"    // Expected: 5 ("nviaj")
  };

  for (int i = 0; i < testCases.size(); i++) {
    string s = testCases[i];
    cout << "\n📋 Test Case " << (i + 1) << ": \"" << s << "\"" << endl;
    cout << "----------------------------------------" << endl;

    // Test brute force approach
    cout << "🔍 Brute Force Approach:" << endl;
    int result1 = findLength(s);
    cout << "Result: " << result1 << endl;

    // Test optimized approach
    cout << "\n⚡ Optimized Approach:" << endl;
    int result2 = findLengthOptimized(s);
    cout << "Result: " << result2 << endl;

    // Test clean optimized approach
    cout << "\n✨ Clean Optimized Approach:" << endl;
    int result3 = findLength2(s);
    cout << "Result: " << result3 << endl;

    // Verify all approaches give same result
    if (result1 == result2 && result2 == result3) {
      cout << "✅ All approaches agree: " << result1 << endl;
    } else {
      cout << "❌ Results differ!" << endl;
    }
  }

  cout << "\n🎉 All test cases completed!" << endl;
  return 0;
}