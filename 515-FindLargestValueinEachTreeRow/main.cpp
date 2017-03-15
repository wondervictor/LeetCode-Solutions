#include <iostream>

#include <vector>
#include <queue>
using std::vector;
using std::queue;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        queue<TreeNode*> nodes;
        vector<int> result;
        if(!root)
            return result;
        nodes.push(root);
        while(nodes.size()) {
            size_t size = nodes.size();
            int max = nodes.front()->val;
            for(int i = 0; i < size; i ++) {
                TreeNode *node = nodes.front();
                nodes.pop();
                max = max > node->val ? max:node->val;
                if(node->left)
                    nodes.push(node->left);
                if(node->right)
                    nodes.push(node->right);
            }
            result.push_back(max);
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}