#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *insert(struct ListNode *previous, int num) {
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = num;
    new->next = NULL;
    if(previous)
        previous->next = new;
    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    int increment = 0;


    struct ListNode *current_one = l1;
    struct ListNode *current_two = l2;
    int num = current_one->val + current_two->val;
    increment = num/10;
    int newNum = num%10;

    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    result->val = newNum;
    struct ListNode *current = result;
    if(l1->next == NULL && l2->next== NULL)
        return result;

    current_one = l1->next;
    current_two = l2->next;



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
    return result;
}


struct ListNode *create(int num) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = num;
}

int main() {

    struct ListNode *l11 = create(0);
    struct ListNode *l12 = create(1);
    struct ListNode *l13 = create(9);
    struct ListNode *l14 = create(1);
    struct ListNode *l21 = create(1);
    struct ListNode *l22 = create(6);
    struct ListNode *l23 = create(4);
    struct ListNode *l24 = create(1);

//    l11->next = l12;
//    l12->next = l13;
//
//    l21->next = l22;
//    l22->next = l23;

    struct ListNode *node = addTwoNumbers(l11,l12);



    free(l11);
    free(l12);
    free(l13);
    free(l14);
    free(l21);
    free(l22);
    free(l23);
    free(l24);




    //printf("Hello, World!\n");
    return 0;
}