#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    void recursive(vector<int>& nums, int& result, int index, int target) {
        if (index == nums.size()) {
            if (target == 0)
                result ++;
            return;
        }
        recursive(nums, result, index+1, target-nums[index]);
        recursive(nums, result, index+1, target+nums[index]);

    }


    // recursive
    int findTargetSumWays1(vector<int>& nums, int S) {
        int result = 0;
        recursive(nums, result, 0, S);
        return result;
    }


    // dp
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = (int)nums.size();
        vector<map<int, int> > dp(size+1);
        dp[0][0] = 1;
        for(int i = 0; i < size; i ++) {
            for(auto p: dp[i]) {
                int curSum = p.first;
                int count = p.second;
                dp[i+1][curSum+nums[i]] += count;
                dp[i+1][curSum-nums[i]] += count;
            }
        }
        return dp[size][S];
    }


};


int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}