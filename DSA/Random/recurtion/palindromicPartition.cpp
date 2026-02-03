/**
 * @file rescurtion-all.cpp
 * @brief Program to find all possible palindromic substring partitions of a given string
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Checks if a substring is a palindrome
 * @param str Input string
 * @param left Starting index of substring
 * @param right Ending index of substring
 * @return true if substring is palindrome, false otherwise
 */
bool isPalindrome(const string& str, int left, int right) {
    while (left <= right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

/**
 * @brief Helper function to recursively find all palindromic substring partitions
 * @param allPartitions Vector to store all valid partitions
 * @param currentPartition Current partition being built
 * @param inputStr Input string
 * @param startIndex Current starting index for partition
 */
void getAllPalindromicPartitionsHelper(
    vector<vector<string>>& allPartitions,
    vector<string>& currentPartition,
    const string& inputStr,
    int startIndex = 0) {
    // Base case: if we've reached the end of string, add current partition
    if (startIndex >= inputStr.size()) {
        allPartitions.push_back(currentPartition);
        return;
    }

    // Try all possible substrings starting from startIndex
    string currentSubstring;
    for (int i = startIndex; i < inputStr.size(); i++) {
        currentSubstring += inputStr[i];

        // Only proceed if current substring is palindrome
        if (!isPalindrome(inputStr, startIndex, i)) {
            continue;
        }

        // Add current substring to partition and recurse
        currentPartition.push_back(currentSubstring);
        getAllPalindromicPartitionsHelper(allPartitions, currentPartition, inputStr, i + 1);
        currentPartition.pop_back();  // Backtrack
    }
}

/**
 * @brief Finds all possible palindromic substring partitions of a string
 * @param inputStr Input string to partition
 * @return Vector of all valid palindromic partitions
 */
vector<vector<string>> getAllPalindromicPartitions(const string& inputStr) {
    vector<string> currentPartition;
    vector<vector<string>> allPartitions;
    getAllPalindromicPartitionsHelper(allPartitions, currentPartition, inputStr);
    return allPartitions;
}

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore();  // Clear newline from buffer

    while (testCases--) {
        string inputString;
        getline(cin, inputString);

        auto partitions = getAllPalindromicPartitions(inputString);

        // Print all partitions
        for (const auto& partition : partitions) {
            for (const auto& substring : partition) {
                cout << substring << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
