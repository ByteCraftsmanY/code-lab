#include <bits/stdc++.h>

#include "listNode.h"
using namespace std;

ListNode<int>* sum(ListNode<int>* a, ListNode<int>* b) {
    int carry = 0;
    ListNode<int>*head, *tail;
    head = new ListNode<int>(-1);
    tail = head;
    while (a && b) {
        int n = a->val + b->val + carry;
        int s = n % 10;
        carry = n / 10;
        tail->next = new ListNode<int>(s);
        tail = tail->next;
        a = a->next;
        b = b->next;
    }
    while (a) {
        int n = a->val + carry;
        int s = n % 10;
        carry = n / 10;
        tail->next = new ListNode<int>(s);
        tail = tail->next;
        a = a->next;
    }
    while (b) {
        int n = b->val + carry;
        int s = n % 10;
        carry = n / 10;
        tail->next = new ListNode<int>(s);
        tail = tail->next;
        b = b->next;
    }
    if (carry) {
        tail->next = new ListNode<int>(carry);
    }
    return head->next;
}

int main() {
    ListNode<int>* a = ListNode<int>::generateList({9, 9, 9});
    ListNode<int>* b = ListNode<int>::generateList({9, 9, 9, 9, 9});
    ListNode<int>* r = sum(a, b);
    cout << r;
    return 0;
}