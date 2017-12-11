#include <iostream>
#include <vector>
using std::vector;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows <= 0)
            return result;

        vector<int> temp{1};
        result.push_back(temp);
        for (int i = 1; i < numRows; ++i) {
            vector<int> newVec;
            newVec.push_back(1);
            for (int j = 1; j < i; ++j) {
                newVec.push_back(temp[j-1]+temp[j]);
            }
            newVec.push_back(1);
            result.push_back(newVec);
            temp = newVec;
        }
        return result;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}