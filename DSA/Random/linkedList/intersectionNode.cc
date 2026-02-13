#include <bits/stdc++.h>

#include "listNode.h"

using namespace std;

ListNode<int>* intersectedListNode(ListNode<int>* a, ListNode<int>* b) {
    if (!a || !b) return nullptr;
    ListNode<int>*p = a, *q = b;
    while (p != q) {
        p = p ? p->next : b;
        q = q ? q->next : a;
    }
    return p;
}

int main() {
    ListNode<int>*a = ListNode<int>::generateList({1, 2}), *b = ListNode<int>::generateList({1, 2, 3}), *n = ListNode<int>::generateList({5, 6, 7}), *r = nullptr;
    a->next = n, b->next = n;
    r = intersectedListNode(a, b);
    if (r) cout << r->val;
    return 0;
}