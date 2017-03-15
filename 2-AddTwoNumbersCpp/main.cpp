#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;

        int increment = 0;
        ListNode *current_one = l1;
        ListNode *current_two = l2;
        int num = current_one->val + current_two->val;
        increment = num/10;
        int newNum = num%10;
        ListNode *result = new ListNode(newNum);
        ListNode *current = result;

        current_one = l1->next;
        current_two = l2->next;

        while(current_one||current_two||increment) {
            int num = (current_two?current_two->val:0) + (current_one?current_one->val:0) + increment;
            increment = num/10;
            int newNum = num%10;
            current = insert(current,newNum);
            current_one = current_one?current_one->next : nullptr;
            current_two = current_two?current_two->next : nullptr;

        }

        /*
        for(;current_one!=NULL && current_two!=NULL;current_one = current_one->next,current_two = current_two->next) {
            int num = current_one->val + current_two->val + increment;
            increment = num/10;
            int newNum = num%10;
            current = insert(current,newNum);
        }
        for(;current_one != NULL;current_one = current_one->next){
            int num = current_one->val + increment;
            increment = num/10;
            int newNum = num%10;
            current = insert(current,newNum);
        }

        for(;current_two != NULL;current_two = current_two->next){
            int num = current_two->val + increment;
            increment = num/10;
            int newNum = num%10;
            current = insert(current,newNum);
        }
        if(increment > 0) {
            insert(current,increment);
        }
        */
        return result;



    }
    ListNode* insert(ListNode *previous,int num) {
        ListNode *node = new ListNode(num);
        node->next = nullptr;
        previous->next = node;
        return node;
    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}