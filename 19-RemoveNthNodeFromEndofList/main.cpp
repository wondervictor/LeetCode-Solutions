#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return nullptr;
        traversal(head,nullptr,head,n);
        return head;
    }
    void traversal(ListNode *(&head),ListNode *parent, ListNode *current, int &n) {
        if(current->next) {
            traversal(head,current,current->next,n);
        }
        if(--n == 0) {
            ListNode *tmp = current;
            if(parent)
                parent->next = current->next;
            else
                head = current->next;
            delete tmp;
            return;
        }
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}