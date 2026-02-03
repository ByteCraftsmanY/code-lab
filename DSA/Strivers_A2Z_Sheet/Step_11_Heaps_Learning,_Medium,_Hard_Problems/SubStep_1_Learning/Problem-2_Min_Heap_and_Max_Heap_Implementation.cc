// Min Heap and Max Heap Implementation
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Learning
// Post Link: N/A
// LeetCode Link: N/A

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MinHeap {
   private:
    vector<T> elements;

    // Helper functions for heap navigation (0-indexed)
    int getLeftChild(int i) const {
        return (2 * i) + 1;
    }

    int getRightChild(int i) const {
        return (2 * i) + 2;
    }

    int getParent(int i) const {
        return (i - 1) / 2;
    }

    // Heapify down: maintain min heap property from top to bottom
    void heapifyDown(int idx) {
        int size = elements.size();
        while (idx < size) {
            int leftChildIdx = getLeftChild(idx);
            int rightChildIdx = getRightChild(idx);
            int smallestIdx = idx;

            // Find the smallest among node and its children
            if (leftChildIdx < size && elements[leftChildIdx] < elements[smallestIdx]) {
                smallestIdx = leftChildIdx;
            }
            if (rightChildIdx < size && elements[rightChildIdx] < elements[smallestIdx]) {
                smallestIdx = rightChildIdx;
            }

            // If node is already smallest, heap property is maintained
            if (smallestIdx == idx) {
                break;
            }

            // Swap with smallest child and continue down
            swap(elements[idx], elements[smallestIdx]);
            idx = smallestIdx;
        }
    }

    // Heapify up: maintain min heap property from bottom to top
    void heapifyUp(int idx) {
        while (idx > 0) {
            int parentIdx = getParent(idx);
            if (elements[parentIdx] <= elements[idx]) {
                break;  // Heap property satisfied
            }
            swap(elements[parentIdx], elements[idx]);
            idx = parentIdx;
        }
    }

   public:
    MinHeap() = default;

    // Insert element into heap
    void insert(const T& ele) {
        elements.push_back(ele);
        heapifyUp(elements.size() - 1);
    }

    // Get minimum element without removing it
    T getMin() const {
        if (isEmpty()) {
            throw runtime_error("Heap is empty");
        }
        return elements[0];
    }

    // Extract and remove minimum element
    T extractMin() {
        if (isEmpty()) {
            throw runtime_error("Heap is empty");
        }
        T minVal = elements[0];
        elements[0] = elements.back();
        elements.pop_back();
        if (!isEmpty()) {
            heapifyDown(0);
        }
        return minVal;
    }

    // Check if heap is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Get size of heap
    size_t size() const {
        return elements.size();
    }

    // Build heap from an array: convert array into min heap
    void heapify(const vector<T>& arr) {
        elements = arr;
        int size = elements.size();
        
        // Start from the last non-leaf node and heapify down
        // Last non-leaf node is at index (size - 2) / 2
        for (int idx = (size - 2) / 2; idx >= 0; idx--) {
            heapifyDown(idx);
        }
    }
};

template <typename T>
class MaxHeap {
   private:
    vector<T> elements;

    // Helper functions for heap navigation (0-indexed)
    int getLeftChild(int i) const {
        return (2 * i) + 1;
    }

    int getRightChild(int i) const {
        return (2 * i) + 2;
    }

    int getParent(int i) const {
        return (i - 1) / 2;
    }

    // Heapify down: maintain max heap property from top to bottom
    void heapifyDown(int idx) {
        int size = elements.size();
        while (idx < size) {
            int leftChildIdx = getLeftChild(idx);
            int rightChildIdx = getRightChild(idx);
            int largestIdx = idx;

            // Find the largest among node and its children
            if (leftChildIdx < size && elements[leftChildIdx] > elements[largestIdx]) {
                largestIdx = leftChildIdx;
            }
            if (rightChildIdx < size && elements[rightChildIdx] > elements[largestIdx]) {
                largestIdx = rightChildIdx;
            }

            // If node is already largest, heap property is maintained
            if (largestIdx == idx) {
                break;
            }

            // Swap with largest child and continue down
            swap(elements[idx], elements[largestIdx]);
            idx = largestIdx;
        }
    }

    // Heapify up: maintain max heap property from bottom to top
    void heapifyUp(int idx) {
        while (idx > 0) {
            int parentIdx = getParent(idx);
            if (elements[parentIdx] >= elements[idx]) {
                break;  // Heap property satisfied
            }
            swap(elements[parentIdx], elements[idx]);
            idx = parentIdx;
        }
    }

   public:
    MaxHeap() = default;

    // Insert element into heap
    void insert(const T& ele) {
        elements.push_back(ele);
        heapifyUp(elements.size() - 1);
    }

    // Get maximum element without removing it
    T getMax() const {
        if (isEmpty()) {
            throw runtime_error("Heap is empty");
        }
        return elements[0];
    }

    // Extract and remove maximum element
    T extractMax() {
        if (isEmpty()) {
            throw runtime_error("Heap is empty");
        }
        T maxVal = elements[0];
        elements[0] = elements.back();
        elements.pop_back();
        if (!isEmpty()) {
            heapifyDown(0);
        }
        return maxVal;
    }

    // Check if heap is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Get size of heap
    size_t size() const {
        return elements.size();
    }

    // Build heap from an array: convert array into max heap
    void heapify(const vector<T>& arr) {
        elements = arr;
        int size = elements.size();
        
        // Start from the last non-leaf node and heapify down
        // Last non-leaf node is at index (size - 2) / 2
        for (int idx = (size - 2) / 2; idx >= 0; idx--) {
            heapifyDown(idx);
        }
    }
};

int main() {
    cout << "=== Min Heap Test ===" << endl;
    MinHeap<int> minHeap;
    // minHeap.insert(5);
    // minHeap.insert(1);
    // minHeap.insert(2);
    // minHeap.insert(12);
    // minHeap.insert(3);

    vector<int> elements = {5, 1, 2, 12, 3};
    minHeap.heapify(elements);

    cout << "Extracting elements in ascending order: ";
    while (!minHeap.isEmpty()) {
        cout << minHeap.extractMin() << " ";
    }
    cout << endl
         << endl;

    cout << "=== Max Heap Test ===" << endl;
    MaxHeap<int> maxHeap;
    // maxHeap.insert(5);
    // maxHeap.insert(1);
    // maxHeap.insert(2);
    // maxHeap.insert(12);
    // maxHeap.insert(3);
    maxHeap.heapify(elements);

    cout << "Extracting elements in descending order: ";
    while (!maxHeap.isEmpty()) {
        cout << maxHeap.extractMax() << " ";
    }
    cout << endl;

    return 0;
}
