#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

      string result;
      size_t size = s.size();
      // IMPORTANT: numRows == 1
      if (size <= 1 || numRows == 1)
        return s;
      int index = 0;
      while (index < size) {
        result += s[index];
        index += 2*numRows-2;
      }
      for(int k = 1; k < numRows-1; k ++) {
        int leftInd = k;
        int rightInd = 2*numRows-2-k;
        while (leftInd < size) {
          result += s[leftInd];
          if (rightInd < size)
            result += s[rightInd];

          leftInd += 2*numRows-2;
          rightInd += 2*numRows-2;
        }
      }
      index = numRows-1;
      while (index < size) {
        result += s[index];
        index += 2*numRows-2;
      }
      return result;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution sol;
  cout<<sol.convert("PAYPALISHIRING", 4)<<endl;
  return 0;
}