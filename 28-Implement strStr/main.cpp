#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
      if(needle.size() == 0)
        return 0;

      int hIndex = 0;
      int nIndex = 0;
      int startIndex = -1;
      while(hIndex < haystack.size()) {
        if(haystack[hIndex] == needle[nIndex]) {
          startIndex = startIndex == -1 ? hIndex : startIndex;
          nIndex ++;
          if(nIndex == needle.size())
            return startIndex;
        } else {
          nIndex = 0;
          hIndex = startIndex >= 0 ? startIndex : hIndex;
          startIndex = -1;
        }
        hIndex ++;
      }
      return -1;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  // "mississippi"
  //"issip"
  string a = "mississippi";
  string needle = "issip";
  Solution sol;
  cout<<sol.strStr(a, needle);
  return 0;
}