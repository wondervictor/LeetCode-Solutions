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
    int maxDepth(TreeNode* root) {
		if(root == nullptr)
			return 0;
		else {
			int num = 0;
			max_traversal(root,0,num);
			return num;
		}
	}

	void max_traversal(TreeNode *node, int num, int &max) {
		num++;
		if(max < num)
			max = num;
		if(node->right)
			max_traversal(node->right,num,max);
		if(node->left)
			max_traversal(node->left,num,max);
	}
}
