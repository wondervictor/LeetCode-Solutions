#include <iostream>
#include <vector>
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:

    /*
    int maxSubArray(vector<int> &nums) {
        int sum , max = nums[0];
        int size = (int)nums.size();
        for(int i = 1; i < size; i ++) {
            sum += nums[i];
            if(sum > max)
                max = sum;
            else if(sum < 0)
                sum = 0;

        }
        return max;
    }
    */

    int maxSubArray(vector<int> &nums) {
        int size = (int)nums.size();
        if(size == 0 )
            return 0;
        int max = nums[0];
        int maxEnd = nums[0];
        for(int i = 1; i < size; i ++) {
            if(maxEnd < 0)
                maxEnd = nums[i];
            else
                maxEnd += nums[i];
            max = max>maxEnd ? max:maxEnd;
        }
        return max;
    }

    /*
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int differ = 0;
        int size = (int)nums.size();
        for(int i = 1; i < size; i ++) {
            int rmax = max;

            if(rmax+differ < 0 && nums[i] > rmax+differ) {
                cout<<"num is changed:"<<nums[i]<<endl;
                max = nums[i];
                differ = 0;
                continue;
            }
            differ += nums[i];
            if(max < max + differ) {
                max = max + differ;
                differ = 0;
            }
        }
        return max;
    }
    */
};

int main() {

    Solution sol;
    vector<int> arr{-3,-2,0,-1};//{8,-19,5,-4,20};//{-1,-1,-2,-2};//{8,-19,5,-4,20};//
    cout<<sol.maxSubArray(arr)<<endl;


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}