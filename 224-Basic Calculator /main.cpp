#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:

    int cal(int a, int b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            default:
                return 0;
        }
    }

    int calculate(string s) {
        stack<char> ops;
        int state = 0;
        string currentNum = "";
        int currentValue = 0;
        stack<int> nums;
        for (auto i: s) {
            if (i >= '0' && i <= '9') {
                currentNum.push_back(i);
            } else if ( i == '+' || i == '-') {
                int num = 0;
                if (currentNum.size() > 0)
                    num = atoi(currentNum.c_str());
                currentNum = "";
                if (ops.size() > 0 && ops.top() != '(') {
                    currentValue = cal(currentValue, num, ops.top());
                    ops.pop();
                } else {
                    currentValue = num + currentValue;
                }
                ops.push(i);
            } else if ( i == '(') {
                if (ops.size() && ops.top() == '(')
                    ops.push('+');
                nums.push(currentValue);
                ops.push('(');
                currentValue = 0;
            } else if (i == ')') {
                int num = 0;
                if (currentNum.size() > 0)
                    num = atoi(currentNum.c_str());                currentNum = "";
                if (ops.size() > 0 && ops.top() != '(') {
                    currentValue = cal(currentValue, num, ops.top());
                    ops.pop();
                } else {
                    currentValue = num + currentValue;
                }
                if (nums.size() > 0) {
                    ops.pop();
                    if (ops.size() == 0)
                        ops.push('+');
                    currentValue = cal(nums.top(), currentValue, ops.top());
                    cout<<currentValue<<"\n";
                    ops.pop();
                    nums.pop();
                }

            }
        }
        int num = 0;
        if (currentNum.size() > 0)
            num = atoi(currentNum.c_str());
        if (ops.size() > 0 && ops.top() != '(') {
            currentValue = cal(currentValue, num, ops.top());
            ops.pop();
        } else {
            currentValue = num + currentValue;
        }
        return currentValue;
    }
};



int main() {

    Solution sol;
    string s = "(1+2) + 29 + 23 +((13+3)-13+(42-(12+4) + 123)-13)";
    cout<<s<<"\n";
    int m = sol.calculate(s);
    cout<<m<<"\n";

    return 0;
}