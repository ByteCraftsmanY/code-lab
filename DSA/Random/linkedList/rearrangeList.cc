// https://leetcode.com/problems/reorder-list/description/

#include <bits/stdc++.h>

#include "listNode.h"
using namespace std;

void reorderList(ListNode<int>* head) {
    // find middle
    ListNode<int>*slow, *norm = head, *fast = head, *head2 = nullptr;
    while (fast && fast->next) {
        slow = norm;
        norm = norm->next;
        fast = fast->next->next;
    }
    if (fast) {
        head2 = norm->next;
        norm->next = nullptr;
    } else {
        head2 = slow->next;
        slow->next = nullptr;
    }

    // reverse 2nd list
    ListNode<int>*prev = nullptr, *curr = nullptr, *fwd = head2;
    while (fwd) {
        prev = curr;
        curr = fwd;
        fwd = fwd->next;
        curr->next = prev;
    }
    head2 = curr;

    ListNode<int>*l1 = head, *l2 = head2, *t1, *t2;
    while (l1 && l2) {
        t1 = l1->next, t2 = l2->next;
        l1->next = l2;
        l2->next = t1;
        l1 = t1, l2 = t2;
    }
}

int main() {
    ListNode<int>* node = ListNode<int>::generateList({1, 2, 3, 4});
    reorderList(node);
    cout << node;
    return 0;
}