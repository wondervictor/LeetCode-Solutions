#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* getNext(struct TreeNode *root) {
    if(root->left != NULL)
        return getNext(root->left);
    else
        return root;
}


struct TreeNode* removeNode(struct TreeNode *root, struct TreeNode *parent, int key) {

    if(key == parent->val) {
        if (!parent->left && !parent->right) {
            free(parent);
            return root;
        }
        if (parent->left && !parent->right){
            struct TreeNode *left = parent->left;
            parent->val = parent->left->val;
            parent->left = parent->left->left;
            parent->right = parent->left->right;
            free(left);
            return root;
        }
        if (parent->right && !parent->left) {
            struct TreeNode *right = parent->right;
            parent->val = parent->right->val;
            parent->left = parent->right->left;
            parent->right = parent->right->right;
            free(right);
            return root;
        }
        if (parent->right && parent->left) {
            struct TreeNode *successor = getNext(parent->right);
            if (!successor->right) {
                parent->val = successor->val;
                free(successor);
                return  root;
            } else {
                struct TreeNode *right = successor->right;
                parent->val = successor->val;
                successor->val = right->val;
                successor->right = right->right;
                successor->left = right->left;
                free(right);
                return root;
            }
        }
        return root;

    } else if (key > parent->val) {
        if (parent->right)
            return removeNode(root,parent->right,key);
        else
            return root;
    } else if (key < parent->val) {
        if (parent->left)
            return removeNode(root,parent->left,key);
        else
            return root;
    } else
        return root;
}


struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return NULL;
    return removeNode(root,root,key);
}


typedef struct TreeNode Tree;

void safe_free(Tree *root){
    if(root)
        free(root);

}

int main() {
    Tree *root = (Tree *)malloc(sizeof(Tree));
    Tree *one = (Tree *)malloc(sizeof(Tree));
    Tree *two = (Tree *)malloc(sizeof(Tree));
    Tree *three = (Tree *)malloc(sizeof(Tree));
    Tree *four = (Tree *)malloc(sizeof(Tree));
    Tree *five = (Tree *)malloc(sizeof(Tree));
    Tree *six = (Tree *)malloc(sizeof(Tree));
    Tree *seven = (Tree *)malloc(sizeof(Tree));
    Tree *eight = (Tree *)malloc(sizeof(Tree));
    Tree *ten = (Tree *)malloc(sizeof(Tree));



    root->left = three;
    root->right = six;
    three->left = two;
    three->right = four;
    six->right = seven;

    root->val = 5;
    three->val = 3;
    six->val = 6;
    two->val = 2;
    four->val = 4;
    seven->val = 7;


    root = deleteNode(root,7);

    safe_free(root);
    safe_free(one);
    safe_free(two);
    safe_free(three);
    safe_free(four);
    safe_free(five);
    safe_free(six);
    safe_free(seven);
    safe_free(eight);
    safe_free(ten);


    return 0;
}