#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        size_t size = nums.size();
        if (size == 0)
            return 0;
        vector<int> minVal(size, 0);
        vector<int> maxVal(size, 0);

        minVal[0] = nums[0];
        maxVal[0] = nums[0];

        for (int i = 1; i < size; i ++) {
            int tmpMax = nums[i] * maxVal[i-1];
            int tmpMin = nums[i] * minVal[i-1];
            if (minVal[i-1] == 0)
                tmpMin = nums[i];
            if (maxVal[i-1] == 0)
                tmpMax = nums[i];
            maxVal[i] = max(tmpMax, tmpMin);
            maxVal[i] = max(nums[i], maxVal[i]);
            minVal[i] = min(tmpMax, tmpMin);
            minVal[i] = min(minVal[i], nums[i]);
        }
        int maxProduct = maxVal[0];
        for(int i = 1; i < size; i ++) {
            if (maxProduct < maxVal[i])
                maxProduct = maxVal[i];
        }
        return maxProduct;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}