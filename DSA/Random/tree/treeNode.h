#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
   public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}

    friend std::ostream& operator<<(std::ostream& os, TreeNode* node) {
        if (!node)
            os << "TreeNode { nullptr }\n";
        else
            os << "TreeNode { val: " << node->val << " } \n";
        return os;
    }
};

#endif