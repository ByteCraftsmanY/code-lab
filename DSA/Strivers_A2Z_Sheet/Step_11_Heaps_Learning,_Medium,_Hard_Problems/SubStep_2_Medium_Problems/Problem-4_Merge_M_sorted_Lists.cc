// Merge M sorted Lists
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Medium Problems
// Post Link: https://takeuforward.org/data-structure/merge-m-sorted-lists
// LeetCode Link: https://leetcode.com/problems/merge-k-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* generateListFromArray(const vector<int>& arr) {
    ListNode *head = nullptr, *tail = nullptr;
    for (auto x : arr) {
        if (!head)
            head = tail = new ListNode(x);
        else {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
    }
    return head;
}

void printList(ListNode* list) {
    ListNode* node = list;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
}

ListNode* mergeTwoSortedList(ListNode* a, ListNode* b) {
    ListNode *head = nullptr, *tail = nullptr;
    while (a && b) {
        ListNode* node;
        if (a->val <= b->val) {
            node = a, a = a->next;
        } else {
            node = b, b = b->next;
        }
        node->next = nullptr;
        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = tail->next;
        }
    }
    while (a) {
        ListNode* node = a;
        a = a->next;
        node->next = nullptr;
        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = tail->next;
        }
    }
    while (b) {
        ListNode* node = b;
        b = b->next;
        node->next = nullptr;
        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = tail->next;
        }
    }
    return head;
}

ListNode* mergeKLists(vector<ListNode*>& lists, int low, int high) {
    // Time: O(n * k)
    // Space: O(n * k)
    // vector<int> arr = vector<int>();
    // for (auto x : lists) {
    //     while (x) {
    //         arr.push_back(x->val);
    //         x = x->next;
    //     }
    // }
    // sort(arr.begin(), arr.end());
    // return generateListFromArray(arr);

    // Time: O(nk)
    // Space: O(1)
    // int idx = -1;
    // ListNode *head = nullptr, *tail = nullptr;
    // while (idx == -1) {
    //     for (int i = 0; i < lists.size(); i++) {
    //         ListNode* list = lists[i];
    //         if (!list)
    //             continue;
    //         else if (idx == -1 || lists[i]->val < lists[idx]->val) {
    //             idx = i;
    //         }
    //     }

    //     if (idx == -1) break;

    //     ListNode* node = lists[idx];
    //     lists[idx] = lists[idx]->next;
    //     node->next = nullptr;

    //     if (!head) {
    //         head = tail = node;
    //     } else {
    //         tail->next = node;
    //         tail = tail->next;
    //     }
    //     idx = -1;
    // }
    // return head;

    // Divide and conqure (merge sort)
    // O(nlog(k))
    // if (low >= high) {
    //     return lists[low];
    // }
    // int mid = low + ((high - low) / 2);
    // ListNode* a = mergeKLists(lists, low, mid);
    // ListNode* b = mergeKLists(lists, mid + 1, high - 1);
    // return mergeTwoSortedList(a, b);

    // using min heap (priority queue is max heap by default, so we need to reverse comparator)
    // For min heap, smaller values should have higher priority
    struct CompareMin {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // smaller value at top (min heap)
        }
    };

    priority_queue<ListNode*, vector<ListNode*>, CompareMin> pq;
    for (auto x : lists) {
        if (x) pq.push(x);  // only push non-null lists
    }
    ListNode *head = nullptr, *tail = nullptr;
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        if (node->next) pq.push(node->next);
        node->next = nullptr;
        if (!head)
            head = tail = node;
        else
            tail->next = node, tail = tail->next;
    }
    return head;
}

int main() {
    vector<vector<int>> arrays = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6},
    };
    vector<ListNode*> lists;
    for (auto x : arrays) {
        lists.push_back(generateListFromArray(x));
    }
    ListNode* result = mergeKLists(lists, 0, lists.size() - 1);
    printList(result);
    return 0;
}
