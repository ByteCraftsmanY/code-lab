// Serialize and deserialize Binary Tree
// Step: Binary Search Tree Part-II
// Difficulty: Hard
// Post Link: https://takeuforward.org/data-structure/serialize-and-deserialize-a-binary-tree/
// LeetCode Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// GFG Link: https://bit.ly/3PqPDSE

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Codec {
    int maxHeight(TreeNode* t) {
        if (!t) return 0;
        return max(maxHeight(t->left), maxHeight(t->right)) + 1;
    }

   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxH = maxHeight(root);
        while (!q.empty()) {
            TreeNode* n = q.front().first;
            int ord = q.front().second;
            q.pop();
            if (!n) {
                res = res + "X|";
                if (ord + 1 <= maxH) {
                    q.push({n, ord + 1});
                    q.push({n, ord + 1});
                }
                continue;
            }
            res = res + to_string(n->val) + "|";
            if (ord + 1 <= maxH) {
                q.push({n->left, ord + 1});
                q.push({n->right, ord + 1});
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << format("got: {}\n", data);
        TreeNode* head = nullptr;
        int v = 0, sepCount = 0, nCount = 0, hasVal = 0, isNeg = false;
        queue<pair<TreeNode*, int>> q;
        for (char& c : data) {
            if (c == '|') {
                if (isNeg) v *= -1;
                TreeNode* n = new TreeNode(v);
                if (!hasVal) n = nullptr;
                q.push({n, nCount});
                v = 0;
                if (!head)
                    head = n;
                else {
                    while (!q.empty()) {
                        TreeNode* nn = q.front().first;
                        int nNum = q.front().second;
                        int parent = nCount & 1 ? nCount >> 1 : (nCount >> 1) - 1;
                        if (parent == nNum) {
                            if (nn) {
                                if (nCount & 1)
                                    nn->left = n;
                                else
                                    nn->right = n;
                            }
                            break;
                        } else {
                            q.pop();
                        }
                    }
                }
                nCount++;
                sepCount++;
                isNeg = false;
            } else if (c == 'X') {
                hasVal = 0;
            } else if (c == '-') {
                isNeg = true;
            } else {
                hasVal = 1;
                v = (v * 10) + (c - '0');
            }
        }
        return head;
    }
};

int main() {
    TreeNode* head = new TreeNode(
        1,
        new TreeNode(2),
        new TreeNode(3, new TreeNode(4, new TreeNode(-6), new TreeNode(7)), new TreeNode(5)));
    Codec* c = new Codec();
    string e = c->serialize(head);
    cout << e << endl;
    TreeNode* n = c->deserialize(e);
    cout << c->serialize(n);
    return 0;
}
