#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    auto size = nums.size();
    if (size == 0) {
      return result;
    }
    int first = nums[0];
    if (size == 1) {
      stringstream s;
      s<<first;
      result.push_back(s.str());
      return result;
    }
    int last = first;
    for (int i = 1; i < size; i ++) {
      if (nums[i]-nums[i-1] == 1) {
        last = nums[i];
      } else {
        if (last > first) {
          stringstream s;
          s<<first;
          s<<"->";
          s<<last;
          result.push_back(s.str());
          first = nums[i];
          last = first;
        } else {
          stringstream s;
          s<<first;
          result.push_back(s.str());
          first = nums[i];
          last = first;
        }
      }
    }

    if (last > first) {
      stringstream s;
      s<<first;
      s<<"->";
      s<<last;
      result.push_back(s.str());
    } else {
      stringstream s;
      s<<first;
      result.push_back(s.str());
    }
    return result;

  }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}