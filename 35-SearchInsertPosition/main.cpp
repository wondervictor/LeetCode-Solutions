#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t size = nums.size();
        for(int i = 0; i < size; i ++ ) {
            if(nums[i] >= target)
                return i;
        }
        return (int)size;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}