#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    // 88.58% time 100% space
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
      vector<int> count(100,0);
      for(auto k: dominoes) {
        int first = k[0] * 10 + k[1];
        int second = k[1] * 10 + k[0];
        count[min(first, second)] += 1;
      }
      int num = 0;
      for (int i = 0; i < 100; i ++) {
        num += count[i] * ( count[i] - 1)/2;
      }
      return num;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}