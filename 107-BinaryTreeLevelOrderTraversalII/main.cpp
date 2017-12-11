#include <iostream>
#include <vector>
#include <queue>
#include <tkDecls.h>

using std::queue;
using std::vector;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(nodes.size()) {
            int size = (int) nodes.size();
            vector<int> layers;
            for (int i = 0; i < size; i++) {
                TreeNode *node = nodes.front();
                nodes.pop();
                layers.push_back(node->val);
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
            }
            result.push_back(layers);
        }
        int size = (int)result.size();
        for(int i = 0; i < size/2; i ++) {
            auto temp = result[i];
            result[i] = result[size-i-1];
            result[size-i-1] = temp;
        }
        return result;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}