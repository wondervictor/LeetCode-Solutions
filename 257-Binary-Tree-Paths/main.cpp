#include <iostream>
#include <vector>
#include <sstream>
using std::string;
using std::cout;
using std::vector;
using std::endl;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> paths;
		if(root != NULL) {
			string path = "";
			traverse(root,path,paths);
		}
		return  paths;
	}

	void traverse(TreeNode *tree,string path,vector<string>& paths) {

		std::stringstream nodeStream;
		nodeStream<<tree->val;
		string nodeStr = nodeStream.str();
		if (tree->left == NULL && tree->right == NULL) {
			path.append(nodeStr);
			paths.push_back(path);
			return;
		}
		string node = nodeStr+"->";
		path.append(node);
		if(tree->left != NULL) {
			traverse(tree->left,path,paths);
		}
		if(tree->right != NULL) {
			traverse(tree->right, path, paths);
		}
	}

};

int main() {
	TreeNode *root = new TreeNode(0);
	TreeNode *_1 = new TreeNode(1);
	TreeNode *_2 = new TreeNode(2);
	root->left = _2;
	root->right = _1;

	TreeNode *_3 = new TreeNode(3);
	_1->left = _3;
	TreeNode *_4 = new TreeNode(4);
	_1->right = _4;
	TreeNode *_5 = new TreeNode(5);
	TreeNode *_6 = new TreeNode(6);
	_2->left = _5;
	_2->right = _6;
	TreeNode *_7 = new TreeNode(7);
	TreeNode *_8 = new TreeNode(8);
	_3->right = _8;
	_3->left = _7;
	TreeNode *_9 = new TreeNode(9);
	_4->left = _9;
	TreeNode *_10 = new TreeNode(10);
	_4->right = _10;
	TreeNode *_11 = new TreeNode(11);
	_5->right = _11;
	TreeNode *_12 = new TreeNode(12);
	_11->left = _12;
	TreeNode *_13 = new TreeNode(13);
	_7->right = _13;
	TreeNode *_14 = new TreeNode(14);
	_13->left = _14;

	Solution sol;
	vector<string> paths = sol.binaryTreePaths(root);
	for (auto i: paths) {
		cout<<i<<endl;
	}

	delete _1;
	delete _2;
	delete _3;
	delete _4;
	delete _5;
	delete _6;
	delete _7;
	delete _8;
	delete _9;
	delete _10;
	delete _11;
	delete _12;
	delete _13;
	delete _14;

	// std::cout << "Hello, World!" << std::endl;
	return 0;
}