#include <iostream>

class Solution{
public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin(), citations.end());
      int index = 0;
      int size = (int)citations.size();

      for(int i = size-1; i >= 0; i--) {
        if(citations[i] < (size - i)) {
          break;
        }
        index ++;
      }
      return index;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}