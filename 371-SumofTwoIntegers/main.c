#include <stdio.h>

int getSum(int a, int b) {
    if(b == 0)
        return a;
    int sum = a^b;
    int car = (a&b)<<1;
    return getSum(sum,car);
}



int main() {
    printf("Hello, World!\n");
    return 0;
}