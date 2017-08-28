#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0)
            return 0;
        int newSize = 1;
        int repeatCount = 1;
        int repeatNum = nums[0];

        for(int i = 1; i < size; i ++) {
            if (repeatNum == nums[i] && repeatCount < 2) {
                nums[newSize] = nums[i];
                newSize ++;
                repeatCount ++;
                continue;
            }
            if (repeatNum != nums[i]) {
                repeatCount = 1;
                repeatNum = nums[i];
                nums[newSize] = nums[i];
                newSize ++;
                continue;
            }
        }
        return newSize;
    }
};


int main() {

    vector<int> s = {1,2,2,2,2,4,5,5,5,6,7,8,8,8};
    Solution sol;



    return 0;
}