#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findLongestChain(vector<vector<int>>& pairs) {
    auto size = pairs.size();
    if (size < 1)
      return 0;
    sort(pairs.begin(), pairs.end(), [](vector<int> f, vector<int> s){ return f[1] < s[1];});
    int maxLen = 1;
    int prev = 0;
    for(int i = 1; i < size; i ++) {
      if (pairs[i][0] > pairs[prev][1]) {
        maxLen += 1;
        prev = i;
      }
    }
    return maxLen;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}