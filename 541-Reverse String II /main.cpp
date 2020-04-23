#include <iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
      string result;
      int size = (int)s.size();
      int ksize = size / k + 1;

      for(int i = 1; i <= ksize; i++) {
        if (i % 2) {
          int cursor = min(k * i - 1, size-1);
          int minValue = max(0,  (i - 1)* k);
          while(i % 2 && cursor >= minValue) {
            result.push_back(s[cursor--]);
          }
        } else {
          int cursor = (i - 1) * k;
          int maxValue = min(i * k, size);
          result += s.substr(cursor, maxValue-cursor);
        }
      }
      return result;
    }
};


int main() {
  string s = "abcdefg";
  Solution sol;
  string result = sol.reverseStr(s, 2);
  cout<<s<<"->"<<result<<endl;
  return 0;
}