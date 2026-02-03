#include <iostream>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/lfu-cache/description/

/**
 * Node class representing a cache entry
 * Contains key, value, frequency count, and doubly-linked list pointers
 */
class Node {
   public:
    int key, value, count;
    Node *prev, *next;

    Node(int key, int val, int count = 0)
        : key(key), value(val), count(count), prev(nullptr), next(nullptr) {}
};

/**
 * LFU (Least Frequently Used) Cache Implementation
 *
 * Features:
 * - O(1) time complexity for get and put operations
 * - Uses frequency-based eviction policy
 * - Maintains doubly-linked lists for each frequency level
 * - Automatically removes least frequently used items when cache is full
 */
class LFUCache {
   private:
    int capacity;                         // Maximum cache capacity
    unordered_map<int, Node *> cacheMap;  // Maps key to Node
    unordered_map<int, pair<Node *, Node *>>
        freqMap;  // Maps frequency to (head, tail) pair
    int minFreq;  // Minimum frequency in cache

    /**
     * Adds a node to the frequency list
     * Creates new frequency list if it doesn't exist
     */
    void addNode(Node *node) {
        Node *head, *tail, *next;

        // Create new frequency list if it doesn't exist
        if (freqMap.find(node->count) == freqMap.end()) {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            freqMap[node->count] = make_pair(head, tail);
        } else {
            auto headTailPair = freqMap[node->count];
            head = headTailPair.first;
            tail = headTailPair.second;
        }

        next = head->next;

        // Insert node after head
        head->next = node;
        node->prev = head;
        node->next = next;
        next->prev = node;
    }

    /**
     * Removes a node from its frequency list
     */
    void removeNode(Node *node) {
        Node *nextNode = node->next;
        Node *prevNode = node->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        node->next = node->prev = nullptr;
    }

    /**
     * Updates the frequency of a node
     * Removes from old frequency list and adds to new frequency list
     */
    void updateFreq(Node *node) {
        int oldFreq = node->count;
        removeNode(node);

        // Remove frequency list if it becomes empty
        int freq = node->count;
        auto [head, tail] = freqMap[freq];
        if (head->next == tail && tail->prev == head) {
            freqMap.erase(freq);
            if (oldFreq == this->minFreq) {
                this->minFreq++;
            }
        }

        // Update frequency and add to new frequency list
        node->count++;
        addNode(node);
    }

   public:
    /**
     * Constructor
     * @param capacity Maximum number of items in cache
     */
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    /**
     * Retrieves value for given key
     * @param key The key to look up
     * @return Value associated with key, or -1 if not found
     */
    int get(int key) {
        auto itr = cacheMap.find(key);
        if (itr == cacheMap.end()) {
            return -1;
        }

        Node *node = itr->second;
        updateFreq(node);
        return node->value;
    }

    /**
     * Inserts or updates key-value pair in cache
     * @param key The key to insert/update
     * @param value The value to associate with key
     */
    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        // If key exists, update value and frequency
        if (cacheMap.find(key) != cacheMap.end()) {
            Node *node = cacheMap[key];
            updateFreq(node);
            node->value = value;
            return;
        }

        // If cache is full, remove least frequently used item
        if (cacheMap.size() >= capacity) {
            auto [head, tail] = freqMap[minFreq];
            Node *node = tail->prev;
            removeNode(node);
            cacheMap.erase(node->key);
            delete node;
        }

        // Add new key with frequency 1
        minFreq = 1;
        Node *node = new Node(key, value, minFreq);
        cacheMap[key] = node;
        addNode(node);
    }
};

/**
 * Main function with comprehensive test cases
 */
int main() {
    cout << "=== LFU Cache Implementation Test Suite ===" << endl;

    // Test Case 1: Basic operations
    cout << "\n📋 Test Case 1: Basic operations" << endl;
    cout << "----------------------------------------" << endl;
    LFUCache cache1(2);

    cout << "Put (1, 1)" << endl;
    cache1.put(1, 1);

    cout << "Put (2, 2)" << endl;
    cache1.put(2, 2);

    cout << "Get(1): " << cache1.get(1) << " (expected: 1)" << endl;
    cout << "Get(2): " << cache1.get(2) << " (expected: 2)" << endl;

    // Test Case 2: Cache eviction
    cout << "\n📋 Test Case 2: Cache eviction" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Put (3, 3) - should evict key 1" << endl;
    try {
        cache1.put(3, 3);
        cout << "✅ Successfully put (3, 3)" << endl;
    } catch (...) {
        cout << "❌ Exception occurred during put" << endl;
    }

    cout << "Get(1): " << cache1.get(1) << " (expected: -1, not found)" << endl;
    cout << "Get(2): " << cache1.get(2) << " (expected: 2)" << endl;
    cout << "Get(3): " << cache1.get(3) << " (expected: 3)" << endl;

    // Test Case 3: LFU behavior
    cout << "\n📋 Test Case 3: LFU behavior" << endl;
    cout << "----------------------------------------" << endl;
    LFUCache cache2(3);

    cache2.put(1, 1);
    cache2.put(2, 2);
    cache2.put(3, 3);

    cout << "Accessing key 1 multiple times..." << endl;
    cache2.get(1);  // freq = 2
    cache2.get(1);  // freq = 3

    cout << "Accessing key 2 once..." << endl;
    cache2.get(2);  // freq = 2

    cout << "Put (4, 4) - should evict key 3 (least frequently used)" << endl;
    cache2.put(4, 4);

    cout << "Get(1): " << cache2.get(1) << " (expected: 1)" << endl;
    cout << "Get(2): " << cache2.get(2) << " (expected: 2)" << endl;
    cout << "Get(3): " << cache2.get(3) << " (expected: -1, evicted)" << endl;
    cout << "Get(4): " << cache2.get(4) << " (expected: 4)" << endl;

    // Test Case 4: Update existing key
    cout << "\n📋 Test Case 4: Update existing key" << endl;
    cout << "----------------------------------------" << endl;
    LFUCache cache3(2);

    cache3.put(1, 10);
    cout << "Get(1): " << cache3.get(1) << " (expected: 10)" << endl;

    cache3.put(1, 20);
    cout << "After updating key 1 to value 20" << endl;
    cout << "Get(1): " << cache3.get(1) << " (expected: 20)" << endl;

    // Test Case 5: Edge cases
    cout << "\n📋 Test Case 5: Edge cases" << endl;
    cout << "----------------------------------------" << endl;
    LFUCache cache4(1);

    cache4.put(1, 1);
    cout << "Get(1): " << cache4.get(1) << " (expected: 1)" << endl;

    cache4.put(2, 2);
    cout << "Put (2, 2) - should evict key 1" << endl;
    cout << "Get(1): " << cache4.get(1) << " (expected: -1)" << endl;
    cout << "Get(2): " << cache4.get(2) << " (expected: 2)" << endl;

    cout << "\n🎉 All test cases completed successfully!" << endl;
    return 0;
}
