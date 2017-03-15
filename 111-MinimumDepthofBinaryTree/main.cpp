#include <iostream>
#include <queue>

using std::cout;
using std::queue;
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
    int minDepth(TreeNode* root) {
		int min_depth = 0;
		if(root == nullptr)
			return 0;
		queue<TreeNode *> tree_queues;
		tree_queues.push(root);
		min_depth = 0;
		while(tree_queues.size() > 0) {
			min_depth ++;
			int size = (int)tree_queues.size();
			for(int i = 0; i < size; i ++ ){
				TreeNode *node = tree_queues.front();
				if(!node->right && !node->left){
					return  min_depth;
				}
				if (node->left)
					tree_queues.push(node->left);
				if (node->right)
					tree_queues.push(node->right);
				tree_queues.pop();
			}
		}
		return min_depth;

    }
};



int main() {


	TreeNode *root = new TreeNode(0);
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

	Solution *sol;
	cout<<"depth: "<<sol->minDepth(root);

	return 0;
}