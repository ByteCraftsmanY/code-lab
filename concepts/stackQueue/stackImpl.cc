#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Abstract base class for Stack implementation
 * @tparam T Data type for stack elements
 */
template <typename T>
class Stack {
public:
    virtual ~Stack() = default;
    virtual void push(const T& value) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual size_t size() const = 0;
};

/**
 * @brief Stack implementation using dynamic array
 * @tparam T Data type for stack elements
 */
template <typename T>
class ArrayStack : public Stack<T> {
private:
    vector<T> data_;
    size_t capacity_;
    
public:
    explicit ArrayStack(size_t initialCapacity = 10) 
        : capacity_(initialCapacity) {
        data_.reserve(initialCapacity);
    }
    
    void push(const T& value) override {
        data_.push_back(value);
    }
    
    void pop() override {
        if (isEmpty()) {
            throw runtime_error("Stack is empty - cannot pop");
        }
        data_.pop_back();
    }
    
    T top() const override {
        if (isEmpty()) {
            throw runtime_error("Stack is empty - cannot get top element");
        }
        return data_.back();
    }
    
    bool isEmpty() const override {
        return data_.empty();
    }
    
    size_t size() const override {
        return data_.size();
    }
    
    size_t capacity() const {
        return data_.capacity();
    }
    
    void clear() {
        data_.clear();
    }
};

/**
 * @brief Node structure for linked list implementation
 * @tparam T Data type for node elements
 */
template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> next;
    
    explicit Node(const T& value) : data(value), next(nullptr) {}
};

/**
 * @brief Stack implementation using linked list
 * @tparam T Data type for stack elements
 */
template <typename T>
class LinkedListStack : public Stack<T> {
private:
    unique_ptr<Node<T>> head_;
    size_t size_;
    
public:
    LinkedListStack() : head_(nullptr), size_(0) {}
    
    void push(const T& value) override {
        auto newNode = make_unique<Node<T>>(value);
        newNode->next = move(head_);
        head_ = move(newNode);
        ++size_;
    }
    
    void pop() override {
        if (isEmpty()) {
            throw runtime_error("Stack is empty - cannot pop");
        }
        head_ = move(head_->next);
        --size_;
    }
    
    T top() const override {
        if (isEmpty()) {
            throw runtime_error("Stack is empty - cannot get top element");
        }
        return head_->data;
    }
    
    bool isEmpty() const override {
        return head_ == nullptr;
    }
    
    size_t size() const override {
        return size_;
    }
    
    void clear() {
        head_.reset();
        size_ = 0;
    }
};

/**
 * @brief Utility function to print stack contents
 * @tparam T Data type for stack elements
 * @param stack Reference to stack object
 * @param name Name of the stack for output
 */
template <typename T>
void printStack(const Stack<T>& stack, const string& name = "Stack") {
    cout << "\n=== " << name << " Contents ===" << endl;
    cout << "Size: " << stack.size() << endl;
    
    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    // Create a temporary stack to reverse the order for display
    auto tempStack = make_unique<ArrayStack<T>>();
    auto originalStack = make_unique<ArrayStack<T>>();
    
    // Copy elements to temporary stack (this will reverse the order)
    while (!stack.isEmpty()) {
        T value = stack.top();
        tempStack->push(value);
        originalStack->push(value);
        const_cast<Stack<T>&>(stack).pop();
    }
    
    // Restore original stack and print in correct order
    cout << "Elements (top to bottom): ";
    while (!originalStack->isEmpty()) {
        T value = originalStack->top();
        cout << value;
        originalStack->pop();
        const_cast<Stack<T>&>(stack).push(value);
        
        if (!originalStack->isEmpty()) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    cout << "=== Stack Implementation Demo ===" << endl;
    
    try {
        // Test Array-based Stack
        cout << "\n1. Testing Array-based Stack:" << endl;
        auto arrayStack = make_unique<ArrayStack<int>>(5);
        
        // Push elements
        for (int i = 1; i <= 5; ++i) {
            arrayStack->push(i);
            cout << "Pushed: " << i << endl;
        }
        
        printStack(*arrayStack, "Array Stack");
        
        // Pop elements
        cout << "\nPopping elements:" << endl;
        while (!arrayStack->isEmpty()) {
            cout << "Popped: " << arrayStack->top() << endl;
            arrayStack->pop();
        }
        
        // Test Linked List-based Stack
        cout << "\n2. Testing Linked List-based Stack:" << endl;
        auto linkedListStack = make_unique<LinkedListStack<int>>();
        
        // Push elements
        for (int i = 10; i <= 15; ++i) {
            linkedListStack->push(i);
            cout << "Pushed: " << i << endl;
        }
        
        printStack(*linkedListStack, "Linked List Stack");
        
        // Pop elements
        cout << "\nPopping elements:" << endl;
        while (!linkedListStack->isEmpty()) {
            cout << "Popped: " << linkedListStack->top() << endl;
            linkedListStack->pop();
        }
        
        // Test error handling
        cout << "\n3. Testing Error Handling:" << endl;
        try {
            arrayStack->pop();
        } catch (const exception& e) {
            cout << "Caught exception: " << e.what() << endl;
        }
        
        try {
            arrayStack->top();
        } catch (const exception& e) {
            cout << "Caught exception: " << e.what() << endl;
        }
        
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
        return 1;
    }
    
    cout << "\n=== Demo completed successfully ===" << endl;
    return 0;
}