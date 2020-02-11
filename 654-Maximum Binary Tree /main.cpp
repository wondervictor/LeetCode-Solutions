#include <iostream>
#include <vector>

using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* constructSubMaximumBinaryTree(vector<int>& nums, int start, int end) {
      int mid = 0;
      int maxNum = -1;

      for(int i = start; i < end; i ++) {
        if(nums[i] > maxNum) {
          maxNum = nums[i];
          mid = i;
        }
      }


      auto root = new TreeNode(maxNum);
      if (mid > start) {
        root->left = constructSubMaximumBinaryTree(nums, start, mid);
      }
      if (mid < end-1) {
        root->right = constructSubMaximumBinaryTree(nums, mid+1, end);
      }
      return root;
    }

    TreeNode* constructMaximumBinaryTree1(vector<int>& nums) {
      return constructSubMaximumBinaryTree(nums, 0, (int)nums.size());
    }

};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}