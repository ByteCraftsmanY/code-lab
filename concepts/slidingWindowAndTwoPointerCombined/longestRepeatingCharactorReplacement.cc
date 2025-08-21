#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// https://leetcode.com/problems/longest-repeating-character-replacement/

/**
 * Find the length of the longest substring that can be formed by replacing
 * at most k characters with any other character
 *
 * Key Insight: The longest substring will have the most frequent character
 * as the majority, and we can replace at most k other characters to make
 * all characters the same.
 *
 * @param s Input string
 * @param k Maximum number of characters that can be replaced
 * @return Length of the longest substring after replacement
 */
int characterReplacement(string s, int k) {
  int result = 0, n = s.size(), maxFreq = 0, dist = 0;

  // Brute Force Approach (O(n²) time complexity)
  // Check all possible substrings and count character frequencies
  // for (int i = 0; i < n; i++) {
  //     maxFreq = 0;
  //     vector<int> freqCounter(26, 0);
  //     for (int j = i; j < n; j++) {
  //         freqCounter[s[j] - 'A']++;
  //         maxFreq = max(maxFreq, freqCounter[s[j] - 'A']);
  //         dist = j - i + 1;
  //         if (dist - maxFreq <= k) {
  //             result = max(result, dist);
  //         } else {
  //             break;
  //         }
  //     }
  // }

  // Sliding window approach with while loop (O(n) time complexity)
  // This approach recalculates maxFreq when shrinking the window
  // int i = 0, j = 0;
  // vector<int> freqCounter(26, 0);
  // while (j < n) {
  //     freqCounter[s[j] - 'A']++;
  //     maxFreq = max(maxFreq, freqCounter[s[j] - 'A']);
  //     while ((j - i + 1) - maxFreq > k) {
  //         freqCounter[s[i] - 'A']--;
  //         int newMaxFreq = 0;
  //         for (int const &count : freqCounter) {
  //             newMaxFreq = max(newMaxFreq, count);
  //         }
  //         maxFreq = newMaxFreq;
  //         i++;
  //     }
  //     dist = j - i + 1;
  //     result = max(result, dist);
  //     j++;
  // }

  // Optimized sliding window approach
  // Key insight: We don't need to recalculate maxFreq when shrinking
  // because the result will only increase when maxFreq increases
  int left = 0, right = 0;
  vector<int> freqCounter(26, 0);

  while (right < n) {
    // Count frequency of current character
    freqCounter[s[right] - 'A']++;
    maxFreq = max(maxFreq, freqCounter[s[right] - 'A']);
    dist = right - left + 1;

    // Shrink window if we need more than k replacements
    // dist - maxFreq = number of characters that need to be replaced
    if (dist - maxFreq > k) {
      freqCounter[s[left] - 'A']--;
      left++;
    }

    // Update result with current window size
    // We only update when the window is valid (≤ k replacements needed)
    dist = right - left + 1;
    if (dist - maxFreq <= k) {
      result = max(result, dist);
    }
    right++;
  }

  return result;
}

int main() {
  // Test case 1: "AABABBA" with k=1
  // Expected: 4 (can replace one 'B' to get "AABABBA" -> "AAAABBA")
  string s1 = "AABABBA";
  int k1 = 1;
  cout << "Test Case 1:" << endl;
  cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
  cout << "Output: " << characterReplacement(s1, k1) << endl;
  cout << endl;

  // Test case 2: "ABAB" with k=2
  // Expected: 4 (can replace both 'B's to get "AAAA")
  string s2 = "ABAB";
  int k2 = 2;
  cout << "Test Case 2:" << endl;
  cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
  cout << "Output: " << characterReplacement(s2, k2) << endl;

  return 0;
}