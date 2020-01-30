#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
      string result;
      // 1000
      int a = num / 1000;
      string aStr(a, 'M');
      result += aStr;

      int remainder = num % 1000;
      // 100
      int b = remainder / 100;
      if (b == 9)
        result += "CM";
      else if (b > 5) {
        string cStr(b-5, 'C');
        result += "D" + cStr;
      } else if (b == 5)
        result += "D";
      else if (b == 4) {
        result += "CD";
      } else {
        string cStr(b, 'C');
        result += cStr;
      }

      remainder = remainder % 100;
      int c = remainder / 10;
      if (c == 9)
        result += "XC";
      else if (c > 5) {
        string cStr(c-5, 'X');
        result += "L" + cStr;
      } else if (c == 5)
        result += "L";
      else if (c == 4) {
        result += "XL";
      } else {
        string cStr(c, 'X');
        result += cStr;
      }

      remainder = remainder % 10;
      int d = remainder;
      if (d == 9)
        result += "IX";
      else if (d > 5) {
        string cStr(d-5, 'I');
        result += "V" + cStr;
      } else if (d == 5)
        result += "V";
      else if (d == 4) {
        result += "IV";
      } else {
        string cStr(d, 'I');
        result += cStr;
      }

      return  result;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution sol;
  cout<<sol.intToRoman(3999)<<endl;
  return 0;
}