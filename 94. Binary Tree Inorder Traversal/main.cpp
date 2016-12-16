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
public:

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> nums;
		if(root)
			traversal_inorder(root,nums);

		return nums;
	}

	void traversal_inorder(TreeNode *root, vector<int>& nums) {
		if(root->left)
			traversal_inorder(root->left, nums);
		nums.push_back(root->val);
		if(root->right)
			traversal_inorder(root->right, nums);
	}

}