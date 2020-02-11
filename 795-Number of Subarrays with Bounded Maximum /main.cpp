#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


class Solution {
public:
    // Another Quesion Bounded Sum
    int numSubarrayBoundedSum(vector<int>& A, int L, int R) {
      auto size = A.size();
      vector<unordered_map<int, int>> sum(size);

      sum[0][A[0]] = 1;
      sum[0][0] = 1;
      for(int i = 1; i < size; i ++) {
        for(auto p: sum[i-1]) {
          int num = p.first;
          int count = p.second;
          int current = num + A[i];
          if(current <= R)
            sum[i][num+A[i]] += count;
          sum[i][num] += count;
        }
      }
      int count = 0;
      for(auto p: sum[size-1]) {
        if(p.first <= R && p.first >= L)
          count += p.second;
      }
      return count;
    }

    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
      int counter = 0;
      auto size = A.size();
      vector<unordered_map<int, int>> sum(size);
      stack<int> negativeIndex;

      if(A[0] <= R && A[0] >= L) {
        sum[0][0] = 1;
        counter += 1;
      } else if (A[0] < L) {
        negativeIndex.push(0);
      }
      for(int i = 1; i < size; i ++) {
        if(A[i] <= R && A[i] >= L) {
          sum[i][i] = 1;
          counter += 1;
          while(negativeIndex.size()) {
            int index = negativeIndex.top();
            negativeIndex.pop();
            sum[i][index] = 1;
            counter ++;
          }
        } else if(A[i] < L) {
          negativeIndex.push(i);
        } else {
          while(negativeIndex.size())
            negativeIndex.pop();
          continue;
        }
        for(auto p: sum[i-1]) {
          int index = p.first;
          int count = p.second;
          sum[i][index] = count;
          counter += count;
        }
      }
      return counter;
    }

};


int main() {



  return 0;
}