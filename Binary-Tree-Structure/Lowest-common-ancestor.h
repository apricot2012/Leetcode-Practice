//
// Leetcode #236
//

#ifndef BINARY_TREE_STRUCTURE_LOWEST_COMMON_ANCESTOR_H
#define BINARY_TREE_STRUCTURE_LOWEST_COMMON_ANCESTOR_H

class Lowest_common_ancestor {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode* result;

    TreeNode* traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        } else {
            TreeNode *left = traverse(root->left, p, q);
            TreeNode *right = traverse(root->right, p, q);

            if((left == p || right == p) && root == q) {
                result = root;
                return nullptr;
            } else if ((left == q || right == q) && root == p) {
                result = root;
                return nullptr;
            } else if (root == p || root == q) {
                return root;
            } else if ((left == q && right == p) || (left == p && right == q)) {
                result = root;
                return nullptr;
            } else if (left == p || left == q) {
                return left;
            } else if (right == p || right == q) {
                return right;
            }

            return nullptr;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p, q);
        return result;
    }
};


#endif //BINARY_TREE_STRUCTURE_LOWEST_COMMON_ANCESTOR_H
