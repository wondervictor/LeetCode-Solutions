#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *fromNode = nullptr;
        ListNode *endNode = nullptr;
        ListNode *moveNode = nullptr;
        ListNode *previousNode = head;
        int counter = 1;
        for (ListNode *current = head, *previous = nullptr; current != nullptr; previous=current, current = current->next) {
            if(counter == m) {
                previousNode = previous;
                fromNode = current;
            }
            if(counter == n) {
                endNode = current;
                break;
            }
            counter ++;
        }
        counter = 0;
        if( previousNode == nullptr)
            head = endNode;
        else
            previousNode->next = endNode;
        while(counter < n-m) {
            moveNode=fromNode;
            fromNode = fromNode->next;
            moveNode->next = endNode->next;
            endNode->next = moveNode;
            counter ++;
        }
        return head;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}