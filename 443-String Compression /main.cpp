#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
      size_t size = chars.size();
      if(size <= 1)
        return (int)size;
      int index = 1;
      int elemInd = 1;
      int currentCounter = 1;
      char currentValue = chars[0];
      while(index < size) {
        auto startIter = chars.begin() + elemInd;
        if (*startIter == currentValue) {
          currentCounter += 1;
          chars.erase(startIter);
        } else {
          currentValue = *startIter;
          int steps = 0;
          auto count = currentCounter > 1;
          while(count && currentCounter > 0) {
            steps ++;
            auto c = (uint8_t)(currentCounter % 10);
            chars.insert(chars.begin()+elemInd, c+'0');
            currentCounter  = currentCounter / 10;
          }
          currentCounter = 1;
          elemInd += steps+1;
        }
        index ++;
      }
      auto count = currentCounter > 1;
      while(count && currentCounter > 0) {
        auto c = (uint8_t)(currentCounter % 10);
        chars.insert(chars.begin()+elemInd, c+'0');
        currentCounter  = currentCounter / 10;
      }
      return (int)chars.size();
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  vector<char> s({'a','b','b','b','a','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b'});
  Solution sol;
  for(auto ch: s) {
    cout<<ch<<" ";
  }
  cout<<endl;
  sol.compress(s);
  for(auto ch: s) {
    cout<<ch<<" ";
  }
  cout<<endl;
  return 0;
}