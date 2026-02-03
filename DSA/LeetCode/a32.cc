#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

void printLinkedList(ListNode* res) {
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}

int pairSum(ListNode* head) {
    int result = 0;
    ListNode *prev = nullptr, *cur = nullptr, *next = head, *fast = head;
    while (fast && fast->next) {
        // mid
        fast = fast->next->next;

        // reverese first half
        prev = cur;
        cur = next;
        next = next->next;
        cur->next = prev;
    }
    ListNode *firstRevHalf = cur, *secondHalf = next;
    // printLinkedList(firstRevHalf);
    // printLinkedList(secondHalf);

    while (secondHalf) {
        result = max(result, firstRevHalf->val + secondHalf->val);
        firstRevHalf = firstRevHalf->next, secondHalf = secondHalf->next;
    }
    return result;

    // int result = 0, i = 0, n = 0;
    // stack<ListNode*> st;
    // ListNode* temp = head;
    // while (temp) {
    //     n++, temp = temp->next;
    // }
    // temp = head;
    // while (temp) {
    //     if (i <= (n / 2) - 1) {
    //         st.push(temp);
    //     } else {
    //         ListNode* topNode = st.top();
    //         st.pop();
    //         result = max(result, topNode->val + temp->val);
    //     }
    //     i++, temp = temp->next;
    // }
    // return result;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, nullptr))))));
    // ListNode* res = reverseList(head);
    // while (res) {
    //     cout << res->val << " ";
    //     res = res->next;
    // }
    cout << pairSum(head);
    return 0;
}