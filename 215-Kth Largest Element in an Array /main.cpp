#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Solution {
public:
    // sort
    int findKthLargest1(vector<int> &nums, int k) {
      sort(nums.begin(), nums.end());
      return nums[nums.size() - k];
    }
    // min heap
    int findKthLargest2(vector<int> &nums, int k) {
      priority_queue<int, vector<int>, greater<int>> numbers;
      for(int i = 0; i < k; i ++) {
        numbers.push(nums[i]);
      }
      for(int i = k; i < nums.size(); i ++) {
        if (nums[i] > numbers.top()) {
          numbers.pop();
          numbers.push(nums[i]);
        }
      }
      return numbers.top();
    }

    int quickSelect(vector<int>& nums, int k, int start, int end) {
      int pivotInd = rand() % (end - start + 1) + start;

      // 204ms: int pivotInd = end;
      // 8ms: int pivotInd = (end + start)/2;
      // 8ms: int pivotInd = rand() % (end - start + 1) + start;

      swap(nums[pivotInd], nums[end]);
      pivotInd = end;
      int pivot = nums[pivotInd];

      cout<<pivot<<endl;
      int i = start, j = start;
      while(j < end) {
        if (nums[j] < pivot) {
          swap(nums[i], nums[j]);
          i ++;
        }
        j ++;
      }
      swap(nums[i], nums[pivotInd]);
      if (i == nums.size()-k)
        return nums[i];
      if (i > nums.size() - k) {
        return quickSelect(nums, k, start, i-1);
      } else {
        return quickSelect(nums, k, i+1, end);
      }
    }
    int findKthLargest(vector<int>& nums, int k) {
      return quickSelect(nums, k, 0, (int)nums.size()-1);
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  vector<int> a = {4, 2, 8,3,9,5,2,1, 5, 6, 7};
  Solution sol;
  int b = sol.findKthLargest(a, 5);
  for(auto p: a)
    cout<<p<<" ";
  cout<<endl;
  cout<<b<<endl;
  return 0;
}