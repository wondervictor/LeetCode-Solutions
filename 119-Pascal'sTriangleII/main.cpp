#include <iostream>

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex <= 0)
            return result;

        result.push_back(1);
        for(int i = 1; i <= rowIndex; ++i) {
            int temp = 0,incre = 0;
            for (int j = 1; j < i; ++j) {
                temp = result[j];
                result[j] = incre + result[j];
                incre = temp;
            }
            result.push_back(1);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}