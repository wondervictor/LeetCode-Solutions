#include <iostream>
#include <vector>
#include <queue>

using std::pair;
using std::queue;
using std::vector;

class Solution {
public:
// dfs
    void search(vector<vector<char>>& grid, int x, int y) {
        size_t row = grid.size();
        if(row == 0)
            return ;
        size_t col = grid[0].size();
        if(x >= row || y >= col)
            return;
        if(grid[x][y] == '0')
            return;
        if(x < 0 || y < 0)
            return;
        grid[x][y] = '0';
        search(grid,x-1,y);
        search(grid,x+1,y);
        search(grid,x,y-1);
        search(grid,x,y+1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        size_t row = grid.size();
        if(row == 0)
            return 0;
        size_t col = grid[0].size();
        for(int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j++) {
                if(grid[i][j] == '1') {
                    search(grid,i,j);
                    counter ++;
                }
            }
        }
        return counter;
    }

// bfs
//    int numIslands(vector<vector<char>>& grid) {
//        int counter = 0;
//        queue<pair<int, int>> edges;
//        size_t row = grid.size();
//        if(row == 0)
//            return 0;
//        size_t col = grid[0].size();
//        for(int i = 0; i < row; i ++) {
//            for(int j = 0; j < col; j ++) {
//                if(grid[i][j] == '1') {
//                    pair<int, int> s(i,j);
//                    edges.push(s);
//                    while(edges.size()) {
//                        size_t edgesSize = edges.size();
//                        for(int p = 0; p < edgesSize; p ++) {
//                            pair<int,int> edge = edges.front();
//                            edges.pop();
//                            int x = edge.first;
//                            int y = edge.second;
//                            grid[x][y] = 'x';
//                            if(x < row-1 && grid[x+1][y] == '1') {
//                                pair<int, int> m(x+1, y);
//                                edges.push(m);
//                            }
//                            if(y < col-1 && grid[x][y+1] == '1') {
//                                pair<int, int> m(x, y+1);
//                                edges.push(m);
//                            }
//                            if(y > 0 && grid[x][y-1] == '1') {
//                                pair<int, int> m(x, y-1);
//                                edges.push(m);
//                            }
//                            if(x > 0 && grid[x-1][y] == '1') {
//                                pair<int, int> m(x-1,y);
//                                edges.push(m);
//                            }
//                        }
//                    }
//                    counter ++;
//                }
//            }
//        }
//        return counter;
//    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}