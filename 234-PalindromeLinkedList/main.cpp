#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	//  stack
	bool isPalindrome(ListNode* head) {
		if(head == NULL) {
			return true;
		}
		return traverse(head,head);
	}

	bool traverse(ListNode *(&front), ListNode *back) {
		ListNode *currentNode = front;
		bool flag = true;
		if(back->next != NULL) {
			flag = traverse(front, back->next);
		}
		if (!flag)
			return false;

		if(front->val == back->val){
			front = front->next;
			return  true;
		} else {
			return false;
		}

	}
};

int main() {

	ListNode *s1 = new ListNode(0);

	ListNode *s2 = new ListNode(2);
	ListNode *s3 = new ListNode(3);
	ListNode *s4 = new ListNode(4);
	ListNode *s5 = new ListNode(5);
	ListNode *s6 = new ListNode(5);
	ListNode *s7 = new ListNode(3);
	ListNode *s8 = new ListNode(2);
	ListNode *s9 = new ListNode(1);

	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = s5;
	s5->next = s6;
	s6->next = s7;
	s7->next = s8;
	s8->next = s9;

	Solution sol;
	cout<<sol.isPalindrome(nullptr);

	std::cout << "Hello, World!" << std::endl;
	return 0;
}