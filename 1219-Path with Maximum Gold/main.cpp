#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int collectGold(vector<vector<int>>& grid, int h, int w, int x, int y) {
      int value = grid[x][y];
      int nextValue = 0;
      grid[x][y] = 0;
      if (x + 1 < h && grid[x+1][y] != 0)
        nextValue = max(collectGold(grid, h, w, x+1, y), nextValue);
      if (x - 1 >= 0 && grid[x-1][y] != 0)
        nextValue = max(collectGold(grid, h, w, x-1, y), nextValue);
      if (y + 1 < w && grid[x][y+1] != 0)
        nextValue = max(collectGold(grid, h, w, x, y+1), nextValue);
      if (y - 1 >= 0 && grid[x][y-1] != 0)
        nextValue = max(collectGold(grid, h, w, x, y-1), nextValue);
      grid[x][y] = value;
      return nextValue + value;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
      int maxValue = 0;
      int h = (int)grid.size();
      int w = (int)grid[0].size();
      for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
          if(grid[i][j] != 0) {
            int value = collectGold(grid, h, w, i, j);
            maxValue = max(maxValue, value);
          }
        }
      }
      return maxValue;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}