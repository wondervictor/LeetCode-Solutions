#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
      if (s.size() == 0)
        return 0;
      unordered_map<char, int> roman({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                        {'C', 100}, {'D', 500}, {'M', 1000}});
      // int num = roman[s[0]];
      int num = 0;
      char cursor = s[0];
      int cursorNum = roman[s[0]];
      for(int i = 1; i < s.size(); i ++) {
        int curValue = roman[s[i]];
        if (roman[cursor] > curValue) {
          num += cursorNum;
          cursorNum = curValue;
          cursor = s[i];
        } else if (roman[cursor] == curValue) {
          cursorNum += curValue;
        } else {
          num -= cursorNum;
          cursorNum = curValue;
          cursor = s[i];
        }
      }
      num += cursorNum;
      return num;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution sol;
  string s("I");
  std::cout<<s<<": "<<sol.romanToInt(s)<<endl;

  return 0;
}