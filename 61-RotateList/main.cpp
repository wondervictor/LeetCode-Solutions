#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        ListNode *newhead = NULL;
        ListNode *newEnd = NULL;
        int len = 0;
        for(ListNode *current = head; current != nullptr; current = current->next) {
            len ++;
            newhead = current;
        }
        newhead->next = head;
        int newKey = len - k%len - 1;
        newEnd = head;
        while(newKey-- > 0) {
            newEnd = newEnd->next;
        }
        head = newEnd->next;
        newEnd->next = nullptr;
        return head;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}