#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int sum = 0;
		int row = 0, col = 0;

		while(row<grid.size()-1&& col < grid[0].size()-1){
			sum += grid[row][col];
			if(grid[row+1][col] > grid[row][col+1]){
				col = col+1;
			} else {
				row = row + 1;
			}
		}

		while(row < grid.size()){
			sum += grid[row][col-1];
			row ++;
		}
		while(col<grid[0].size()){
			sum += grid[row-1][col];
			col ++;
		}
		return sum;
	}
};

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}