/**
 *
 * functional requirements:
 * 1. we should be assign capacity
 * 2. once we hit the capacity oldest/ least recently used key should be deleted
 *
 * non functional requirement:
 * 1. should be able to add/update/delete cache key
 * 2. during any ops it should be prioritize
 *
 */

#include <bits/stdc++.h>

#include <chrono>

using namespace std;

long long getCurrentTime(bool miliseconds = true) {
    if (miliseconds)
        return chrono::duration_cast<chrono::milliseconds>(
                   chrono::system_clock::now().time_since_epoch())
            .count();
    // in nanoseconds
    return chrono::system_clock().now().time_since_epoch().count();
}

template <typename KeyType, typename ValueType>
class Node {
   public:
    KeyType key;
    ValueType value;
    long long ttl;
    Node<KeyType, ValueType>*next, *prev;

    Node() {}

    Node(KeyType key, ValueType value) {
        this->key = key;
        this->value = value;
        this->ttl = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    void setTTL(long long ttl) {
        if (ttl == 0) return;
        this->ttl = getCurrentTime() + ttl;
    }

    bool isExpired() {
        if (this->ttl == 0) return false;
        bool result = this->ttl < getCurrentTime();
        if (result) {
            cout << "removing key: " << this->key << endl;
        }
        return result;
    }

    void print(std::ostream& os) const {
        os << "Node{ key=" << key << ", value=" << value << "}";
    }

    friend std::ostream& operator<<(std::ostream& os, Node<KeyType, ValueType>* node) {
        node->print(os);
        return os;
    }
};

template <typename KeyType, typename ValueType>
class LRU {
    int capacity;
    Node<KeyType, ValueType>*head, *tail;
    map<KeyType, Node<KeyType, ValueType>*> mp;

    void evictExpiredKeys() {
        Node<KeyType, ValueType>* node = this->head->next;
        while (node) {
            if (node->isExpired()) {
                this->removeKey(node->key);
            }
            node = node->next;
        }
    }

   public:
    LRU(int capacity) {
        this->head = new Node<KeyType, ValueType>();
        this->tail = new Node<KeyType, ValueType>();
        this->head->next = (this->tail);
        this->tail->prev = (this->head);
        this->capacity = capacity;
    }

    void removeLRUKey() {
        Node<KeyType, ValueType>* node = this->tail->prev;
        if (node == this->head) return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        mp.erase(node->key);
        delete node;
    }

    void detachNode(Node<KeyType, ValueType>* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = node->prev = nullptr;
    }

    void attachNode(Node<KeyType, ValueType>* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void addKey(KeyType key, ValueType value, long long ttl = 0) {
        evictExpiredKeys();
        Node<KeyType, ValueType>* node;
        if (this->mp.find(key) != this->mp.end()) {
            node = mp[key];
            node->value = value;
            if (ttl == 0 && node->isExpired()) {
                removeKey(key);
                return;
            }
            if (ttl > 0) {
                node->setTTL(ttl);
            }
            detachNode(node);
            attachNode(node);
            return;
        }
        node = new Node<KeyType, ValueType>(key, value);
        if (this->mp.size() == this->capacity) {
            this->removeLRUKey();
        }
        node->setTTL(ttl);
        this->mp[key] = node;
        attachNode(node);
    }

    void removeKey(KeyType key) {
        if (this->mp.find(key) == this->mp.end()) {
            return;
        }
        Node<KeyType, ValueType>* node = mp[key];
        detachNode(node);
        mp.erase(key);
        delete node;
    }

    Node<KeyType, ValueType>* getNodeByKey(KeyType key) {
        if (this->mp.find(key) == this->mp.end()) {
            return nullptr;
        }
        Node<KeyType, ValueType>* node = mp[key];
        detachNode(node);
        if (node->isExpired()) {
            this->removeKey(node->key);
            return nullptr;
        }
        attachNode(node);
        return node;
    }

    void debugCache() {
        cout << "debugCache: ";
        Node<KeyType, ValueType>* node = this->head;
        while (node) {
            if (node->key)
                cout << node << "\t";
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
    LRU<int, int>* lruCache = new LRU<int, int>(3);
    lruCache->addKey(10, 10);
    lruCache->debugCache();
    lruCache->addKey(20, 20);
    lruCache->debugCache();
    lruCache->addKey(30, 30, 1);
    lruCache->debugCache();
    lruCache->addKey(20, 25);
    lruCache->debugCache();
    lruCache->addKey(12, 24);
    lruCache->debugCache();
    lruCache->getNodeByKey(30);
    lruCache->debugCache();
    lruCache->removeKey(12);
    lruCache->debugCache();

    // long long time = system_clock::now().time_since_epoch().count();
    // cout << time << endl;

    // auto compare = [](Node<int, int>* a, Node<int, int>* b) -> bool {
    //     return a->updatedAt < b->updatedAt;
    // };

    // priority_queue < Node<int, int>*, vector<Node<int, int>*, decltype(compare)> pq;
    // cout << getCurrentTime() << endl;
    // cout << getCurrentTime(0) << endl;

    int m, n;
    cin >> n >> m;
    cout << n << "\n" << m;
    return 0;
}