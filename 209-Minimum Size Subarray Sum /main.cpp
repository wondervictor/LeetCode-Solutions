#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    // O(N^2)
    int minSubArrayLen1(int s, vector<int>& nums) {
        int start = 0, end = 0;
        size_t size = nums.size();
        int len = (int)size;
        int currentSum = 0;
        int flag = false;
        for(int i = 0; i < size; i ++) {
            currentSum = 0;
            start = i;
            end = i;
            currentSum += nums[i];
            if (currentSum >= s) {
                return 1;
            }
            for (int j = i + 1; j < size; j ++) {
                currentSum += nums[j];
                if (currentSum >= s) {
                    end = j;
                    flag = true;
                    break;
                }
            }
            if (end>start && len > end-start+1) {
                len = end-start+1;
            }
        }
        return flag ? len : 0;
    }

    int minSubArrayLen(int s, vector<int>& nums) {
        int size = (int)nums.size();
        int len = size+1;
        int left = 0, right = 0;
        int sum = 0;
        while(right < size) {
            while(sum < s && right < size) {
                sum += nums[right];
                right ++;
            }
            while(sum >= s) {
                len = min(len, right-left);
                sum -= nums[left];
                left ++;
            }
        }
        return len > size ? 0 : len;
    }


};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}