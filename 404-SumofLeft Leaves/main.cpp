#include <iostream>
#include <vector>

using std::vector;

class Solution {
    int sumOfLeftLeaves(TreeNode* root) {
		if(root == nullptr)
			return 0;
		else{
			int sum = 0;
			left_traversal(root,0,sum);
			return sum;
		}
	}


	// flag == 1 left
	// flag == 0 right
	void left_traversal(TreeNode *node, int flag, int &sum) {
		if(!node->right && !node->left && flag == 1){
			sum += node->val;
			return;
		}
		if(node->right){
			left_traversal(node->right, 0, sum);
		}
		if(node->left){
			left_traversal(node->left, 1, sum);
		}
	}
}
