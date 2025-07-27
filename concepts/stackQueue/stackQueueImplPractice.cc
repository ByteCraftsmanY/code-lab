#include <bits/stdc++.h>
using namespace std;

/**
 * Custom Stack Implementation using Array
 * Supports basic stack operations: push, pop, top, getSize
 */
class Stack {
private:
    int* arr;
    int capacity;
    int size;

public:
    /**
     * Constructor to initialize stack with given capacity
     * @param cap Maximum capacity of the stack
     */
    Stack(int cap) {
        arr = new int[cap];  // Fixed: was using 'size' instead of 'cap'
        this->capacity = cap;
        this->size = -1;     // Initialize size to -1 (empty stack)
    }

    /**
     * Destructor to free allocated memory
     */
    ~Stack() {
        delete[] arr;
    }

    /**
     * Push an element onto the stack
     * @param ele Element to push
     * @throws runtime_error if stack is full
     */
    void push(int ele) {
        if (this->size + 1 == this->capacity) {
            throw runtime_error("Stack is full");
        }
        this->arr[++this->size] = ele;
    }

    /**
     * Remove and return the top element from the stack
     * @throws runtime_error if stack is empty
     */
    void pop() {
        if (this->getSize() == 0) {
            throw runtime_error("Stack is empty");
        }
        this->size--;
    }

    /**
     * Get the top element without removing it
     * @return Top element of the stack
     * @throws runtime_error if stack is empty
     */
    int top() {
        if (this->getSize() == 0) {
            throw runtime_error("Stack is empty");
        }
        return this->arr[this->size];
    }

    /**
     * Get the current size of the stack
     * @return Number of elements in the stack
     */
    int getSize() {
        return this->size + 1;
    }

    /**
     * Check if stack is empty
     * @return true if stack is empty, false otherwise
     */
    bool isEmpty() {
        return this->size == -1;
    }

    /**
     * Check if stack is full
     * @return true if stack is full, false otherwise
     */
    bool isFull() {
        return this->size + 1 == this->capacity;
    }
};

/**
 * Custom Queue Implementation using Circular Array
 * Supports basic queue operations: push, pop, top, getSize
 */
class Queue {
private:
    int* arr;
    int capacity;
    int size;
    int frontIndex;
    int rearIndex;

public:
    /**
     * Constructor to initialize queue with given capacity
     * @param cap Maximum capacity of the queue
     */
    Queue(int cap) {
        this->arr = new int[cap];
        this->capacity = cap;
        this->size = 0;
        this->frontIndex = 0;
        this->rearIndex = -1;
    }

    /**
     * Destructor to free allocated memory
     */
    ~Queue() {
        delete[] arr;
    }

    /**
     * Add an element to the rear of the queue
     * @param val Element to add
     * @throws runtime_error if queue is full
     */
    void push(int val) {
        if (this->size == this->capacity) {
            throw runtime_error("Queue is full");
        }
        this->rearIndex = (this->rearIndex + 1) % this->capacity;
        this->arr[this->rearIndex] = val;
        this->size++;
    }

    /**
     * Remove and return the front element from the queue
     * @throws runtime_error if queue is empty
     */
    void pop() {
        if (this->getSize() == 0) {
            throw runtime_error("Queue is empty");
        }
        this->arr[this->frontIndex] = -1;  // Mark as removed
        this->frontIndex = (this->frontIndex + 1) % this->capacity;
        this->size--;
        
        // Reset indices if queue becomes empty
        if (this->size == 0) {
            this->rearIndex = -1;
            this->frontIndex = 0;
        }
    }

    /**
     * Get the front element without removing it
     * @return Front element of the queue
     * @throws runtime_error if queue is empty
     */
    int top() {
        if (this->getSize() == 0) {
            throw runtime_error("Queue is empty");
        }
        return this->arr[this->frontIndex];
    }

    /**
     * Get the current size of the queue
     * @return Number of elements in the queue
     */
    int getSize() {
        return this->size;
    }

    /**
     * Check if queue is empty
     * @return true if queue is empty, false otherwise
     */
    bool isEmpty() {
        return this->size == 0;
    }

    /**
     * Check if queue is full
     * @return true if queue is full, false otherwise
     */
    bool isFull() {
        return this->size == this->capacity;
    }

    /**
     * Print the queue contents for debugging
     */
    void print() {
        cout << "Queue contents: ";
        for (int i = 0; i < this->capacity; i++) {
            cout << this->arr[i] << " ";
        }
        cout << " | Size: " << this->size 
             << " | Capacity: " << this->capacity 
             << " | Front: " << this->frontIndex 
             << " | Rear: " << this->rearIndex << endl;
    }
};

/**
 * Stack Implementation using Queue
 * Uses a single queue to implement stack behavior
 */
class StackByQueue {
private:
    queue<int> q;

public:
    /**
     * Push an element onto the stack
     * @param val Element to push
     */
    void push(int val) {
        q.push(val);
        
        // Rotate queue to make the new element at front
        while (q.front() != val) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    /**
     * Remove the top element from the stack
     */
    void pop() {
        if (!q.empty()) {
            q.pop();
        }
    }

    /**
     * Get the top element without removing it
     * @return Top element of the stack
     */
    int top() {
        if (q.empty()) {
            throw runtime_error("Stack is empty");
        }
        return q.front();
    }

    /**
     * Check if stack is empty
     * @return true if stack is empty, false otherwise
     */
    bool isEmpty() {
        return q.empty();
    }
};

/**
 * Queue Implementation using Two Stacks (Method 1)
 * Uses two stacks with expensive push operation
 */
class QueueByStack {
private:
    stack<int> s1, s2;

public:
    /**
     * Add an element to the rear of the queue
     * @param ele Element to add
     */
    void push(int ele) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        // Push new element to s1
        s1.push(ele);
        
        // Move all elements back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    /**
     * Remove the front element from the queue
     */
    void pop() {
        if (!s1.empty()) {
            s1.pop();
        }
    }

    /**
     * Get the front element without removing it
     * @return Front element of the queue
     */
    int top() {
        if (s1.empty()) {
            throw runtime_error("Queue is empty");
        }
        return s1.top();
    }

    /**
     * Check if queue is empty
     * @return true if queue is empty, false otherwise
     */
    bool isEmpty() {
        return s1.empty();
    }
};

/**
 * Queue Implementation using Two Stacks (Method 2 - Amortized)
 * Uses two stacks with expensive pop/peek operations
 * More efficient for multiple operations
 */
class QueueByStack2 {
private:
    stack<int> s1, s2;  // s1 for push, s2 for pop/peek

public:
    /**
     * Add an element to the rear of the queue
     * @param n Element to add
     */
    void push(int n) {
        s1.push(n);
    }

    /**
     * Remove the front element from the queue
     */
    void pop() {
        if (s2.empty()) {
            // Transfer all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        if (!s2.empty()) {
            s2.pop();
        }
    }

    /**
     * Get the front element without removing it
     * @return Front element of the queue
     */
    int top() {
        if (s2.empty()) {
            // Transfer all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        if (s2.empty()) {
            throw runtime_error("Queue is empty");
        }
        
        return s2.top();
    }

    /**
     * Check if queue is empty
     * @return true if queue is empty, false otherwise
     */
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Main function to demonstrate all implementations
 */
int main() {
    cout << "=== Custom Stack Implementation ===" << endl;
    Stack* s = new Stack(3);
    cout << "Initial size: " << s->getSize() << endl;
    
    s->push(10);
    cout << "After pushing 10, size: " << s->getSize() << endl;
    
    s->push(20);
    cout << "After pushing 20, size: " << s->getSize() << endl;
    
    s->push(30);
    cout << "After pushing 30, size: " << s->getSize() << endl;
    
    cout << "Top element: " << s->top() << endl;
    s->pop();
    cout << "After pop, top element: " << s->top() << endl;
    
    s->pop();
    s->pop();
    cout << "After popping all elements, size: " << s->getSize() << endl;
    
    s->push(40);
    cout << "After pushing 40, top element: " << s->top() << endl;
    delete s;

    cout << "\n=== Custom Queue Implementation ===" << endl;
    Queue* q = new Queue(3);
    cout << "Initial size: " << q->getSize() << endl;
    
    q->push(10);
    q->push(20);
    q->push(30);
    q->print();
    
    cout << "Front element: " << q->top() << endl;
    q->pop();
    cout << "After pop, front element: " << q->top() << endl;
    
    q->pop();
    cout << "After another pop, front element: " << q->top() << endl;
    
    q->push(40);
    q->pop();
    cout << "After push(40) and pop, front element: " << q->top() << endl;
    delete q;

    cout << "\n=== Stack Implementation using Queue ===" << endl;
    StackByQueue* sq = new StackByQueue();
    sq->push(10);
    sq->push(20);
    sq->push(30);

    cout << "Top element: " << sq->top() << endl;
    sq->pop();
    cout << "After pop, top element: " << sq->top() << endl;
    sq->pop();
    cout << "After another pop, top element: " << sq->top() << endl;
    delete sq;

    cout << "\n=== Queue Implementation using Two Stacks (Amortized) ===" << endl;
    QueueByStack2* st = new QueueByStack2();
    st->push(10);
    st->push(20);
    st->push(30);
    
    cout << "Front element: " << st->top() << endl;
    st->pop();
    cout << "After pop, front element: " << st->top() << endl;
    st->pop();
    cout << "After another pop, front element: " << st->top() << endl;
    delete st;

    return 0;
}