#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> result(size);
        for(int &p: result) {
            p = -1;
        }
        stack<int> s;
        for(int i = 0; i < 2 * size; i ++) {
            int index = i % size;
            while (s.size() && nums[index] > nums[s.top()]) {
                result[s.top()] = nums[index];
                s.pop();
            }
            if ( i < size) {
                s.push(index);
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}