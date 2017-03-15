#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for(auto i: matrix) {
            vector<int> arr;
            arr.push_back(0);
            int sum = 0;
            for(auto j: i) {
                sum += j;
                arr.push_back(sum);
            }
            this->matrix.push_back(arr);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i ++){
            sum += this->matrix[i][col2+1]-this->matrix[i][col1];
        }
        return sum;
    }

private:
    vector<vector<int>> matrix;
};


int main() {
    vector<vector<int>> s = {};
    NumMatrix ma(s);
    cout<<ma.sumRegion(1, 1, 2, 2)<<endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}