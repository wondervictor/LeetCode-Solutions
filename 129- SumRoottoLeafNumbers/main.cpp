#include <iostream>

#include <vector>
#include <queue>
#include <tuple>

using std::vector;
using std::queue;
using std::tuple;

//  Definition for a binary tree node.

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    int sumNumbers(TreeNode* root) {
		if(root == nullptr)
			return 0;
		else{
			int sum = 0;
			sumTraversal(root,0,sum);
			return sum;
		}

	}

	void sumTraversal(TreeNode *node, int num, int &sum) {
		num = 10 * num + node->val;
		if(!node->left && !node->right){
			sum += num;
			return;
		}
		if(node->left)
			sumTraversal(node->left, num, sum);
		if(node->right)
			sumTraversal(node->right, num, sum);

	}
}
