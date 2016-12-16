#include <iostream>

using std::cout;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *firstCursor, *secondCursor;
		if (l1 == nullptr && l2 == nullptr) {
			return nullptr;
		}
		if (l1 == nullptr && l2 != nullptr)
			return l2;
		if (l1 != nullptr && l2 == nullptr)
			return l1;
		if(l1->val < l2->val) {
			firstCursor = l1;
			secondCursor = l2;
		} else {
			firstCursor = l2;
			secondCursor = l1;
		}
		ListNode *result = firstCursor;
		while(secondCursor != nullptr) {
			if(firstCursor->val <= secondCursor->val) {
				if (firstCursor->next == nullptr) {
					firstCursor->next = secondCursor;
					break;
				} else if (secondCursor->val < firstCursor->next->val) {
					ListNode *tmp = secondCursor;
					secondCursor = secondCursor->next;
					tmp->next = firstCursor->next;
					firstCursor->next = tmp;
				}
				firstCursor = firstCursor->next;
			} else {

			}
		}
		return result;
    }
};

int main() {
	ListNode *h1 = new ListNode(1);
//	ListNode *h1 = new ListNode(12);
//	ListNode *h2 = new ListNode(41);
//	ListNode *h3 = new ListNode(65);
//	ListNode *h4 = new ListNode(100);
//	ListNode *h5 = new ListNode(200);
//	ListNode *h6 = new ListNode(250);
//	ListNode *h7 = new ListNode(300);
//	h1->next = h2;
//	h2->next = h3;
//	h3->next = h4;
//	h4->next = h5;
//	h5->next = h6;
//	h6->next = h7;

	ListNode *s1 = new ListNode(1);
	/*
	ListNode *s1 = new ListNode(1);
	ListNode *s2 = new ListNode(23);
	ListNode *s3 = new ListNode(54);
	ListNode *s4 = new ListNode(67);
	ListNode *s5 = new ListNode(190);
	ListNode *s6 = new ListNode(210);
	ListNode *s7 = new ListNode(220);
	ListNode *s8 = new ListNode(320);
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = s5;
	s5->next = s6;
	s6->next = s7;
	s7->next = s8;
	*/
	Solution sol;

	ListNode *result = sol.mergeTwoLists(h1,s1);
	ListNode *p = result;
	while(p != nullptr) {
		cout<<p->val<<" ";
		p=p->next;
	}

	return 0;
}