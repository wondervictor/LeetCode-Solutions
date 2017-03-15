#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;


class NumArray {
public:
    NumArray(vector<int> &nums) {
        int currentSum = 0;
        this->nums.push_back(0);
        ///nums;
        for(auto i: nums) {
            currentSum += i;
            this->nums.push_back(currentSum);
        }

    }

    int sumRange(int i, int j) {

        return nums[j+1]-nums[i];
    }

    void print() {
        for(auto i: nums) {
            cout<<i<<endl;
        }
    }

private:
    vector<int> nums;

};






int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray ar(nums);
    ar.print();

    std::cout<<ar.sumRange(0,0)<<endl;
    cout<<ar.sumRange(2,5)<<endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}