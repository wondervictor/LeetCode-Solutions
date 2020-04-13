#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
      auto size = A.size();
      if (size <= 2)
        return true;
      bool result = true;
      int pre = 0;
      for(int i = 0; i < size-2; i ++) {
        if(A[i+2] < A[i] || A[i+2] < A[pre]) {
          result = false;
          break;
        }
        pre = i;
      }
      return result;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}