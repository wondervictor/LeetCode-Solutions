#include <iostream>


struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(!head || !head->next)
			return head;
		else {
			ListNode *next = head->next;
			head->next = nullptr;
			return reverse(head,next);
		}
    }

	ListNode *reverse(ListNode *previous, ListNode *current) {
		ListNode *next = current->next;
		current->next = previous;
		if(next)
			return reverse(current, next);
		else{
			return current;
		}
	}
};

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}