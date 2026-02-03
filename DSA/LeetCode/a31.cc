#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = nullptr, *next = head;
    while (next) {
        prev = curr;
        curr = next;
        next = next->next;
        curr->next = prev;
    }
    return curr;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    ListNode* res = reverseList(head);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}