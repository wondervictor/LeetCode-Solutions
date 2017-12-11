#include <iostream>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *previous = nullptr;
        ListNode *current = head;
        int64_t currentValue = INT64_MAX;
        for (; current; ) {
            if(current->next && current->next->val == current->val) {
                currentValue = current->val;
            }
            if(current->val == currentValue) {
                if(!previous) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                ListNode *tmp = current;
                current = current->next;
                delete tmp;
            } else {
                previous = current;
                current = current->next;
            }
        }
        return head;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}