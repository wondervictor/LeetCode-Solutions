#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


 // Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if(head==NULL || head->next == NULL)
        return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

/*
bool hasCycle(struct ListNode *head) {
    int address = 0;
    struct ListNode *node = head;
    while (node != NULL) {
        address ^= (int)head;
        node = node->next;
        if(node == 0)
            break;
    }
    return node == 0;
}

*/
int main() {

    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = 0;

    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 0;

    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2->val = 0;

    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node3->val = 0;

    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node4->val = 0;
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node5->val = 0;

    struct ListNode *node6 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node6->val = 0;

    node->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    return 0;
}