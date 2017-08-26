#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = (int)nums.size();
        if (size <= 1)
            return 0;
        int endIndex = -1;
        int startIndex = -1;
        bool flag = true;
        for (int i = 0; i < size-1; i ++) {
            if (nums[i] > nums[i+1] && flag) {
                startIndex = i;
                flag = false;
            }
            while(startIndex>0 && nums[i] < nums[startIndex-1] && !flag) {
                startIndex --;
            }
        }
        while(startIndex>0 && nums[size-1] < nums[startIndex-1]) {
            startIndex --;
        }
        flag = true;
        for (int i = size-1; i >= 1; i --) {
            if (nums[i] < nums[i-1] && flag) {
                endIndex = i;
                flag = false;
            }
            while(endIndex<size-1 && nums[i] > nums[endIndex+1] && !flag) {
                endIndex ++;
            }

        }
        while(endIndex<size-1 && nums[0] > nums[endIndex+1]) {
            endIndex ++;
        }
        int result = endIndex-startIndex+1;
        return  result > 1 ? result : 0;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}