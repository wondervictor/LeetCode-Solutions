#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;


class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
      centerX = x_center;
      centerY = y_center;
      this->radius = radius;
    }

    vector<double> randPoint() {
      double r = this->radius * sqrt((double)rand() / RAND_MAX);
      double theta = ((double)rand() / RAND_MAX) * 2 * M_PI;
      double x = r * cos(theta) + this->centerX;
      double y = r * sin(theta) + this->centerY;
      vector<double> point = {x, y};
      return point;
    }
private:
    double centerX;
    double centerY;
    double radius;
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}