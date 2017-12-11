#include <iostream>
#include <map>

using std::map;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:



    ListNode *getIntersectionNodes(ListNode *headA, ListNode *headB) {
        map<ListNode *, int> times;
        ListNode *current = headA;
        for (; current; current = current->next ) {
            times[current] = 1;
        }
        current = headB;
        for (; current; current = current->next ) {
            if(times[current] == 1)
                break;
        }
        return current;
    }


    // O(1) Space O(n) time
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode *current = headA;
        for (; current; current = current->next ) {
            lenA ++;
        }
        current = headB;
        for (; current; current = current->next) {
            lenB ++;
        }
        int different = lenA - lenB;
        current = headA;
        ListNode *currentB = headB;
        while (different > 0) {
            current = current->next;
            different --;
        }
        while (different < 0) {
            currentB = currentB->next;
            different ++;
        }
        while(currentB != current) {
            current = current->next;
            currentB = currentB->next;
        }
        return current;
    }
};

int main() {

    ListNode *aHead = new ListNode(10);
    ListNode *a1 = new ListNode(1);
    aHead->next = a1;
    ListNode *a2 = new ListNode(30);
    a1->next = a2;
    ListNode *a3 = new ListNode(14);
    a2->next = a3;
    ListNode *bHead = new ListNode(8);
    ListNode *b1 = new ListNode(19);
    bHead->next = b1;
    ListNode *Common = new ListNode(11);
    ListNode *c1 = new ListNode(34);
    a3->next = Common;
    b1->next = Common;
    Common->next = c1;

    Solution sol;
    ListNode *result = sol.getIntersectionNodes(aHead, bHead);
    using namespace std;
    cout<<result->val<<endl;

    return 0;
}