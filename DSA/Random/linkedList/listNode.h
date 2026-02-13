#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>

template <typename T>
class ListNode {
   public:
    T val;
    ListNode* next;

    ListNode(T val) : val(val), next(nullptr) {};
    ListNode(T val, ListNode* next) : val(val), next(next) {}

    static ListNode* generateList(std::vector<T> arr) {
        ListNode *head, *tail;
        head = tail = nullptr;
        for (auto x : arr) {
            ListNode<T>* node = new ListNode<T>(x, nullptr);
            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }

    friend std::ostream& operator<<(std::ostream& os, ListNode<T>* node) {
        ListNode<T>* temp = node;
        while (temp) {
            os << temp->val;
            if (temp->next) os << "->";
            temp = temp->next;
        }
        os << "\n";
        return os;
    }
};

#endif