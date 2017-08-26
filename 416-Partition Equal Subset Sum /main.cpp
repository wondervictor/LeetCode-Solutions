#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:

    bool findNum(int start, int end, vector<int>& nums, int target, int& index) {
        int mid;
        while(start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        index = start;
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // O(N)
        for(auto i: nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        sum = sum / 2;

        int size = (int)nums.size();
//        // O(NlogN)
//        sort(nums.begin(), nums.end());
//        int idx = -1;
//        // O(logN)
//        bool flag = findNum(0, size-1, nums, sum, idx);
//        if (flag)
//            return true;
//        while(nums[idx] < sum) {
//            idx ++;
//        }
//        idx --;

        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i = 0; i < size; i ++) {
            for (int j = sum; j >= nums[i]; j --) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}