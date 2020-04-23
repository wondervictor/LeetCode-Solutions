#include <iostream>
#include <vector>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:

    void traverse(Node* root, vector<int>& nums) {
      if (root == nullptr)
        return;
      nums.push_back(root->val);
      for(auto p: root->children)
        traverse(p, nums);
    }

    vector<int> preorder(Node* root) {
      vector<int> nums;
      traverse(root, nums);
      return nums;
    }
};



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}