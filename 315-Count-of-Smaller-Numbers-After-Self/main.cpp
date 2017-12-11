#include <iostream>
#include <vector>

using std::vector;



class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        size_t size = nums.size();
        vector<int> counts(size);
        for(int i = (int)size - 1; i >= 0; i --) {
            counts[i] = 0;
            for(int j = 1; j < (int)size-i; j ++) {
                if (nums[j+i] < nums[i]) {
                    counts[i] ++;
                }
            }
        }
        return counts;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}