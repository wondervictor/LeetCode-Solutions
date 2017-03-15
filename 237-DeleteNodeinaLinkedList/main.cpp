#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
		ListNode *previous_node = node;
		if(node == nullptr)
			return;
		while(node->next){
			previous_node = node;
			node->val = node->next->val;
			node = node->next;
		}
		previous_node->next = nullptr;
		delete node;
    }


	//  203. Remove Linked List Elements  /

	ListNode* removeElements(ListNode* head, int val) {


		if (head == nullptr){
			return nullptr;
		}

		while(head && head->val == val){
			ListNode *tmp = head;
			head = head->next;
			delete tmp;
		}
		if (head == nullptr){
			return nullptr;
		}

		ListNode *parent = head;
		ListNode *current = head;


		while(current != nullptr){
			if(current->val == val) {
				ListNode *tmp = current;
				current = current->next;
				parent->next = current;
				delete tmp;
			} else {
				parent = current;
				current = current->next;
			}
		}


		/*
		while(current!= nullptr) {
			if(current->val == val) {
				ListNode *tmp = current;
				current = current->next;
				parent->next = current;
				delete tmp;
			}
			if(current->next == nullptr)
				break;
			current = current->next;
			parent = current;
		}
		*/
		return head;
	}
};

int main() {

	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(1);
	ListNode *l3 = new ListNode(1);
	l1->next = l2;
	l2->next = l3;
	/*
	ListNode *l4 = new ListNode(4);

	ListNode *l5 = new ListNode(3);
	ListNode *l6 = new ListNode(6);
	ListNode *l7 = new ListNode(3);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	*/

	Solution sol;
	sol.removeElements(l1,1);

	ListNode *node = l1;
	while(node != nullptr){
		std::cout<<" "<<node->val;
		node = node->next;
	}
	std::cout<<std::endl;






	//std::cout << "Hello, World!" << std::endl;
	return 0;
}