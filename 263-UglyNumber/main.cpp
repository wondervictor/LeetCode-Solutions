#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
	bool isUgly(int num) {
		if(num == 0 )
			return false;
		while(num%2 == 0)
			num = num/2;
		while(num%3 == 0)
			num = num/3;
		while(num%5 == 0)
			num = num/5;
		if(num != 1 && num != 2 && num != 3 && num!=5)
			return false;
		else
			return true;

	}
};


int main() {

	Solution sol;
	cout<<sol.isUgly(8);

	// std::cout << "Hello, World!" << std::endl;
	return 0;
}