#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:

  ListNode* mergeList(ListNode* head1, ListNode* head2) {
    ListNode* _head = nullptr;
    if (head1 == nullptr)
      return head2;
    if (head2 == nullptr)
      return head1;
    if (head1->val > head2->val) {
      _head = head2;
      head2 = head2->next;
    } else {
      _head = head1;
      head1 = head1->next;
    }
    ListNode* currentNode = _head;
    while(head1 && head2) {
      if (head1->val <= head2->val) {
        currentNode->next = head1;
        head1 = head1->next;
      } else {
        currentNode->next = head2;
        head2 = head2->next;
      }
      currentNode = currentNode->next;
    }

    if (head1)
      currentNode->next = head1;
    if (head2)
      currentNode->next = head2;
    return _head;
  }

  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode* leftNode = head;
    ListNode* rightNode = head;
    ListNode* _head = nullptr;

    while(rightNode->next && rightNode->next->next) {
      leftNode = leftNode->next;
      rightNode = rightNode->next->next;
    }
    if (rightNode == head) {
      rightNode = head->next;
      leftNode->next = nullptr;
      _head = mergeList(head, rightNode);
      return _head;
    }

    rightNode = sortList(leftNode->next);
    leftNode->next = nullptr;
    leftNode = sortList(head);
    _head = mergeList(rightNode, leftNode);
    return _head;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}