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
    struct Value{
		int val;
		int flag;
		Value(int val,int flag):val(val),flag(flag){}
	};
	bool isSymmetric(TreeNode* root) {
		if(!root)
			return true;
		queue<Value> nums;
		traverseTree(root,nums,1);
		return traversalSymmetric(root, nums,0);
	}
	// left 0 right 1
	void traverseTree(TreeNode *root, queue<Value>& nums,int flag) {
		if (root->left)
			traverseTree(root->left, nums,0);
		nums.push(Value(root->val,flag));
		if (root->right)
			traverseTree(root->right, nums,1);
	}



	bool traversalSymmetric(TreeNode *root, queue<Value>& nums,int flag) {
		bool flag_1 = true, flag_2 = true,flag_all = false;
		if(root->right)
			flag_1 = traversalSymmetric(root->right, nums,1);
		Value value = nums.front();

		if(root->val == value.val && value.flag != flag){
			flag_all = true;
			nums.pop();
		}

		if(root->left)
			flag_2 = traversalSymmetric(root->left, nums,0);
		return flag_1 && flag_2 && flag_all;
	}
}
