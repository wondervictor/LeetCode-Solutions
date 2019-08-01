#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    // 71.55% time 93.3% space
    bool isUnivalTree(TreeNode* root) {
      if (!root)
        return false;
      bool result = true;
      if (root->left) {
        if(root->left->val == root->val)
          result = result & isUnivalTree(root->left);
        else
          return false;
      }
      if (root->right) {
        if(root->right->val == root->val)
          result = result & isUnivalTree(root->right);
        else
          return false;
      }
      return result;
    }
};





int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}