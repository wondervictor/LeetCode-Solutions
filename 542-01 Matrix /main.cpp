#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:

    int find(vector<vector<int> >& mat, int i, int j, int x, int y) {
        if (mat[i][j] == 1) {
            mat[i][j] = x*y*y*x;
            int distance = x*y*y*x;
            if (i > 0) {
                // if (mat[i-1][j] == 0) {
                //     mat[i][j] = 2;
                //     return 1;
                // }
                distance = min(distance, find(mat, i-1, j, x, y));
            }
            if (j > 0) {
                // if (mat[i][j-1] == 0) {
                //     mat[i][j] = 2;
                //     return 1;
                // }
                distance = min(distance, find(mat, i, j-1, x, y));
            }
            if (i < x-1) {
                // if (mat[i+1][j] == 0) {
                //     mat[i][j] = 2;
                //     return 1;
                // }
                distance = min(distance, find(mat, i+1, j, x, y));
            }
            if (j < y-1) {
                // if (mat[i][j+1] == 0) {
                //     mat[i][j] = 2;
                //     return 1;
                // }
                distance = min(distance, find(mat, i, j+1, x, y));
            }
            mat[i][j] = distance+1+x*y*y;
            // cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
            return mat[i][j];
        } else if (mat[i][j] >= x*y*y*x){
            return x*y*y*x;
        } else if (mat[i][j] > x*y*y) {
            return mat[i][j]%(x*y*y);
        }else {
            return 0;
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int x = (int)matrix.size();

        if (x == 0) {
            return matrix;
        }
        vector<vector<int> >m = matrix;
        int y = (int)matrix[0].size();
        for(int i = 0; i < x; i ++) {
            for (int j = 0; j < y; j ++) {
                if (m[i][j] >= x*y*y) {
                    m[i][j] = 1;
                }
                if (m[i][j] == 1) {
                    int distance = find(m,i,j,x,y);
                }
            }
        }
        for(int i = 0; i < x; i ++) {
            for (int j = 0; j < y; j ++) {
                if (m[i][j] > 1) {
                    m[i][j] = m[i][j]%(x*y*y);
                }
            }
        }
        return m;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}