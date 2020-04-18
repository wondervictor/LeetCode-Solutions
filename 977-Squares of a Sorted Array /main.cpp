#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
      int negativeInd = 0;
      int positiveInd = 0;
      int index = 0;
      while(index < A.size() && A[index] <= 0) {
        index ++;
      }
      positiveInd = index;
      negativeInd = index - 1;
      vector<int> result(A.size(), 0);
      index = 0;
      while(negativeInd >= 0 && positiveInd < A.size()) {
        if (-A[negativeInd] > A[positiveInd]) {
          result[index++] = A[positiveInd]*A[positiveInd];
          positiveInd ++;
        } else {
          result[index++] = A[negativeInd]*A[negativeInd];
          negativeInd --;
        }
      }
      while(negativeInd >= 0) {
        result[index++] = A[negativeInd]*A[negativeInd];
        negativeInd --;
      }
      while(positiveInd < A.size()) {
        result[index++] = A[positiveInd]*A[positiveInd];
        positiveInd ++;
      }
      return result;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}