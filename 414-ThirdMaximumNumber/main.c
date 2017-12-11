#include <stdio.h>
#include <limits.h>



int thirdMax(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;

    int min = nums[0];
    for(int i = 0; i < numsSize; i ++) {
        min = min < nums[i] ? min:nums[i];
    }

    int firstMax = min;
    int secondMax = min;
    int thirdMax = min;

    for(int i = 0; i < numsSize; i ++) {
        if(nums[i] > firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = nums[i];
        } else if (nums[i] > secondMax && nums[i] < firstMax) {
            thirdMax = secondMax;
            secondMax = nums[i];
        } else if (nums[i] > thirdMax && nums[i] < secondMax)
            thirdMax = nums[i];
    }
    if(secondMax == thirdMax)
        return firstMax;
    return thirdMax;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}