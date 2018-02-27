#include <iostream>
/**
 * ax+by=z
 * */

class Solution {
 public:
  bool canMeasureWater(int x, int y, int z) {
    return z == 0 || (x + y >= z && gcd(x, y) % z == 0);
  }

  int gcd(int m, int n) {
    return (m == 0) ? n : gcd(n % m, m);
  }

};



int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}