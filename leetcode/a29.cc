#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    ListNode *prev = nullptr, *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}