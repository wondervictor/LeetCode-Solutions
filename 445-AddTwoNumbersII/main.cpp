#include <iostream>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pl1 = l1;
        ListNode *pl2 = l2;
        int counter = 0;
        ListNode *modi_node = nullptr;
        for(;pl1&&pl2; pl1 = pl1->next, pl2 = pl2->next){}
        for(;pl1;pl1=pl1->next,counter++)
            modi_node = pl2;
        for(;pl2;pl2=pl2->next,counter++)
            modi_node = pl1;
        ListNode *newNode = nullptr;
        ListNode *current = modi_node;
        for(int i = 0; i < counter; i ++) {
            newNode = new ListNode(0);
            newNode->next = current;
            current = newNode;
        }
        int num = 0;
        ListNode *endNode = nullptr;
        if(modi_node == l1)
            endNode = cal(newNode,l2,num);
        else if (modi_node == l2)
            endNode = cal(l1,newNode,num);
        else
            endNode = cal(l1,l2,num);
        if(num>0) {
            ListNode *newNode = new ListNode(num);
            newNode->next = endNode;
            endNode = newNode;
        }
        return endNode;
    }
    ListNode *cal(ListNode *l1, ListNode *l2, int & increment) {
        ListNode *nextPointer = nullptr;
        if(l1->next && l2->next)
            nextPointer = cal(l1->next,l2->next,increment);
        int num = l1->val + l2->val + increment;
        ListNode *newNode = new ListNode(num%10);
        increment = num/10;
        newNode->next = nextPointer;
        return newNode;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}