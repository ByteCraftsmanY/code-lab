// Kth largest element in an array [use priority queue]
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Medium Problems
// Post Link: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/
// LeetCode Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Heap {
   public:
    virtual void heapify(vector<int>&) = 0;
    virtual int extractEle(vector<int>&) = 0;
    virtual ~Heap() = default;
};

class MinHeap : public Heap {
   public:
    int extractEle(vector<int>& elements) {
        if (elements.empty()) {
            throw runtime_error("elements are empty");
        }
        int ele = elements[0];
        elements[0] = elements.back();
        elements.pop_back();
        if (!elements.empty()) {
            this->heapifyDown(elements, 0);
        }
        return ele;
    }

    void heapify(vector<int>& elements) {
        int n = elements.size(), idx = (n - 2) / 2;
        while (idx >= 0) {
            this->heapifyDown(elements, idx);
            idx--;
        }
    }

    void heapifyDown(vector<int>& elements, int idx = 0) {
        int n = elements.size();
        while (idx < n) {
            int smallest = idx, leftChildIdx = (2 * idx) + 1, rightChildIdx = (2 * idx) + 2;
            if (leftChildIdx < n && elements[smallest] > elements[leftChildIdx]) {
                smallest = leftChildIdx;
            }
            if (rightChildIdx < n && elements[smallest] > elements[rightChildIdx]) {
                smallest = rightChildIdx;
            }
            if (idx == smallest) {
                break;
            }
            swap(elements[smallest], elements[idx]);
            idx = smallest;
        }
    }
};

class MaxHeap : public Heap {
   public:
    int extractEle(vector<int>& elements) {
        if (elements.empty()) {
            throw runtime_error("elements are empty");
        }
        int ele = elements[0];
        elements[0] = elements.back();
        elements.pop_back();
        if (!elements.empty()) {
            this->heapifyDown(elements, 0);
        }
        return ele;
    }

    void heapify(vector<int>& elements) {
        int n = elements.size(), idx = (n - 2) / 2;
        while (idx >= 0) {
            this->heapifyDown(elements, idx);
            idx--;
        }
    }

    void heapifyDown(vector<int>& elements, int idx = 0) {
        int n = elements.size();
        while (idx < n) {
            int largest = idx, leftChildIdx = (2 * idx) + 1, rightChildIdx = (2 * idx) + 2;
            if (leftChildIdx < n && elements[largest] < elements[leftChildIdx]) {
                largest = leftChildIdx;
            }
            if (rightChildIdx < n && elements[largest] < elements[rightChildIdx]) {
                largest = rightChildIdx;
            }
            if (idx == largest) {
                break;
            }
            swap(elements[largest], elements[idx]);
            idx = largest;
        }
    }
};

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        Heap* heap;
        int n = nums.size(), res = 0;
        bool useMaxHeap = ((double)n / (double)k) >= 2.0;
        if (useMaxHeap) {
            heap = new MaxHeap();
        } else {
            heap = new MinHeap();
        }
        heap->heapify(nums);
        int c = useMaxHeap ? k : n - k + 1;
        for (int i = 0; i < c; i++) {
            res = heap->extractEle(nums);
        }
        return res;
    }

    int findKthSmallest(vector<int>& nums, int k) {
        Heap* heap;
        int n = nums.size(), res = 0;
        bool useMinHeap = ((double)n / (double)k) >= 2.0;
        if (useMinHeap) {
            heap = new MinHeap();
        } else {
            heap = new MaxHeap();
        }
        heap->heapify(nums);
        int c = useMinHeap ? k : n - k + 1;
        for (int i = 0; i < c; i++) {
            res = heap->extractEle(nums);
        }
        return res;
    }
};

int main() {
    vector<int> elements = {3, 2, 1, 5, 6, 4};
    int k = 2, n = elements.size(), res = 0;
    Solution* s = new Solution();
    // s->findKthLargest(elements, k);
    cout << s->findKthSmallest(elements, k);
    return 0;
}
