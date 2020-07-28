//
// Leetcode #124
//

#ifndef BINARY_TREE_STRUCTURE_MAX_PATH_H
#define BINARY_TREE_STRUCTURE_MAX_PATH_H

#include <iostream>
class Max_path {
public:
    struct sumStruct{
        int maxsumconnected;
        int maxsumwithroot;
    };

    struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };


    sumStruct traverse(TreeNode* root) {
        if(root == nullptr) {
            sumStruct sum{INT32_MIN/4, INT32_MIN/4};
            return sum;
        }
        sumStruct left = traverse(root->left);
        sumStruct right = traverse(root->right);

        int sumr = INT32_MIN/4;
        int suml = INT32_MIN/4;
        int sumcurr = INT32_MIN/4;

        suml = left.maxsumconnected + root->val;

        sumr = right.maxsumconnected + root->val;

        sumcurr = root->val;

        int connectedmax = std::max(sumcurr, std::max(suml, sumr));

        int sumall = left.maxsumconnected + right.maxsumconnected + root->val;
        int l = left.maxsumwithroot;
        int r = right.maxsumwithroot;

        int withrootmax = std::max(connectedmax, std::max(std::max(l, r), sumall));

        sumStruct result{};

        result.maxsumconnected = connectedmax;

        result.maxsumwithroot = withrootmax;

        return result;
    }

    int maxPathSum(TreeNode* root) {
        sumStruct result = traverse(root);
        return std::max(result.maxsumconnected, result.maxsumwithroot);
    }
};

#endif //BINARY_TREE_STRUCTURE_MAX_PATH_H
