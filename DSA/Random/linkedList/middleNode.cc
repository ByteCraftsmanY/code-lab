// https://leetcode.com/problems/middle-of-the-linked-list/

#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node(int data, Node* next) : data(data), next(next) {}
};

Node* generateList(vector<int>& arr) {
    Node *head, *tail;
    head = tail = nullptr;
    for (auto x : arr) {
        Node* node = new Node(x, nullptr);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

Node* findMiddle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6},
    };
    for (auto& row : mat) {
        Node* head = generateList(row);
        cout << findMiddle(head)->data << endl;
    }
    return 0;
}