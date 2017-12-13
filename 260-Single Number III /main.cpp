#include <iostream>
#include <vector>

using namespace std;


class Solution {
 public:

  // O(NlgN)
  vector<int> singleNumber1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> result;
    if (nums.size() == 1) {
      nums.push_back(0);
      return nums;
    }
    if (nums.size() == 2)
      return nums;
    if (nums[0] != nums[1]) {
      result.push_back(nums[0]);
    }
    for(int i = 1; i < nums.size(); i ++) {
      if (nums[i] == nums[i-1])
        continue;
      if (i < nums.size()-1 && nums[i] == nums[i+1]) {
        i ++;
        continue;
      }
      result.push_back(nums[i]);
    }
    return result;
  }

  /// 找到两个数不同的那位，进行区别
  vector<int> singleNumber(vector<int>& nums) {
    int twoXOR = 0;
    for(auto i: nums)
      twoXOR ^= i;

    int flag = twoXOR & -twoXOR;

    vector<int> result(2);
    for(auto i: nums) {
      if (i & flag == 0)
        result[0] ^= i;
      else
        result[1] ^= i;
    }
    return result;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}