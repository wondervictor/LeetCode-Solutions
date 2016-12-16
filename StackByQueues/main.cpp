#include <iostream>
#include <queue>

using std::queue;
using std::cout;
using std::endl;


class Stack {
public:
	void push(int x){
		inQueue.push(x);
		int i = 0;
		while(i < inQueue.size()-1) {
			inQueue.push(inQueue.front());
			inQueue.pop();
			i ++;
		}
	}

	void pop() {
		inQueue.pop();
		/*
		if (inQueue.empty()) {
			if (!outQueue.empty()) {
				int i = 0,num;
				while (i < outQueue.size()-1) {
					num = outQueue.front();
					outQueue.pop();
					outQueue.push(num);
				}
				outQueue.pop();
			}
		} else {
			int num;
			while(inQueue.size() > 1) {
				num = inQueue.front();
				inQueue.pop();
				outQueue.push(num);
			}
			inQueue.pop();
		}
		*/
	}

	int top(){
		if (!inQueue.empty()){
			return inQueue.front();
		} else {
			return -1;
		}
		/*
		if (inQueue.empty()) {
			if (!outQueue.empty())
				return outQueue.back();
			else
				return -1;
		} else if (!inQueue.empty()) {

			return inQueue.back();
		}
		return -1;
		*/
	}

	bool empty() {
		return inQueue.empty();
	}

private:
	queue<int> inQueue;


};

/*
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
		inContainer.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {


		if(outContainer.empty()){
			while (!inContainer.empty()) {
				int p = inContainer.front();
				inContainer.pop();
				outContainer.push(p);
			}
		}
		outContainer.pop();

    }

    // Get the top element.
    int top() {
		if(outContainer.empty()){
			while (!inContainer.empty()) {
				int p = inContainer.front();
				inContainer.pop();
				outContainer.push(p);
			}
		}
		return outContainer.front();
    }

    // Return whether the stack is empty.
    bool empty() {
		return (outContainer.empty() && inContainer.empty());
    }

private:
	queue<int> inContainer;
	queue<int> outContainer;
};
*/
int main() {

	Stack stack;
	stack.push(10);
	cout<<stack.top()<<endl;
	stack.push(9);
	cout<<stack.top()<<endl;
	stack.push(7);
	cout<<stack.top()<<endl;
	stack.pop();
	cout<<stack.top()<<endl;



	return 0;
}
