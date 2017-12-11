#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    /*
    int minimumTotal(vector<vector<int>>& triangle) {
        size_t size = triangle.size();
        if (size == 0)
            return 0;
        vector<int> previous(size,0);
        previous[0] = triangle[0][0];
        vector<int> current(size,0);
        for(int i = 1; i < size; i ++) {
            current[0] = previous[0] + triangle[i][0];
            current[i] = previous[i-1] + triangle[i][i];
            for(int j = 1; j < i; j ++) {
                current[j] = std::min(previous[j],previous[j-1])+ triangle[i][j];
            }
            previous = current;
        }
        int min = INT_MAX;
        for(auto i: previous)
            min = std::min(min, i);
        return min;
    }
    */
//    int minimumTotal(vector<vector<int>>& triangle) {
//        size_t size = triangle.size();
//        for(int i = 0; i < size; i ++) {
//            for(int j = 1; j < i; j ++) {
//                triangle[i][j]
//            }
//
//        }
//
//    }


};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}