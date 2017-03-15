#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::cout;
using std::endl;
class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		inStack.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (outStack.empty() && !inStack.empty()) {
			int p;
			while(!inStack.empty()) {
				p = inStack.top();
				inStack.pop();
				outStack.push(p);
			}
		}
		if(!outStack.empty())
			outStack.pop();
	}

	// Get the front element.
	int peek(void) {
		if (outStack.empty() && !inStack.empty()) {
			int p;
			while(!inStack.empty()) {
				p = inStack.top();
				inStack.pop();
				outStack.push(p);
			}
		}
		if(!outStack.empty())
			return outStack.top();
		else
			return  -1;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return (inStack.empty() && outStack.empty());
	}

private:
	stack<int> inStack;
	stack<int> outStack;
};

int main() {

	Queue que;
	que.push(10);
	cout<<que.peek()<<endl;
	que.pop();
	que.push(3);
	cout<<que.peek()<<endl;
	que.push(12);
	que.push(14);
	que.push(40);
	cout<<que.peek()<<endl;
	que.pop();
	cout<<que.peek()<<endl;

	return 0;
}