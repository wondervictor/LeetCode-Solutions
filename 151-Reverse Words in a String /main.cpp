#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
  void reverseWords(string &s) {
    string tmp;
    stack<string> words;
    for(auto ch: s) {
      if(ch == ' ') {
        if (!tmp.empty())
          words.push(tmp);
        tmp = "";
      } else {
        tmp.push_back(ch);
      }
    }
    if (!tmp.empty())
      words.push(tmp);
    s = "";
    while(!words.empty()) {
      s += words.top();
      words.pop();
      s.push_back(' ');
    }
    s.pop_back();
  }
};


int main() {

  string s = "    ";
  Solution sol;
  sol.reverseWords(s);
  cout<<s<<"<"<<endl;

  std::cout << "Hello, World!" << std::endl;
  return 0;
}