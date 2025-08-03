#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Find the maximum number of fruits that can be collected using at most 2
 * baskets
 *
 * @param fruits Vector of integers representing fruit types
 * @return Maximum number of fruits that can be collected
 */
int totalFruit(vector<int> &fruits) {
    const int baskets = 2;
    int result = 0, n = fruits.size();

    // Brute Force Approach (O(n²) time complexity)
    // for (int i = 0; i < n; i++) {
    //     unordered_set<int> st;
    //     for (int j = i; j < n; j++) {
    //         if (st.size() > baskets) {
    //             break;
    //         }
    //         st.insert(fruits[j]);
    //         result = max(result, j - i + 1);
    //     }
    // }

    // Sliding window approach with while loop (O(n) time complexity)
    // int i = 0, j = 0;
    // unordered_map<int, int> charCountMap;
    // while (j < n) {
    //     charCountMap[fruits[j]]++;
    //     while (charCountMap.size() > baskets) {
    //         charCountMap[fruits[i]]--;
    //         if (charCountMap[fruits[i]] <= 0) {
    //             charCountMap.erase(fruits[i]);
    //         }
    //         i++;
    //     }
    //     result = max(result, j - i + 1);
    //     j++;
    // }

    // Optimized sliding window approach
    int left = 0, right = 0;
    unordered_map<int, int> fruitCountMap;

    while (right < n) {
        // Add current fruit to the basket
        fruitCountMap[fruits[right]]++;

        // Shrink window if we have more than 2 fruit types
        if (fruitCountMap.size() > baskets) {
            fruitCountMap[fruits[left]]--;
            if (fruitCountMap[fruits[left]] <= 0) {
                fruitCountMap.erase(fruits[left]);
            }
            left++;
        }

        // Update result only when window is valid (≤ 2 fruit types)
        if (fruitCountMap.size() <= baskets) {
            result = max(result, right - left + 1);
        }
        right++;
    }

    return result;
}

int main() {
    // Test case 1
    vector<int> fruits1 = {1, 2, 3, 2, 2};
    cout << "Test Case 1:" << endl;
    cout << "Input: [1, 2, 3, 2, 2]" << endl;
    cout << "Output: " << totalFruit(fruits1) << endl;
    cout << endl;

    // Test case 2
    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Test Case 2:" << endl;
    cout << "Input: [0, 1, 2, 2]" << endl;
    cout << "Output: " << totalFruit(fruits2) << endl;

    return 0;
}