#include <stdio.h>


int removeElement(int* nums, int numsSize, int val) { \
    int cursor = numsSize -1;
    int counter = 0;
    for(int i = 0; i <= cursor; i ++) {
        if(nums[i] == val) {
            counter ++;
            while(nums[cursor]==val&&cursor != i) {
                counter ++;
                cursor --;
            }
            nums[i] = nums[cursor--];
        }
    }
    return numsSize - counter;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}