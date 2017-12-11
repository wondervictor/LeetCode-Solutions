#include <stdio.h>



int maxArea(int* height, int heightSize) {
//    int maxPoint = 0;
//
//
//   O(n^2)
//    for(int i = 0; i < heightSize; i ++) {
//        for(int j = i+1; j < heightSize; j ++) {
//            int current = (height[i] > height[j]?height[j]:height[i])*(j-i);
//            area = current > area ? current : area;
//        }
//    }
//    return area;
    int maxArea = 0;
    int j = heightSize-1, i = 0;
    while(j < i) {
        int area = (height[i] > height[j] ? height[j] : height[i]) * (j-i);
        maxArea = area > maxArea ? area:maxArea;
        if(height[i] > height[j])
            j --;
        else
            i ++;
    }
    return maxArea;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}