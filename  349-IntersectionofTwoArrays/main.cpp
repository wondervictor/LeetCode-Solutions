#include <iostream>
#include <vector>

/**
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * */

using std::vector;
using std::cout;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
		vector<int> result;
		vector<int>::iterator nums1_iterator = nums1.begin();
		vector<int >::iterator nums2_iterator = nums2.begin();

		while (nums1_iterator != nums1.end() && nums2_iterator != nums2.end()) {
			int leftValue = *nums1_iterator;
			int rightValue = *nums2_iterator;
			if (leftValue == rightValue){
				if (result.empty()) {
					result.push_back(leftValue);
				} else if (!result.empty() && leftValue != *(result.end()-1)) {
					result.push_back(leftValue);
				}
				nums1_iterator++;
				nums2_iterator++;
			} else if (leftValue < rightValue) {
				nums1_iterator ++;
			} else if (rightValue < leftValue) {
				nums2_iterator++;
			}
		}
		return result;
	}
};



int main() {
	std::cout << "Hello, World!" << std::endl;
	Solution sol;
	vector<int> a{1, 2, 2, 1};
	vector<int> b{2, 2};

	vector<int> result = sol.intersection(a,b);
	for (auto i: result) {
		cout<<i<<" ";
	}
	return 0;
}