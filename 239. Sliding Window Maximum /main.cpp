#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
    vector<int> result;
    auto size = nums.size();
    if (k == 0 || size == 0)
      return result;
    int currentMax = 0;
    for(int i = 0; i + k < size; i ++) {
      currentMax = *max_element(nums.begin()+i, nums.begin()+i+k);
      result.push_back(currentMax);
    }
    return result;
  }

  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    auto size = nums.size();
    if (k == 0 || size == 0)
      return result;

    int currentMax = *max_element(nums.begin(), nums.begin()+k);
    result.push_back(currentMax);
    for (int i = k; i < size; i ++) {
      if (nums[i - k] == currentMax && nums[i] < currentMax) {
        currentMax = *max_element(nums.begin() + i - k + 1, nums.begin() + i + 1);
        result.push_back(currentMax);
        continue;
      }

      if (nums[i] >= currentMax) {
        currentMax = nums[i];
        result.push_back(currentMax);
        continue;
      }
      result.push_back(currentMax);
    }
    return result;
  }

};


int main() {

  Solution sol;
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  int k = 3;
  vector<int> reuslt1 = sol.maxSlidingWindow(nums, k);
  vector<int> reuslt2 = sol.maxSlidingWindow1(nums, k);

  for (auto i: reuslt1) {
    cout<<" "<<i;
  }
  cout<<endl;
  for (auto i: reuslt2) {
    cout<<" "<<i;
  }
  cout<<endl;

  return 0;
}