#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int n = (int)nums.size();
    	int sum = 0;
		for(int i = 0; i <= n; i ++)
			sum ^= i;
		for(auto i : nums)
			sum ^= i;
		cout<<sum;
		return sum;
    }

	//136. Single Number
	int singleNumber(vector<int>& nums) {
		int sum = 0;
		/*
		for(auto i : nums)
			sum ^= i;
		*/
		int  size = (int)nums.size();
		for(int i = 0; i < size; i++)
			sum ^= nums[i];
		return sum;
	}

};





int main() {
	Solution sol;
	vector<int> s{2, 1, 0};
	sol.missingNumber(s);

	std::cout << "Hello, World!" << std::endl;
	return 0;
}