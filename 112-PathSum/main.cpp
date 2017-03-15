#include <iostream>

#include <vector>
using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)
			return false;

		return traverse(root,0,sum);

    }

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> paths;
		if(root == nullptr)
			return paths;
		vector<int> current_path;

		traverse_path(root,0,sum,current_path,paths);
		return paths;

	}

	/** Path sum II */

	void  traverse_path(TreeNode *root, int currentSum,int sum,vector<int>& current_path,vector<vector<int>> &paths){
		currentSum += root->val;
		current_path.push_back(root->val);
		if(!root->left && !root->right) {
			if(currentSum == sum){
				paths.push_back(current_path);
				current_path.pop_back();
			}
			else {
				current_path.pop_back();
			}
		} else {
			if(root->left != nullptr){
				traverse_path(root->left, currentSum,sum,current_path,paths);
			}
			if(root->right != nullptr){
				traverse_path(root->right,currentSum,sum,current_path,paths);
			}
			current_path.pop_back();
		}



	}

	bool traverse(TreeNode *root, int currentSum,int sums) {
		currentSum += root->val;
		if(!root->left && !root->right) {
			if(currentSum == sum)
				return true;
			else
				return false;
		}
		bool flag = false;

		if(root->left != nullptr)
			flag = traverse(root->left, currentSum,sum);
		if(root->right != nullptr)
			flag = flag || traverse(root->right,currentSum,sum);
		return flag;
	}


};

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}