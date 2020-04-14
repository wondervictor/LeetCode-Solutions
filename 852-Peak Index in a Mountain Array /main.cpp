#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
      int mid = (int)A.size() / 2;
      int peakIndex = mid;
      if (A[mid] > A[mid+1]) {
        while(mid >= 1 && A[mid-1] > A[mid])
          mid --;
        peakIndex = mid;
      } else if (A[mid] < A[mid+1]) {
        while(mid < A.size()-1 && A[mid+1] > A[mid])
          mid ++;
        peakIndex = mid;
      }
      return peakIndex;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}