//
// Solution to 104 depth of binary tree
//

#ifndef BINARY_TREE_STRUCTURE_MAX_DEPTH_BIN_TREE_H
#define BINARY_TREE_STRUCTURE_MAX_DEPTH_BIN_TREE_H

class Max_depth_bin_tree {
public:
     struct TreeNode {
             int val;
             TreeNode *left;
             TreeNode *right;
             TreeNode() : val(0), left(nullptr), right(nullptr) {}
             TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
             TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

    int traverse(TreeNode* root, int depth) {
        if(root == nullptr) {
            return depth;
        }
        int left = traverse(root->left, depth + 1);
        int right = traverse(root->right, depth + 1);

        int result;
        if(left > right)
            result = left;
        else result = right;
        return result;
    }

    int maxDepth(TreeNode* root) {
        return traverse(root, 0);
    }
};

#endif //BINARY_TREE_STRUCTURE_MAX_DEPTH_BIN_TREE_H
