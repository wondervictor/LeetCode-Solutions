#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    // 0:down2top 1:top2down
    int direction = 0;
    vector<int> result;
    int xsize = (int)matrix.size();
    if (!xsize)
      return result;
    int ysize = (int)matrix[0].size();
    int x = 0, y = 0;
    for(int i = 0; i < xsize*ysize; i ++) {
      result.push_back(matrix[x][y]);
      if (x == 0 && y < ysize-1 && direction == 0) {
        direction = 1;
        y += 1;
        continue;
      }
      if (y == ysize-1 && direction == 0) {
        direction = 1;
        x += 1;
        continue;
      }
      if (y == 0 && x < xsize-1 && direction == 1) {
        direction = 0;
        x += 1;
        continue;
      }
      if (x == xsize-1 && direction == 1) {
        direction = 0;
        y += 1;
        continue;
      }

      if (direction == 0) {
        x -= 1;
        y += 1;
      } else {
        x += 1;
        y -= 1;
      }
    }
    return result;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}