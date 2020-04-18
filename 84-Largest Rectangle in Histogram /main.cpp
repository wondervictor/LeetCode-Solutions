#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // TLE O(N^2)
    int largestRectangleArea1(vector<int>& heights) {
      int maxArea = 0;
      int size = (int)heights.size();
      for(int i = 0; i < size; i ++) {
        int minHeight = INT_MAX;
        for(int j = i; j < size; j++) {
          minHeight = min(minHeight, heights[j]);
          maxArea = max(minHeight * (j - i + 1), maxArea);
        }
      }
      return maxArea;
    }
    // O(N^2), prune
    int largestRectangleArea(vector<int>& heights) {
      int maxArea = 0;
      int size = (int)heights.size();
      for(int i = 0; i < size; i ++) {
        if (i < size - 1 && heights[i] <= heights[i+1])
          continue;
        int minHeight = INT_MAX;
        for(int j = i; j >= 0; j--) {
          minHeight = min(minHeight, heights[j]);
          maxArea = max(minHeight * (i - j + 1), maxArea);
        }
      }
      return maxArea;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}