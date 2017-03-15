#include <iostream>
#include <stack>

using std::stack;
using std::endl;
using std::cout;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<TreeNode*> nodes;
        traversal(root,nodes, nullptr);
        //regular(root);
    }

    void regular(TreeNode *root) {
        if(root->left){
            root->right = root->left;
            root->left = nullptr;
        }
        if(root->right)
            regular(root->right);
    }

    void traversal(TreeNode *root, stack<TreeNode *>& nodes, TreeNode *linkNode) {

        if(root->left){
            TreeNode *node = root->left;
            if(root->right)
                nodes.push(root);
            else {
                root->right = node;
                root->left = nullptr;
            }
            traversal(node,nodes,linkNode);
        } else {
            if(root->right){
                linkNode = root->right;
                traversal(root->right,nodes,linkNode);
            } else {
                if(nodes.size() == 0)
                    return;
                linkNode = root;
                TreeNode *parent = nodes.top();
                nodes.pop();
                TreeNode *right = parent->right;
                linkNode->right = right;
                parent->right = parent->left;
                parent->left = nullptr;
                traversal(right,nodes,linkNode);
            }
        }

    }
};




int main() {

    TreeNode *root = new TreeNode(0);
    TreeNode *r1 = new TreeNode(1);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *r3 = new TreeNode(3);
    TreeNode *r4 = new TreeNode(4);
    TreeNode *r5 = new TreeNode(5);
    TreeNode *r6 = new TreeNode(6);
    TreeNode *r7 = new TreeNode(7);
    TreeNode *r8 = new TreeNode(8);
    TreeNode *r9 = new TreeNode(9);
    TreeNode *r10 = new TreeNode(10);

    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r3->right = r6;
    r6->left = r7;
    r6->right = r8;
    r5->left = r9;
    r9->right = r10;

    Solution sol;
    sol.flatten(root);
    //sol.traversal(root,)


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}