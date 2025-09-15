#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode *next;
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode *oddEvenList(ListNode *head) {
    ListNode *oddNodeHead = nullptr, *oddNodeTail = nullptr;
    ListNode *evenNodeHead = nullptr, *evenNodeTail = nullptr, *temp = head;
    auto addNode = [](ListNode **head, ListNode **tail, ListNode *node) -> void {
        if (*head == nullptr) {
            *head = *tail = node;
            return;
        }
        (*tail)->next = node;
        *tail = (*tail)->next;
    };
    int c = 1;
    while (temp) {
        if (c & 1) {  // odd
            addNode(&oddNodeHead, &oddNodeTail, temp);
        } else {  // even
            addNode(&evenNodeHead, &evenNodeTail, temp);
        }
        temp = temp->next, c++;
    }
    if (oddNodeTail)
        oddNodeTail->next = evenNodeHead;
    if (evenNodeTail)
        evenNodeTail->next = nullptr;
    return oddNodeHead;
}

int main() {
    ListNode *head = new ListNode(
        1, new ListNode(
               2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
    ListNode *res = oddEvenList(head);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}