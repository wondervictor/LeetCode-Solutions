#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Solution {
public:


    int traverse(TreeNode* root, int& max) {
        int left = 0;
        int right = 0;
        if (root->left) {
            left = traverse(root->left, max);
        }
        if (root->right) {
            right = traverse(root->right, max);
        }

        int currentMax = root->val + left + right;
        currentMax = currentMax > root->val ? currentMax : root->val;
        int sideMax = ( left > right ? left : right );
        root->val = (sideMax > 0 ? sideMax : 0) + root->val;
        currentMax = currentMax > root->val ? currentMax : root->val;
        max = max > currentMax ? max : currentMax;
        return root->val;
    }

    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        int max = -INT_MAX;
        int rootVal = traverse(root, max);
        return max;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}