#include <iostream>
#include <cmath>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int getDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int currentNum = 1;
        currentNum += getDepth(root->left);
        return currentNum;

    }

    int getBlankNOdes(TreeNode* root, int count) {
        int num = 0;
        if (count == 2) {
            if (!root->left)
                num += 1;
            if (!root->right)
                num += 1;
            if (num == 0)
        } else if (count > 2) {
            if (root->right) {
                num += getBlankNOdes(root->right, count-1);
            }
            if (root->left) {
                num += getBlankNOdes(root->left, count-1);
            }
        }
        return num;
    }

    int countNodes(TreeNode* root) {
        TreeNode* leftNode = root;
        TreeNode* rightNode = root;

        int leftDepth = 0;
        int rightDepth = 0;

        while(leftNode) {
            leftDepth += 1;
            leftNode = leftNode->left;
        }

        while(rightNode) {
            rightDepth += 1;
            rightNode = rightNode->right;
        }
        if(rightDepth == leftDepth) {
            return (int)pow(2,leftDepth)  - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
//        int blank = getBlankNOdes(root, depth);
//        return (int)pow(2,depth) - blank - 1;
    }

    /* TLE
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return 1 + left + right;
    }
     */



};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}