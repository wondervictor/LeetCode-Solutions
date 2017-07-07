#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int currentLength = 0;
        stack<char> charStack;
        stack<int> numStack;
        int maxLength = 0;
        for(char i: s) {
            if (i == '(') {
                numStack.push(currentLength);
                charStack.push('(');
                maxLength = maxLength > currentLength ? maxLength : currentLength;
                currentLength = 0;
            } else if (i == ')') {
                if (charStack.size() && charStack.top() == '(') {
                    charStack.pop();
                    currentLength += numStack.top();
                    currentLength += 2;
                    numStack.pop();
                    maxLength = maxLength > currentLength ? maxLength : currentLength;
                } else {
                    numStack.push(0);
                    currentLength = 0;
                }
            }

        }
        return maxLength;
    }
};

int main() {

    string tes = "((()))()()(())";
    Solution sol;
    cout<<sol.longestValidParentheses(tes)<<"\n";


    return 0;
}