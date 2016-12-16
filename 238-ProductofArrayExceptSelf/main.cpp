#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int product = 1;
		int zero_count = 0;
		vector<int> result;
		for(auto i : nums) {
			if(i == 0){
				zero_count ++;
				if(zero_count >= 2)
					break;
				continue;
			}
			product = product * i;
		}
		if(zero_count >= 2) {
			for(auto i : nums) {
				result.push_back(0);
			}
		} else if (zero_count == 1) {
			for(auto i : nums) {
				if(i == 0)
					result.push_back(product);
				else
					result.push_back(0);
			}
		} else {
			for(auto i : nums) {
				result.push_back(product/i);
			}
		}
		return result;
    }
};


int main() {
	//std::cout << "Hello, World!" << std::endl;

	vector<int> test{1,2,3,4,0,0};
	Solution sol;

	vector<int> result = sol.productExceptSelf(test);

	for(auto i : result)
		cout<<i<<" ";


	return 0;
}