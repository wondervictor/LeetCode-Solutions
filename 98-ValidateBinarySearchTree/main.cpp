#include <iostream>



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:


	bool isValidBST(TreeNode *root){
		if(!root)
			return true;


		long min = INT64_MIN;
		//INT_MIN;
		long max = INT64_MAX;

		bool flag = true;
		if(root->right)
			flag = flag && traversal_2_valid(root->right,root->val, max);
		if(root->left)
			flag = flag && traversal_2_valid(root->left, min, root->val);

		return flag;
	}

	bool traversal_2_valid(TreeNode *node, long min, long max){
		int val = node->val;
		if(val >= max || val <= min)
			return false;
		bool flag = true;
		if(node->right)
			flag = flag && traversal_2_valid(node->right,val,max);
		if(node->left)
			flag = flag && traversal_2_valid(node->left, min, val);
		return flag;

	}

	bool traversal_valid(TreeNode *node, long min, long max,int direction){
		// 右边
		int val = node->val;
		if(val >= max || val <= min)
			return false;
		bool flag = true;
		if(node->right)
			flag = flag && traversal_valid(node->right,val,max,1);
		if(node->left)
			flag = flag && traversal_valid(node->left, min, val,0);

		/*
		if(direction == 1){
			if(node->right)
				flag = flag && traversal_valid(node->right,val,max,1);
			if(node->left)
				flag = flag && traversal_valid(node->left,min,val,0);
		} else {
			if(node->right)
				flag = flag && traversal_valid(node->right,val,max,1);
			if(node->left)
				flag = flag && traversal_valid(node->left, min, val,0);
		}
		*/
		return flag;
	}

	/*
	bool isValidBST(TreeNode* root) {
		if(!root)
			return true;
		else {
			bool flag = true;

			if(root->left){
			    if(root->val <= root->left->val)
			        return false;
				flag = flag && traversal_valid(root->left,root,0);
			}
			if(root->right ){
			    if(root->right->val <= root->val )
			        return false;
				flag = flag && traversal_valid(root->right,root,1);
			}

			return flag;
		}
	}
	// direction = 0 left
	// direction = 1 right
	bool traversal_valid(TreeNode *root, TreeNode *grand,int direction){
		bool flag = true;
		if(direction == 0){
			if(root->right){
				if(root->right->val >= grand->val || root->right->val <= root->val)
					return false;
				else
					flag = flag && traversal_valid(root->right,root,1);
			}
			if(root->left){
				if(root->left->val >= root->val)
					return false;
				else
					flag = flag && traversal_valid(root->left,root,0);
			}
		} else {
			if(root->left){
				if(root->left->val <= grand->val || root->left->val >= root->val)
					return false;
				else
					flag = flag && traversal_valid(root->left,root,0);
			}
			if(root->right){
				if(root->right->val <= root->val)
					return false;
				else
					flag = flag && traversal_valid(root->right,root,1);
			}
		}
		return flag;
	}
	*/
};



int main() {
	TreeNode *root = new TreeNode(0);
	TreeNode *l1 = new TreeNode(1);
	TreeNode *l2 = new TreeNode(2);
	TreeNode *l3 = new TreeNode(1);
	TreeNode *l4 = new TreeNode(4);
	TreeNode *l5 = new TreeNode(2);
	TreeNode *l6 = new TreeNode(6);
	TreeNode *l7 = new TreeNode(7);
	TreeNode *l8 = new TreeNode(3);
	TreeNode *l9 = new TreeNode(9);
	TreeNode *l10 = new TreeNode(10);
	TreeNode *l11 = new TreeNode(11);


	l5->right = l8;
	l5->left = l3;
	/*
	l3->right = l4;
	l3->left = l2;
	l2->left = l1;
	l8->left = l10;
	l8->right = l9;
	*/

	/*
	root->right = l1;
	root->left = l2;
	l1->left = l3;
	l2->right = l4;
	l3->right = l5;
	l5->right = l6;
	l3->left = l7;
	l7->right = l8;
	l4->left = l9;
	l9->right = l10;
	l10->left = l11;
	*/

	Solution sol;
	std::cout<<sol.isValidBST(l5);

	//std::cout << "Hello, World!" << std::endl;
	std::cout<<" "<<INT64_MAX<<" "<<INT64_MIN<<std::endl;

	return 0;
}