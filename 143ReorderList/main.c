#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorder(struct ListNode **left,struct ListNode *right, int *counter) {
    if (right->next)
        reorder(left,right->next,counter);
    struct ListNode *left_next = (*left)->next;
    (*left)->next = right;
    (*left) = left_next;
    right->next = left_next;
    if(--*counter == 0) {
        (*left)->next = NULL;
        return;
    }

}

void reorderList(struct ListNode* head) {
    struct ListNode *left = head;
    int len = 0;
    for (struct ListNode *current = head; current != NULL; current = current->next) {
        len++;
    }
    if (len <= 0)
        return;
    struct ListNode *right = head;
    for(int i = 0; i < (len+1)/2; i ++) {
        right = right->next;
    }
    int point = len/2;
    reorder(&left,right,&point);

}



int main() {

    struct ListNode *one = (struct ListNode *)malloc(sizeof(struct ListNode));
    one->val = 1;
    struct ListNode *two = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *three = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *four = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *five = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *six = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *seven = (struct ListNode *)malloc(sizeof(struct ListNode));
    two->val = 2;
    three->val = 3;
    four->val = 4;
    five->val = 5;
    six->val = 6;
    seven->val = 7;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = NULL;
    //six->next = seven;
    //seven->next = NULL;

    reorderList(one);


    //printf("Hello, World!\n");
    return 0;
}