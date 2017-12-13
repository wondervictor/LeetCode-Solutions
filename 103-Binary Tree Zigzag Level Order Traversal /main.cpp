#include <iostream>
#include <vector>
#include <deque>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > result;
    if (root == nullptr)
      return result;
    deque<TreeNode* > nodes;
    nodes.push_back(root);
    // 0: left->right 1: right->left
    int direction = 0;

    while(!nodes.empty()) {
      vector<int> tmp;
      if (direction) {
        // right -> left
        auto size = (int)nodes.size();
        for(int i = 0; i < size; i ++) {
          TreeNode* currentNode = nodes.back();
          nodes.pop_back();
          if (currentNode->right)
            nodes.push_front(currentNode->right);
          if (currentNode->left)
            nodes.push_front(currentNode->left);
          tmp.push_back(currentNode->val);
        }
        direction = 0;
      } else {
        auto size = (int)nodes.size();
        for(int i = 0; i < size; i ++) {
          TreeNode* currentNode = nodes.front();
          nodes.pop_front();
          if (currentNode->left)
            nodes.push_back(currentNode->left);
          if (currentNode->right)
            nodes.push_back(currentNode->right);
          tmp.push_back(currentNode->val);
        }
        direction = 1;
      }
      result.push_back(tmp);
    }
    return result;
  }
};



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}