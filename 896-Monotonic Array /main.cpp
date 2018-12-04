#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
      bool increase = true;
      bool decrease = true;
      int idx = *A.begin();
      for(auto i=A.begin()+1; i != A.end() && (increase||decrease); i ++) {
        increase &= (idx <= *i);
        decrease &= (idx >= *i);
        idx = *i;
      }
      return increase || decrease;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}