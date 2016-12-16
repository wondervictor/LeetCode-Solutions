#include <iostream>
#include <vector>




using std::cout;
using std::cin;
using std::endl;

using std::vector;


class MinStack {
public:
	MinStack() =default;

	void push(int num) {
		if (minStack.empty() || num < *(minStack.end()-1)) {
			minStack.push_back(num);
		}
		stack.push_back(num);
	}

	void pop() {
		int num = *(stack.end()-1);
		if(num == *(minStack.end()-1)) {
			minStack.pop_back();
		}
		stack.pop_back();
	}

	int top() {
		return *(stack.end()-1);
	}

	int getMin() {
		return *(minStack.end() - 1);
	}

private:
	vector<int> stack;
	vector<int> minStack;

};

int main() {

	MinStack stack = MinStack();

	stack.push(5);
	stack.push(19);
	stack.push(1);
	cout<<"top"<<stack.top()<<endl;
	cout<<"min"<<stack.min()<<endl;
	stack.pop();
	cout<<"top"<<stack.top()<<endl;
	cout<<"min"<<stack.min()<<endl;

	return 0;
}

