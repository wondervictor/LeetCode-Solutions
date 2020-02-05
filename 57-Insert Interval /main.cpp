#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> result;
      if(newInterval.size() == 0)
        return intervals;
      if(intervals.size() == 0) {
        result.push_back(newInterval);
        return result;
      }
      int startIndex = newInterval[0];
      int endIndex = newInterval[1];
      bool openInterval = false;
      for(int i = 0; i < intervals.size(); i ++) {
        auto currentInterval = intervals[i];
        if (currentInterval[1] < startIndex || endIndex == -1) {
          result.push_back(currentInterval);
          continue;
        }
        if (startIndex >= currentInterval[0] && startIndex <= currentInterval[1])
          startIndex = currentInterval[0];

        if (endIndex >= currentInterval[0] && endIndex <= currentInterval[1]) {
          endIndex = currentInterval[1];
          vector<int> inInterval;
          inInterval.push_back(startIndex);
          inInterval.push_back(endIndex);
          result.push_back(inInterval);
          startIndex = -1;
          endIndex = -1;
          continue;
        }
        if (endIndex >= 0 && endIndex < currentInterval[0]) {
          vector<int> inInterval;
          inInterval.push_back(startIndex);
          inInterval.push_back(endIndex);
          result.push_back(inInterval);
          result.push_back(currentInterval);
          startIndex = -1;
          endIndex = -1;
          continue;
        }
      }
      if (endIndex > 0) {
        vector<int> inInterval;
        inInterval.push_back(startIndex);
        inInterval.push_back(endIndex);
        result.push_back(inInterval);
      }
      return result;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}