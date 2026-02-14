// https://leetcode.com/problems/same-tree/

#include <bits/stdc++.h>

#include "treeNode.h"
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)
        return true;
    else if ((p && !q) || (!p && q))
        return false;
    else if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    TreeNode* t1 = new TreeNode(1, new TreeNode(5), new TreeNode(3));
    TreeNode* t2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << isSameTree(t1, t2);
    return 0;
}