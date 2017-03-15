#include <iostream>


/**
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

* */

using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr||head->next == nullptr)
            return head;
        ListNode *next = head->next;
        ListNode *returnNode = next;
        ListNode *previous = nullptr;
        ListNode *current = head;
        for(;current!= nullptr;) {
            if(!current->next)
                break;
            current->next = next->next;
            next->next = current;
            if(previous)
                previous->next = next;

            previous = current;

            current = current->next;

            if(!current)
                break;
            next = current->next;
        }
        return returnNode;

    }
};

int main() {
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    //ListNode *four = new ListNode(4);
    one->next = two;

    two->next = three;
    //three->next = four;

    Solution sol;
    ListNode *node =  sol.swapPairs(one);

    while(node != nullptr){
        cout<<node->val<<"-";
        node = node->next;
    }
    delete one;
    delete two;
    delete three;
    //delete four;


    return 0;
}