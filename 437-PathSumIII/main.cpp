#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::endl;

// beat 100%

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        int counter = 0;
        sumAll(root,sum,counter);
        return counter;
    }

    void sumAll(TreeNode *root, int sum,int& counter) {
        traversal(root,sum,0,counter);
        if(root->left)
            sumAll(root->left,sum,counter);
        if(root->right)
            sumAll(root->right,sum,counter);
    }

    void traversal(TreeNode *root, int sum, int currentSum, int &counter) {
        currentSum += root->val;
        if(currentSum == sum) {
            counter ++;
        }
        if(root->right) {
            traversal(root->right,sum,currentSum,counter);
        }
        if(root->left) {
            traversal(root->left,sum,currentSum,counter);
        }

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}