//
// Leetcode #110
//

#ifndef BINARY_TREE_STRUCTURE_BALANCED_BIN_TREE_H
#define BINARY_TREE_STRUCTURE_BALANCED_BIN_TREE_H
#include <stdlib.h>

class Balanced_bin_tree {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    bool isbalanced = true;

    int traverse(TreeNode* root, int depth) {
        if(root == nullptr) {
            return depth;
        }
        int left = traverse(root->left, depth + 1);
        int right = traverse(root->right, depth + 1);

        if(abs(left-right) > 1)
            isbalanced = false;

        if(left > right)
            return left;
        else return right;
    }

    bool isBalanced(TreeNode* root) {
        traverse(root, 0);
        return isbalanced;
    }
};

#endif //BINARY_TREE_STRUCTURE_BALANCED_BIN_TREE_H
