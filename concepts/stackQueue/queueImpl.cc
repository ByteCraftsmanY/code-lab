#include <bits/stdc++.h>
using namespace std;

template <typename t>
class QueueImpl {
   public:
    virtual void push(t) = 0;
    virtual void pop() = 0;
    virtual t top() = 0;
    virtual bool isEmpty() = 0;
};

template <typename t>
class QueueArrImpl : public QueueImpl<t> {
    int start, end, size, currSize;
    vector<t> arr;

   public:
    QueueArrImpl(int size) : size(size), currSize(-1), arr(vector<t>(size)) {
        start = end = -1;
    }

    void push(t data) {
        if (currSize >= size) {
            cout << "queue is full\n";
            return;
        }
        if (start == -1) {
            start++;
        }
        end = (end + 1) % size;
        arr[end] = data;
        currSize++;
    }

    void pop() {
        if (currSize == -1) {
            cout << "queue is empty\n";
            return;
        }
        if (start == end) {
            start = end = -1;
        }
        start = (start + 1) % size;
        currSize--;
    }

    t top() {
        if (currSize == -1) {
            t data;
            cout << "queue is empty\n";
            return data;
        }
        return arr[start];
    }

    bool isEmpty() {
        return (currSize == -1);
    }
};

template <typename t>
class Node {
   public:
    t data;
    Node<t> *next;
    Node() {}
    Node(t data) : data(data), next(nullptr) {}
    Node(t data, Node<t> *next) : data(data), next(next) {}
};

template <typename t>
class QueueLLImpl : public QueueImpl<t> {
    Node<t> *left, *right;

   public:
    QueueLLImpl() : left(nullptr), right(nullptr) {}

    void push(t data) {
        Node<t> *node = new Node<t>(data);
        if (!this->left && !this->right) {
            this->left = this->right = node;
            return;
        }
        this->right->next = node;
        this->right = node;
    }

    void pop() {
        if (!this->left) {
            return;
        }
        if (this->left == this->right) {
            delete this->left;
            this->left = this->right = nullptr;
            return;
        }
        Node<t> *temp = this->left;
        this->left = left->next;
        delete temp;
    }

    t top() {
        if (!left) {
            t data;
            cout << "queue is empty";
            return data;
        }
        return this->left->data;
    }

    bool isEmpty() {
        return this->left == nullptr;
    }
};

int main() {
    QueueImpl<int> *q = new QueueArrImpl<int>(5);
    for (int i = 1; i <= 5; i++)
        q->push(i);

    while (!q->isEmpty()) {
        cout << q->top() << endl;
        q->pop();
    }
    return 0;
}