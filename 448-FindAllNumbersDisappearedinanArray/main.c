#include <stdio.h>
#include <stdlib.h>
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int cursor = 0;
    while(cursor < numsSize) {
        while(nums[cursor] == 0 && cursor < numsSize)
            cursor ++;
        if(cursor == numsSize)
            break;
        int a = nums[cursor] - 1;
        while(nums[a] != 0) {
            int b = nums[a]-1;
            nums[a] = 0;
            a = b;
        }
        cursor ++;
    }
    for(int i = 0; i < numsSize; i ++)
        *returnSize = nums[i] != 0 ? *returnSize+1:*returnSize;
    int *returnNum = (int*)malloc(*returnSize * sizeof(int));
    int j = 0;
    for(int i = 0; i < numsSize; i ++) {
        if (nums[i]!=0)
            returnNum[j++] = i+1;
    }
    return returnNum;
}


int main() {


    int a[14] = {4,3,2,7,3,2,3,1,9,10,4,12,13,14};
    int s = 0;
    int *p = findDisappearedNumbers(a,14,&s);
    for(int i = 0; i < s; i ++)
        printf("%d ",p[i]);

    //printf("Hello, World!\n");
    return 0;
}