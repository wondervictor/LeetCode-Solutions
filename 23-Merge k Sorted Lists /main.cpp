#include <iostream>
#include <vector>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      auto size = lists.size();
      if (size == 0)
        return nullptr;
      ListNode* headNode = lists[0];
      ListNode* cursorNode = nullptr;
      if (size == 1)
        return headNode;
      // cout<<"hello"<<endl;
      int index = 1;
      while(headNode == nullptr && index < size) {
        headNode = lists[index];
        index ++;
      }
      if (headNode == nullptr && index == size)
        return nullptr;
      for(auto i = index; i < size; i ++) {
        ListNode* firstNode = lists[i];
        if (firstNode == nullptr)
          continue;
        ListNode* nextNode = firstNode;
        if (headNode->val > firstNode->val) {
          nextNode = firstNode->next;
          firstNode->next = headNode;
          headNode = firstNode;
        }

        ListNode* previousNode = headNode;
        cursorNode = previousNode->next;

        while(nextNode != nullptr) {
          while(cursorNode && cursorNode->val < nextNode->val) {
            cursorNode = cursorNode->next;
            previousNode = previousNode->next;
          }
          ListNode* nNextNode = nextNode->next;
          previousNode->next = nextNode;
          nextNode->next = cursorNode;
          previousNode = nextNode;
          nextNode = nNextNode;
        }
      }
      return headNode;
    }
};




int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}