#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    string convertToTitle(int n) {
      string result;
      n = n - 1;
      int q = n % 26;
      n = n / 26;
      result.push_back((char)('A'+q));
      while (n > 0) {
        n = n - 1;
        q = n % 26;
        result.insert(0, 1, (char)('A'+q));
        n /= 26;
      }
      return result;
    }
};



int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution sol;
  auto m = sol.convertToTitle(701);
  cout<<m<<endl;
  return 0;
}