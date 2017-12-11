#include <iostream>
#include <queue>

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

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* insertNode = new TreeNode(v);
            insertNode->left = root;
            return insertNode;
        }
        queue<TreeNode* > rowNodes;
        rowNodes.push(root);
        while (d > 2) {
            d --;
            size_t size = rowNodes.size();
            for (int i = 0; i < size; i ++) {
                TreeNode* node = rowNodes.front();
                rowNodes.pop();
                if (node->left)
                    rowNodes.push(node->left);
                if (node->right)
                    rowNodes.push(node->right);
            }
        }
        while (rowNodes.size()) {
            TreeNode* curNode = rowNodes.front();
            TreeNode* insertLeftNode = new TreeNode(v);
            insertLeftNode->left = curNode->left;
            TreeNode* insertRightNode = new TreeNode(v);
            insertRightNode->right = curNode->right;
            curNode->right = insertRightNode;
            curNode->left = insertLeftNode;
            rowNodes.pop();
        }
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}