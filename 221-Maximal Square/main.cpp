#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int maxVal = 0;
    auto xSize = matrix.size();
    if (xSize == 0)
      return 0;
    auto ySize = matrix[0].size();
    if (ySize == 0)
      return 0;
    vector<vector<int> > dp(xSize, vector<int>(ySize, 0));
    for (int i = 0; i < ySize; i ++) {
      if (matrix[0][i] == '1') {
        maxVal = 1;
        dp[0][i] = 1;
      }
    }
    for (int j = 1; j < xSize; j ++) {
      if (matrix[j][0] == '1') {
        maxVal = 1;
        dp[j][0] = 1;
      }
    }
    for (int i = 1; i < xSize; i ++) {
      for(int j = 1; j < ySize; j ++) {
        if (matrix[i][j] == '1') {
          dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
          maxVal = max(maxVal, dp[i][j]);
        }
      }
    }
    return maxVal * maxVal;
  }
};

int main() {

  std::cout << "Hello, World!" << std::endl;
  return 0;
}