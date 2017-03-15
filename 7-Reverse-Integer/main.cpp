//
// Created by VicChan on 2016/12/10.
//

#include <iostream>
#include <queue>

using std::queue;
using std::cout;
using std::endl;

class Solution {
public:
	int reverse(int x) {
		int flag = x < 0 ? -1:1;
		queue<int> numQueue;
		x = abs(x);
		while(x !=0 ) {
			numQueue.push(x%10);
			x = x / 10;
		}
		long result = 0;
		while(numQueue.size() != 0) {
			result = result * 10 + numQueue.front();
			numQueue.pop();
		}
		cout<<"raw: "<<result<<endl;
		result = flag * result;
		if(result > 2147483647 || result < -2147483648)
			return 0;
		else
			return (int)result;
	}
};

int main() {

	Solution sol;
	cout<<sol.reverse(-1000000003)<<endl;

	return 0;
}