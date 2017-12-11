#include <iostream>
#include <vector>


using std::vector


class Solution {
public:

    // O(n^2)
    /*
    int lengthOfLIS(vector<int>& nums) {
        size_t size = nums.size();
        if(size == 0)
            return 0;
        vector<int> result(size);
        result[0] = 1;
        for(int i = 1; i < size; i ++) {
            result[i] = 1;
            for (int j = 0; j < i; ++j) {
                if(result[j] >= result[i] && nums[j] < nums[i])
                    result[i] = result[j] + 1;
            }
        }
        int max = 0;
        for(auto i: result)
            max = max > i ? max : i;
        return max;
    }
    */


    int lengthOfLIS(vector<int>& nums) {
        size_t size = nums.size();
        vector<int> results(size);





    }

};



int main() {






//    std::cout << "Hello, World!" << std::endl;
    return 0;
}