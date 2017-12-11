#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m + n - 1;
        for(;k > 0; k --) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i --;
            } else {
                nums1[k] = nums2[j];
                j --;
            }
        }

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}