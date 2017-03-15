#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
		for (int i = 0; i < s.size(); i ++) {
			if (s[i] == '{'||s[i] == '[' || s[i] == '(')
				stack.push_back(s[i]);
			else {
				if (s[i] == ']') {
					if (!stack.empty()&& *(stack.end()-1) == '[')
						stack.pop_back();
					else
						stack.push_back(']');
				}else if (s[i] == '}') {
					if (!stack.empty()&& *(stack.end()-1) == '{')
						stack.pop_back();
					else
						stack.push_back('}');
				} else if (s[i] == ')') {
					if ( !stack.empty()&& *(stack.end()-1) == '(')
						stack.pop_back();
					else
						stack.push_back(')');
				}
			}

		}
		return stack.empty();
    }
};

int main() {


	Solution sol;
	std::cout<<sol.isValid("]");


	return 0;
}