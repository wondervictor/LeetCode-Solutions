#include <stdio.h>
#include <tkDecls.h>


int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int size = 0;
    int currentSize = 0;
    for(int i = 0; i < numsSize;) {
        if(nums[i] == 1) {
            currentSize ++;
        } else {
            size = size > currentSize ? size:currentSize;
            currentSize = 0;
            while(nums[i++] == 0)
                i++;
            continue;
        }
        i ++;
    }
    size = size > currentSize ? size:currentSize;
    return size;
}


int main() {

    int a[6] = {1,0,1,1,0,1};
    printf("%d\n",findMaxConsecutiveOnes(a,6));


    //printf("Hello, World!\n");
    return 0;
}