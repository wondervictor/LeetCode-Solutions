#include <iostream>
#include <vector>

using std::vector;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        TreeNode *centerNode = root;
        while(1) {
            int centerVal = centerNode->val;
            if((pVal <= centerNode->val && qVal >= centerVal)||(pVal >= centerVal && qVal <= centerVal)) {
                return centerNode;
            } else if (qVal > centerVal && pVal > centerVal) {
                centerNode = centerNode->right;
            } else {
                centerNode = centerNode->left;
            }
        }
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}