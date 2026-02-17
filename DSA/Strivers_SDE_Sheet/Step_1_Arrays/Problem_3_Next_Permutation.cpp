// Next Permutation
// Step: Arrays
// Difficulty: Medium
// Post Link: https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
// LeetCode Link: https://leetcode.com/problems/next-permutation/
// GFG Link: https://bit.ly/3dug78u

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    /*
        try to match longest suffix
            aaa
            aab
            ar

            # if we didnt find the breakpoint then arr is in reverse order then reverse it and return

    */

    /*
        2 1 5 4 3 0 0
        # find breakpoint
        # if we draw graph from end to start the breakpoint is at 1 index
    */
    int breakPointIndex = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i + 1] > arr[i]) {
            breakPointIndex = i;
            break;
        }
    }

    // if no breakpoint means it is sorted in reverse order | reverse and return
    if (breakPointIndex == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    /*
        find smallest element greater then breakingPointIndexElement
        Example: 2 1 5 4 3 0 0
        3 is the element which is the first greater element from the right
        swap it with breakpoint index
        2 3 5 4 1 0
    */
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > arr[breakPointIndex]) {
            swap(arr[i], arr[breakPointIndex]);
            break;
        }
    }

    /*
        reverse half arr after breaking point to make it next smaller
        2 3 0 0 1 4 5
    */
    reverse(arr.begin() + breakPointIndex + 1, arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3};
    arr = {3, 2, 1};
    nextPermutation(arr);
    return 0;
}
