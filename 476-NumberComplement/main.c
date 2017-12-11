#include <stdio.h>

int findComplement(int num) {
    int sNum = 1,copyNum = num;
    while(copyNum != 0) {
        sNum = sNum * 2;
        copyNum = (copyNum-copyNum%2)/2;
    }
    return num ^(sNum-1);
}



int main() {
    printf("Hello, World!\n");
    return 0;
}