#include <iostream>
#include <vector>
using std::vector;
using std::cout;


class Solution {
public:
	/*
	int findDuplicate(vector<int>& nums) {
		std::sort(nums.begin(),nums.end());
		for(int i = 1; i < nums.size(); i ++) {
			if (nums[i] == nums[i - 1])
				return  nums[i];
		}
		return 0;
	}
	 */
	/*
	bool find(int num, vector<int> & nums) {
		int high = (int)(nums.size()-1);
		int low = 0;
		int mid = (high+low)/2;
		while(low <= high) {
			if (nums[mid] == num)
				return true;
			else if (nums[mid]) {


			}

		}

		return false;
	}

	int findDuplicate(vector<int>& nums) {
		for (int i = 0; i < nums.size()-1; i ++) {
			for (int js = i + 1; js < nums.size(); js ++)
				if (nums[js] == nums[i])
					return nums[js];
		}
		return 0;
	}
	*/


	// Flyod 算法

	int findDuplicate(vector<int>& nums) {
		if(nums.size() == 0 ) return 0;
		int slow = 0, fast = 0;
		slow = nums[slow];
		fast = nums[nums[fast]];
		while(slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		fast = 0;
		while(fast != slow) {
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}

};


int main() {
	std::cout << "Hello, World!" << std::endl;


	Solution sol;
	vector<int> s = {6,1,3,5,4,2,1};
	cout<<sol.findDuplicate(s);

	return 0;
}