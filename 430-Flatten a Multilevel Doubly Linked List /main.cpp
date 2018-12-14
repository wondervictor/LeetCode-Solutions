#include <iostream>



// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};


class Solution {
public:

    Node* flatten(Node* head) {
      if (!head)
        return nullptr;
      Node* current = head;
      while(!current->child && current->next) {
        current = current->next;
      }

      Node* next1 = flatten(current->child);
      Node* next2 = flatten(current->next);
      current->next = next1;
      current->child = nullptr;
      if (next1) {
        next1->prev = current;
        current = next1;
        while (current->next)
          current = current->next;
      }
      current->next = next2;
      current->child = nullptr;
      if (next2) {
        next2->prev = current;
        next2->child = nullptr;
      }
      return head;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}