#include <iostream>
#include <queue>

using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> node_que;
        node_que.push(root);
        int val = 0;
        while(node_que.size()) {
            size_t size = node_que.size();
            val = node_que.front()->val;
            for(int i = 0; i < size; i ++) {
                TreeNode *node = node_que.front();
                node_que.pop();
                if(node->left)
                    node_que.push(node->left);
                if(node->right)
                    node_que.push(node->right);
            }
        }
        return val;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}