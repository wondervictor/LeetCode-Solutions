#include <iostream>



class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; i ++) {
            result = 2 * result + n % 2;
            n /= 2;
        }
        return result;
    }
};



int main() {

    using namespace std;
    uint32_t input = 43261596;
    Solution sol;
    uint32_t output = sol.reverseBits(input);
    cout<<output;

    return 0;
}