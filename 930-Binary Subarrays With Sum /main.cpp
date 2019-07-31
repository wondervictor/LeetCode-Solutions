#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    // 24ms (95.25%) 10.8 MB (100%)
    int numSubarraysWithSum(vector<int>& A, int S) {
      auto size = A.size();
      int start = 0;
      int end = 0;
      int num = 0;
      int currentSum = 0;
      if (size == 1) {
        if (A[0] == S)
          return 1;
        else
          return 0;
      }
      if (S == 0) {
        while(1) {
          int numZeros = 0;
          while(start < size && A[start] != 0)
            start += 1;
          if (start == size)
            return 0;
          numZeros += 1;
          end = start + 1;
          while(end < size && A[end]!=1) {
            numZeros += 1;
            end ++;
          }
          num += (numZeros+1)*numZeros/2;
          if (end < size-1) {
            start = end;
          } else {
            break;
          }
        }
        return num;
      }

      int state = 0;
      int ratio = 1;
      if (A[start] == 0) {
        while(start < size && A[start] == 0) {
          start ++;
          ratio ++;
        }
        if (start == size)
          return 0;
      }
      currentSum = A[start];
      end = start;

      while (start <= end && end < size) {
        // move end
        if (currentSum == S) {
          num += ratio;
        }
        end += 1;
        while(end < size) {
          if(A[end] == 0 && currentSum == S) {
            num += ratio;
            end += 1;
          } else if (A[end] == 0 && currentSum != S) {
            end += 1;
          } else if (A[end] == 1) {
            if (currentSum == S) {
              break;
            } else {
              currentSum += 1;
              if (currentSum == S)
                num += ratio;
              end += 1;

            }
          }
        }
        // move start
        ratio = 1;
        if (A[start] == 1) {
          start += 1;
          while(start < end) {
            if (A[start] == 0)
              ratio += 1;
            else
              break;
            start += 1;
          }
        }
      }
      return num;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution sol;
  vector<int> a{1,1,1,1,1};
  cout<<sol.numSubarraysWithSum(a, 5);
  return 0;
}