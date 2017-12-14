#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:

  void f(vector<int>& nums, int index, vector<int> current, vector<vector<int>>& result) {

    if (index == nums.size()) {
      result.push_back(current);
      return;
    }

    f(nums, index+1, current, result);
    current.push_back(nums[index]);
    f(nums, index+1, current, result);
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) {
      result.push_back(nums);
      return result;
    }
    vector<int> current;
    f(nums, 0, current, result);
    return result;
  }
};



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}