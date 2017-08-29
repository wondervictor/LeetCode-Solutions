#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> output = nums;
        int n = (int)nums.size();
        for(int i = n - 1; i >= 0; i--) {
            int index = rand() % (i + 1);
            swap(output[i], output[index]);
        }
        return output;
    }
private:
    vector<int> nums;


};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}