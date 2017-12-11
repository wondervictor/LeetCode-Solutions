#include <stdio.h>


int mySqrt(int x) {
    __int64_t left = 1;
    __int64_t right = x;
    __int64_t mid = 0;
    while(left <= right) {
        mid = (left + right+1)/2;
        __int64_t sqr = mid * mid;
        if(sqr == x)
            break;
        else if (sqr > x) {
            if((mid-1)*(mid-1) <= x)
                return mid-1;
            right = mid;
        } else {
            left = mid;
        }
    }
    return (int)mid;
}


int main() {

    printf("%d\n", mySqrt(2147395599));
    return 0;
}