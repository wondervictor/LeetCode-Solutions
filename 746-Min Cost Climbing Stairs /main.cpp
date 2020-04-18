#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:


    // TLE (recursive)
    // duplicate
    int climb(vector<int>& cost, int end) {
      int minCost = INT_MAX;
      if(end >= 2) {
        minCost = min(minCost, climb(cost, end-2));
        minCost = min(minCost, climb(cost, end-1));
        return minCost + cost[end];
      }
      return cost[end];
    }

    int minCostClimbingStairs1(vector<int>& cost) {
      int minCost = 0;
      int end = (int)cost.size();
      cost.push_back(0);
      minCost = climb(cost, end);
      return minCost;
    }

    // 4ms, 97.30%
    int minCostClimbingStairs(vector<int>& cost) {
      int size = (int)cost.size();
      vector<int> accumulateCost((size_t)size+1,0);
      for(int i = 2; i < size+1; i ++) {
        accumulateCost[i] = min(accumulateCost[i-1] + cost[i-1], accumulateCost[i-2]+cost[i-2]);
      }
      return accumulateCost[size];
    }

};




int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}