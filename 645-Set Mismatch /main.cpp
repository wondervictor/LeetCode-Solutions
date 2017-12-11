#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> counter(nums.size(), 0);
        vector<int> result(2);
        for (auto i: nums) {
            if (counter[i-1] == 1) {
                result[0] = i;
            } else {
                counter[i-1] = 1;
            }
        }
        for(int i = 0; i < counter.size(); i ++) {
            if (counter[i] == 0) {
                result[1] = i+1;
                return result;
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}