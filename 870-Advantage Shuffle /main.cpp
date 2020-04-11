#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

//    int findNearestNumber(vector<int>& A, int num) {
//      int left = 0;
//      int right = (int)A.size();
//      while(left < right) {
//        int mid = (left + right) / 2;
//
//      }
//    }

    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
      auto size = B.size();
      vector<int> result(size);
      sort(A.begin(), A.end());
      vector<pair<int, int>> indexB;
      for(int i = 0; i < size; i ++) {
        indexB.push_back(pair<int, int>(B[i], i));
      }
      sort(indexB.begin(), indexB.end());
      int i = 0, j = 0, k = size-1;

      while(i < size) {
        if(A[i] > indexB[j].first) {
          indexB[j].first = A[i];
          j ++;
        } else {
          indexB[k].first = A[i];
          k --;
        }
        i ++;
      }
      for (auto p: indexB) {
        result[p.second] = p.first;
      }
      return result;
    }
    // TLE O(N^2)
    vector<int> advantageCount1(vector<int>& A, vector<int>& B) {
      auto size = B.size();
      vector<int> result(size);
      int min = INT_MAX;
      int delta = 0;
      int value = -1;
      vector<int>::iterator index;
      for(int i = 0; i < size; i ++) {
        min = INT_MAX;
        value = -1;
        for(auto p = A.begin(); p != A.end(); p ++) {
          delta = *p - B[i];
          if (delta > 0 && delta < min) {
            min = delta;
            value = *p;
            index = p;
          }
        }
        if (value != -1)
          A.erase(index);
        result[i] = value;
      }
      min = 0;
      for(int i = 0; i < size; i ++) {
        if (result[i] == -1) {
          result[i] = A[min];
          min ++;
        }
      }
      return result;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  vector<int> A = {12,24,8,32};
  vector<int> B = {13,25,32,11};
  Solution sol;
  auto m = sol.advantageCount(A, B);
  for(auto i: m)
    cout<<i<<" ";

  return 0;
}