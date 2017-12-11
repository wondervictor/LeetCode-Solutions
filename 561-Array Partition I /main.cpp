#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <nums.size(); i += 2)
            sum += nums[i];
        return sum;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}