#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // slow
  int characterReplacement1(string s, int k) {
    int breakpoint = -1;
    int maxLen = 1;
    if (s.size() <= 1)
      return (int)s.size();
    char current = s[0];
    int currentLen = 1;
    int currentPos = 0;
    int left = k;
    int bestPos = -1;
    int bestLeft = k;

    for(int i = 1; i < s.size(); i ++) {
      if(current == s[i]) {
        currentLen ++;
      } else if (left > 0) {
        left --;
        currentLen ++;
        breakpoint = breakpoint == -1 ? i : breakpoint;
      } else {
        left = k;
        maxLen = max(currentLen, maxLen);
        breakpoint = breakpoint == -1 ? i : breakpoint;
        current = s[breakpoint];
        i = breakpoint;
        currentLen = 1;
        breakpoint = -1;
        currentPos = i;
      }

      if (i == s.size()-1 && left > 0) {
        int j = currentPos - 1;
        while(j >= 0 && left > 0) {
          if (s[j] == current) {
            currentLen ++;
          } else {
            left --;
            currentLen ++;
          }
          j --;
        }
      }
    }
    maxLen = max(currentLen, maxLen);
    return maxLen;
  }


  int characterReplacement(string s, int k) {
    int maxLen = 0;
    int maxCount = 0;
    int start = 0;

    vector<int> count(26, 0);
    for(int i = 0; i < s.size(); i ++) {
      int ind = s[i] - 'A';
      count[ind] += 1;
      maxCount = max(maxCount, count[ind]);
      while(i - start + 1 - maxCount > k) {
        count[s[start]-'A'] --;
        start ++;
      }
      maxLen = max(maxLen, i-start+1);
    }
    return maxLen;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  string input = "AAAB";
  Solution sol;
  cout<<sol.characterReplacement(input, 0);
  return 0;
}