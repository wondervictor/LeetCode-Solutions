#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n == 0) {
            result.push_back(0);
            return result;
        }
        result = {0,1};
        int addition = 1;
        while(n > 1) {
            n --;
            addition *= 2;
            size_t size = result.size();
            for(int i = size-1; i >= 0; i --) {
                result.push_back(addition + result[i]);
            }
        }
        return result;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}