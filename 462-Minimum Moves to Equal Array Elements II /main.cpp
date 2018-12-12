#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



class Solution {
public:
    // 12ms in leetcode O(n*log(n)) time complexity
    // one loops naive methods
    // 1. sort the arry
    // 2. find the relationship between adjacent elements
    // 3. apply the relationship to solve
    int minMoves2(vector<int>& nums) {
      long minDistance = LONG_MAX;
      // n*log(n)
      sort(nums.begin(), nums.end());
      int first = nums[0];
      int size = (int)nums.size();
      // n
      for(int i = 1; i < size; i ++) {
        minDistance += (long)abs(first - nums[i]);
      }
      long curDistance = 0;
      long formerDistance = minDistance;
      // n
      for(int i = 1; i < size; i ++) {
        curDistance = formerDistance + (nums[i]-nums[i-1])*(2*i - size);
        formerDistance = curDistance;
        minDistance = minDistance > curDistance ? curDistance : minDistance;
      }

      return (int)minDistance;
    }
};

class Solution1 {
public:
    // 708ms O(n^2) time complexity
    // two loops naive methods
    //
    int minMoves2(vector<int>& nums) {
      long minDistance = LONG_MAX;
      for(auto i: nums) {
        long curDistance = 0;
        for(auto j: nums) {
          curDistance += (long)abs(i-j);
        }
        minDistance = minDistance > curDistance ? curDistance : minDistance;
      }
      return (int)minDistance;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}