#include <iostream>
#include <unordered_map>
using namespace std;

template <typename KeyType, typename ValueType>
class Node {
   public:
    KeyType key;
    ValueType value;
    Node *prev;
    Node *next;

    Node(KeyType k, ValueType v)
        : key(k), value(v), prev(nullptr), next(nullptr) {}
};

template <typename KeyType, typename ValueType>
class LRUCache {
   private:
    int capacity;
    int size;
    Node<KeyType, ValueType> *head;
    Node<KeyType, ValueType> *tail;
    unordered_map<KeyType, Node<KeyType, ValueType> *> cache;

    // Remove node from its current position
    void removeNode(Node<KeyType, ValueType> *node) {
        if (!node)
            return;

        // Update head if this is the head node
        if (node == head) {
            head = node->next;
        }

        // Update tail if this is the tail node
        if (node == tail) {
            tail = node->prev;
        }

        // Update the links
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }

        // Clear node's links
        node->prev = nullptr;
        node->next = nullptr;
    }

    // Add node to the front (most recently used)
    void addToFront(Node<KeyType, ValueType> *node) {
        if (!node)
            return;

        node->next = head;
        if (head) {
            head->prev = node;
        }
        head = node;

        // If this is the first node, set tail
        if (!tail) {
            tail = head;
        }
    }

    // Move node to front (make it most recently used)
    void moveToFront(Node<KeyType, ValueType> *node) {
        if (!node)
            return;

        removeNode(node);
        addToFront(node);
    }

    // Remove least recently used node (from end)
    void removeLRU() {
        if (!tail)
            return;

        Node<KeyType, ValueType> *nodeToRemove = tail;

        if (head == tail) {
            // Only one node in the list
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        cache.erase(nodeToRemove->key);
        delete nodeToRemove;
        size--;
    }

   public:
    LRUCache(int cap) : capacity(cap), size(0), head(nullptr), tail(nullptr) {}

    ~LRUCache() {
        Node<KeyType, ValueType> *current = head;
        while (current) {
            Node<KeyType, ValueType> *next = current->next;
            delete current;
            current = next;
        }
    }

    // Get value for key, return -1 if not found
    ValueType get(KeyType key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }

        Node<KeyType, ValueType> *node = it->second;
        moveToFront(node);
        return node->value;
    }

    // Put key-value pair into cache
    void put(KeyType key, ValueType value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            // Key exists, update value and move to front
            Node<KeyType, ValueType> *node = it->second;
            node->value = value;
            moveToFront(node);
        } else {
            // Key doesn't exist
            if (size >= capacity) {
                removeLRU();
            }

            Node<KeyType, ValueType> *newNode =
                new Node<KeyType, ValueType>(key, value);
            cache[key] = newNode;
            addToFront(newNode);
            size++;
        }
    }

    // Print current cache state (for debugging)
    void printCache() {
        cout << "Cache state (size: " << size << "/" << capacity << "): ";
        Node<KeyType, ValueType> *current = head;
        while (current) {
            cout << "(" << current->key << ":" << current->value << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "=== LRU Cache Implementation Test ===" << endl;

    // Test Case 1: Basic functionality
    cout << "\n--- Test Case 1: Basic LRU Cache (capacity=2) ---" << endl;
    LRUCache<int, int> cache1(2);

    cache1.put(1, 1);
    cache1.printCache();

    cache1.put(2, 2);
    cache1.printCache();

    cout << "get(1): " << cache1.get(1) << endl;  // Expected: 1
    cache1.printCache();

    cache1.put(3, 3);
    cache1.printCache();

    cout << "get(2): " << cache1.get(2) << endl;  // Expected: -1 (evicted)
    cache1.printCache();

    cache1.put(4, 4);
    cache1.printCache();

    cout << "get(1): " << cache1.get(1) << endl;  // Expected: -1 (evicted)
    cout << "get(3): " << cache1.get(3) << endl;  // Expected: 3
    cout << "get(4): " << cache1.get(4) << endl;  // Expected: 4

    // Test Case 2: Single capacity cache
    cout << "\n--- Test Case 2: Single Capacity Cache ---" << endl;
    LRUCache<int, int> cache2(1);

    cache2.put(2, 1);
    cache2.printCache();

    cout << "get(2): " << cache2.get(2) << endl;  // Expected: 1

    cache2.put(3, 2);
    cache2.printCache();

    cout << "get(2): " << cache2.get(2) << endl;  // Expected: -1 (evicted)
    cout << "get(3): " << cache2.get(3) << endl;  // Expected: 2

    // Test Case 3: Update existing key
    cout << "\n--- Test Case 3: Update Existing Key ---" << endl;
    LRUCache<int, int> cache3(2);

    cache3.put(1, 10);
    cache3.put(2, 20);
    cache3.printCache();

    cache3.put(1, 100);  // Update existing key
    cache3.printCache();

    cout << "get(1): " << cache3.get(1) << endl;  // Expected: 100
    cout << "get(2): " << cache3.get(2) << endl;  // Expected: 20

    return 0;
}