#include <iostream>

int guess(int num) {
    if(num>1702766719)
        return 1;
    else if(num < 1702766719)
        return -1;
    else
        return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        uint max = n;
        uint min = 1;
        if(guess(max) == 0)
            return max;
        while(min <= max) {
            uint num = (max+min)/2;
            //(max+min)/2;
            int i = guess(num);
            if(i == -1) {
                max = num;
            } else if (i == 1) {
                min = num;
            } else {
                return num;
            }
        }
        return 0;
    }
};




int main() {
    Solution sol;
    int n = 2126753390;
    std::cout<<sol.guessNumber(n);

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}