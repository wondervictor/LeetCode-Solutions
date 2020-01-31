#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    void flood(vector<vector<int>>& image, vector<vector<int>>& trace, int sr, int sc, int color, int newColor) {
      auto row = image.size();
      auto column = image[0].size();
      image[sr][sc] = newColor;
      trace[sr][sc] = -1;
      if (sr + 1 < row && image[sr+1][sc] == color && trace[sr+1][sc] != -1)
        flood(image, trace, sr+1, sc, color, newColor);
      if (sr -1 >= 0 && image[sr-1][sc] == color && trace[sr-1][sc] != -1)
        flood(image, trace, sr-1, sc, color, newColor);
      if (sc + 1 < column && image[sr][sc+1] == color && trace[sr][sc+1] != -1)
        flood(image, trace, sr, sc+1, color, newColor);
      if (sc - 1 >= 0 && image[sr][sc-1] == color && trace[sr][sc-1] != -1)
        flood(image, trace, sr, sc-1, color, newColor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      vector<vector<int>> floodImage = image;
      vector<vector<int>> trace = image;
      int color = image[sr][sc];
      flood(floodImage, trace, sr, sc, color, newColor);
      return floodImage;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}