#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        int max_row = (int)grid.size();
        if (max_row == 0)
            return 0;
        int max_col = (int)grid[0].size();
        if (max_col == 0)
            return 0;
        for(int i = 1; i < max_row; i ++) {
            grid[i][0] += grid[i-1][0];
        }
        for(int i = 1; i < max_col; i ++) {
            grid[0][i] += grid[0][i-1];
        }

        for(int i = 1; i < max_row; i ++) {
            for(int j = 1; j < max_col; j ++) {
                grid[i][j] = (grid[i-1][j] < grid[i][j-1]?grid[i-1][j]:grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[max_row-1][max_col-1];
    }

//	int minPathSum(vector<vector<int>>& grid) {
//		int sum = 0;
//		int row = 0, col = 0;
//
//		while(row<grid.size()-1&& col < grid[0].size()-1){
//			sum += grid[row][col];
//			if(grid[row+1][col] > grid[row][col+1]){
//				col = col+1;
//			} else {
//				row = row + 1;
//			}
//		}
//
//		while(row < grid.size()){
//			sum += grid[row][col-1];
//			row ++;
//		}
//		while(col<grid[0].size()){
//			sum += grid[row-1][col];
//			col ++;
//		}
//		return sum;
//
//	}
};

int main() {

    vector<vector<int>> s = {{3,4,2,1},
                             {1,4,7,3},
                             {4,1,2,5},
                             {9,7,4,1}};

    Solution sol;
    std::cout<<sol.minPathSum(s)<<std::endl;


    //std::cout << "Hello, World!" << std::endl;
	return 0;
}