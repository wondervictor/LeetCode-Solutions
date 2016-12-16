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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if(!p && !q)
			return true;
		else if( p && !q || !p && q)
			return false;
		else
			return traverseTwo(p,q);
	}

	bool traverseTwo(TreeNode *p, TreeNode *q){
		if(p->val != q->val)
			return false;
		if((p->left && !q->left )|| (p->left && !q->left ))
			return false;
		if((p->right && !q->right)||(!p->right && q->right))
			return false;
		bool flagRight = true,flagLeft = true;
		if(p->right && q->right)
			flagRight = traverseTwo(p->right, q->right);
		if(q->left && p->left)
			flagLeft = traverseTwo(p->left, q->left);
		return flagLeft && flagRight;
		//if(p == nullptr && q != nullptr)

	}

}