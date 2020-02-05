#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
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

// log
class Solution {
public:
    int hIndex(vector<int>& citations) {
      int leftIndex = 0;
      int rightIndex = (int)citations.size();
      int index = 0;
      int currentIndex = 0;
      while(leftIndex < rightIndex) {
        int mid = (leftIndex + rightIndex) / 2;
        currentIndex = (int)citations.size() - mid;
        if(citations[mid] >= currentIndex) {
          index = max(index, currentIndex);
          rightIndex = mid;
        } else {
          leftIndex = mid+1;
        }
        // cout<<leftIndex<<" "<<mid<<" "<<rightIndex<<endl;
      }
      return index;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}