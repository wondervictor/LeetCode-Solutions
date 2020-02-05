#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
      auto size = s.size();
      if(size == 0)
        return 0;
      int startIndex = (int)size - 1;
      while(startIndex >= 0 && s[startIndex] == ' ')
        startIndex --;
      int length = 0;
      for(int i = startIndex; i >= 0; i --) {
        if(s[i] != ' ')
          length ++;
        else
          break;
      }
      return length;
    }
};



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}