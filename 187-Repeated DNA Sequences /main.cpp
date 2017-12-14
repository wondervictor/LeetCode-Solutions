#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    size_t index = 0;
    vector<string> result;
    map<string, int> content;
    auto size = (int)s.size();

    for(; index <= size-10; index ++) {
      string tmp = s.substr(index,10);
      if (content.find(tmp) == content.end())
        content[tmp] = 1;
      else {
        content[tmp] += 1;
        if (content[tmp] == 2)
          result.push_back(tmp);
      }

    }
    return result;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}