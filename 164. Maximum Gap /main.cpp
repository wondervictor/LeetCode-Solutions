#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
      auto size = (int)nums.size();
      if(size < 2)
        return 0;
      int maxVal = *max_element(nums.begin(), nums.end());
      int minVal = *min_element(nums.begin(), nums.end());
      auto gap = (maxVal - minVal)/size + 1;
      auto numBucket = (maxVal - minVal) / gap + 1;

      vector<vector<int> > bucket(numBucket);

      for(auto x: nums) {
        int idx = (x - minVal) / gap;
        if (bucket[idx].empty()) {
          bucket[idx].reserve(2);
          bucket[idx].push_back(x);
          bucket[idx].push_back(x);
        } else {
          if (bucket[idx][0] > x)
            bucket[idx][0] = x;
          if (bucket[idx][1] < x)
            bucket[idx][1] = x;
        }
      }

      int maxGap = 0;
      int lastValue = 0;
      for(int i = 1; i < numBucket; i ++) {
        if (bucket[i].empty())
          continue;
        maxGap = max(maxGap, (bucket[i][0] - bucket[lastValue][1]));
        lastValue = i;
      }

        return maxGap;
    }
};



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}