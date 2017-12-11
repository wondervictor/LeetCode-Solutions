#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int increment = 1;
    int *returnArr = (int *)malloc((digitsSize+1)* sizeof(int));

    for(int i = digitsSize-1; i >= 0; i --) {
        int num = digits[i] + increment;
        returnArr[i] = num%10;
        increment = num/10;
    }
    *returnSize = digitsSize;
    if(increment != 0) {
        (*returnSize) ++;
        for (int i = digitsSize; i > 0 ; i --) {
            returnArr[i] = returnArr[i-1];
        }
        returnArr[0] = increment;
    }
    return returnArr;
}

int main() {
    int a[3] = {1,2,3};
    int sized = 0;
    int *p = plusOne(a,3,&sized);


    free(p);
    printf("Hello, World!\n");
    return 0;
}