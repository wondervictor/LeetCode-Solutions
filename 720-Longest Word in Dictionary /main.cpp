#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
  // duplicate computation
  string longestWord(vector<string>& words) {
    string result;
    int maxLen = 0;
    unordered_set<string> dict(words.begin(), words.end());
    for(auto p: words) {
      int psize = (int)p.size();
      if(psize < maxLen||(psize==maxLen && p >= result))
        continue;
      bool isValid = true;
      string substr;
      for(int i = 0; i < psize; i ++) {
        substr += p[i];
        if(dict.find(substr) == dict.end()) {
          isValid = false;
          break;
        }
      }
      if(isValid) {
        maxLen = psize;
        result = p;
      }
    }
    return result;
  }
};


class Solution1 {
public:
    // 96ms
    bool exist(unordered_set<string>& words, unordered_set<string>& existSet, string word, int len) {

      auto substr = word.substr(0, len);
      if (existSet.find(substr) != existSet.end())
        return true;
      if (words.find(substr) == words.end())
        return false;
      if (len == 1) {
        existSet.insert(substr);
        return true;
      }
      auto res = exist(words, existSet, word, len-1);
      cout<<substr<<": "<<res<<endl;
      if (!res) {
        words.erase(substr);
        return false;
      }
      existSet.insert(substr);
      return true;
    }

    string longestWord(vector<string>& words) {
      string result = "";
      int maxLen = 0;
      unordered_set<string> wordSet(words.begin(), words.end());
      unordered_set<string> existSet;
      for(auto p: words) {
        bool res = exist(wordSet, existSet, p, (int)p.size());
        if (res && p.size() >= maxLen) {
          if (p.size() == maxLen)
            result = result > p ? p : result;
          else
            result = p;
          maxLen = p.size();
        }
      }
      return result;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}