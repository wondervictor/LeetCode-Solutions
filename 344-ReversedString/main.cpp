#include <iostream>
#include <vector>
using std::cout;
using std::string;

class Solution {
public:
    string reverseString(string s) {
        string p;
		int size = (int)s.size();
		int i = size - 1;
		for (;i >= 0;i--) {
			p.push_back(s[i]);
		}
		return p;
    }
};

int main() {

	Solution sol;
	cout<<sol.reverseString("HELLO");


	return 0;
}

