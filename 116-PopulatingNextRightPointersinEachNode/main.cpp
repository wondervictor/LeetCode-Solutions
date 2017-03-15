#include <iostream>


struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr)
            return;
        TreeLinkNode *previous = root;
        TreeLinkNode *currentHead = nullptr;
        root->next = nullptr;
        while(previous) {
            TreeLinkNode *head = nullptr;
            while(previous) {

                if(previous->left) {
                    if(!currentHead) {
                        currentHead = previous->left;
                        head = currentHead;
                    } else {
                        currentHead->next = previous->left;
                        currentHead = previous->left;
                    }
                }
                if(previous->right) {
                    if(!currentHead) {
                        currentHead = previous->right;
                        head = currentHead;
                    } else {
                        currentHead->next = previous->right;
                        currentHead = previous->right;
                    }
                }

                previous = previous->next;
            }
            if(currentHead)
                currentHead->next = nullptr;
            currentHead = nullptr;
            previous = head;
        }

    }
};


int main() {

    TreeLinkNode *root = new TreeLinkNode(0);
    TreeLinkNode *r1 = new TreeLinkNode(1);
    TreeLinkNode *r2 = new TreeLinkNode(2);
    TreeLinkNode *r3 = new TreeLinkNode(3);
    TreeLinkNode *r4 = new TreeLinkNode(4);
    TreeLinkNode *r5 = new TreeLinkNode(5);
    TreeLinkNode *r6 = new TreeLinkNode(6);
    TreeLinkNode *r7 = new TreeLinkNode(7);
    TreeLinkNode *r8 = new TreeLinkNode(8);
    TreeLinkNode *r9 = new TreeLinkNode(9);
    TreeLinkNode *r10 = new TreeLinkNode(10);

    root->left = r1;
    root->right = r2;

    r1->left = r3;
    r1->right = r4;

    r2->left = r5;
    r2->right = r6;


    r3->left = r7;
    r3->right = r8;
    r4->left = r9;
    r4->right = r10;

    Solution sol;

    sol.connect(root);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}