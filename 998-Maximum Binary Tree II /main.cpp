#include <iostream>

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
      if(root == nullptr || val > root->val) {
        auto newRoot = new TreeNode(val);
        newRoot->left = root;
        return newRoot;
      }
      auto right = insertIntoMaxTree(root->right, val);
      root->right = right;
      return root;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}