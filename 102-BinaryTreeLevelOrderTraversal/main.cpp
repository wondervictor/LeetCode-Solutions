#include <iostream>
#include <vector>
#include <queue>
using std::vector;
using std::queue;
using std::cout;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int >> nodes;
		if(root) {
			queue<TreeNode *> node_queue;
			node_queue.push(root);
			while(node_queue.size()){
				vector<int> values;
				int size = (int)node_queue.size();
				for (int i = 0; i < size; ++i) {
					TreeNode *front_node = node_queue.front();
					node_queue.pop();
					values.push_back(front_node->val);
					if(front_node->left)
						node_queue.push(front_node->left);
					if(front_node->right)
						node_queue.push(front_node->right);
				}
				nodes.push_back(values);
			}
		}
		return nodes;
    }

};

int main() {
	//std::cout << "Hello, World!" << std::endl;
	return 0;
}