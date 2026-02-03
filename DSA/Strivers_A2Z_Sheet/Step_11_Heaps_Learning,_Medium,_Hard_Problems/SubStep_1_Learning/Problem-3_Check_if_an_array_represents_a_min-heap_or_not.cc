// Check if an array represents a min-heap or not
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Learning
// Post Link: https://takeuforward.org/data-structure/check-if-an-array-represents-a-min-heap
// LeetCode Link: N/A
// GFG Link: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(vector<int>& elements) {
    int leftChildIdx, rightChildIdx, currentIdx = 0, size = elements.size();
    while (currentIdx < size) {
        if (currentIdx >= ((size / 2) - 1)) break;
        leftChildIdx = (2 * currentIdx) + 1;
        rightChildIdx = (2 * currentIdx) + 2;
        bool a = leftChildIdx >= size || elements[currentIdx] <= elements[leftChildIdx];
        bool b = rightChildIdx >= size || elements[currentIdx] <= elements[rightChildIdx];
        if (!(a && b)) {
            return false;
        }
        currentIdx++;
    }
    return true;
}

bool isMaxHeap(vector<int>& elements) {
    int leftChildIdx, rightChildIdx, currentIdx = 0, size = elements.size();
    while (currentIdx < size) {
        leftChildIdx = (2 * currentIdx) + 1;
        rightChildIdx = (2 * currentIdx) + 2;
        bool a = leftChildIdx >= size || elements[currentIdx] >= elements[leftChildIdx];
        bool b = rightChildIdx >= size || elements[currentIdx] >= elements[rightChildIdx];
        if (!(a && b)) {
            return false;
        }
        currentIdx++;
    }
    return true;
}

int main() {
    vector<vector<int>> tests = {
        {10, 20, 30, 21, 23},
        {10, 20, 30, 25, 15},
        {90, 15, 10, 7, 12, 2},
        {9, 15, 10, 7, 12, 11}};
    for (auto test : tests) {
        cout << "isMinHeap: " << isMinHeap(test) << "\t";
        cout << "isMaxHeap: " << isMaxHeap(test) << endl;
    }
    return 0;
}
