#include <iostream>
#include <tkDecls.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fastPointer = head;
        ListNode *slowPointer = head;
        ListNode *movePointer = head;
        bool flag = false;
        while(fastPointer != nullptr && slowPointer != nullptr && fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if(slowPointer == fastPointer) {
                flag = true;
                break;
            }
        }
        if(!flag)
            return nullptr;
        while(1) {
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;
            if(slowPointer == movePointer || fastPointer == movePointer) {
                return movePointer;
            }
            if(fastPointer == slowPointer) {
                movePointer = movePointer->next;
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!whi" << std::endl;
    return 0;
}