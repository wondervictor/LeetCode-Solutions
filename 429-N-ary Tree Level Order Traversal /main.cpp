#include <iostream>
#include <vector>
#include <queue>

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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      vector<vector<int>> results;
      if (root == nullptr)
        return results;
      queue<Node* > nodeQueues;
      nodeQueues.push(root);
      while (!nodeQueues.empty()) {
        auto qsize = nodeQueues.size();
        vector<int> subResults;
        for(int i = 0; i < qsize; i ++) {
          Node* node = nodeQueues.front();
          nodeQueues.pop();
          subResults.push_back(node->val);
          for(auto childNode: node->children) {
            nodeQueues.push(childNode);
          }

        }
        results.push_back(subResults);
      }
      return results;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}