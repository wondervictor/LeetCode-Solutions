#include <iostream>
#include <stack>
#include <queue>



using std::stack;
using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        stack<TreeNode *> nodeStack;
//        queue<TreeNode *> pPath;
//        queue<TreeNode *> qPath;
//        bool pFlag = false, qFlag = true;
//        while(!pFlag || !qFlag) {
//
//        }
//
//
//    }




    void traverse(int flag, TreeNode *root, vector<TreeNode*> &pPath, vector<TreeNode*> &qPath,TreeNode *targetP,
                                TreeNode *targetQ, vector<TreeNode *> &path) {
        if(root == nullptr)
            return;
        path.push_back(root);
        if(root == targetP) {
            pPath = path;
            flag ++;
        }
        if(root == targetQ) {
            qPath = path;
            flag++;
        }
        if(flag == 2)
            return;
        traverse(flag,root->left, pPath, qPath, targetP, targetQ, path);
        traverse(flag,root->left, pPath, qPath, targetP, targetQ, path);
        path.pop_back();
    }

//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == NULL) return NULL;
//        if (root == p || root == q) return root;
//        TreeNode *L = lowestCommonAncestor(root->left, p, q);
//        TreeNode *R = lowestCommonAncestor(root->right, p, q);
//        if (L && R) return root;
//        return L ? L : R;
//    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> pPath;
        vector<TreeNode *> qPath;
        vector<TreeNode *> path;
        traverse(0, root, pPath, qPath, p, q, path);
        TreeNode *result = root;
        size_t size = pPath.size() < qPath.size() ? pPath.size():qPath.size();
        for(int i = 0; i < size; i ++) {
            if(pPath[i] == qPath[i]) {
                result = pPath[i];
            } else
                break;
        }
        return result;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}