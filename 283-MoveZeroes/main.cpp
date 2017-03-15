#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Solution {
public:


	void moveZeroes(vector<int>& nums) {
		int cursor = 0, i = 0;
		while (i < nums.size()) {
			if (nums[i]!=0){
				int tmp = nums[cursor];
				nums[cursor] = nums[i];
				nums[i] = tmp;
				cursor ++;
			}
			i ++;
		}

	}


		/* 顺序改了
		void moveZeroes(vector<int>& nums) {
			int zeroPointer = 0, cursor = nums.size()-1;

			while(cursor != zeroPointer) {
				if(nums[zeroPointer] == 0) {
					if (nums[cursor] != 0 ) {
						nums[zeroPointer] = nums[cursor];
						nums[cursor] = 0;
						cursor --;
						zeroPointer++;
					} else {
						cursor --;
					}
				} else {
					if (nums[cursor] == 0){
						cursor --;
					}
					zeroPointer ++;
				}
			}
		}
		*/




	/* Time Exceeded
    void moveZeroes(vector<int>& nums) {
        int zpointer = 0, cursor = 1;
		while (cursor < nums.size()) {
			if (nums[cursor] != 0) {
				if(nums[zpointer] == 0) {
					nums[zpointer] = nums[cursor];
					nums[cursor] = 0;
				}
				zpointer ++;
				cursor ++;
			} else {
				cursor++;
			}
			if (nums[zpointer] != 0) {
				zpointer ++;
			}
		}
    }

	*/
};


int main() {
	vector<int> nums{0,1,0,3,12};
	Solution sol;
	sol.moveZeroes(nums);
	for(auto i : nums) {
		cout<<i<<" ";
	}


	std::cout << "Hello, World!" << std::endl;
	return 0;
}