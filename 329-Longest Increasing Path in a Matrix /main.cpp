#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:


    int search(vector<vector<int>>& matrix, vector<vector<int>>& distance, int x, int y, int width, int height) {
        if (distance[x][y] > 0)
            return distance[x][y];

        if (x > 0 && matrix[x][y] < matrix[x-1][y])
            distance[x][y] = max(distance[x][y], search(matrix, distance, x-1, y, width, height));
        if (y > 0  && matrix[x][y] < matrix[x][y-1])
            distance[x][y] = max(distance[x][y], search(matrix, distance, x, y-1, width, height));
        if (x < height - 1 && matrix[x][y] < matrix[x+1][y])
            distance[x][y] = max(distance[x][y], search(matrix, distance, x+1, y, width, height));
        if (y < width -1 && matrix[x][y] < matrix[x][y+1])
            distance[x][y] = max(distance[x][y], search(matrix, distance, x, y+1, width, height));
        distance[x][y] ++;

        return distance[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int height = (int)matrix.size();
        if (height == 0)
            return 0;
        int width = (int)matrix[0].size();
        int result = 0;
        vector<vector<int> > distance(height,vector<int>(width,0));
        for(int i = 0; i < height; i ++) {
            for(int j = 0; j < width; j ++) {
                result = max(result, search(matrix, distance,i,j,width,height));
            }

        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}