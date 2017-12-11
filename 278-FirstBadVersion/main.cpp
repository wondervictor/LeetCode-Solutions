#include <iostream>


bool isBadVersion(int version) {
    return version >= 1702766719;
}
/*
 * 2126753390 versions
1702766719 is the first bad version.
 * */

class Solution {
public:
    int firstBadVersion(int n) {
        uint left = 1;
        uint right = n;
        uint min = n;
        while(left < right) {
            uint mid = (left + right)/2;
            if(isBadVersion(mid)) {
                min = std::min(min, mid);
                right = min;
            } else {
                left = mid+1;
            }
        }
        return min;
    }
};

int main() {
    Solution sol;
    std::cout<<sol.firstBadVersion(2126753390);

    return 0;
}