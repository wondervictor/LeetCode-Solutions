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

}