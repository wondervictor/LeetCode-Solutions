#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        size_t size = nums.size();
        if(size < 3)
            return false;
        int i = INT_MAX;
        int j = INT_MAX;
        for(auto m: nums) {
            if(m <= i)
                i = m;
            else if (m <= j)
                j = m;
            else
                return true;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}