#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode* > nodes;
        nodes.push(root);
        while(nodes.size()) {
            int size = (int)nodes.size();
            double currentSum = 0;
            for(int i = 0; i < size; i ++) {
                TreeNode* curNode = nodes.front();
                nodes.pop();
                currentSum += curNode->val;
                if (curNode->left)
                    nodes.push(curNode->left);
                if (curNode->right)
                    nodes.push(curNode->right);
            }
            double avg = currentSum/size;
            result.push_back(avg);
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}