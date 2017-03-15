#include <iostream>
#include <stack>

using std::stack;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->root = root;
		if(root)
			getCurrent(root);

    }

	void getCurrent(TreeNode *root) {
		if(root->left){
			has_next = true;
			flag = false;
			parents.push(root);
			getCurrent(root->left);
		}
		else{
			std::cout<<root->val<<" ";
			parents.push(root);
			currentNode = root;
		}
	}
    /** @return whether we have a next smallest number */
    bool hasNext() {
		if(root)
			return !parents.empty();
		else
			return false;
    }

    /** @return the next smallest number */

	int next() {
		if(currentNode){
			TreeNode *node = currentNode;
			if(node->right){
				parents.pop();
				getCurrent(node->right);
			} else if(parents.size() > 1){
				parents.pop();
				TreeNode *parent = parents.top();
				currentNode = parent;
			} else {
				parents.pop();
			}
			return node->val;
		} else
			return 0;

	}


private:
	// right 1 or left 0
	bool flag;
	bool has_next;
	TreeNode *root;
	stack<TreeNode *> parents;
	TreeNode *currentNode;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}