#include <iostream>
#include <vector>

using namespace std;

/**
 *  计算时间间隔，如果间隔大于duration，则直接在总时间上加上duration，
 *  如果小于的话，就直接算上时间间隔
 *
 */

class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int nums = 0;
    int currentNum = 0;
    int currentTime = 0;
    if (timeSeries.empty())
      return 0;
    for(int i = 0; i < timeSeries.size()-1; i ++) {
      currentNum = 0;
      int timeDiff = timeSeries[i+1]-timeSeries[i];
      nums += timeDiff > duration ? duration:timeDiff;
    }
    nums += duration;
    return nums;
  }
};

//class Solution {
//public:
//    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//      int nums = 0;
//      int currentNum = 0;
//      int currentTime = 0;
//      if (timeSeries.empty())
//        return 0;
//      for(int i = 0; i < timeSeries.size()-1; i ++) {
//        currentNum = 0;
//        int timeDiff = timeSeries[i+1]-timeSeries[i];
//        if (timeDiff > duration)
//          currentNum = duration;
//        else
//          currentNum = timeDiff;
//        /*
//        while(currentTime < timeSeries[i+1] && currentNum < duration) {
//          currentNum ++;
//          currentTime ++;
//        }
//        */
//        nums += currentNum;
//      }
//      nums += duration;
//      return nums;
//    }
//};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}