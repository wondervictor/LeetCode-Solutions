#include <iostream>
#include <cmath>

class Solution {
public:
    double angleClock(int hour, int minutes) {
      double minDegree = minutes * 6;
      double hourDegree = (hour%12) * 30 + minutes / 2;
      double distance = abs(hourDegree - minDegree);
      return distance <= 180 ? distance : 360 - distance;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}