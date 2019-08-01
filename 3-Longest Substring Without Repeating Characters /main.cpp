#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    // 61.59% time  54.49% space
    int lengthOfLongestSubstring(string s) {
      auto size = s.size();
      if(size == 0)
        return 0;
      if(size == 1)
        return 1;

      map<char, int> location;
      int maxLen = 1;
      int currentLen = 1;
      int start = 0;
      int end = 1;
      location[s[start]] = 0;
      while (end < size) {
        auto iter = location.find(s[end]);
        if(iter != location.end() && iter->second >= start) {
          int currentStart = iter->second;
          currentLen -= (currentStart - start);
          // cout<<"end: "<<s[end]<<endl;
          // cout<<"start: "<<start <<" current start: "<<currentStart<<" current len:"<<currentLen<<endl;
          start = currentStart+1;
          location[s[end]] = end;
        } else {
          if (iter != location.end()) {
            location[s[end]] = end;
          }
          location[s[end]] = end;
          currentLen += 1;
          maxLen = max(currentLen, maxLen);
        }
        end ++;
      }
      maxLen = max(maxLen, currentLen);
      return maxLen;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution sol;
  cout<<sol.lengthOfLongestSubstring("abcabcfefavfasdb")<<endl;
  return 0;
}