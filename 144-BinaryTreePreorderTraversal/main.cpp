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
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> nums;
		if(root == nullptr)
			return nums;
		else {
			preTraversal(root,nums);
			return nums;
		}
	}

	void preTraversal(TreeNode *node, vector<int> &nums) {
		nums.push_back(node->val);
		if(node->left)
			preTraversal(node->left,nums);
		if(node->right)
			preTraversal(node->right,nums);
	}
}
