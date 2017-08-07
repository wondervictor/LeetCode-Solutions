#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> counter;
        counter.push_back(nums[0]);
        counter.push_back(max(nums[0], nums[1]));
        for (int i = 2; i <= nums.size(); i ++) {
            counter.push_back(max(nums[i]+counter[i-2], counter[i-1]));
        }
        return counter[nums.size()-1];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}