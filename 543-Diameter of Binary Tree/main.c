#include <stdio.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int maxPath(struct TreeNode* root, int path, int *max) {
    int rightMax = 0;
    int leftMax = 0;
    int leftPath = 0;
    int rightPath = 0;
    path ++;
    if(root->left)
        leftMax = maxPath(root->left, path, &leftPath);
    if(root->right)
        rightMax = maxPath(root->right, path, &rightPath);
    *max = (rightPath > leftPath ? rightPath : leftPath) + 1;

    int nodeMax = leftPath + rightPath;
    int subnodeMax = leftMax > rightMax ? leftMax : rightMax;
    return nodeMax > subnodeMax ? nodeMax : subnodeMax;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int path = 0;
    if(root)
        return maxPath(root, 0, &path);
    else
        return 0;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}