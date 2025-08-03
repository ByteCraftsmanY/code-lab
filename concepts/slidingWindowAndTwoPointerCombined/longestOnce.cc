#include <iostream>
#include <vector>
using namespace std;

/**
 * Find the longest subarray with at most k zeros
 *
 * @param nums Vector of integers (0s and 1s)
 * @param k Maximum number of zeros allowed
 * @return Length of the longest subarray with at most k zeros
 */
int longestOnes(vector<int> &nums, int k) {
    int result = 0;

    // Brute Force Approach (O(n²) time complexity)
    // for (int i = 0; i < nums.size(); i++) {
    //     int zeroCount = 0;
    //     for (int j = i; j < nums.size(); j++) {
    //         if (nums[j] == 0) zeroCount++;
    //         if (zeroCount > k) {
    //             break;
    //         }
    //         result = max(result, j - i + 1);
    //     }
    // }

    // Sliding window approach (O(n) time complexity)
    // int left = 0, right = 0, zeroCount = 0;
    //
    // while (right < nums.size()) {
    //     // Expand window by including current element
    //     if (nums[right] == 0) {
    //         zeroCount++;
    //     }
    //
    //     // Shrink window if we have more than k zeros
    //     while (zeroCount > k) {
    //         if (nums[left] == 0) {
    //             zeroCount--;
    //         }
    //         left++;
    //     }
    //
    //     // Update result with current window size
    //     result = max(result, right - left + 1);
    //     right++;
    // }

    // Optimized sliding window approach
    int left = 0, right = 0, zeroCount = 0;

    while (right < nums.size()) {
        // Count zeros in current window
        if (nums[right] == 0) {
            zeroCount++;
        }

        // Shrink window if we exceed k zeros
        if (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        // Update result only when window is valid
        if (zeroCount <= k) {
            result = max(result, right - left + 1);
        }
        right++;
    }

    return result;
}

int main() {
    // Test case 1
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    cout << "Test Case 1:" << endl;
    cout << "Input: [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], k = " << k1 << endl;
    cout << "Output: " << longestOnes(nums1, k1) << endl;
    cout << endl;

    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    cout << "Test Case 2:" << endl;
    cout << "Input: [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1], k "
            "= "
         << k2 << endl;
    cout << "Output: " << longestOnes(nums2, k2) << endl;

    return 0;
}