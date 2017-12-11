#include <iostream>
#include <vector>



using namespace std;

///
/// [0,1,0,2,1,0,1,3,2,1,2,1]
/// [0,1,1,2,2,2,2,3,2,2,2,1]
///

/*
 *             if (height[i] >= leftHeight) {
                i ++;
                leftHeight = height[i];
            } else {
                int increment = 1;
                rightHeight = height[i];
                while(i+increment < size && height[i+increment] < leftHeight) {
                    increment ++;
                    if (rightHeight < height[i+increment]) {
                        rightHeight = height[i+increment];
                    }
                }



            }
 *
 * */

class Solution {
public:

    int trap(vector<int>& height) {
        int leftHeight = 0;
        int rightHeight = 0;
        int nums = 0;
        size_t size = height.size();
        for(int i = 0; i < size;) {
            if (height[i] >= leftHeight) {
                leftHeight = height[i];
                i ++;
            } else {
                int increment = 1;
                rightHeight = height[i];
                int maxIndex = i;
                while(i+increment < size && height[i+increment] < leftHeight) {
                    if (rightHeight <= height[i+increment]) {
                        rightHeight = height[i+increment];
                        maxIndex = i+increment;
                    }
                    increment ++;
                }
                if (i+increment < size && height[i+increment] >= leftHeight) {
                    maxIndex = i + increment;
                    rightHeight = height[maxIndex];
                }
                int stdHeight = leftHeight > rightHeight ? rightHeight : leftHeight;
                while(i < maxIndex) {
                    nums += stdHeight - height[i];
                    i ++;
                }
                i = maxIndex;
                leftHeight = rightHeight;
            }
        }
        return nums;
    }
};

int main() {

    vector<int> s = {1,3,0,2,0};//{10,1,0,2,1,0,1,3,2,1,2,1,5,0,3,4,0,0,0,19};
    Solution sol;

    cout<<sol.trap(s);
    return 0;
}