#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode *previous = head;
    struct ListNode *current = head->next;

    for(;current!=NULL;){
        if(current->val == previous->val){
            struct ListNode *tmp = current;
            previous->next = current->next;
            current = current->next;
            free(tmp);
        } else {
            previous=current;
            current=current->next;
        }
    }
    return head;
}

int main() {
    //printf("Hello, World!\n");
    return 0;
}