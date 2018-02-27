#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:

  struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) const {
      return a.second < b.second;
    }
  };

  vector<string> findRelativeRanks(vector<int>& nums) {
    auto size = nums.size();
    vector<string> result(size);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> athletes;

    for(int i = 0; i < size; i ++) {
      athletes.push(make_pair(i, nums[i]));
    }

    vector<string> ranks = {"Gold Medal", "Silver Medal", "Bronze Medal"};

    for(int i = 0; i < size; i ++) {
      auto ath = athletes.top();
      athletes.pop();
      if (i <= 2) {
        result[ath.first] = ranks[i];
      } else {
        stringstream ss;
        ss<<(i+1);
        result[ath.first] = ss.str();
      }
    }
    return result;
  }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}