#include <iostream>


class Solution {
public:
    int hammingDistance(int x, int y) {
        int p = x^y;
        std::cout<<p<<"\n";
        int distance = 0;
        while(p)
        {
            if(p & 1)
                distance ++;

            p = p >> 1;
        }

        return distance;
    }
};


int main() {



    Solution sol;
    std::cout<<sol.hammingDistance(1,4);

    return 0;
}