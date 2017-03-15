#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int search(int p, vector<int> arr,int index) {
        int left = 0;
        int right = (int)arr.size();
        int mid = (left + right) / 2;
        while(left < right) {
            if (arr[mid] == p) {
                if(mid == index)
                    continue;
                else
                    return mid;
            }
            else if(arr[mid] > p) {
                right = mid;
                mid = (right + left)/2;
                continue;
            } else {
                left = mid+1;
                mid = (right + mid)/2;
                continue;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        size_t size = numbers.size();
        vector<int> result;
        for(int i = 0; i < size; i ++) {
            int p = target - numbers[i];
            int index = search(p, numbers,i);
            if(index != -1) {
                result.push_back(i+1);
                result.push_back(index+1);
                break;
            }
        }
        return result;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}