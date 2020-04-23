#include <iostream>
#include <vector>

using namespace std;




// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};



//recursive
class Solution2 {
public:
    void traverse(Node* root, vector<int>& values) {
      if (root == nullptr)
        return;
      for(auto node: root->children) {
        traverse(node, values);
        values.push_back(node->val);
      }
      values.push_back(root->val);

    }

    vector<int> postorder(Node* root) {
      vector<int> values;
      traverse(root, values);
      return values;
    }
};


// recursive
class Solution1 {
public:
    vector<int> postorder(Node* root) {
      vector<int> values;
      if (root == nullptr)
        return values;

      for(auto node: root->children) {
        auto childValues = postorder(node);
        for(auto v: childValues) {
          values.push_back(v);
        }
      }
      values.push_back(root->val);
      return values;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}