#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //  204ms/92MB
    bool checkSubarraySum1(vector<int>& nums, int k) {
      if(nums.size() <= 1)
        return false;
      vector<vector<int>> sum(nums.size(), vector<int>());
      sum[0].push_back(nums[0]);
      for(int i = 1; i < nums.size(); i ++) {
        sum[i].push_back(nums[i]);
        for(auto p: sum[i-1]) {
          int res = p + nums[i];
          if ((k && res % k == 0 )||(!k && res == 0)) {
            return true;
          }
          sum[i].push_back(res);
        }
      }
      return false;
    }
    // 60ms/8.3MB
    bool checkSubarraySum2(vector<int>& nums, int k) {
      for(int i = 0; i < nums.size()-1; i ++) {
        int sum = nums[i];
        for (int j = i+1; j < nums.size(); j ++) {
          sum += nums[j];
          if (sum == k || ( k && sum % k == 0))
            return true;
        }
      }
      return false;
    }
    bool checkSubarraySum(vector<int>& nums, int k) {

      return false;
    }
};



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}