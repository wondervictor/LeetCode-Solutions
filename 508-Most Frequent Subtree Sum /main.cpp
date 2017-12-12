#include <iostream>
#include <vector>
#include <map>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    int traverse(TreeNode* root, map<int, int>& nodes, int& maxCount) {
      if (root == nullptr)
        return 0;
      int leftValue = traverse(root->left, nodes, maxCount);
      int rightValue = traverse(root->right, nodes, maxCount);
      int sumValue = leftValue + rightValue + root->val;
      if(nodes.find(sumValue)!=nodes.end()) {
        nodes[sumValue] += 1;
        if (nodes[sumValue] > maxCount) {
          maxCount = nodes[sumValue];
        }
      } else {
        nodes[sumValue] = 1;
      }
      return sumValue;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
      map<int, int> counter;
      int maxCount = 1;
      traverse(root, counter, maxCount);
      vector<int> result;
      for(auto it=counter.begin(); it != counter.end(); it ++) {
        if (it->second == maxCount) {
          result.push_back(it->first);
        }
      }
      return result;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}