#include <iostream>

/**
 *
 *
Delete Node in BST
 *
 * */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
		if(root == nullptr)
			return nullptr;
		return deleteNodes(root, nullptr,key);
    }

	TreeNode *deleteNodes(TreeNode *root, TreeNode *parent, int key){
		if (root->val == key) {
			if(!root->left && !root->right) { /* 左右子节点都不存在*/
				std::cout<<root->val<<" ";
				//free(root);
				//root = nullptr;
			}
			else if(!root->right && root->left){
				// 只存在左节点
				TreeNode *node = root;
				if(parent == nullptr) {
					root = root->left;
				} else {
					if(parent->left == root){
						parent->left = root->left;
					} else {
						parent->right = root->left;
					}

					root = root->left;
				}
				delete node;
			}else if(!root->left && root->right) {
				// 只存在右节点
				TreeNode *node = root;
				if(parent == nullptr) {
					root = root->right;
				} else {
					if(parent->left == root){
						parent->left = root->right;
					} else {
						parent->right = root->right;
					}
					root = root->right;
				}
				delete node;
			} else if(root->left && root->right) {
				TreeNode *node = root;
				if(parent == nullptr){
					root = root->right;
					insertNode(node->left,root);
				} else {
					if(parent->left == root){
						parent->left = root->right;
					} else {
						parent->right = root->right;
					}
					insertNode(root->left, root->right);
					root = root->right;
				}
				delete node;
			}
		} else if(root->val > key && root->left) {
			deleteNodes(root->left,root,key);
		} else if(root->val < key && root->right) {
			deleteNodes(root->right,root,key);
		}
		return root;
	}
	void insertNode(TreeNode *node, TreeNode *root) {
		if(root->left != nullptr)
			insertNode(node, root->left);
		else
			root->left = node;
	}

};

int main() {
	TreeNode *l1 = new TreeNode(1);
	TreeNode *l2 = new TreeNode(2);
	TreeNode *l3 = new TreeNode(3);
	TreeNode *l4 = new TreeNode(4);
	TreeNode *l5 = new TreeNode(5);
	TreeNode *l6 = new TreeNode(6);
	TreeNode *l7 = new TreeNode(7);
	TreeNode *l8 = new TreeNode(8);
	TreeNode *l9 = new TreeNode(9);
	TreeNode *l10 = new TreeNode(10);
	TreeNode *l11 = new TreeNode(11);

	TreeNode *root = l5;
	l5->left = l3;
	l5->right = l8;
	l3->right = l4;
	l3->left = l2;
	l2->left = l1;

	l8->left = l6;
	l6->right = l7;
	l8->right = l10;
	l10->left = l9;
	l10->right = l11;



	Solution sol;
	root = sol.deleteNode(root,9);

	return 0;
}