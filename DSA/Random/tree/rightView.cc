#include <bits/stdc++.h>

#include "treeNode.h"
using namespace std;

vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};
    vector<int> arr;
    TreeNode* lastNode = nullptr;
    int level, lastLevel = 1;

    queue<pair<int, TreeNode*>> q;
    q.push({1, root});

    while (!q.empty()) {
        auto d = q.front();
        q.pop();
        TreeNode* node = d.second;
        level = d.first;

        TreeNode *left = node->left, *right = node->right;
        if (left) q.push({level + 1, left});
        if (right) q.push({level + 1, right});

        if (lastLevel + 1 == level) {
            arr.push_back(lastNode->val);
        }
        lastLevel = level;
        lastNode = node;
    }
    arr.push_back(lastNode->val);
    return arr;
}

// Time: O(N), Space: O(1)
void helper(TreeNode* node, int level, vector<int>& result) {
    if (!node) return;
    if (level == result.size()) {
        result.push_back(node->val);
    }
    if (node->right) helper(node->right, level + 1, result);
    if (node->left) helper(node->left, level + 1, result);
}

vector<int> rightSideView2(TreeNode* root) {
    vector<int> result;
    helper(root, 0, result);
    return result;
}

int main() {
    TreeNode* n = new TreeNode(1);
    n->left = new TreeNode(2);
    n->right = new TreeNode(3);
    // n->left->right = new TreeNode(5);
    // n->right->right = new TreeNode(4);
    n->left->left = new TreeNode(5);
    n->left->left->left = new TreeNode(6);
    auto arr = rightSideView2(n);
    for (auto x : arr) cout << x << " ";
    return 0;
}