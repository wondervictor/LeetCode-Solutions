#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int row = (int)grid.size();
      if (grid[0][0] || grid[row-1][row-1])
        return -1;
      int shortestPath = -1;
      queue<vector<int>> traverseQueue;
      traverseQueue.push({0, 0, 1});
      grid[0][0] = 1;
      while(!traverseQueue.empty()) {
        auto point = traverseQueue.front();
        traverseQueue.pop();
        if(point[0]==row-1 && point[1]==row-1) {
          shortestPath = point[2];
          break;
        }
        for(int x = -1; x <= 1; x ++) {
          for(int y = -1; y <= 1; y ++) {
            if( x == 0 && y == 0 ) continue;
            int nx = point[0] + x;
            int ny = point[1] + y;
            if(nx >= row || nx < 0 || ny >= row || ny < 0 || grid[nx][ny] != 0)
              continue;
            traverseQueue.push({nx, ny, point[2]+1});
            grid[nx][ny] = 1;
          }
        }
      }
      return shortestPath;
    }
};




int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}