#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = (int)obstacleGrid.size();
        int col = (int)obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 0 ||obstacleGrid[row-1][col-1] == 0)
            return 0;
        if(row == 1) {
            for(int i = 0; i < col; i ++) {
                if (obstacleGrid[0][i] == 1)
                    return 0;
            }
            return 1;
        }
        if(col == 1  ) {
            for(int i = 0; i < row; i ++) {
                if (obstacleGrid[i][0] == 1)
                    return 0;
            }
            return 1;
        }
        bool flag = -1;
        for(int i = 0; i < col; i ++) {
            if(obstacleGrid[0][i] == 1) {
                flag = 0;
            }
            obstacleGrid[0][i] = flag;
        }
        flag = -1;
        for(int i = 1; i < row; i ++) {
            if(obstacleGrid[i][0] == 1)
                flag = 0;
            obstacleGrid[i][0] = flag;
            for(int j = 1; j<col; j++) {
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return -obstacleGrid[row-1][col-1];
    }
};


int main() {



    //std::cout << "Hello, World!" << std::endl;
    return 0;
}