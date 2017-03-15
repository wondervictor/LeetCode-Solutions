#include <iostream>


class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 1)
            return true;
        int mid = num/2;
        for(int i = 2; i <= mid; i ++) {
            if(i * i == num)
                return true;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}