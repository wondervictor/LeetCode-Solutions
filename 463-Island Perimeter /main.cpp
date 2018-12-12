#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    int islandPerimeter(vector<vector<int>>& grid) {
      int perimeter = 0;
      auto height = grid.size();
      if (height == 0)
        return perimeter;
      auto width = grid[0].size();
      int cur = 0;
      for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          cur = 0;
          cur += (i==0) + (i == (height-1)) + (j == 0) + (j == (width-1));
          cur += i < height-1 ? 1 - grid[i+1][j] : 0;
          cur += j < width-1 ? 1 - grid[i][j+1] : 0;
          cur += i > 0 ? 1 - grid[i-1][j] : 0;
          cur += j > 0 ? 1 - grid[i][j-1] : 0;
          perimeter += cur * grid[i][j];
        }
      }
      return perimeter;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}