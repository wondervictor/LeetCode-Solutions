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
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> nums;
		if(root == nullptr)
			return nums;
		else{
			postTraversal(root,nums);
			return nums;
		}
	}

	void postTraversal(TreeNode *node, vector<int >&nums){
		if(node->left)
			postTraversal(node->left,nums);
		if(node->right)
			postTraversal(node->right,nums);
		nums.push_back(node->val);
	}
}
