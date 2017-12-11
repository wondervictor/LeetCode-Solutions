#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:



    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root)
            return nullptr;
        if (!root->right && !root->left && root->val)
            return nullptr;
//        if (!root->right && key == root->val) {
//            if(!root->left) {
//                return nullptr;
//            } else {
//                TreeNode *left = root->left;
//                delete root;
//                return left;
//            }
//        }
        return removeNode(root,root,key, nullptr,0);

    }

    TreeNode *getNext(TreeNode *root) {
        while(root->left)
            root = root->left;
        return root;
    }

    void swap(int *a, int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    TreeNode *removeNode(TreeNode *root, TreeNode *current, int key, TreeNode *parent, int flag) {
        if (current->val == key) {
            if(current->right) {
                TreeNode *next = getNext(current->right);
                swap(&next->val, &current->val);
                return removeNode(root,current->right,key,current,1);
            } else {
                if (current->left) {
                    TreeNode *left = current->left;
                    current->left = left->left;
                    current->right = left->right;
                    current->val = left->val;
                    delete left;
                    return root;
                } else {
                    delete current;
                    if(parent) {
                        if (flag==1)
                            parent->right = nullptr;
                        else
                            parent->left = nullptr;
                    }
                    return root;
                }
            }
        }
        if (current->val > key) {
            if (current->left)
                return removeNode(root,current->left,key,current,0);
            else
                return root;
        } else if (current->val < key) {
            if (current->right)
                return removeNode(root,current->right,key,current,1);
            else
                return root;
        }
        return root;
    }




//    TreeNode* getNext(TreeNode *root) {
//        if(root->left != NULL)
//            return getNext(root->left);
//        else
//            return root;
//    }
//
//    TreeNode* removeNode(TreeNode *root, TreeNode *parent, int key) {
//
//        if(key == parent->val) {
//            if (!parent->left && !parent->right) {
//                delete parent;
//                return root;
//            }
//            if (parent->left && !parent->right){
//                TreeNode *left = parent->left;
//                parent->val = parent->left->val;
//                parent->left = parent->left->left;
//                parent->right = parent->left->right;
//                delete left;
//                return root;
//            }
//            if (parent->right && !parent->left) {
//                TreeNode *right = parent->right;
//                parent->val = parent->right->val;
//                parent->left = parent->right->left;
//                parent->right = parent->right->right;
//                delete right;
//                return root;
//            }
//            if (parent->right && parent->left) {
//                TreeNode *successor = getNext(parent->right);
//                if (!successor->right) {
//                    parent->val = successor->val;
//                    delete successor;
//                    return  root;
//                } else {
//                    TreeNode *right = successor->right;
//                    parent->val = successor->val;
//                    successor->val = right->val;
//                    successor->right = right->right;
//                    successor->left = right->left;
//                    delete right;
//                    return root;
//                }
//            }
//            return root;
//
//        } else if (key > parent->val) {
//            if (parent->right)
//                return removeNode(root,parent->right,key);
//            else
//                return root;
//        } else if (key < parent->val) {
//            if (parent->left)
//                return removeNode(root,parent->left,key);
//            else
//                return root;
//        } else
//            return root;
//    }
//
//    TreeNode* deleteNode(TreeNode* root, int key) {
//        if (root == NULL)
//            return NULL;
//        return removeNode(root,root,key);
//    }
};

void safe_free(TreeNode *root){
    if(root)
        delete root;

}

int main() {

    TreeNode *root = new TreeNode(2);
    TreeNode *three = new TreeNode(1);
    TreeNode *six = new TreeNode(4);
    TreeNode *two = new TreeNode(1);
    TreeNode *four = new TreeNode(4);
    TreeNode *seven = new  TreeNode(7);
    root->left = two;
    //root->right = four;
    //two->left = three;
    //root->left = three;
    //root->right = six;
//    three->left = two;
//    three->right = four;
//    six->right = seven;

    Solution sol;
    root = sol.deleteNode(root,2);
    //delete root;

    safe_free(root);
    safe_free(three);
    safe_free(six);
    safe_free(four);
    safe_free(two);
    safe_free(seven);


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}