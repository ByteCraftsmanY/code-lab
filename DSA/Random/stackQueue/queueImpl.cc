#include <bits/stdc++.h>
using namespace std;

template <typename T>
class QueueImpl {
   public:
    virtual void push(T) = 0;
    virtual void pop() = 0;
    virtual T top() = 0;
    virtual bool isEmpty() = 0;
};

template <typename T>
class QueueArrImpl : public QueueImpl<T> {
    int start, end, size, currSize;
    vector<T> arr;

   public:
    QueueArrImpl(int size) : size(size), currSize(-1), arr(vector<T>(size)) {
        start = end = -1;
    }

    void push(T data) {
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

    T top() {
        if (currSize == -1) {
            T data;
            cout << "queue is empty\n";
            return data;
        }
        return arr[start];
    }

    bool isEmpty() {
        return (currSize == -1);
    }
};

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node() {}
    Node(T data) : data(data), next(nullptr) {}
    Node(T data, Node<T> *next) : data(data), next(next) {}
};

template <typename T>
class QueueLLImpl : public QueueImpl<T> {
    Node<T> *left, *right;

   public:
    QueueLLImpl() : left(nullptr), right(nullptr) {}

    void push(T data) {
        Node<T> *node = new Node<T>(data);
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
        Node<T> *temp = this->left;
        this->left = left->next;
        delete temp;
    }

    T top() {
        if (!left) {
            T data;
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