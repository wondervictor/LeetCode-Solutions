#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if(nums.size() == 0)
			return false;
		std::sort(nums.begin(),nums.end());
		vector<int>::iterator iter = nums.begin();
		while(iter != nums.end()-1){
			if(*iter == *(iter+1))
				return true;
			iter ++;
		}
		return false;
	}

	// 219. Contains Duplicate II
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int i = 0;
		int size = (int)nums.size();
		unordered_map<int,int > num;
		while(i < size){
			if(num.find(nums[i]) != num.end() && num[nums[i]]-i == k)
				return true;
			else
				num[nums[i]] = i;
			i ++;
		}
		return false;


		/*
		while(i+k < size){
			if(nums[i] == nums[i + k])
				return true;
			i ++;
		}
		return false;
		*/
	}
};

int main() {

	vector<int> s{3,1};
	Solution sol;
	sol.containsDuplicate(s);
	//std::cout << "Hello, World!" << std::endl;
	return 0;
}