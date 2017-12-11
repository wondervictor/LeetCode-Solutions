#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
    double s = log10(n)/log10(3);
    return s == (int)s;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}