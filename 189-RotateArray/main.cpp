#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
public:


	// Dirty Method
	/*
	void rotate(vector<int> & nums, int k) {
		vector<int> newVec;
		k = k % (int)nums.size();
		if(k <= 0)
			return;
		int size = (int)nums.size();
		for(int i = 0; i < k; i ++) {
			newVec.push_back(nums[size-k+i]);
		}
		for(int i = k; i < size; i ++){
			newVec.push_back(nums[i-k]);
		}
		nums = newVec;
	}
	 */

	void rotate(vector<int>& nums, int k) {
		int size = (int)nums.size();
		k = k % size;
		if(k <= 0)
			return;
		int mid = size-k;
		reverse(nums,0,mid);
		reverse(nums,mid,size);
		reverse(nums,0,size);
	}

	void reverse(vector<int>& nums,int start, int end) {
		for(int i = start; i < (start + end)/2; i ++) {
			nums[i] ^= nums[start + end - i-1];
			nums[start + end - i-1] ^= nums[i];
			nums[i] ^= nums[start + end - i-1];
		}
	}

	/*
	void rotate(vector<int>& nums, int k) {
		k = k % (int)nums.size();
		if(k <= 0)
			return;
		int cursor = (int)nums.size()-k;
		while(cursor >= k){
			cursor = swap(nums,k,cursor);
		}
		int i = 0;
		while(i < cursor){
			int m = 0;
			int val = nums[m];
			while(m < k + cursor-1){
				nums[m] = nums[m+1];
				m ++;
			}
			nums[cursor-1 + k] = val;
			i ++;
		}
	}
	int swap(vector<int > &nums, int k, int cursor){
		int i = 0;
		int front = cursor - k;
		while(i < k){
			nums[cursor+i] ^= nums[front + i];
			nums[front+i] ^= nums[cursor + i];
			nums[cursor + i] ^= nums[front + i];
			i ++;
		}
		return front;
	}
	*/
};
int main() {
	vector<int> s{12,3,1,431,5131,52431,315252,23,41313};
	Solution sol;
	sol.rotate(s,12);
	for(auto i: s){
		cout<<i<<" ";
	}

	//std::cout << "Hello, World!" << std::endl;
	return 0;
}