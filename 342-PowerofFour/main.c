#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool isPowerOfFour(int num) {
    double re = log2(num)/2;
    return re == (int)re;
}


int main() {


    printf("Hello, World!\n");
    return 0;
}