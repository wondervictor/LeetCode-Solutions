#include <stdio.h>


int minMoves(int* nums, int numsSize) {
    int sum = 0;
    int min;
    for(int i = 0; i < numsSize; i ++){
        min = min < nums[i]?min:nums[i];
        sum += nums[i];
    }
    return sum - numsSize * min;


}


int main() {
    printf("Hello, World!\n");
    return 0;
}