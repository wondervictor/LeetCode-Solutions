#include <iostream>
#include <vector>
#include <stack>
using namespace std;



class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto i: tokens) {
            if (i.size() == 1 && (i[0] == '*' || i[0] == '/' || i[0] == '+' || i[0] == '-')) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                switch (i[0]) {
                    case '+':
                        nums.push(a + b);
                        break;
                    case '-':
                        nums.push(a - b);
                        break;
                    case '*':
                        nums.push(a * b);
                        break;
                    case '/':
                        nums.push(a / b);
                        break;
                    default:
                        nums.push(a + b);
                        break;
                }
            }
            else {
                nums.push(atoi(i.c_str()));
            }
        }
        return nums.top();
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}