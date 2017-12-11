#include <stdio.h>
#include <stdbool.h>



struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


bool dfs(struct TreeNode* root, int *num) {
    int rightHeight = 0;
    int leftHeight = 0;
    bool left = true, right = true;
    if (root->left)
        left = dfs(root->left, &leftHeight);
    if (root->right)
        right = dfs(root->right, &rightHeight);
    if (!left || !right)
        return false;
    if (rightHeight - leftHeight > 1 || rightHeight-leftHeight < -1)
        return false;
    *num = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    return true;
}

bool isBalanced(struct TreeNode* root) {
    int num = 0;
    if (!root)
        return false;
    else
        return dfs(root, &num);
}



int main() {
    printf("Hello, World!\n");
    return 0;
}