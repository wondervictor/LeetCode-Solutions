#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* construct(int* nums, int start, int end) {
    int mid = (start + end) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    struct TreeNode* left = NULL;
    struct TreeNode* right = NULL;
    if (mid > start) {
        left = construct(nums, start, mid-1);
    }
    if (end > mid) {
        right = construct(nums, mid+1,  end);
    }
    node->right = right;
    node->left = left;
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;
    return construct(nums, 0, numsSize-1);
}




int main() {
    printf("Hello, World!\n");
    return 0;
}