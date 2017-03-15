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



	// 144. Binary Tree Preorder Traversal
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


	// 145. Binary Tree Postorder Traversal
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

	//129. Sum Root to Leaf Numbers
	int sumNumbers(TreeNode* root) {
		if(root == nullptr)
			return 0;
		else{
			int sum = 0;
			sumTraversal(root,0,sum);
			return sum;
		}

	}

	void sumTraversal(TreeNode *node, int num, int &sum) {
		num = 10 * num + node->val;
		if(!node->left && !node->right){
			sum += num;
			return;
		}
		if(node->left)
			sumTraversal(node->left, num, sum);
		if(node->right)
			sumTraversal(node->right, num, sum);

	}



	//104. Maximum Depth of Binary Tree

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

	// 404. Sum of Left Leaves
	int sumOfLeftLeaves(TreeNode* root) {
		if(root == nullptr)
			return 0;
		else{
			int sum = 0;
			left_traversal(root,0,sum);
			return sum;
		}
	}


	// flag == 1 left
	// flag == 0 right
	void left_traversal(TreeNode *node, int flag, int &sum) {
		if(!node->right && !node->left && flag == 1){
			sum += node->val;
			return;
		}
		if(node->right){
			left_traversal(node->right, 0, sum);
		}
		if(node->left){
			left_traversal(node->left, 1, sum);
		}
	}

	// 100. Same Tree
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

	// 101. Symmetric Tree

	//[1,2,2,null,3,null,3]
	// 相当dirty
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

	/*
	// BFS
	vector<int> rightSideView(TreeNode *root) {
		vector<int> values;
		if(root == nullptr)
			return values;

		queue<TreeNode *> tree_queue;
		tree_queue.push(root);
		while(tree_queue.size() > 0) {
			int size = (int)tree_queue.size();
			int val = tree_queue.back()->val;
			values.push_back(val);
			for(int i = 0; i < size; i ++){
				TreeNode *node = tree_queue.front();
				if(node->left)
					tree_queue.push(node->left);
				if(node->right)
					tree_queue.push(node->right);
				tree_queue.pop();
			}
		}
		return values;
	}
	*/


	/*
	vector<int> rightSideView(TreeNode* root) {
		vector<int> values;

		if(root == nullptr)
			return values;
		TreeNode *currentNode = root;
		while(currentNode != nullptr){
			if (currentNode->right){
				values.push_back(currentNode->val);
				currentNode = currentNode->right;
			} else if(currentNode->left) {
				values.push_back(currentNode->val);
				currentNode = currentNode->left;
			} else {
				values.push_back(currentNode->val);
				break;
			}
		}
		return values;
	}
	*/



	//94. Binary Tree Inorder Traversal
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



	Solution sol;

	std::cout << "Hello, World!" << std::endl;
	return 0;
}