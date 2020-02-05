#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
      int num = 0;
      int currentNum = 0;
      stack<int> numStack;
      for (auto c: S) {
        if (c == '(') {
          numStack.push(-1);
        } else {
          auto top = numStack.top();
          if(top == -1) {
            numStack.pop();
            numStack.push(1);
            continue;
          }
          currentNum = 0;
          while(top != -1) {
            numStack.pop();
            currentNum += top;
            top = numStack.top();
          }
          numStack.pop();
          numStack.push(currentNum*2);
        }
      }
      while(numStack.size()) {
        num += numStack.top();
        numStack.pop();
      }
      return num;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}