#include <stdio.h>
#include <limits.h>
//int removeDuplicates(int* nums, int numsSize) {
//    int counter = 0;
//    int j = 0;
//    for(int i = numsSize-1; i >= 1; i --){
//        if(nums[i] == nums[i-1]) {
//            counter ++;
//            nums[i] = INT_MAX;
//            j = i;
//        }
//    }
//    int pCounter = counter;
//    int cursor = 0;
//
////    int j = 0;
////    for(;j < numsSize; j ++) {
////        if(nums[j] == INT_MAX)
////            break;
////    }
//    cursor = j;
//    while(j < numsSize) {
//        cursor = cursor + 1;
//        while(nums[cursor] != INT_MAX && j < numsSize) {
//            nums[j++] = nums[cursor];
//            cursor++;
//        }
//        pCounter --;
//        int bias = counter - pCounter;
//        j = cursor - bias;
//    }
//
//    return numsSize - counter;
//}

int removeDuplicates(int* nums, int numsSize) {
    int counter = 0;
    int j = 0;
    for(int i = numsSize-1; i >= 1; i --){
        if(nums[i] == nums[i-1]) {
            counter ++;
            nums[i] = INT_MAX;
            j = i;
        }
    }
    int pCounter = counter;
    int cursor = j;
    while(j < numsSize && pCounter > 0) {
        cursor = cursor + 1;
        while(nums[cursor] != INT_MAX && j < numsSize) {
            nums[j++] = nums[cursor++];
        }
        pCounter --;
        int bias = counter - pCounter;
        j = cursor - bias;
    }

    return numsSize - counter;
}




int main() {
    int a[3] = {1,1,1};
    printf("%d\n",removeDuplicates(a,3));
    //printf("Hello, World!\n");
    return 0;
}