#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return nullptr;
        ListNode* firstLargeNode = nullptr;
        ListNode* lastLessNode = nullptr;
        ListNode* previous = nullptr;
        ListNode* current = nullptr;
        for(current = head; current != nullptr;) {
            if (current->val >= x) {
                firstLargeNode = current;
                lastLessNode = previous;
                break;
            }
            previous=current;
            current = current->next;
        }
        if (firstLargeNode == nullptr || firstLargeNode->next == nullptr)
            return head;
        previous = firstLargeNode;
        for(current = firstLargeNode->next; current != nullptr;) {
            if (current->val < x) {
                if (lastLessNode == nullptr) {
                    ListNode* tmp = current->next;
                    previous->next = current->next;
                    lastLessNode = current;
                    lastLessNode->next = firstLargeNode;
                    head = lastLessNode;
                    current = tmp;
                } else {
                    ListNode* tmp = current->next;
                    previous->next = current->next;
                    lastLessNode->next = current;
                    lastLessNode = current;
                    lastLessNode->next = firstLargeNode;
                    current = tmp;
                }
            } else {
                previous=current;
                current = current->next;
            }
        }

        return head;
    }
};




int main() {
    ListNode* node1 = new ListNode(1);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node3 = new ListNode(2);
//    ListNode* node4 = new ListNode(3);
//    ListNode* node5 = new ListNode(1);
//    ListNode* node6 = new ListNode(5);
//    ListNode* node7 = new ListNode(2);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = node7;
    Solution sol;
    sol.partition(node1,2);

    return 0;
}