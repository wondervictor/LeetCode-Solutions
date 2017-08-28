#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        size_t size = nums.size();
        if (size <= 1)
            return nums;
        sort(nums.begin(), nums.end());
        vector<int> previous(size, -1);
        int maxID = -1;
        int maxSize = -1;
        vector<int> dp(size, 1);
        dp[0] = 1;

        for(int i = 1; i < size; i ++) {
            for(int j = i-1; j >= 0; j --) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    previous[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxID = i;
            }
        }

        while(maxID != -1) {
            result.push_back(nums[maxID]);
            maxID = previous[maxID];
        }
        return result;

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}