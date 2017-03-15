#include <iostream>
#include <vector>
#include <map>
#include <queue>
using std::vector;
using std::map;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        map<int, int> values;

        queue<TreeNode *> node_queues;
        node_queues.push(root);
        int max = 0;
        while(node_queues.size()) {
            size_t size = node_queues.size();
            for(int i = 0; i < size; i ++) {
                TreeNode *node = node_queues.front();
                node_queues.pop();
                values[node->val] += 1;
                max = max > values[node->val] ? max:values[node->val];
                if(node->left)
                    node_queues.push(node->left);
                if(node->right)
                    node_queues.push(node->right);
            }
        }
        map<int, int>::iterator iter;
        for(iter=values.begin(); iter != values.end(); iter ++) {
            int val = iter->first;
            int num = iter->second;
            if(num == max)
                result.push_back(val);
        }
        return result;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}