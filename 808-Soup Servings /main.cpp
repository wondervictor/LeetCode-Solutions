#include <iostream>
#include <unordered_map>


using namespace std;

class Solution {
public:

    double getProb(unordered_map<int, unordered_map<int, double>>& prob, int a, int b) {
      if (a <= 0 && b <= 0)
        return 0.5;
      if (b <= 0)
        return 0.0;
      if (a <= 0)
        return 1.0;
      if (!prob.count(a) || !prob[a].count(b))
        prob[a][b] = 0.25 * (getProb(prob, a-4, b) + getProb(prob, a-3, b-1)
                + getProb(prob, a-2, b-2) + getProb(prob, a-1, b-3));
      return prob[a][b];
    }

    double soupServings(int N) {
      if (N == 0)
        return 0.5;
      unordered_map<int, unordered_map<int, double>> probMatrix;
      int size = (N + 24) / 25;

      return N > 4800 ? 1:getProb(probMatrix, size, size);
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution sol;
  cout<<sol.soupServings(100331415);
  return 0;
}