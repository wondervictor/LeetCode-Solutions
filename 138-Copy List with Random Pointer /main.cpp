#include <iostream>
#include <map>

using namespace std;



//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* newHead = nullptr;
        if (head == nullptr) {
            return newHead;
        }
        map<RandomListNode*, RandomListNode*> relaionship;
        RandomListNode* originCurrent = head->next;
        newHead = new RandomListNode(head->label);
        RandomListNode* newCurrent = newHead;
        relaionship[head] = newHead;

        for(; originCurrent != nullptr; originCurrent = originCurrent->next) {
            RandomListNode* newNode = new RandomListNode(originCurrent->label);
            relaionship[originCurrent] = newNode;
            newCurrent->next = newNode;
            newCurrent = newNode;
        }
        originCurrent = head;
        newCurrent = newHead;
        for(;originCurrent != nullptr;) {
            if (originCurrent->random) {
                newCurrent->random = relaionship[originCurrent->random];
            }
            originCurrent = originCurrent->next;
            newCurrent = newCurrent->next;
        }
        return newHead;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}