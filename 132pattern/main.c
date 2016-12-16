#include <stdio.h>
#include <limits.h>
#define false 0
#define true  1

typedef int bool;

bool turnback(int *nums, int index);
bool find132pattern(int* nums, int numsSize);
//[3,5,0,3,4]

int main(int argc, char const *argv[]) {


    int a[5] = {3,5,0,3,4};
    printf("%d\n",find132pattern(a,5));
    return 0;
}
bool turnback(int *nums, int index) {
    bool result = false;
    bool flag = false;
    int i = index;
    int maxIndex = -1;
    int value = nums[index];
    while (i > 0) {
        i --;
        if (nums[i] > value) {
            flag = true;
            maxIndex = i;
            continue;
        }
        if (nums[i] < value && maxIndex > i && flag) {
            result = true;
            break;
        }
    }
    return result;
}

bool find132pattern(int* nums, int numsSize) {
    int stack[numsSize];
    int top = 0;
    int min = INT_MIN;
    for (int i = numsSize-1; i >= 0; i --) {
        if (nums[i] < min) {
            return true;
        } else {
            while (nums[i] > stack[top] && top >= 1) {
                min = stack[top];
                top --;
            }
            top ++;
            stack[top] = nums[i];
        }
    }
    return false;
}

/*
// O(n ^ 2)
bool find132pattern(int* nums, int numsSize) {
    int i = 1;
    bool result = false;
    while (++i < numsSize) {
        bool flag = false;
        int j = i;
        int value = nums[i];
        while (j > 0) {
            j --;
            if (nums[j] > value) {
                flag = true;
                continue;
            }
            if (nums[j] < value && flag) {
                result = true;
                break;
            }
        }
        if (result == true)
            break;
    }

    return result;
}
*/

/*
bool turnback(int *nums, int index) {
    int value = nums[index];
    bool flag = false;
    int i = index;
    while (i > 0) {
        i --;
        if (nums[i] < value) {
            flag = true;
            break;
        }
    }
    return flag;
}

bool find132pattern(int* nums, int numsSize) {
    int i = 1;
    bool flag = false;
    while (i < numsSize) {
        if (nums[i] < nums[i - 1]) {
            flag = turnback(nums, i);
            if (flag == true) {
                break;
            }
        }

        i ++;
    }
    return flag;
}
*/


/*
bool pattern(int *args, int num){
    bool flag = FALSE;
    if (args[0]<args[1]) {
        for (int i = 1; i < num; i ++) {
            if (args[i-1] > args[i]) {
                flag = TRUE;
                break;
            }
        }
    } else if (args[0]>args[1]) {
        for (int i = 1; i < num; i ++) {
            if (args[i-1] < args[i]) {
                flag = TRUE;
                break;
            }
        }
    }
    return flag;
}
*/
