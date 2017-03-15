#include <iostream>
#include <stack>

using std::cout;
using std::stack;
using std::endl;


//  Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	// Recursive Method
    TreeNode* invertTree(TreeNode* root) {
		if(root==nullptr)
			return nullptr;
		TreeNode *node = root->left;
		root->left = root->right;
		root->right = node;
		invertTree(root->left);
		invertTree(root->right);
		return root;
    }
/*
	TreeNode* invert_tree(TreeNode *root){
		if(root == nullptr)
			return nullptr;
		stack<TreeNode *> tree_stack;
		tree_stack.push(root);
		while(1){
			TreeNode *node = tree_stack.top();
			tree_stack.pop();




		}


	}
*/


};




int main() {



	return 0;
}