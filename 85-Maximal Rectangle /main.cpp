#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
      auto height = matrix.size();
      if (height == 0)
        return 0;
      auto width = matrix[0].size();
      vector<vector<int>> dp(height, vector<int>(width, 0));
      for(int i = 0; i < height; i ++) {
        for(int j = 0; j < width; j ++) {
          if (matrix[i][j] == '1') {
            if (j == 0)
              dp[i][j] = 1;
            else
              dp[i][j] = dp[i][j-1] + 1;
          }
        }
      }
      int result = 0;
      for(int i = 0; i < height; i ++) {
        for(int j = 0; j < width; j ++) {
          int rectWidth = INT_MAX;
          for(int k = i; k < height; k ++) {
            rectWidth = min(rectWidth, dp[k][j]);
            if (rectWidth == 0)
              break;
            result = max((k-i+1)*rectWidth, result);
          }
        }
      }

      return result;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}